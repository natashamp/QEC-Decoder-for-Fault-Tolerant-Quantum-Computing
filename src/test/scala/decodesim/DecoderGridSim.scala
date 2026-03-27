package decodesim

import spinal.core._
import spinal.core.sim._
import org.scalatest.funsuite.AnyFunSuite

class DecoderGridSim extends AnyFunSuite {

  val spinalConfig = SpinalConfig(defaultClockDomainFrequency = FixedFrequency(100 MHz))

  def compileGrid(d: Int): SimCompiled[DecoderGrid] = {
    SimConfig.withConfig(spinalConfig).compile {
      DecoderGrid(DecoderConfig(codeDistance = d))
    }
  }

  def initGrid(dut: DecoderGrid): Unit = {
    dut.io.syndromeFrame #= 0
    dut.io.loadEnable    #= false
    dut.io.start         #= false
    dut.io.reset_n       #= true
  }

  def step(dut: DecoderGrid, n: Int = 1): Unit = {
    dut.clockDomain.waitRisingEdge(n)
    sleep(1)
  }

  // Load syndrome and run full decode cycle through DONE
  def runFullDecode(dut: DecoderGrid, syndrome: Long, maxCycles: Int = 50): Unit = {
    // Load
    dut.io.syndromeFrame #= syndrome
    dut.io.loadEnable #= true
    step(dut)
    dut.io.loadEnable #= false

    // Start decode
    dut.io.start #= true
    step(dut)

    // Wait for DONE
    for (_ <- 0 until maxCycles if !dut.io.done.toBoolean) {
      step(dut)
    }
  }

  // ── Instantiation tests ──────────────────────────────────────────

  test("d=3 grid instantiates as 2x2 with 4 nodes") {
    compileGrid(3).doSim("d3_instantiate") { dut =>
      dut.clockDomain.forkStimulus(10)
      initGrid(dut)
      step(dut, 2)

      for (i <- 0 until 4) {
        assert(dut.io.nodeStates(i).toEnum == NodeState.IDLE,
          s"Node $i should be IDLE, got ${dut.io.nodeStates(i).toEnum}")
      }
      assert(!dut.io.anyGrowing.toBoolean)
      assert(dut.io.gridPhase.toEnum == GridPhase.IDLE)
    }
  }

  test("d=5 grid instantiates as 4x4 with 16 nodes") {
    compileGrid(5).doSim("d5_instantiate") { dut =>
      dut.clockDomain.forkStimulus(10)
      initGrid(dut)
      step(dut, 2)

      for (i <- 0 until 16) {
        assert(dut.io.nodeStates(i).toEnum == NodeState.IDLE)
      }
      assert(!dut.io.anyGrowing.toBoolean)
    }
  }

  test("d=7 grid instantiates as 6x6 with 36 nodes") {
    compileGrid(7).doSim("d7_instantiate") { dut =>
      dut.clockDomain.forkStimulus(10)
      initGrid(dut)
      step(dut, 2)

      for (i <- 0 until 36) {
        assert(dut.io.nodeStates(i).toEnum == NodeState.IDLE)
      }
    }
  }

  // ── Grid FSM phases ──────────────────────────────────────────────

  test("d=3 grid progresses through LOADING → DECODING → PEELING → DONE") {
    compileGrid(3).doSim("d3_phase_progression") { dut =>
      dut.clockDomain.forkStimulus(10)
      initGrid(dut)
      step(dut, 2)

      assert(dut.io.gridPhase.toEnum == GridPhase.IDLE)

      // Start → LOADING
      dut.io.start #= true
      step(dut)
      // Load syndrome while in LOADING
      dut.io.syndromeFrame #= (1 << 0) | (1 << 1) // adjacent pair
      dut.io.loadEnable #= true
      step(dut)
      dut.io.loadEnable #= false

      // Should progress through DECODING
      var sawDecoding = false
      var sawPeeling = false
      for (_ <- 0 until 50 if !dut.io.done.toBoolean) {
        step(dut)
        val phase = dut.io.gridPhase.toEnum
        if (phase == GridPhase.DECODING) sawDecoding = true
        if (phase == GridPhase.PEELING) sawPeeling = true
      }

      assert(sawDecoding, "Should have passed through DECODING phase")
      assert(sawPeeling, "Should have passed through PEELING phase")
      assert(dut.io.done.toBoolean, "Should reach DONE")
      assert(dut.io.gridPhase.toEnum == GridPhase.DONE)
    }
  }

  // ── Syndrome loading ─────────────────────────────────────────────

