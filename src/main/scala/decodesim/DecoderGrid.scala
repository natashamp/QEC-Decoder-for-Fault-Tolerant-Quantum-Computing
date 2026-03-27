package decodesim

import spinal.core._
import spinal.lib._

// Parameterized 2D grid of DecoderNodes with nearest-neighbor wiring,
// grid-level FSM orchestration, and correction extraction.
//
// Decode phases:
//   IDLE → LOADING → DECODING → PEELING → DONE
//
// During DECODING, the growth algorithm runs: syndrome nodes expand outward,
// passive nodes join growing regions, and collisions trigger matching.
// After all active regions are matched (or timeout), the grid enters PEELING
// where the leaf-peeling algorithm runs to extract correction paths.
// The CorrectionExtractor then computes the data-qubit correction vector.

case class DecoderGrid(config: DecoderConfig) extends Component {
  val rows = config.gridRows
  val cols = config.gridCols

  val io = new Bundle {
    // Syndrome frame: one bit per stabilizer, loaded in parallel
    val syndromeFrame = in Bits(config.numStabilizers bits)
    val loadEnable    = in Bool()

    // Global control
    val start   = in Bool()
    val reset_n = in Bool()

    // Per-node status outputs (exposed for testability)
    val nodeStates    = out Vec(NodeState(), rows * cols)
    val nodeRegionIds = out Vec(UInt(config.regionIdWidth bits), rows * cols)
    val nodeParentDirs = out Vec(ParentDir(), rows * cols)
    val nodeMatchDirs  = out Vec(ParentDir(), rows * cols)
    val nodePeeled    = out Vec(Bool(), rows * cols)
    val nodeSyndromes = out Vec(Bool(), rows * cols)

    // Aggregate correction output
    val correctionFlags = out Bits(config.numStabilizers bits)
    val correction      = out(CorrectionOutput(config))

    // Grid-level status
    val gridPhase  = out(GridPhase())
    val allMatched = out Bool()
    val anyGrowing = out Bool()
    val stall      = out Bool()  // Growth phase exceeded cycle budget
    val done       = out Bool()  // Decode complete, correction valid
  }

  // ── Grid-level FSM ─────────────────────────────────────────────────
  val phaseReg    = RegInit(GridPhase.IDLE)
  val cycleCount  = RegInit(U(0, log2Up(config.maxGrowthCycles + config.maxPeelCycles + 2) bits))
  val stallReg    = RegInit(False)
  val doneReg     = RegInit(False)
  val peelingDone = RegInit(False)

  // ── Instantiate nodes ──────────────────────────────────────────────
  val nodes = Array.tabulate(rows, cols) { (r, c) =>
    DecoderNode(config, row = r, col = c)
  }

  // Internal start/peel signals driven by grid FSM
  val nodeStart     = RegInit(False)
  val nodeStartPeel = RegInit(False)

  // Wire global control signals and syndrome bits to each node
  for (r <- 0 until rows; c <- 0 until cols) {
    val node = nodes(r)(c)
    val flatIdx = r * cols + c

    node.io.syndromeIn := io.syndromeFrame(flatIdx)
    node.io.loadEnable := io.loadEnable
    node.io.start      := nodeStart
    node.io.startPeel  := nodeStartPeel
    node.io.reset_n    := io.reset_n
  }

  // ── Wire nearest-neighbor links ────────────────────────────────────
  for (r <- 0 until rows; c <- 0 until cols) {
    val node = nodes(r)(c)

    if (r > 0)        node.io.neighborIn.north := nodes(r - 1)(c).io.linkOut
    else              node.io.neighborIn.north := NodeLinkUtils.tiedOff(config)

    if (r < rows - 1) node.io.neighborIn.south := nodes(r + 1)(c).io.linkOut
    else              node.io.neighborIn.south := NodeLinkUtils.tiedOff(config)

    if (c > 0)        node.io.neighborIn.west := nodes(r)(c - 1).io.linkOut
    else              node.io.neighborIn.west := NodeLinkUtils.tiedOff(config)

    if (c < cols - 1) node.io.neighborIn.east := nodes(r)(c + 1).io.linkOut
    else              node.io.neighborIn.east := NodeLinkUtils.tiedOff(config)
  }

  // ── Wire status outputs ────────────────────────────────────────────
  for (r <- 0 until rows; c <- 0 until cols) {
    val flatIdx = r * cols + c
    io.nodeStates(flatIdx)     := nodes(r)(c).io.state
    io.nodeRegionIds(flatIdx)  := nodes(r)(c).io.regionId
    io.nodeParentDirs(flatIdx) := nodes(r)(c).io.parentDir
    io.nodeMatchDirs(flatIdx)  := nodes(r)(c).io.matchDir
    io.nodePeeled(flatIdx)     := nodes(r)(c).io.peeled
    io.nodeSyndromes(flatIdx)  := nodes(r)(c).io.syndrome
    io.correctionFlags(flatIdx) := nodes(r)(c).io.correctionFlag
  }

  // ── Aggregate status ───────────────────────────────────────────────
  val nodeStateVec = (for (r <- 0 until rows; c <- 0 until cols)
                       yield nodes(r)(c).io.state).toSeq

  val anyGrowingWire = nodeStateVec.map(_ === NodeState.GROWING).reduce(_ || _)
  val allMatchedWire = !anyGrowingWire && nodeStateVec.map { st =>
    st === NodeState.IDLE || st === NodeState.MATCHED || st === NodeState.PEELING
  }.reduce(_ && _)

  // Check if any node had a syndrome (i.e., there's actual work to do)
  val anySyndrome = (for (r <- 0 until rows; c <- 0 until cols)
                      yield nodes(r)(c).io.syndrome).reduce(_ || _)

  // Check if all nodes have finished peeling
  val allPeeled = (for (r <- 0 until rows; c <- 0 until cols) yield {
    val node = nodes(r)(c)
    node.io.peeled || node.io.syndrome || (node.io.state === NodeState.IDLE)
  }).reduce(_ && _)

  io.anyGrowing := anyGrowingWire
  io.allMatched := allMatchedWire

  // ── CorrectionExtractor ────────────────────────────────────────────
  val extractor = CorrectionExtractor(config)
  for (i <- 0 until config.numStabilizers) {
    extractor.io.nodeParentDirs(i) := io.nodeParentDirs(i)
    extractor.io.nodeMatchDirs(i)  := io.nodeMatchDirs(i)
    extractor.io.nodePeeled(i)     := io.nodePeeled(i)
    extractor.io.nodeStates(i)     := io.nodeStates(i)
    extractor.io.nodeRegionIds(i)  := io.nodeRegionIds(i)
    extractor.io.nodeMatchedWith(i) := nodes(i / cols)(i % cols).io.matchedWithId
    extractor.io.nodeSyndromes(i)  := io.nodeSyndromes(i)
  }
  extractor.io.trigger := doneReg
  io.correction := extractor.io.correction

  // ── Grid-level FSM logic ───────────────────────────────────────────
  switch(phaseReg) {
    is(GridPhase.IDLE) {
      nodeStart     := False
      nodeStartPeel := False
      doneReg       := False
      stallReg      := False
      cycleCount    := 0
      peelingDone   := False

      when(io.start) {
        phaseReg := GridPhase.LOADING
      }
    }

    is(GridPhase.LOADING) {
      // Wait for loadEnable to complete (external control)
      // Transition to DECODING when start is asserted and loading is done
      when(!io.loadEnable) {
        phaseReg   := GridPhase.DECODING
        nodeStart  := True
        cycleCount := 0
      }
    }

    is(GridPhase.DECODING) {
      nodeStart  := True
      cycleCount := cycleCount + 1

      when(allMatchedWire && !anyGrowingWire) {
        // All active regions have matched — proceed to peeling
        when(anySyndrome) {
          phaseReg      := GridPhase.PEELING
          nodeStart     := False
          nodeStartPeel := True
          cycleCount    := 0
        } otherwise {
          // No syndromes — nothing to decode
          phaseReg := GridPhase.DONE
          doneReg  := True
        }
      } elsewhen(cycleCount >= config.maxGrowthCycles) {
        // Growth budget exceeded — stall
        stallReg := True
        // Still transition to peeling with whatever matching we have
        phaseReg      := GridPhase.PEELING
        nodeStart     := False
        nodeStartPeel := True
        cycleCount    := 0
      }
    }

    is(GridPhase.PEELING) {
      nodeStartPeel := False  // Only pulse for one cycle
      nodeStart     := False
      cycleCount    := cycleCount + 1

      when(cycleCount >= config.maxPeelCycles || peelingDone) {
        phaseReg := GridPhase.DONE
        doneReg  := True
      }

      // Check if peeling has converged (no more nodes can be peeled)
      when(allPeeled) {
        peelingDone := True
      }
    }

    is(GridPhase.DONE) {
      // Stay in DONE until reset
      doneReg := True
    }
  }

  // Reset overrides everything
  when(!io.reset_n) {
    phaseReg      := GridPhase.IDLE
    cycleCount    := 0
    stallReg      := False
    doneReg       := False
    peelingDone   := False
    nodeStart     := False
    nodeStartPeel := False
  }

  io.gridPhase := phaseReg
  io.stall     := stallReg
  io.done      := doneReg
}

// Verilog generation entry points
object DecoderGridVerilog extends App {
  SpinalVerilog(DecoderGrid(DecoderConfig(codeDistance = 3)))
}

object DecoderGridVerilogD5 extends App {
  SpinalVerilog(DecoderGrid(DecoderConfig(codeDistance = 5)))
}
