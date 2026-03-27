package decodesim

import spinal.core._
import spinal.core.sim._
import org.scalatest.funsuite.AnyFunSuite

class DecoderNodeSim extends AnyFunSuite {

  val spinalConfig = SpinalConfig(defaultClockDomainFrequency = FixedFrequency(100 MHz))

  def compileDut(): SimCompiled[DecoderNode] = {
    SimConfig.withConfig(spinalConfig).compile {
      val config = DecoderConfig(codeDistance = 3)
      DecoderNode(config, row = 0, col = 0)
    }
  }

  def tieOffNeighbors(dut: DecoderNode): Unit = {
    for (n <- Seq(dut.io.neighborIn.north, dut.io.neighborIn.south,
                  dut.io.neighborIn.east, dut.io.neighborIn.west)) {
      n.valid     #= false
      n.regionId  #= 0
      n.grown     #= false
      n.parentDir #= ParentDir.NONE
      n.peeled    #= true
    }
  }

  def initSignals(dut: DecoderNode): Unit = {
    dut.io.reset_n    #= true
    dut.io.start      #= false
    dut.io.startPeel  #= false
    dut.io.loadEnable #= false
    dut.io.syndromeIn #= false
    tieOffNeighbors(dut)
  }

  def step(dut: DecoderNode, n: Int = 1): Unit = {
    dut.clockDomain.waitRisingEdge(n)
    sleep(1)
  }

  test("Node starts in IDLE state") {
    compileDut().doSim("idle_state") { dut =>
      dut.clockDomain.forkStimulus(10)
      initSignals(dut)

      step(dut, 3)
      assert(dut.io.state.toEnum == NodeState.IDLE)
      assert(!dut.io.correctionFlag.toBoolean)
    }
  }

  test("Node with syndrome transitions to GROWING on start") {
    compileDut().doSim("syndrome_grows") { dut =>
      dut.clockDomain.forkStimulus(10)
      initSignals(dut)
      step(dut, 2)

      dut.io.syndromeIn #= true
      dut.io.loadEnable #= true
      step(dut)
      dut.io.loadEnable #= false
      dut.io.syndromeIn #= false

      dut.io.start #= true
      step(dut, 2)

      assert(dut.io.state.toEnum == NodeState.GROWING)
      assert(dut.io.linkOut.valid.toBoolean)
      assert(dut.io.linkOut.grown.toBoolean)
      assert(dut.io.regionId.toInt == 1)
      assert(dut.io.parentDir.toEnum == ParentDir.NONE, "Syndrome root should have no parent")
    }
  }

  test("Node without syndrome stays IDLE on start") {
    compileDut().doSim("no_syndrome_idle") { dut =>
      dut.clockDomain.forkStimulus(10)
      initSignals(dut)
      step(dut, 2)

      dut.io.loadEnable #= true
      step(dut)
      dut.io.loadEnable #= false

      dut.io.start #= true
      step(dut, 2)

      assert(dut.io.state.toEnum == NodeState.IDLE)
      assert(!dut.io.linkOut.valid.toBoolean)
    }
  }

  test("GROWING node transitions to MATCHED on collision") {
    compileDut().doSim("collision_match") { dut =>
      dut.clockDomain.forkStimulus(10)
      initSignals(dut)
      step(dut, 2)

      dut.io.syndromeIn #= true
      dut.io.loadEnable #= true
      step(dut)
      dut.io.loadEnable #= false
      dut.io.syndromeIn #= false

      dut.io.start #= true
      step(dut, 2)
      assert(dut.io.state.toEnum == NodeState.GROWING)

      dut.io.neighborIn.north.valid    #= true
      dut.io.neighborIn.north.regionId #= 3
      dut.io.neighborIn.north.grown    #= true
      dut.io.neighborIn.north.peeled   #= false
      step(dut)

      assert(dut.io.state.toEnum == NodeState.MATCHED)
      assert(dut.io.correctionFlag.toBoolean)
    }
  }

  test("Reset returns node to IDLE") {
    compileDut().doSim("reset_test") { dut =>
      dut.clockDomain.forkStimulus(10)
      initSignals(dut)
      step(dut, 2)

      dut.io.syndromeIn #= true
      dut.io.loadEnable #= true
      step(dut)
      dut.io.loadEnable #= false
      dut.io.syndromeIn #= false
      dut.io.start #= true
      step(dut, 2)
      assert(dut.io.state.toEnum == NodeState.GROWING)

      dut.io.reset_n #= false
      step(dut)
      assert(dut.io.state.toEnum == NodeState.IDLE)
      assert(!dut.io.correctionFlag.toBoolean)

      dut.io.reset_n #= true
    }
  }

  test("Passive node absorbed by growing neighbor tracks parent direction") {
    compileDut().doSim("passive_absorption") { dut =>
      dut.clockDomain.forkStimulus(10)
      initSignals(dut)
      step(dut, 2)

      dut.io.loadEnable #= true
      step(dut)
      dut.io.loadEnable #= false

      dut.io.neighborIn.east.valid     #= true
      dut.io.neighborIn.east.regionId  #= 5
      dut.io.neighborIn.east.grown     #= true
      dut.io.neighborIn.east.peeled    #= false
      dut.io.neighborIn.east.parentDir #= ParentDir.NONE

      dut.io.start #= true
      step(dut, 2)

      assert(dut.io.state.toEnum == NodeState.GROWING)
      assert(dut.io.regionId.toInt == 5)
      assert(dut.io.parentDir.toEnum == ParentDir.EAST, "Parent should be EAST (absorbed from east)")
    }
  }

  test("MATCHED node transitions to PEELING on startPeel") {
    compileDut().doSim("matched_to_peeling") { dut =>
      dut.clockDomain.forkStimulus(10)
      initSignals(dut)
      step(dut, 2)

      // Load syndrome, start, get to GROWING
      dut.io.syndromeIn #= true
      dut.io.loadEnable #= true
      step(dut)
      dut.io.loadEnable #= false
      dut.io.syndromeIn #= false
      dut.io.start #= true
      step(dut, 2)
      assert(dut.io.state.toEnum == NodeState.GROWING)

      // Collision → MATCHED
      dut.io.neighborIn.north.valid    #= true
      dut.io.neighborIn.north.regionId #= 3
      dut.io.neighborIn.north.grown    #= true
      dut.io.neighborIn.north.peeled   #= false
      step(dut)
      assert(dut.io.state.toEnum == NodeState.MATCHED)

      // Start peeling
      dut.io.start #= false
      dut.io.startPeel #= true
      step(dut)
      dut.io.startPeel #= false
      step(dut)

      assert(dut.io.state.toEnum == NodeState.PEELING)
      // Syndrome node should NOT be peeled
      assert(!dut.io.peeled.toBoolean, "Syndrome node should not be peeled")
    }
  }
}