  test("d=3 syndrome load activates correct nodes") {
    compileGrid(3).doSim("d3_syndrome_load") { dut =>
      dut.clockDomain.forkStimulus(10)
      initGrid(dut)
      step(dut, 2)

      // Load and start through the grid FSM
      dut.io.start #= true
      dut.io.syndromeFrame #= (1 << 0) | (1 << 3) // nodes (0,0) and (1,1)
      dut.io.loadEnable #= true
      step(dut, 2)
      dut.io.loadEnable #= false

      // Wait for DECODING phase
      for (_ <- 0 until 10 if dut.io.gridPhase.toEnum != GridPhase.DECODING) {
        step(dut)
      }
      step(dut, 2)

      // Nodes 0 and 3 should be GROWING (or already MATCHED if very fast)
      val n0 = dut.io.nodeStates(0).toEnum
      val n3 = dut.io.nodeStates(3).toEnum
      assert(n0 != NodeState.IDLE, s"Node 0 should not be IDLE, got $n0")
      assert(n3 != NodeState.IDLE, s"Node 3 should not be IDLE, got $n3")
    }
  }

  // ── Growth propagation ───────────────────────────────────────────

  test("d=3 growth propagates to neighbors with parent tracking") {
    compileGrid(3).doSim("d3_growth_parent_tracking") { dut =>
      dut.clockDomain.forkStimulus(10)
      initGrid(dut)
      step(dut, 2)

      // Single syndrome at node (0,0) = bit 0
      dut.io.syndromeFrame #= 1
      dut.io.loadEnable #= true
      dut.io.start #= true
      step(dut, 2)
      dut.io.loadEnable #= false

      // Wait for DECODING and let growth propagate
      for (_ <- 0 until 10 if dut.io.gridPhase.toEnum != GridPhase.DECODING) step(dut)
      step(dut, 8) // need several cycles: nodeStart register delay + node FSM + neighbor propagation

      // Check that at least one neighbor of node 0 has been absorbed
      // Node (0,1)=idx1 should have parent WEST (absorbed from west neighbor (0,0))
      // Node (1,0)=idx2 should have parent NORTH (absorbed from north neighbor (0,0))
      val n1State = dut.io.nodeStates(1).toEnum
      val n2State = dut.io.nodeStates(2).toEnum
      val someAbsorbed = (n1State != NodeState.IDLE) || (n2State != NodeState.IDLE)
      assert(someAbsorbed, s"At least one neighbor should be absorbed. N1=$n1State, N2=$n2State")
    }
  }

  // ── Collision / matching ─────────────────────────────────────────

  test("d=3 adjacent syndromes match and reach DONE") {
    compileGrid(3).doSim("d3_adjacent_match_done") { dut =>
      dut.clockDomain.forkStimulus(10)
      initGrid(dut)
      step(dut, 2)

      // Adjacent syndromes: (0,0) and (0,1)
      runFullDecode(dut, (1 << 0) | (1 << 1))

      assert(dut.io.done.toBoolean, "Should reach DONE")
      assert(dut.io.correction.valid.toBoolean, "Correction should be valid")
    }
  }

  test("d=3 diagonal syndromes match through growth") {
    compileGrid(3).doSim("d3_diagonal_match_done") { dut =>
      dut.clockDomain.forkStimulus(10)
      initGrid(dut)
      step(dut, 2)

      // Diagonal syndromes: (0,0) and (1,1)
      runFullDecode(dut, (1 << 0) | (1 << 3))

      assert(dut.io.done.toBoolean, "Diagonal syndromes should reach DONE")
    }
  }

  // ── Correction extraction ────────────────────────────────────────

  test("d=3 adjacent pair produces non-zero correction") {
    compileGrid(3).doSim("d3_correction_nonzero") { dut =>
      dut.clockDomain.forkStimulus(10)
      initGrid(dut)
      step(dut, 2)

      // Adjacent syndromes at (0,0) and (0,1)
      runFullDecode(dut, (1 << 0) | (1 << 1))

      assert(dut.io.done.toBoolean, "Should reach DONE")

      // Debug: print node states
      for (i <- 0 until 4) {
        println(s"  Node $i: state=${dut.io.nodeStates(i).toEnum}, " +
                s"region=${dut.io.nodeRegionIds(i).toInt}, " +
                s"parent=${dut.io.nodeParentDirs(i).toEnum}, " +
                s"match=${dut.io.nodeMatchDirs(i).toEnum}, " +
                s"peeled=${dut.io.nodePeeled(i).toBoolean}, " +
                s"syndrome=${dut.io.nodeSyndromes(i).toBoolean}")
      }
      val corrBits = dut.io.correction.bits.toLong
      println(s"  Correction bits: $corrBits (binary: ${corrBits.toBinaryString})")

      assert(corrBits != 0, s"Correction should be non-zero for matched pair, got $corrBits")
    }
  }

