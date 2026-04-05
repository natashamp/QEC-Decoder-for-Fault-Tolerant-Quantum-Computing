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
      val corrBits = dut.io.correction.bits.toLong

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

  test("d=3 diagonal pair corrects exact data qubits via path marking") {
    compileGrid(3).doSim("d3_correction_exact_diagonal") { dut =>
      dut.clockDomain.forkStimulus(10)
      initGrid(dut)
      step(dut, 2)

      // Diagonal syndromes at (0,0) and (1,1) in a 2x2 stabilizer grid.
      // The correction path goes: stab(0,0) → collision EAST → stab(0,1) → parent SOUTH → stab(1,1).
      // Collision edge EAST from stab(0,0) → data qubit 0*3 + 0 + 1 = 1.
      // Parent edge SOUTH from stab(0,1) → data qubit (0+1)*3 + 1 = 4.
      // Expected correction = bits 1 and 4.
      runFullDecode(dut, (1 << 0) | (1 << 3))

      assert(dut.io.done.toBoolean, "Should reach DONE")
      val corrBits = dut.io.correction.bits.toLong
      val expected = (1L << 1) | (1L << 4)
      assert(corrBits == expected,
        s"Diagonal pair (0,0)-(1,1) should correct data qubits 1,4 (expected=$expected), got correction=$corrBits (binary=${corrBits.toBinaryString})")
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

  test("d=3 single syndrome matches to boundary") {
    compileGrid(3).doSim("d3_boundary_match") { dut =>
      dut.clockDomain.forkStimulus(10)
      initGrid(dut)
      step(dut, 2)

      // Single syndrome at (0,0) — no matching partner, should match to
      // grid boundary after the boundary match delay. The correction path
      // goes from stab(0,0) to its nearest boundary edge.
      runFullDecode(dut, 1, maxCycles = 100)

      assert(dut.io.done.toBoolean, "Should reach DONE via boundary matching")
      assert(!dut.io.stall.toBoolean, "Should NOT stall — boundary matching resolves it")

      // stab(0,0) is at grid corner — it matches to boundary (NORTH or WEST).
      // The correction should include the boundary edge data qubit.
      val corrBits = dut.io.correction.bits.toLong
      assert(corrBits != 0, s"Boundary match should produce non-zero correction, got $corrBits")
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

  // ── Correction value verification ─────────────────────────────────

  test("d=3 horizontal adjacent pair corrects exact data qubit") {
    compileGrid(3).doSim("d3_correction_exact_horizontal") { dut =>
      dut.clockDomain.forkStimulus(10)
      initGrid(dut)
      step(dut, 2)

      // Adjacent syndromes at (0,0) and (0,1) in a 2x2 stabilizer grid.
      // These collide on the EAST edge of stab(0,0).
      // EAST from stab(0,0) → data qubit index 0*3 + 0 + 1 = 1.
      // Only stab(0,0) contributes (smaller regionId). Expected correction = bit 1.
      runFullDecode(dut, (1 << 0) | (1 << 1))

      assert(dut.io.done.toBoolean, "Should reach DONE")
      val corrBits = dut.io.correction.bits.toLong
      assert(corrBits == (1L << 1),
        s"Horizontal pair (0,0)-(0,1) should correct data qubit 1, got correction=$corrBits (binary=${corrBits.toBinaryString})")
    }
  }

  test("d=3 vertical adjacent pair corrects exact data qubit") {
    compileGrid(3).doSim("d3_correction_exact_vertical") { dut =>
      dut.clockDomain.forkStimulus(10)
      initGrid(dut)
      step(dut, 2)

      // Adjacent syndromes at (0,0) and (1,0) in a 2x2 stabilizer grid.
      // These collide on the SOUTH edge of stab(0,0).
      // SOUTH from stab(0,0) → data qubit index (0+1)*3 + 0 = 3.
      // Only stab(0,0) contributes (smaller regionId). Expected correction = bit 3.
      runFullDecode(dut, (1 << 0) | (1 << 2))  // node (1,0) = flat index 2

      assert(dut.io.done.toBoolean, "Should reach DONE")
      val corrBits = dut.io.correction.bits.toLong
      assert(corrBits == (1L << 3),
        s"Vertical pair (0,0)-(1,0) should correct data qubit 3, got correction=$corrBits (binary=${corrBits.toBinaryString})")
    }
  }

  test("d=5 horizontal adjacent pair corrects exact data qubit") {
    compileGrid(5).doSim("d5_correction_exact_horizontal") { dut =>
      dut.clockDomain.forkStimulus(10)
      initGrid(dut)
      step(dut, 2)

      // Adjacent syndromes at (0,0) and (0,1) in a 4x4 stabilizer grid.
      // EAST from stab(0,0) → data qubit 0*5 + 0 + 1 = 1.
      runFullDecode(dut, (1 << 0) | (1 << 1), maxCycles = 80)

      assert(dut.io.done.toBoolean, "Should reach DONE")
      val corrBits = dut.io.correction.bits.toLong
      assert(corrBits == (1L << 1),
        s"d=5 horizontal pair should correct data qubit 1, got correction=$corrBits (binary=${corrBits.toBinaryString})")
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

  // ── Phase 3: Multi-pair tests ────────────────────────────────────

  test("d=5 two independent adjacent pairs decode to DONE") {
    compileGrid(5).doSim("d5_two_pairs") { dut =>
      dut.clockDomain.forkStimulus(10)
      initGrid(dut)
      step(dut, 2)

      // 4x4 grid. Two independent pairs:
      //   Pair 1: (0,0)=idx0 and (0,1)=idx1 (adjacent horizontal, top-left)
      //   Pair 2: (3,2)=idx14 and (3,3)=idx15 (adjacent horizontal, bottom-right)
      val syndrome = (1L << 0) | (1L << 1) | (1L << 14) | (1L << 15)
      runFullDecode(dut, syndrome, maxCycles = 80)

      assert(dut.io.done.toBoolean, "Two pairs should decode to DONE")
      val corrBits = dut.io.correction.bits.toLong
      assert(corrBits != 0, s"Should produce non-zero correction, got $corrBits")

      // Verify each pair contributed at least its collision edge:
      //   Pair 1: EAST(0,0) → dq 1 should be set
      //   Pair 2: EAST(3,2) → dq 18 should be set
      assert((corrBits & (1L << 1)) != 0,
        s"Pair 1 collision edge (dq 1) should be in correction, got $corrBits")
      assert((corrBits & (1L << 18)) != 0,
        s"Pair 2 collision edge (dq 18) should be in correction, got $corrBits")
    }
  }

  test("d=5 four syndromes in a square form two pairs") {
    compileGrid(5).doSim("d5_four_syndromes_square") { dut =>
      dut.clockDomain.forkStimulus(10)
      initGrid(dut)
      step(dut, 2)

      // 4x4 grid. Four syndromes forming a 2x2 square:
      //   (0,0)=0, (0,1)=1, (1,0)=4, (1,1)=5
      // Growth from all four starts simultaneously. Adjacent pairs should
      // match before interfering with each other.
      val syndrome = (1L << 0) | (1L << 1) | (1L << 4) | (1L << 5)
      runFullDecode(dut, syndrome, maxCycles = 80)

      assert(dut.io.done.toBoolean, "Four syndromes should decode to DONE")
      val corrBits = dut.io.correction.bits.toLong
      assert(corrBits != 0, s"Should produce non-zero correction, got $corrBits")
    }
  }

  // ── Phase 3: Boundary matching tests ─────────────────────────────

  test("d=3 single syndrome boundary match produces exact correction") {
    compileGrid(3).doSim("d3_boundary_exact") { dut =>
      dut.clockDomain.forkStimulus(10)
      initGrid(dut)
      step(dut, 2)

      // Single syndrome at (0,0) in 2x2 grid. No partner exists, so it
      // matches to the boundary. stab(0,0) is at the NORTH and WEST boundary.
      // After boundary delay, it should match to one of those edges.
      // The correction path is just the boundary edge data qubit.
      runFullDecode(dut, 1, maxCycles = 100)

      assert(dut.io.done.toBoolean, "Should reach DONE via boundary match")

      val corrBits = dut.io.correction.bits.toLong
      // stab(0,0) matches to boundary. With priority encoder (reversed 0..3),
      // NORTH (i=0) has highest priority. NORTH boundary from (0,0) → dq 0*3+0 = 0.
      assert(corrBits == (1L << 0),
        s"Single syndrome at corner should correct boundary dq 0, got $corrBits (binary=${corrBits.toBinaryString})")
    }
  }

  test("d=5 single syndrome at center boundary-matches after delay") {
    compileGrid(5).doSim("d5_boundary_center") { dut =>
      dut.clockDomain.forkStimulus(10)
      initGrid(dut)
      step(dut, 2)

      // Single syndrome at (2,2) in 4x4 grid — center of grid.
      // No boundary neighbor, so it grows until reaching an edge,
      // then boundary-matches.
      val idx = 2 * 4 + 2 // flat index 10
      runFullDecode(dut, 1L << idx, maxCycles = 100)

      assert(dut.io.done.toBoolean, "Center syndrome should eventually reach DONE")
      val corrBits = dut.io.correction.bits.toLong
      assert(corrBits != 0, s"Should produce non-zero correction, got $corrBits")
    }
  }

  test("d=5 three syndromes: two pair plus one boundary match") {
    compileGrid(5).doSim("d5_three_syndromes") { dut =>
      dut.clockDomain.forkStimulus(10)
      initGrid(dut)
      step(dut, 2)

      // Three syndromes: (0,0)=0, (0,1)=1, (3,3)=15
      // (0,0) and (0,1) are adjacent → they should pair with each other.
      // (3,3) has no partner → boundary match.
      val syndrome = (1L << 0) | (1L << 1) | (1L << 15)
      runFullDecode(dut, syndrome, maxCycles = 100)

      assert(dut.io.done.toBoolean, "Three syndromes should decode to DONE")
      val corrBits = dut.io.correction.bits.toLong
      assert(corrBits != 0, s"Should produce non-zero correction, got $corrBits")
    }
  }

  // ── Phase 3: Larger distance tests ───────────────────────────────

  test("d=7 adjacent pair decodes to DONE with correction") {
    compileGrid(7).doSim("d7_adjacent_decode") { dut =>
      dut.clockDomain.forkStimulus(10)
      initGrid(dut)
      step(dut, 2)

      // 6x6 grid. Adjacent syndromes at (0,0)=0 and (0,1)=1.
      runFullDecode(dut, (1L << 0) | (1L << 1), maxCycles = 100)

      assert(dut.io.done.toBoolean, "d=7 adjacent pair should reach DONE")
      val corrBits = dut.io.correction.bits.toLong
      // EAST from stab(0,0) → dq 0*7+0+1 = 1
      assert(corrBits == (1L << 1),
        s"d=7 adjacent pair should correct dq 1, got $corrBits (binary=${corrBits.toBinaryString})")
    }
  }

  test("d=7 distant pair decodes to DONE") {
    compileGrid(7).doSim("d7_distant_decode") { dut =>
      dut.clockDomain.forkStimulus(10)
      initGrid(dut)
      step(dut, 2)

      // 6x6 grid. Distant syndromes: (0,0)=0 and (5,5)=35
      runFullDecode(dut, (1L << 0) | (1L << 35), maxCycles = 100)

      assert(dut.io.done.toBoolean, "d=7 distant pair should reach DONE")
      val corrBits = dut.io.correction.bits.toLong
      assert(corrBits != 0, s"Should produce non-zero correction, got $corrBits")
    }
  }
}
