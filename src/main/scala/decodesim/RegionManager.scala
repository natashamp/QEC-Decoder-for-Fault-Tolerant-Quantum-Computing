package decodesim

import spinal.core._
import spinal.lib._

// Distributed union-find region tracker.
//
// In the region-growing decoder, each stabilizer node maintains its own
// region ID. The RegionManager provides the logic for:
//   1. Region activation — a syndrome node creates a new region with its unique ID
//   2. Region absorption — a passive node joins a neighbor's region
//   3. Region collision — two different regions meet, triggering a match
//   4. Boundary collision — a region reaches the grid edge
//
// This is a "distributed union-find" because there is no central data structure.
// Each node tracks its own root, and merges are detected locally when two
// adjacent nodes have different non-zero region IDs.
//
// The RegionManager is instantiated as an Area inside each DecoderNode,
// providing a clean separation of region-tracking logic from FSM control.

case class RegionManager(config: DecoderConfig) extends Area {
  val regionId    = RegInit(U(0, config.regionIdWidth bits))
  val matchedWith = RegInit(U(0, config.regionIdWidth bits))
  val matchDir    = RegInit(ParentDir.NONE)

  // Activate: create a new region rooted at this node
  def activate(id: UInt): Unit = {
    regionId := id
  }

  // Absorb: join a neighbor's region during growth
  def absorb(neighborRegionId: UInt): Unit = {
    regionId := neighborRegionId
  }

  // Detect collision: returns true if neighbor has a different active region
  def detectCollision(neighborRegionId: UInt): Bool = {
    regionId =/= U(0) &&
    neighborRegionId =/= U(0) &&
    neighborRegionId =/= regionId
  }

  // Mark matched: record the collision partner's region ID and direction
  def markMatched(otherRegionId: UInt, direction: ParentDir.C): Unit = {
    matchedWith := otherRegionId
    matchDir    := direction
  }

  // Mark boundary match: match to virtual boundary (matchedWith=0)
  def markBoundaryMatch(direction: ParentDir.C): Unit = {
    matchedWith := U(0)
    matchDir    := direction
  }

  // Reset all region tracking state
  def reset(): Unit = {
    regionId    := U(0)
    matchedWith := U(0)
    matchDir    := ParentDir.NONE
  }
}
