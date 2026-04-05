package decodesim

import spinal.core._
import spinal.lib._

// Correction extractor using path-marking wave results.
//
// The correction path between two matched syndromes is identified by:
//   1. Path-marked parent edges: each node on the correction path (onPath=true)
//      with a parent direction contributes its parent edge to the correction.
//   2. Primary collision edge: the edge where the primary collision node meets
//      its partner across region boundaries, OR the boundary edge for
//      boundary-matched nodes (matchedWith=0).
//
// Edge-to-data-qubit mapping (stabilizer at grid position (r,c)):
//   Parent NORTH → data qubit (r,   c  )  i.e. index r*d + c
//   Parent SOUTH → data qubit (r+1, c  )  i.e. index (r+1)*d + c
//   Parent EAST  → data qubit (r,   c+1)  i.e. index r*d + c + 1
//   Parent WEST  → data qubit (r,   c  )  i.e. index r*d + c
//
// The same mapping is used for collision/boundary edge directions (matchDir).
// For boundary edges, the guards (r>0, c>0, etc.) are relaxed since the
// edge connects to the grid boundary rather than an adjacent stabilizer.

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
    val nodeOnPath     = in Vec(Bool(), config.numStabilizers)
    val isPrimaryCollision = in Vec(Bool(), config.numStabilizers)
    val trigger        = in Bool()

    val correction = out(CorrectionOutput(config))
  }

  val contributions = Array.fill(config.numDataQubits)(scala.collection.mutable.ArrayBuffer[Bool]())

  for (r <- 0 until rows; c <- 0 until cols) {
    val idx = r * cols + c

    // 1. Parent edge contributions from path-marked nodes
    val hasParent = io.nodeParentDirs(idx) =/= ParentDir.NONE
    val parentOnPath = io.nodeOnPath(idx) && hasParent

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
      contributions(r * d + c) += (parentOnPath && parentIsWest)

    // 2. Primary collision edge: only the selected primary collision node
    //    contributes its matchDir edge.
    //    For region-to-region collisions, boundary guards apply (the
    //    neighbor must exist). For boundary matches (matchedWith=0),
    //    the edge goes to the grid boundary — no neighbor needed.
    val collisionOnPath = io.isPrimaryCollision(idx)
    val isBoundary = io.nodeMatchedWith(idx) === U(0)

    val matchIsNorth = io.nodeMatchDirs(idx) === ParentDir.NORTH
    val matchIsSouth = io.nodeMatchDirs(idx) === ParentDir.SOUTH
    val matchIsEast  = io.nodeMatchDirs(idx) === ParentDir.EAST
    val matchIsWest  = io.nodeMatchDirs(idx) === ParentDir.WEST

    // NORTH collision/boundary edge → data qubit r*d + c
    if (r > 0)
      contributions(r * d + c) += (collisionOnPath && matchIsNorth && !isBoundary)
    if (r == 0)
      contributions(r * d + c) += (collisionOnPath && matchIsNorth && isBoundary)

    // SOUTH collision/boundary edge → data qubit (r+1)*d + c
    if (r < rows - 1)
      contributions((r + 1) * d + c) += (collisionOnPath && matchIsSouth && !isBoundary)
    if (r == rows - 1)
      contributions((r + 1) * d + c) += (collisionOnPath && matchIsSouth && isBoundary)

    // EAST collision/boundary edge → data qubit r*d + c + 1
    if (c < cols - 1)
      contributions(r * d + (c + 1)) += (collisionOnPath && matchIsEast && !isBoundary)
    if (c == cols - 1)
      contributions(r * d + (c + 1)) += (collisionOnPath && matchIsEast && isBoundary)

    // WEST collision/boundary edge → data qubit r*d + c
    if (c > 0)
      contributions(r * d + c) += (collisionOnPath && matchIsWest && !isBoundary)
    if (c == 0)
      contributions(r * d + c) += (collisionOnPath && matchIsWest && isBoundary)
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
