package decodesim

import spinal.core._
import spinal.lib._

// Configuration for the decoder, parameterized by code distance
case class DecoderConfig(
  codeDistance: Int = 3
) {
  require(codeDistance >= 3 && codeDistance % 2 == 1, "Code distance must be odd and >= 3")

  val gridRows: Int = codeDistance - 1
  val gridCols: Int = codeDistance - 1
  val numStabilizers: Int = gridRows * gridCols
  val numDataQubits: Int = codeDistance * codeDistance

  // Bit widths
  val regionIdWidth: Int = log2Up(numStabilizers + 1) // +1 for "no region" sentinel
  val coordWidth: Int = log2Up(scala.math.max(gridRows, gridCols))

  // Cycle budgets for decode phases
  val maxGrowthCycles: Int = gridRows + gridCols // worst-case: full grid traversal
  val maxPeelCycles: Int = gridRows + gridCols   // worst-case: deepest tree
}

// State machine states for a single decoder node
object NodeState extends SpinalEnum {
  val IDLE, GROWING, MATCHED, PEELING = newElement()
}

// Parent direction: tracks which neighbor absorbed this node during growth
object ParentDir extends SpinalEnum {
  val NONE, NORTH, SOUTH, EAST, WEST = newElement()
}

// Grid-level decode phase
object GridPhase extends SpinalEnum {
  val IDLE, LOADING, DECODING, PEELING, DONE = newElement()
}

// Communication bundle between adjacent nodes
case class NodeLink(config: DecoderConfig) extends Bundle {
  val valid     = Bool()           // Is this neighbor active?
  val regionId  = UInt(config.regionIdWidth bits) // Which region
  val grown     = Bool()           // Is this neighbor's region actively growing?
  val parentDir = ParentDir()      // Parent direction of this neighbor (for peeling)
  val peeled    = Bool()           // Has this neighbor been peeled (removed from correction tree)?
}

// Top-level I/O for the full decoder grid
case class SyndromeInput(config: DecoderConfig) extends Bundle {
  val bits  = Bits(config.numStabilizers bits)
  val valid = Bool()
}

case class CorrectionOutput(config: DecoderConfig) extends Bundle {
  val bits  = Bits(config.numDataQubits bits)
  val valid = Bool()
}

// Grid coordinate for identifying node position
case class GridCoord(config: DecoderConfig) extends Bundle {
  val row = UInt(config.coordWidth bits)
  val col = UInt(config.coordWidth bits)
}
