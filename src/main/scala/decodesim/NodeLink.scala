package decodesim

import spinal.core._

// Helper object for NodeLink operations used during grid wiring
object NodeLinkUtils {

  // Create a tied-off (inactive) NodeLink — used for boundary nodes
  // that have no neighbor on one or more sides.
  // In the surface code, the grid boundary acts as a virtual boundary
  // that can absorb growing regions (boundary matching).
  def tiedOff(config: DecoderConfig): NodeLink = {
    val link = NodeLink(config)
    link.valid     := False
    link.regionId  := U(0, config.regionIdWidth bits)
    link.grown     := False
    link.parentDir := ParentDir.NONE
    link.peeled    := True  // boundary is always "peeled" (not on correction path)
    link.onPath    := False // boundary is never on the correction path
    link
  }
}
