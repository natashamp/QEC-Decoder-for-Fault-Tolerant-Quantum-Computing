package decodesim

import spinal.core._
import spinal.lib._

// Peeling decoder that computes the final data-qubit correction vector.
//
// Two types of edges contribute to the correction:
//   1. Parent edges: each non-peeled node with a parent contributes the edge to its parent
//   2. Collision edges: the edge where two growing regions met. Tracked via matchDir.
//      Only one node per collision pair contributes (the one with smaller regionId).
//
// Edge-to-data-qubit mapping:
//   Parent NORTH → data qubit (r,   c  )  i.e. index r*d + c
//   Parent SOUTH → data qubit (r+1, c  )  i.e. index (r+1)*d + c
//   Parent EAST  → data qubit (r,   c+1)  i.e. index r*d + c + 1
//   Parent WEST  → data qubit (r+1, c  )  i.e. index (r+1)*d + c
//
// The same mapping is used for matchDir (collision edge direction).

case class CorrectionExtractor(config: DecoderConfig) extends Component {
  val d    = config.codeDistance
  val rows = config.gridRows
  val cols = config.gridCols

  val io = new Bundle {
    val nodeParentDirs = in Vec(ParentDir(), config.numStabilizers)
    val nodeMatchDirs  = in Vec(ParentDir(), config.numStabilizers)
    val nodePeeled     = in Vec(Bool(), config.numStabilizers)
    val nodeStates     = in Vec(NodeState(), config.numStabilizers)
    val nodeRegionIds  = in Vec(UInt(config.regionIdWidth bits), config.numStabilizers)
    val nodeMatchedWith = in Vec(UInt(config.regionIdWidth bits), config.numStabilizers)
    val nodeSyndromes  = in Vec(Bool(), config.numStabilizers)
    val trigger        = in Bool()

    val correction = out(CorrectionOutput(config))
  }

  val contributions = Array.fill(config.numDataQubits)(scala.collection.mutable.ArrayBuffer[Bool]())

  // Helper: add a directional correction contribution for node at (r,c)
  def addContribution(r: Int, c: Int, dir: Bool => Unit, condition: Bool): Unit = {
    dir(condition)
  }

  for (r <- 0 until rows; c <- 0 until cols) {
    val idx = r * cols + c
    val inPeeling = io.nodeStates(idx) === NodeState.PEELING
    val notPeeled = !io.nodePeeled(idx)

    // 1. Parent edge contributions: non-peeled nodes with a parent direction
    val hasParent = io.nodeParentDirs(idx) =/= ParentDir.NONE
    val parentOnPath = inPeeling && notPeeled && hasParent

    val parentIsNorth = io.nodeParentDirs(idx) === ParentDir.NORTH
    val parentIsSouth = io.nodeParentDirs(idx) === ParentDir.SOUTH
    val parentIsEast  = io.nodeParentDirs(idx) === ParentDir.EAST
    val parentIsWest  = io.nodeParentDirs(idx) === ParentDir.WEST

    if (r > 0)
      contributions(r * d + c) += (parentOnPath && parentIsNorth)
    if (r < rows - 1)
      contributions((r + 1) * d + c) += (parentOnPath && parentIsSouth)
    if (c < cols - 1)
      contributions(r * d + (c + 1)) += (parentOnPath && parentIsEast)
    if (c > 0)
      contributions((r + 1) * d + c) += (parentOnPath && parentIsWest)

    // 2. Collision edge contributions: the edge where two regions met.
    //    Only contribute from the node with the SMALLER regionId to avoid double-counting.
    val hasMatch = io.nodeMatchDirs(idx) =/= ParentDir.NONE
    val isSmaller = io.nodeRegionIds(idx) < io.nodeMatchedWith(idx)
    val collisionOnPath = inPeeling && notPeeled && hasMatch && isSmaller

    val matchIsNorth = io.nodeMatchDirs(idx) === ParentDir.NORTH
    val matchIsSouth = io.nodeMatchDirs(idx) === ParentDir.SOUTH
    val matchIsEast  = io.nodeMatchDirs(idx) === ParentDir.EAST
    val matchIsWest  = io.nodeMatchDirs(idx) === ParentDir.WEST

    if (r > 0)
      contributions(r * d + c) += (collisionOnPath && matchIsNorth)
    if (r < rows - 1)
      contributions((r + 1) * d + c) += (collisionOnPath && matchIsSouth)
    if (c < cols - 1)
      contributions(r * d + (c + 1)) += (collisionOnPath && matchIsEast)
    if (c > 0)
      contributions((r + 1) * d + c) += (collisionOnPath && matchIsWest)
  }

  val correctionBits = Bits(config.numDataQubits bits)
  for (i <- 0 until config.numDataQubits) {
    if (contributions(i).nonEmpty) {
      correctionBits(i) := contributions(i).reduce(_ ^ _)
    } else {
      correctionBits(i) := False
    }
  }

  io.correction.bits  := correctionBits
  io.correction.valid := io.trigger
}