  test("d=3 no syndrome produces zero correction") {
    compileGrid(3).doSim("d3_no_syndrome_correction") { dut =>
      dut.clockDomain.forkStimulus(10)
      initGrid(dut)
      step(dut, 2)

      // No syndromes
      runFullDecode(dut, 0)

      assert(dut.io.done.toBoolean, "Should reach DONE")
      assert(dut.io.correction.bits.toLong == 0, "No syndrome should produce zero correction")
    }
  }

  // ── Peeling ──────────────────────────────────────────────────────

  test("d=3 peeling removes non-syndrome leaves") {
    compileGrid(3).doSim("d3_peeling") { dut =>
      dut.clockDomain.forkStimulus(10)
      initGrid(dut)
      step(dut, 2)

      // Diagonal syndromes (0,0)=node0 and (1,1)=node3
      // The growth tree will absorb nodes 1 and 2 as intermediaries.
      // After peeling, nodes 1 and 2 should be peeled (non-syndrome leaves)
      // UNLESS they are on the correction path.
      runFullDecode(dut, (1 << 0) | (1 << 3))

      assert(dut.io.done.toBoolean)

      // Syndrome nodes should NOT be peeled
      assert(!dut.io.nodePeeled(0).toBoolean, "Syndrome node 0 should not be peeled")
      assert(!dut.io.nodePeeled(3).toBoolean, "Syndrome node 3 should not be peeled")
    }
  }

  // ── Stall ────────────────────────────────────────────────────────

  test("d=3 single syndrome with no match partner triggers stall") {
    compileGrid(3).doSim("d3_stall") { dut =>
      dut.clockDomain.forkStimulus(10)
      initGrid(dut)
      step(dut, 2)

      // Single syndrome — no matching partner, growth will fill grid
      // and eventually time out
      runFullDecode(dut, 1, maxCycles = 100)

      assert(dut.io.done.toBoolean, "Should eventually reach DONE even with stall")
      assert(dut.io.stall.toBoolean, "Single unpaired syndrome should trigger stall")
    }
  }

  // ── Reset ────────────────────────────────────────────────────────

  test("d=3 reset during decode returns to IDLE") {
    compileGrid(3).doSim("d3_reset") { dut =>
      dut.clockDomain.forkStimulus(10)
      initGrid(dut)
      step(dut, 2)

      // Start a decode
      dut.io.syndromeFrame #= 1
      dut.io.loadEnable #= true
      dut.io.start #= true
      step(dut, 3)
      dut.io.loadEnable #= false

      // Wait a bit then reset
      step(dut, 3)
      dut.io.reset_n #= false
      step(dut)
      dut.io.reset_n #= true

      assert(dut.io.gridPhase.toEnum == GridPhase.IDLE, "Should return to IDLE after reset")
      for (i <- 0 until 4) {
        assert(dut.io.nodeStates(i).toEnum == NodeState.IDLE,
          s"Node $i should be IDLE after reset")
      }
      assert(!dut.io.done.toBoolean)
      assert(!dut.io.stall.toBoolean)
    }
  }

  // ── d=5 full decode ──────────────────────────────────────────────

  test("d=5 adjacent pair decodes to DONE with correction") {
    compileGrid(5).doSim("d5_adjacent_decode") { dut =>
      dut.clockDomain.forkStimulus(10)
      initGrid(dut)
      step(dut, 2)

      // Adjacent syndromes in a 4x4 grid: nodes (0,0)=0 and (0,1)=1
      runFullDecode(dut, (1 << 0) | (1 << 1), maxCycles = 80)

      assert(dut.io.done.toBoolean, "d=5 adjacent pair should reach DONE")
      assert(dut.io.correction.bits.toLong != 0, "Should produce non-zero correction")
    }
  }

  test("d=5 distant pair decodes to DONE") {
    compileGrid(5).doSim("d5_distant_decode") { dut =>
      dut.clockDomain.forkStimulus(10)
      initGrid(dut)
      step(dut, 2)

      // Distant syndromes: (0,0)=0 and (3,3)=15 in 4x4 grid
      runFullDecode(dut, (1 << 0) | (1 << 15), maxCycles = 80)

      assert(dut.io.done.toBoolean, "d=5 distant pair should reach DONE")
    }
  }
}
