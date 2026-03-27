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
//
// This is a "distributed union-find" because there is no central data structure.
// Each node tracks its own root, and merges are detected locally when two
// adjacent nodes have different non-zero region IDs.
//
// The RegionManager is instantiated as an Area inside each DecoderNode,
// providing a clean separation of region-tracking logic from FSM control.

case class RegionManager(config: DecoderConfig) extends Area {
  val regionId   = RegInit(U(0, config.regionIdWidth bits))
  val matchedWith = RegInit(U(0, config.regionIdWidth bits))

  def activate(id: UInt): Unit = {
    regionId := id
  }

  def absorb(neighborRegionId: UInt): Unit = {
    regionId := neighborRegionId
  }

  def detectCollision(neighborRegionId: UInt): Bool = {
    regionId =/= U(0) &&
    neighborRegionId =/= U(0) &&
    neighborRegionId =/= regionId
  }

  def markMatched(otherRegionId: UInt): Unit = {
    matchedWith := otherRegionId
  }

  def reset(): Unit = {
    regionId   := U(0)
    matchedWith := U(0)
  }
}
