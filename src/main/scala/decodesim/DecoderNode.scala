package decodesim

import spinal.core._
import spinal.lib._

case class DecoderNode(config: DecoderConfig, row: Int, col: Int) extends Component {
  val io = new Bundle {
    // Syndrome input for this stabilizer
    val syndromeIn = in Bool()
    val loadEnable = in Bool()   // Pulse high for one cycle to latch syndrome

    // Global control
    val start     = in Bool()    // Begin growth phase
    val startPeel = in Bool()    // Begin peeling phase
    val reset_n   = in Bool()    // Active-low reset to return to IDLE

    // Neighbor links: what we receive from each neighbor
    val neighborIn = new Bundle {
      val north = in(NodeLink(config))
      val south = in(NodeLink(config))
      val east  = in(NodeLink(config))
      val west  = in(NodeLink(config))
    }

    // Our output link broadcast to all neighbors
    val linkOut = out(NodeLink(config))

    // Path marking control (driven by grid's primary collision selection)
    val startPathMark = in Bool()

    // Boundary matching enable (driven by grid after delay threshold)
    val boundaryEnable = in Bool()

    // Node status
    val state    = out(NodeState())
    val regionId = out UInt(config.regionIdWidth bits)

    // Correction outputs
    val correctionFlag = out Bool()
    val parentDir      = out(ParentDir())
    val matchDir       = out(ParentDir())  // Direction of collision neighbor
    val matchedWithId  = out UInt(config.regionIdWidth bits) // Region ID of collision partner
    val peeled         = out Bool()
    val syndrome       = out Bool()
    val onPath         = out Bool()        // Is this node on the correction path?
  }

  // Internal registers
  val stateReg     = RegInit(NodeState.IDLE)
  val syndromeReg  = RegInit(False)
  val parentDirReg = RegInit(ParentDir.NONE)
  val peeledReg    = RegInit(False)
  val onPathReg    = RegInit(False)

  // Region tracking via RegionManager
  val region = RegionManager(config)

  // Unique ID for this node (1-indexed; 0 = no region)
  val nodeId = U(row * config.gridCols + col + 1, config.regionIdWidth bits)

  // Latch syndrome on load — resets all state
  when(io.loadEnable) {
    syndromeReg  := io.syndromeIn
    stateReg     := NodeState.IDLE
    parentDirReg := ParentDir.NONE
    peeledReg    := False
    onPathReg    := False
    region.reset()
  }

  // Collect neighbor signals
  val neighbors = Vec(io.neighborIn.north, io.neighborIn.south,
                      io.neighborIn.east, io.neighborIn.west)
  val neighborDirs = Seq(ParentDir.NORTH, ParentDir.SOUTH, ParentDir.EAST, ParentDir.WEST)
  val oppositeDirs = Seq(ParentDir.SOUTH, ParentDir.NORTH, ParentDir.WEST, ParentDir.EAST)

  val anyNeighborGrown = neighbors.map(n => n.valid && n.grown).orR

  // Combinational priority encoder: find the first growing neighbor for absorption.
  val absorbRegionIdComb = UInt(config.regionIdWidth bits)
  val absorbParentDirComb = ParentDir()
  absorbRegionIdComb  := U(0)
  absorbParentDirComb := ParentDir.NONE
  for (i <- (0 until 4).reverse) {
    when(neighbors(i).valid && neighbors(i).grown) {
      absorbRegionIdComb  := neighbors(i).regionId
      absorbParentDirComb := neighborDirs(i)
    }
  }

  // ── Peeling logic ──────────────────────────────────────────────────
  val childActive = Vec(Bool(), 4)
  for (i <- 0 until 4) {
    childActive(i) := neighbors(i).valid &&
                       !neighbors(i).peeled &&
                       (neighbors(i).parentDir === oppositeDirs(i)) &&
                       (neighbors(i).regionId =/= U(0))
  }
  val numActiveChildren = childActive.map(_.asUInt.resize(3)).reduce(_ + _)
  val isLeaf = numActiveChildren === 0

  // ── Path marking wave logic ────────────────────────────────────────
  // A child is "on the path" if it has onPath=true and its parentDir points at me.
  val childOnPath = Vec(Bool(), 4)
  for (i <- 0 until 4) {
    childOnPath(i) := neighbors(i).valid &&
                       neighbors(i).onPath &&
                       (neighbors(i).parentDir === oppositeDirs(i)) &&
                       (neighbors(i).regionId =/= U(0))
  }
  val anyChildOnPath = childOnPath.orR

  // ── FSM ────────────────────────────────────────────────────────────
  switch(stateReg) {
    is(NodeState.IDLE) {
      when(io.startPeel) {
        // IDLE node forced to PEELING (not on any correction path)
        stateReg  := NodeState.PEELING
        peeledReg := True
      } elsewhen(io.start && syndromeReg) {
        stateReg     := NodeState.GROWING
        region.activate(nodeId)
        parentDirReg := ParentDir.NONE
      } elsewhen(io.start && !syndromeReg && anyNeighborGrown) {
        stateReg     := NodeState.GROWING
        region.absorb(absorbRegionIdComb)
        parentDirReg := absorbParentDirComb
      }
    }

    is(NodeState.GROWING) {
      // Check for collision: neighbor growing with a different region
      for (i <- 0 until 4) {
        when(neighbors(i).valid && neighbors(i).grown &&
             region.detectCollision(neighbors(i).regionId)) {
          stateReg := NodeState.MATCHED
          region.markMatched(neighbors(i).regionId, neighborDirs(i))
        }
      }

      // Boundary matching: a growing node at the grid edge can match to
      // the virtual boundary. matchedWith=0 signals a boundary match.
      // Only triggers if no region-to-region collision was detected above,
      // AND boundaryEnable is asserted (after a delay to let real matches happen).
      val regionCollisionDetected = Vec(Bool(), 4)
      for (i <- 0 until 4) {
        regionCollisionDetected(i) := neighbors(i).valid && neighbors(i).grown &&
          region.detectCollision(neighbors(i).regionId)
      }
      when(!regionCollisionDetected.orR && io.boundaryEnable) {
        for (i <- (0 until 4).reverse) {
          when(!neighbors(i).valid) {
            // Inactive neighbor = grid boundary in this direction
            stateReg := NodeState.MATCHED
            region.markBoundaryMatch(neighborDirs(i))
          }
        }
      }

      // If grid controller forces peeling (stall timeout), skip to PEELING
      // and immediately peel since there's no valid match
      when(io.startPeel) {
        stateReg  := NodeState.PEELING
        peeledReg := True // force-peeled (not on any correction path)
      }
    }

    is(NodeState.MATCHED) {
      when(io.startPeel) {
        stateReg  := NodeState.PEELING
        peeledReg := False
      }
    }

    is(NodeState.PEELING) {
      // Path marking wave: propagate from primary collision nodes toward roots
      when(io.startPathMark || anyChildOnPath) {
        onPathReg := True
      }

      // Leaf peeling (still useful for convergence detection)
      when(isLeaf && !syndromeReg && !peeledReg) {
        peeledReg := True
      }
    }
  }

  // Reset
  when(!io.reset_n) {
    stateReg     := NodeState.IDLE
    syndromeReg  := False
    parentDirReg := ParentDir.NONE
    peeledReg    := False
    onPathReg    := False
    region.reset()
  }

  // ── Drive outputs ──────────────────────────────────────────────────
  io.linkOut.valid     := stateReg =/= NodeState.IDLE
  io.linkOut.regionId  := region.regionId
  io.linkOut.grown     := stateReg === NodeState.GROWING
  io.linkOut.parentDir := parentDirReg
  io.linkOut.peeled    := peeledReg
  io.linkOut.onPath    := onPathReg

  io.state          := stateReg
  io.regionId       := region.regionId
  io.parentDir      := parentDirReg
  io.matchDir       := region.matchDir
  io.matchedWithId  := region.matchedWith
  io.peeled         := peeledReg
  io.syndrome       := syndromeReg
  io.onPath         := onPathReg

  // Correction flag: kept for backwards compatibility but no longer primary
  io.correctionFlag := onPathReg && (parentDirReg =/= ParentDir.NONE)
}

// Verilog generation entry point
object DecoderNodeVerilog extends App {
  val config = DecoderConfig(codeDistance = 3)
  SpinalVerilog(DecoderNode(config, row = 0, col = 0))
}
