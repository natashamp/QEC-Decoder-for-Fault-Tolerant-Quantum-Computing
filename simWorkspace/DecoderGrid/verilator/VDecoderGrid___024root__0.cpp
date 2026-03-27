// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VDecoderGrid.h for the primary calling header

#include "VDecoderGrid__pch.h"

void VDecoderGrid___024root___eval_triggers_vec__act(VDecoderGrid___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderGrid___024root___eval_triggers_vec__act\n"); );
    VDecoderGrid__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((((IData)(vlSelfRef.reset) 
                                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__reset__0))) 
                                                      << 1U) 
                                                     | ((IData)(vlSelfRef.clk) 
                                                        & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__reset__0 = vlSelfRef.reset;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__VactDidInit)))))) {
        vlSelfRef.__VactDidInit = 1U;
        vlSelfRef.__VactTriggered[0U] = (1ULL | vlSelfRef.__VactTriggered[0U]);
        vlSelfRef.__VactTriggered[0U] = (2ULL | vlSelfRef.__VactTriggered[0U]);
    }
}

bool VDecoderGrid___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderGrid___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void VDecoderGrid___024root___nba_sequent__TOP__0(VDecoderGrid___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderGrid___024root___nba_sequent__TOP__0\n"); );
    VDecoderGrid__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*2:0*/ __Vdly__DecoderGrid__DOT__phaseReg;
    __Vdly__DecoderGrid__DOT__phaseReg = 0;
    CData/*3:0*/ __Vdly__DecoderGrid__DOT__cycleCount;
    __Vdly__DecoderGrid__DOT__cycleCount = 0;
    // Body
    vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_0_1__DOT__stateReg 
        = vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__stateReg;
    vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_1_0__DOT__stateReg 
        = vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__stateReg;
    vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_0_0__DOT__regionIdReg 
        = vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__regionIdReg;
    vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_1_1__DOT__regionIdReg 
        = vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__regionIdReg;
    vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_0_0__DOT__stateReg 
        = vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__stateReg;
    vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_1_1__DOT__stateReg 
        = vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__stateReg;
    vlSelfRef.__Vdly__DecoderGrid__DOT__nodeStart = vlSelfRef.DecoderGrid__DOT__nodeStart;
    __Vdly__DecoderGrid__DOT__phaseReg = vlSelfRef.DecoderGrid__DOT__phaseReg;
    __Vdly__DecoderGrid__DOT__cycleCount = vlSelfRef.DecoderGrid__DOT__cycleCount;
    vlSelfRef.__Vdly__DecoderGrid__DOT__nodeStartPeel 
        = vlSelfRef.DecoderGrid__DOT__nodeStartPeel;
    if (vlSelfRef.reset) {
        __Vdly__DecoderGrid__DOT__phaseReg = 0U;
        __Vdly__DecoderGrid__DOT__cycleCount = 0U;
        vlSelfRef.DecoderGrid__DOT__stallReg = 0U;
        vlSelfRef.DecoderGrid__DOT__doneReg = 0U;
        vlSelfRef.DecoderGrid__DOT__peelingDone = 0U;
        vlSelfRef.__Vdly__DecoderGrid__DOT__nodeStart = 0U;
        vlSelfRef.__Vdly__DecoderGrid__DOT__nodeStartPeel = 0U;
        vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_0_0__DOT__stateReg = 0U;
        vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_0_0__DOT__regionIdReg = 0U;
        vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__matchedWith = 0U;
        vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__parentDirReg = 0U;
        vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__matchDirReg = 0U;
        vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__peeledReg = 0U;
        vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_1_1__DOT__stateReg = 0U;
        vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_1_1__DOT__regionIdReg = 0U;
        vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__matchedWith = 0U;
        vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__parentDirReg = 0U;
        vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__matchDirReg = 0U;
        vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__peeledReg = 0U;
    } else {
        if ((4U & (IData)(vlSelfRef.DecoderGrid__DOT__phaseReg))) {
            vlSelfRef.DecoderGrid__DOT__doneReg = 1U;
        } else if ((2U & (IData)(vlSelfRef.DecoderGrid__DOT__phaseReg))) {
            if ((1U & (IData)(vlSelfRef.DecoderGrid__DOT__phaseReg))) {
                __Vdly__DecoderGrid__DOT__cycleCount 
                    = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.DecoderGrid__DOT__cycleCount)));
                vlSelfRef.__Vdly__DecoderGrid__DOT__nodeStartPeel = 0U;
                vlSelfRef.__Vdly__DecoderGrid__DOT__nodeStart = 0U;
                if (vlSelfRef.DecoderGrid__DOT__when_DecoderGrid_l201) {
                    __Vdly__DecoderGrid__DOT__phaseReg = 4U;
                    vlSelfRef.DecoderGrid__DOT__doneReg = 1U;
                }
                if ((((IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__peeledReg) 
                      | ((IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__syndromeReg) 
                         | (0U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__stateReg)))) 
                     & (((IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__peeledReg) 
                         | ((IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__syndromeReg) 
                            | (0U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__stateReg)))) 
                        & (((IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__peeledReg) 
                            | ((IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__syndromeReg) 
                               | (0U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__stateReg)))) 
                           & ((IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__peeledReg) 
                              | ((IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__syndromeReg) 
                                 | (0U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__stateReg)))))))) {
                    vlSelfRef.DecoderGrid__DOT__peelingDone = 1U;
                }
            } else {
                vlSelfRef.__Vdly__DecoderGrid__DOT__nodeStart = 1U;
                __Vdly__DecoderGrid__DOT__cycleCount 
                    = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.DecoderGrid__DOT__cycleCount)));
                if (((~ (IData)(vlSelfRef.io_anyGrowing)) 
                     & (IData)(vlSelfRef.io_allMatched))) {
                    if (((IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__syndromeReg) 
                         | ((IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__syndromeReg) 
                            | ((IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__syndromeReg) 
                               | (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__syndromeReg))))) {
                        __Vdly__DecoderGrid__DOT__phaseReg = 3U;
                        vlSelfRef.__Vdly__DecoderGrid__DOT__nodeStart = 0U;
                        vlSelfRef.__Vdly__DecoderGrid__DOT__nodeStartPeel = 1U;
                        __Vdly__DecoderGrid__DOT__cycleCount = 0U;
                    } else {
                        __Vdly__DecoderGrid__DOT__phaseReg = 4U;
                        vlSelfRef.DecoderGrid__DOT__doneReg = 1U;
                    }
                } else if (vlSelfRef.DecoderGrid__DOT__when_DecoderGrid_l185) {
                    vlSelfRef.DecoderGrid__DOT__stallReg = 1U;
                    __Vdly__DecoderGrid__DOT__phaseReg = 3U;
                    vlSelfRef.__Vdly__DecoderGrid__DOT__nodeStart = 0U;
                    vlSelfRef.__Vdly__DecoderGrid__DOT__nodeStartPeel = 1U;
                    __Vdly__DecoderGrid__DOT__cycleCount = 0U;
                }
            }
        } else if ((1U & (IData)(vlSelfRef.DecoderGrid__DOT__phaseReg))) {
            if ((1U & (~ (IData)(vlSelfRef.io_loadEnable)))) {
                __Vdly__DecoderGrid__DOT__phaseReg = 2U;
                vlSelfRef.__Vdly__DecoderGrid__DOT__nodeStart = 1U;
                __Vdly__DecoderGrid__DOT__cycleCount = 0U;
            }
        } else {
            vlSelfRef.__Vdly__DecoderGrid__DOT__nodeStart = 0U;
            vlSelfRef.__Vdly__DecoderGrid__DOT__nodeStartPeel = 0U;
            vlSelfRef.DecoderGrid__DOT__doneReg = 0U;
            vlSelfRef.DecoderGrid__DOT__stallReg = 0U;
            __Vdly__DecoderGrid__DOT__cycleCount = 0U;
            vlSelfRef.DecoderGrid__DOT__peelingDone = 0U;
            if (vlSelfRef.io_start) {
                __Vdly__DecoderGrid__DOT__phaseReg = 1U;
            }
        }
        if (vlSelfRef.io_loadEnable) {
            vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_0_0__DOT__stateReg = 0U;
            vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_0_0__DOT__regionIdReg = 0U;
            vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__matchedWith = 0U;
            vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__parentDirReg = 0U;
            vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__matchDirReg = 0U;
            vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__peeledReg = 0U;
            vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_1_1__DOT__stateReg = 0U;
            vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_1_1__DOT__regionIdReg = 0U;
            vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__matchedWith = 0U;
            vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__parentDirReg = 0U;
            vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__matchDirReg = 0U;
            vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__peeledReg = 0U;
        }
        if ((0U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__stateReg))) {
            if (((IData)(vlSelfRef.DecoderGrid__DOT__nodeStart) 
                 & (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__syndromeReg))) {
                vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_0_0__DOT__stateReg = 1U;
                vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_0_0__DOT__regionIdReg = 1U;
                vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__parentDirReg = 0U;
            } else if (((IData)(vlSelfRef.DecoderGrid__DOT__nodeStart) 
                        & ((~ (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__syndromeReg)) 
                           & ((IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__when_DecoderNode_l78_3) 
                              | (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__when_DecoderNode_l78))))) {
                vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_0_0__DOT__stateReg = 1U;
                vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_0_0__DOT__regionIdReg 
                    = vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__absorbRegionIdComb;
                vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__parentDirReg 
                    = vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__absorbParentDirComb;
            }
        } else if ((1U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__stateReg))) {
            if (vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__when_DecoderNode_l114_1) {
                vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_0_0__DOT__stateReg = 2U;
                vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__matchedWith 
                    = vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__regionIdReg;
                vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__matchDirReg = 2U;
            }
            if (vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__when_DecoderNode_l114_2) {
                vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_0_0__DOT__stateReg = 2U;
                vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__matchedWith 
                    = vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__regionIdReg;
                vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__matchDirReg = 3U;
            }
            if (vlSelfRef.DecoderGrid__DOT__nodeStartPeel) {
                vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_0_0__DOT__stateReg = 3U;
                vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__peeledReg = 1U;
            }
        } else if ((2U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__stateReg))) {
            if (vlSelfRef.DecoderGrid__DOT__nodeStartPeel) {
                vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_0_0__DOT__stateReg = 3U;
                vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__peeledReg = 0U;
            }
        } else if (vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__when_DecoderNode_l137) {
            vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__peeledReg = 1U;
        }
        if (vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__when_DecoderNode_l144) {
            vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_0_0__DOT__stateReg = 3U;
            vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__peeledReg = 1U;
        }
        if ((0U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__stateReg))) {
            if (((IData)(vlSelfRef.DecoderGrid__DOT__nodeStart) 
                 & (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__syndromeReg))) {
                vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_1_1__DOT__stateReg = 1U;
                vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_1_1__DOT__regionIdReg = 4U;
                vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__parentDirReg = 0U;
            } else if (((IData)(vlSelfRef.DecoderGrid__DOT__nodeStart) 
                        & ((~ (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__syndromeReg)) 
                           & ((IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__when_DecoderNode_l78) 
                              | (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__when_DecoderNode_l78_3))))) {
                vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_1_1__DOT__stateReg = 1U;
                vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_1_1__DOT__regionIdReg 
                    = vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__absorbRegionIdComb;
                vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__parentDirReg 
                    = vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__absorbParentDirComb;
            }
        } else if ((1U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__stateReg))) {
            if (vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__when_DecoderNode_l114) {
                vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_1_1__DOT__stateReg = 2U;
                vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__matchedWith 
                    = vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__regionIdReg;
                vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__matchDirReg = 1U;
            }
            if (vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__when_DecoderNode_l114_3) {
                vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_1_1__DOT__stateReg = 2U;
                vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__matchedWith 
                    = vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__regionIdReg;
                vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__matchDirReg = 4U;
            }
            if (vlSelfRef.DecoderGrid__DOT__nodeStartPeel) {
                vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_1_1__DOT__stateReg = 3U;
                vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__peeledReg = 1U;
            }
        } else if ((2U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__stateReg))) {
            if (vlSelfRef.DecoderGrid__DOT__nodeStartPeel) {
                vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_1_1__DOT__stateReg = 3U;
                vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__peeledReg = 0U;
            }
        } else if (vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__when_DecoderNode_l137) {
            vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__peeledReg = 1U;
        }
        if (vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__when_DecoderNode_l144) {
            vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_1_1__DOT__stateReg = 3U;
            vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__peeledReg = 1U;
        }
        if ((1U & (~ (IData)(vlSelfRef.io_reset_n)))) {
            __Vdly__DecoderGrid__DOT__phaseReg = 0U;
            __Vdly__DecoderGrid__DOT__cycleCount = 0U;
            vlSelfRef.DecoderGrid__DOT__stallReg = 0U;
            vlSelfRef.DecoderGrid__DOT__doneReg = 0U;
            vlSelfRef.DecoderGrid__DOT__peelingDone = 0U;
            vlSelfRef.__Vdly__DecoderGrid__DOT__nodeStart = 0U;
            vlSelfRef.__Vdly__DecoderGrid__DOT__nodeStartPeel = 0U;
            vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_0_0__DOT__stateReg = 0U;
            vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_0_0__DOT__regionIdReg = 0U;
            vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__matchedWith = 0U;
            vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__parentDirReg = 0U;
            vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__matchDirReg = 0U;
            vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__peeledReg = 0U;
            vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_1_1__DOT__stateReg = 0U;
            vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_1_1__DOT__regionIdReg = 0U;
            vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__matchedWith = 0U;
            vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__parentDirReg = 0U;
            vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__matchDirReg = 0U;
            vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__peeledReg = 0U;
        }
    }
    vlSelfRef.DecoderGrid__DOT__phaseReg = __Vdly__DecoderGrid__DOT__phaseReg;
    vlSelfRef.DecoderGrid__DOT__cycleCount = __Vdly__DecoderGrid__DOT__cycleCount;
    vlSelfRef.io_gridPhase = vlSelfRef.DecoderGrid__DOT__phaseReg;
    vlSelfRef.io_stall = vlSelfRef.DecoderGrid__DOT__stallReg;
    vlSelfRef.io_correction_valid = vlSelfRef.DecoderGrid__DOT__doneReg;
    vlSelfRef.io_done = vlSelfRef.DecoderGrid__DOT__doneReg;
    vlSelfRef.DecoderGrid__DOT__when_DecoderGrid_l185 
        = (4U <= (IData)(vlSelfRef.DecoderGrid__DOT__cycleCount));
    vlSelfRef.DecoderGrid__DOT__when_DecoderGrid_l201 
        = ((4U <= (IData)(vlSelfRef.DecoderGrid__DOT__cycleCount)) 
           | (IData)(vlSelfRef.DecoderGrid__DOT__peelingDone));
}

void VDecoderGrid___024root___nba_sequent__TOP__1(VDecoderGrid___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderGrid___024root___nba_sequent__TOP__1\n"); );
    VDecoderGrid__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__stateReg 
        = vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_0_0__DOT__stateReg;
    vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__stateReg 
        = vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_1_1__DOT__stateReg;
    vlSelfRef.io_nodeMatchDirs_0 = vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__matchDirReg;
    vlSelfRef.io_nodeParentDirs_0 = vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__parentDirReg;
    vlSelfRef.io_nodePeeled_0 = vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__peeledReg;
    if (vlSelfRef.reset) {
        vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__syndromeReg = 0U;
        vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__syndromeReg = 0U;
        vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_0_1__DOT__stateReg = 0U;
        vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__regionIdReg = 0U;
        vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__matchedWith = 0U;
        vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__parentDirReg = 0U;
        vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__matchDirReg = 0U;
        vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__peeledReg = 0U;
        vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_1_0__DOT__stateReg = 0U;
        vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__regionIdReg = 0U;
        vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__matchedWith = 0U;
        vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__parentDirReg = 0U;
        vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__matchDirReg = 0U;
        vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__peeledReg = 0U;
    } else {
        if (vlSelfRef.io_loadEnable) {
            vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__syndromeReg 
                = (1U & (IData)(vlSelfRef.io_syndromeFrame));
            vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__syndromeReg 
                = (1U & ((IData)(vlSelfRef.io_syndromeFrame) 
                         >> 3U));
            vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_0_1__DOT__stateReg = 0U;
            vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__regionIdReg = 0U;
            vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__matchedWith = 0U;
            vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__parentDirReg = 0U;
            vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__matchDirReg = 0U;
            vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__peeledReg = 0U;
            vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_1_0__DOT__stateReg = 0U;
            vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__regionIdReg = 0U;
            vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__matchedWith = 0U;
            vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__parentDirReg = 0U;
            vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__matchDirReg = 0U;
            vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__peeledReg = 0U;
        }
        if ((0U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__stateReg))) {
            if (((IData)(vlSelfRef.DecoderGrid__DOT__nodeStart) 
                 & (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__syndromeReg))) {
                vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_0_1__DOT__stateReg = 1U;
                vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__regionIdReg = 2U;
                vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__parentDirReg = 0U;
            } else if (((IData)(vlSelfRef.DecoderGrid__DOT__nodeStart) 
                        & ((~ (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__syndromeReg)) 
                           & ((IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__when_DecoderNode_l78_3) 
                              | (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__when_DecoderNode_l78_1))))) {
                vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_0_1__DOT__stateReg = 1U;
                vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__regionIdReg 
                    = vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__absorbRegionIdComb;
                vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__parentDirReg 
                    = vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__absorbParentDirComb;
            }
        } else if ((1U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__stateReg))) {
            if (vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__when_DecoderNode_l114_1) {
                vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_0_1__DOT__stateReg = 2U;
                vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__matchedWith 
                    = vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__regionIdReg;
                vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__matchDirReg = 2U;
            }
            if (vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__when_DecoderNode_l114_3) {
                vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_0_1__DOT__stateReg = 2U;
                vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__matchedWith 
                    = vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__regionIdReg;
                vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__matchDirReg = 4U;
            }
            if (vlSelfRef.DecoderGrid__DOT__nodeStartPeel) {
                vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_0_1__DOT__stateReg = 3U;
                vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__peeledReg = 1U;
            }
        } else if ((2U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__stateReg))) {
            if (vlSelfRef.DecoderGrid__DOT__nodeStartPeel) {
                vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_0_1__DOT__stateReg = 3U;
                vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__peeledReg = 0U;
            }
        } else if (vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__when_DecoderNode_l137) {
            vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__peeledReg = 1U;
        }
        if (vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__when_DecoderNode_l144) {
            vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_0_1__DOT__stateReg = 3U;
            vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__peeledReg = 1U;
        }
        if ((0U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__stateReg))) {
            if (((IData)(vlSelfRef.DecoderGrid__DOT__nodeStart) 
                 & (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__syndromeReg))) {
                vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_1_0__DOT__stateReg = 1U;
                vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__regionIdReg = 3U;
                vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__parentDirReg = 0U;
            } else if (((IData)(vlSelfRef.DecoderGrid__DOT__nodeStart) 
                        & ((~ (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__syndromeReg)) 
                           & ((IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__when_DecoderNode_l78_1) 
                              | (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__when_DecoderNode_l78_3))))) {
                vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_1_0__DOT__stateReg = 1U;
                vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__regionIdReg 
                    = vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__absorbRegionIdComb;
                vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__parentDirReg 
                    = vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__absorbParentDirComb;
            }
        } else if ((1U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__stateReg))) {
            if (vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__when_DecoderNode_l114) {
                vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_1_0__DOT__stateReg = 2U;
                vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__matchedWith 
                    = vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__regionIdReg;
                vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__matchDirReg = 1U;
            }
            if (vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__when_DecoderNode_l114_2) {
                vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_1_0__DOT__stateReg = 2U;
                vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__matchedWith 
                    = vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__regionIdReg;
                vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__matchDirReg = 3U;
            }
            if (vlSelfRef.DecoderGrid__DOT__nodeStartPeel) {
                vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_1_0__DOT__stateReg = 3U;
                vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__peeledReg = 1U;
            }
        } else if ((2U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__stateReg))) {
            if (vlSelfRef.DecoderGrid__DOT__nodeStartPeel) {
                vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_1_0__DOT__stateReg = 3U;
                vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__peeledReg = 0U;
            }
        } else if (vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__when_DecoderNode_l137) {
            vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__peeledReg = 1U;
        }
        if (vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__when_DecoderNode_l144) {
            vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_1_0__DOT__stateReg = 3U;
            vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__peeledReg = 1U;
        }
        if ((1U & (~ (IData)(vlSelfRef.io_reset_n)))) {
            vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__syndromeReg = 0U;
            vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__syndromeReg = 0U;
            vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_0_1__DOT__stateReg = 0U;
            vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__regionIdReg = 0U;
            vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__matchedWith = 0U;
            vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__parentDirReg = 0U;
            vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__matchDirReg = 0U;
            vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__peeledReg = 0U;
            vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_1_0__DOT__stateReg = 0U;
            vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__regionIdReg = 0U;
            vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__matchedWith = 0U;
            vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__parentDirReg = 0U;
            vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__matchDirReg = 0U;
            vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__peeledReg = 0U;
        }
    }
    vlSelfRef.io_nodeStates_0 = vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__stateReg;
    vlSelfRef.io_nodeMatchDirs_3 = vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__matchDirReg;
    vlSelfRef.io_nodeParentDirs_3 = vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__parentDirReg;
    vlSelfRef.io_nodePeeled_3 = vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__peeledReg;
    vlSelfRef.io_nodeStates_3 = vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__stateReg;
    vlSelfRef.DecoderGrid__DOT__extractor__DOT____VdfgRegularize_hb2993a7d_0_3 
        = ((~ (IData)(vlSelfRef.io_nodePeeled_0)) & 
           (3U == (IData)(vlSelfRef.io_nodeStates_0)));
    vlSelfRef.DecoderGrid__DOT__extractor__DOT____VdfgRegularize_hb2993a7d_0_0 
        = ((~ (IData)(vlSelfRef.io_nodePeeled_3)) & 
           (3U == (IData)(vlSelfRef.io_nodeStates_3)));
    vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__stateReg 
        = vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_0_1__DOT__stateReg;
    vlSelfRef.DecoderGrid__DOT__nodeStart = vlSelfRef.__Vdly__DecoderGrid__DOT__nodeStart;
    vlSelfRef.DecoderGrid__DOT__nodeStartPeel = vlSelfRef.__Vdly__DecoderGrid__DOT__nodeStartPeel;
    vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__when_DecoderNode_l78_1 
        = ((1U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__stateReg)) 
           & (0U != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__stateReg)));
    vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__when_DecoderNode_l78_3 
        = ((1U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__stateReg)) 
           & (0U != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__stateReg)));
    vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__regionIdReg 
        = vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_0_0__DOT__regionIdReg;
    vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__regionIdReg 
        = vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_1_1__DOT__regionIdReg;
}

void VDecoderGrid___024root___nba_sequent__TOP__2(VDecoderGrid___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderGrid___024root___nba_sequent__TOP__2\n"); );
    VDecoderGrid__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__stateReg 
        = vlSelfRef.__Vdly__DecoderGrid__DOT__nodes_1_0__DOT__stateReg;
    vlSelfRef.io_nodeSyndromes_0 = vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__syndromeReg;
    vlSelfRef.DecoderGrid__DOT__extractor__DOT___zz_correctionBits_2 
        = ((IData)(vlSelfRef.DecoderGrid__DOT__extractor__DOT____VdfgRegularize_hb2993a7d_0_3) 
           & (0U != (IData)(vlSelfRef.io_nodeParentDirs_0)));
    vlSelfRef.io_nodeSyndromes_3 = vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__syndromeReg;
    vlSelfRef.DecoderGrid__DOT__extractor__DOT___zz_correctionBits_14 
        = ((IData)(vlSelfRef.DecoderGrid__DOT__extractor__DOT____VdfgRegularize_hb2993a7d_0_0) 
           & (0U != (IData)(vlSelfRef.io_nodeParentDirs_3)));
    vlSelfRef.io_nodeMatchDirs_1 = vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__matchDirReg;
    vlSelfRef.io_nodeRegionIds_1 = vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__regionIdReg;
    vlSelfRef.io_nodeParentDirs_1 = vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__parentDirReg;
    vlSelfRef.io_nodePeeled_1 = vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__peeledReg;
    if (vlSelfRef.reset) {
        vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__syndromeReg = 0U;
        vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__syndromeReg = 0U;
    } else {
        if (vlSelfRef.io_loadEnable) {
            vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__syndromeReg 
                = (1U & ((IData)(vlSelfRef.io_syndromeFrame) 
                         >> 1U));
            vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__syndromeReg 
                = (1U & ((IData)(vlSelfRef.io_syndromeFrame) 
                         >> 2U));
        }
        if ((1U & (~ (IData)(vlSelfRef.io_reset_n)))) {
            vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__syndromeReg = 0U;
            vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__syndromeReg = 0U;
        }
    }
    vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__when_DecoderNode_l78_3 
        = ((1U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__stateReg)) 
           & (0U != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__stateReg)));
    vlSelfRef.io_nodeStates_1 = vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__stateReg;
    vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__when_DecoderNode_l144 
        = ((0U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__stateReg)) 
           & (IData)(vlSelfRef.DecoderGrid__DOT__nodeStartPeel));
    vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__when_DecoderNode_l144 
        = ((0U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__stateReg)) 
           & (IData)(vlSelfRef.DecoderGrid__DOT__nodeStartPeel));
    vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__when_DecoderNode_l144 
        = ((0U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__stateReg)) 
           & (IData)(vlSelfRef.DecoderGrid__DOT__nodeStartPeel));
    vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__absorbParentDirComb = 0U;
    vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__absorbParentDirComb = 0U;
    vlSelfRef.io_nodeMatchDirs_2 = vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__matchDirReg;
    vlSelfRef.io_nodeRegionIds_2 = vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__regionIdReg;
    vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__when_DecoderNode_l114_3 
        = ((IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__when_DecoderNode_l78_3) 
           & (((IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__regionIdReg) 
               != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__regionIdReg)) 
              & (0U != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__regionIdReg))));
    vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__when_DecoderNode_l114 
        = ((IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__when_DecoderNode_l78_3) 
           & (((IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__regionIdReg) 
               != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__regionIdReg)) 
              & (0U != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__regionIdReg))));
    vlSelfRef.io_nodeRegionIds_0 = vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__regionIdReg;
    vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__when_DecoderNode_l114_1 
        = ((IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__when_DecoderNode_l78_1) 
           & (((IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__regionIdReg) 
               != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__regionIdReg)) 
              & (0U != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__regionIdReg))));
    vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__when_DecoderNode_l114_2 
        = ((IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__when_DecoderNode_l78_1) 
           & (((IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__regionIdReg) 
               != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__regionIdReg)) 
              & (0U != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__regionIdReg))));
    vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__absorbRegionIdComb = 0U;
    if (vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__when_DecoderNode_l78_3) {
        vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__absorbParentDirComb = 4U;
    }
    if (vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__when_DecoderNode_l78_1) {
        vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__absorbParentDirComb = 2U;
        vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__absorbParentDirComb = 3U;
    }
    vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__absorbRegionIdComb = 0U;
    if (vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__when_DecoderNode_l78_3) {
        vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__absorbParentDirComb = 1U;
        vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__absorbRegionIdComb 
            = vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__regionIdReg;
    }
    if (vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__when_DecoderNode_l78_1) {
        vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__absorbRegionIdComb 
            = vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__regionIdReg;
        vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__absorbRegionIdComb 
            = vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__regionIdReg;
    }
    if (vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__when_DecoderNode_l78_3) {
        vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__absorbRegionIdComb 
            = vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__regionIdReg;
    }
    vlSelfRef.io_nodeRegionIds_3 = vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__regionIdReg;
    vlSelfRef.io_nodeParentDirs_2 = vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__parentDirReg;
    vlSelfRef.io_nodePeeled_2 = vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__peeledReg;
    vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__when_DecoderNode_l144 
        = ((0U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__stateReg)) 
           & (IData)(vlSelfRef.DecoderGrid__DOT__nodeStartPeel));
    vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__when_DecoderNode_l137 
        = ((0U == (7U & (((~ (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__peeledReg)) 
                          & ((0U != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__stateReg)) 
                             & ((1U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__parentDirReg)) 
                                & (0U != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__regionIdReg))))) 
                         + ((~ (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__peeledReg)) 
                            & ((0U != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__stateReg)) 
                               & ((4U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__parentDirReg)) 
                                  & (0U != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__regionIdReg)))))))) 
           & ((~ (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__syndromeReg)) 
              & (~ (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__peeledReg))));
    vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__when_DecoderNode_l137 
        = ((0U == (7U & (((~ (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__peeledReg)) 
                          & ((0U != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__stateReg)) 
                             & ((2U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__parentDirReg)) 
                                & (0U != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__regionIdReg))))) 
                         + ((~ (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__peeledReg)) 
                            & ((0U != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__stateReg)) 
                               & ((3U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__parentDirReg)) 
                                  & (0U != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__regionIdReg)))))))) 
           & ((~ (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__syndromeReg)) 
              & (~ (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__peeledReg))));
    vlSelfRef.io_anyGrowing = ((1U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__stateReg)) 
                               | ((1U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__stateReg)) 
                                  | ((1U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__stateReg)) 
                                     | (1U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__stateReg)))));
    vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__when_DecoderNode_l78 
        = ((1U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__stateReg)) 
           & (0U != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__stateReg)));
    vlSelfRef.io_nodeStates_2 = vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__stateReg;
    vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__when_DecoderNode_l114_2 
        = ((IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__when_DecoderNode_l78_3) 
           & (((IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__regionIdReg) 
               != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__regionIdReg)) 
              & (0U != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__regionIdReg))));
    vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__when_DecoderNode_l114 
        = ((IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__when_DecoderNode_l78_3) 
           & (((IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__regionIdReg) 
               != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__regionIdReg)) 
              & (0U != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__regionIdReg))));
    vlSelfRef.DecoderGrid__DOT__extractor__DOT____VdfgRegularize_hb2993a7d_0_2 
        = ((~ (IData)(vlSelfRef.io_nodePeeled_1)) & 
           (3U == (IData)(vlSelfRef.io_nodeStates_1)));
    vlSelfRef.DecoderGrid__DOT__extractor__DOT___zz_correctionBits_3 
        = ((IData)(vlSelfRef.DecoderGrid__DOT__extractor__DOT____VdfgRegularize_hb2993a7d_0_3) 
           & ((0U != (IData)(vlSelfRef.io_nodeMatchDirs_0)) 
              & ((IData)(vlSelfRef.io_nodeRegionIds_0) 
                 < (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__matchedWith))));
    vlSelfRef.DecoderGrid__DOT__extractor__DOT___zz_correctionBits_15 
        = ((IData)(vlSelfRef.DecoderGrid__DOT__extractor__DOT____VdfgRegularize_hb2993a7d_0_0) 
           & ((0U != (IData)(vlSelfRef.io_nodeMatchDirs_3)) 
              & ((IData)(vlSelfRef.io_nodeRegionIds_3) 
                 < (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__matchedWith))));
    vlSelfRef.io_allMatched = ((~ (IData)(vlSelfRef.io_anyGrowing)) 
                               & (((0U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__stateReg)) 
                                   | ((2U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__stateReg)) 
                                      | (3U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__stateReg)))) 
                                  & (((0U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__stateReg)) 
                                      | ((2U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__stateReg)) 
                                         | (3U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__stateReg)))) 
                                     & (((0U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__stateReg)) 
                                         | ((2U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__stateReg)) 
                                            | (3U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__stateReg)))) 
                                        & ((0U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__stateReg)) 
                                           | ((2U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__stateReg)) 
                                              | (3U 
                                                 == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__stateReg))))))));
    vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__absorbParentDirComb = 0U;
    vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__absorbParentDirComb = 0U;
    if (vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__when_DecoderNode_l78_3) {
        vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__absorbParentDirComb = 3U;
    }
    if (vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__when_DecoderNode_l78) {
        vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__absorbParentDirComb = 2U;
        vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__absorbParentDirComb = 4U;
    }
    if (vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__when_DecoderNode_l78_3) {
        vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__absorbParentDirComb = 1U;
    }
    vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__when_DecoderNode_l114_1 
        = ((IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__when_DecoderNode_l78) 
           & (((IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__regionIdReg) 
               != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__regionIdReg)) 
              & (0U != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__regionIdReg))));
    vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__when_DecoderNode_l114_3 
        = ((IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__when_DecoderNode_l78) 
           & (((IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__regionIdReg) 
               != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__regionIdReg)) 
              & (0U != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__regionIdReg))));
    vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__absorbRegionIdComb = 0U;
}

void VDecoderGrid___024root___nba_sequent__TOP__3(VDecoderGrid___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderGrid___024root___nba_sequent__TOP__3\n"); );
    VDecoderGrid__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ DecoderGrid__DOT__extractor__DOT___zz_correctionBits_6;
    DecoderGrid__DOT__extractor__DOT___zz_correctionBits_6 = 0;
    CData/*0:0*/ DecoderGrid__DOT__extractor__DOT___zz_correctionBits_7;
    DecoderGrid__DOT__extractor__DOT___zz_correctionBits_7 = 0;
    CData/*0:0*/ DecoderGrid__DOT__extractor__DOT___zz_correctionBits_10;
    DecoderGrid__DOT__extractor__DOT___zz_correctionBits_10 = 0;
    CData/*0:0*/ DecoderGrid__DOT__extractor__DOT___zz_correctionBits_11;
    DecoderGrid__DOT__extractor__DOT___zz_correctionBits_11 = 0;
    CData/*0:0*/ DecoderGrid__DOT__extractor__DOT____VdfgRegularize_hb2993a7d_0_1;
    DecoderGrid__DOT__extractor__DOT____VdfgRegularize_hb2993a7d_0_1 = 0;
    // Body
    vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__absorbRegionIdComb = 0U;
    if (vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__when_DecoderNode_l78_3) {
        vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__absorbRegionIdComb 
            = vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__regionIdReg;
    }
    if (vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__when_DecoderNode_l78) {
        vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__absorbRegionIdComb 
            = vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__regionIdReg;
        vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__absorbRegionIdComb 
            = vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__regionIdReg;
    }
    if (vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__when_DecoderNode_l78_3) {
        vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__absorbRegionIdComb 
            = vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__regionIdReg;
    }
    DecoderGrid__DOT__extractor__DOT____VdfgRegularize_hb2993a7d_0_1 
        = ((~ (IData)(vlSelfRef.io_nodePeeled_2)) & 
           (3U == (IData)(vlSelfRef.io_nodeStates_2)));
    vlSelfRef.io_nodeSyndromes_1 = vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__syndromeReg;
    vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__when_DecoderNode_l137 
        = ((0U == (7U & (((~ (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__peeledReg)) 
                          & ((0U != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__stateReg)) 
                             & ((1U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__parentDirReg)) 
                                & (0U != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__regionIdReg))))) 
                         + ((~ (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__peeledReg)) 
                            & ((0U != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__stateReg)) 
                               & ((3U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__parentDirReg)) 
                                  & (0U != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__regionIdReg)))))))) 
           & ((~ (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__syndromeReg)) 
              & (~ (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__peeledReg))));
    DecoderGrid__DOT__extractor__DOT___zz_correctionBits_6 
        = ((IData)(vlSelfRef.DecoderGrid__DOT__extractor__DOT____VdfgRegularize_hb2993a7d_0_2) 
           & (0U != (IData)(vlSelfRef.io_nodeParentDirs_1)));
    DecoderGrid__DOT__extractor__DOT___zz_correctionBits_7 
        = ((IData)(vlSelfRef.DecoderGrid__DOT__extractor__DOT____VdfgRegularize_hb2993a7d_0_2) 
           & ((0U != (IData)(vlSelfRef.io_nodeMatchDirs_1)) 
              & ((IData)(vlSelfRef.io_nodeRegionIds_1) 
                 < (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__matchedWith))));
    vlSelfRef.io_nodeSyndromes_2 = vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__syndromeReg;
    vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__when_DecoderNode_l137 
        = ((0U == (7U & (((~ (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__peeledReg)) 
                          & ((0U != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__stateReg)) 
                             & ((2U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__parentDirReg)) 
                                & (0U != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__regionIdReg))))) 
                         + ((~ (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__peeledReg)) 
                            & ((0U != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__stateReg)) 
                               & ((4U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__parentDirReg)) 
                                  & (0U != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__regionIdReg)))))))) 
           & ((~ (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__syndromeReg)) 
              & (~ (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__peeledReg))));
    vlSelfRef.io_correctionFlags = ((((((2U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__stateReg)) 
                                        & (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__syndromeReg)) 
                                       | ((3U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__stateReg)) 
                                          & ((~ (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__peeledReg)) 
                                             & ((0U 
                                                 != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__parentDirReg)) 
                                                | (0U 
                                                   != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__matchDirReg)))))) 
                                      << 3U) | ((((2U 
                                                   == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__stateReg)) 
                                                  & (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__syndromeReg)) 
                                                 | ((3U 
                                                     == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__stateReg)) 
                                                    & ((~ (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__peeledReg)) 
                                                       & ((0U 
                                                           != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__parentDirReg)) 
                                                          | (0U 
                                                             != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__matchDirReg)))))) 
                                                << 2U)) 
                                    | (((((2U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__stateReg)) 
                                          & (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__syndromeReg)) 
                                         | ((3U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__stateReg)) 
                                            & ((~ (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__peeledReg)) 
                                               & ((0U 
                                                   != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__parentDirReg)) 
                                                  | (0U 
                                                     != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__matchDirReg)))))) 
                                        << 1U) | ((
                                                   (2U 
                                                    == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__stateReg)) 
                                                   & (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__syndromeReg)) 
                                                  | ((3U 
                                                      == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__stateReg)) 
                                                     & ((~ (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__peeledReg)) 
                                                        & ((0U 
                                                            != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__parentDirReg)) 
                                                           | (0U 
                                                              != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__matchDirReg))))))));
    DecoderGrid__DOT__extractor__DOT___zz_correctionBits_10 
        = ((IData)(DecoderGrid__DOT__extractor__DOT____VdfgRegularize_hb2993a7d_0_1) 
           & (0U != (IData)(vlSelfRef.io_nodeParentDirs_2)));
    DecoderGrid__DOT__extractor__DOT___zz_correctionBits_11 
        = ((IData)(DecoderGrid__DOT__extractor__DOT____VdfgRegularize_hb2993a7d_0_1) 
           & ((0U != (IData)(vlSelfRef.io_nodeMatchDirs_2)) 
              & ((IData)(vlSelfRef.io_nodeRegionIds_2) 
                 < (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__matchedWith))));
    vlSelfRef.io_correction_bits = (((((IData)(vlSelfRef.DecoderGrid__DOT__extractor__DOT___zz_correctionBits_14) 
                                       & (4U == (IData)(vlSelfRef.io_nodeParentDirs_3))) 
                                      ^ ((IData)(vlSelfRef.DecoderGrid__DOT__extractor__DOT___zz_correctionBits_15) 
                                         & (4U == (IData)(vlSelfRef.io_nodeMatchDirs_3)))) 
                                     << 7U) | (((((IData)(DecoderGrid__DOT__extractor__DOT___zz_correctionBits_6) 
                                                  & (2U 
                                                     == (IData)(vlSelfRef.io_nodeParentDirs_1))) 
                                                 ^ 
                                                 (((IData)(DecoderGrid__DOT__extractor__DOT___zz_correctionBits_6) 
                                                   & (4U 
                                                      == (IData)(vlSelfRef.io_nodeParentDirs_1))) 
                                                  ^ 
                                                  (((IData)(DecoderGrid__DOT__extractor__DOT___zz_correctionBits_7) 
                                                    & (2U 
                                                       == (IData)(vlSelfRef.io_nodeMatchDirs_1))) 
                                                   ^ 
                                                   (((IData)(DecoderGrid__DOT__extractor__DOT___zz_correctionBits_7) 
                                                     & (4U 
                                                        == (IData)(vlSelfRef.io_nodeMatchDirs_1))) 
                                                    ^ 
                                                    (((IData)(DecoderGrid__DOT__extractor__DOT___zz_correctionBits_10) 
                                                      & (3U 
                                                         == (IData)(vlSelfRef.io_nodeParentDirs_2))) 
                                                     ^ 
                                                     (((IData)(DecoderGrid__DOT__extractor__DOT___zz_correctionBits_11) 
                                                       & (3U 
                                                          == (IData)(vlSelfRef.io_nodeMatchDirs_2))) 
                                                      ^ 
                                                      (((IData)(vlSelfRef.DecoderGrid__DOT__extractor__DOT___zz_correctionBits_14) 
                                                        & (1U 
                                                           == (IData)(vlSelfRef.io_nodeParentDirs_3))) 
                                                       ^ 
                                                       ((IData)(vlSelfRef.DecoderGrid__DOT__extractor__DOT___zz_correctionBits_15) 
                                                        & (1U 
                                                           == (IData)(vlSelfRef.io_nodeMatchDirs_3)))))))))) 
                                                << 4U) 
                                               | (((((IData)(vlSelfRef.DecoderGrid__DOT__extractor__DOT___zz_correctionBits_2) 
                                                     & (2U 
                                                        == (IData)(vlSelfRef.io_nodeParentDirs_0))) 
                                                    ^ 
                                                    (((IData)(vlSelfRef.DecoderGrid__DOT__extractor__DOT___zz_correctionBits_3) 
                                                      & (2U 
                                                         == (IData)(vlSelfRef.io_nodeMatchDirs_0))) 
                                                     ^ 
                                                     (((IData)(DecoderGrid__DOT__extractor__DOT___zz_correctionBits_10) 
                                                       & (1U 
                                                          == (IData)(vlSelfRef.io_nodeParentDirs_2))) 
                                                      ^ 
                                                      ((IData)(DecoderGrid__DOT__extractor__DOT___zz_correctionBits_11) 
                                                       & (1U 
                                                          == (IData)(vlSelfRef.io_nodeMatchDirs_2)))))) 
                                                   << 3U) 
                                                  | ((((IData)(vlSelfRef.DecoderGrid__DOT__extractor__DOT___zz_correctionBits_2) 
                                                       & (3U 
                                                          == (IData)(vlSelfRef.io_nodeParentDirs_0))) 
                                                      ^ 
                                                      ((IData)(vlSelfRef.DecoderGrid__DOT__extractor__DOT___zz_correctionBits_3) 
                                                       & (3U 
                                                          == (IData)(vlSelfRef.io_nodeMatchDirs_0)))) 
                                                     << 1U))));
}

void VDecoderGrid___024root___eval_nba(VDecoderGrid___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderGrid___024root___eval_nba\n"); );
    VDecoderGrid__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        VDecoderGrid___024root___nba_sequent__TOP__0(vlSelf);
        VDecoderGrid___024root___nba_sequent__TOP__1(vlSelf);
        VDecoderGrid___024root___nba_sequent__TOP__2(vlSelf);
        VDecoderGrid___024root___nba_sequent__TOP__3(vlSelf);
    }
}

void VDecoderGrid___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderGrid___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VDecoderGrid___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool VDecoderGrid___024root___eval_phase__act(VDecoderGrid___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderGrid___024root___eval_phase__act\n"); );
    VDecoderGrid__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VDecoderGrid___024root___eval_triggers_vec__act(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VDecoderGrid___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    VDecoderGrid___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void VDecoderGrid___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderGrid___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool VDecoderGrid___024root___eval_phase__nba(VDecoderGrid___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderGrid___024root___eval_phase__nba\n"); );
    VDecoderGrid__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = VDecoderGrid___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        VDecoderGrid___024root___eval_nba(vlSelf);
        VDecoderGrid___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void VDecoderGrid___024root___eval(VDecoderGrid___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderGrid___024root___eval\n"); );
    VDecoderGrid__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            VDecoderGrid___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("/Users/natashaprabhoo/git/QEC-Decoder-Sim/./simWorkspace/tmp/job_1/DecoderGrid.v", 7, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                VDecoderGrid___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("/Users/natashaprabhoo/git/QEC-Decoder-Sim/./simWorkspace/tmp/job_1/DecoderGrid.v", 7, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactPhaseResult = VDecoderGrid___024root___eval_phase__act(vlSelf);
        } while (vlSelfRef.__VactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = VDecoderGrid___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

#ifdef VL_DEBUG
void VDecoderGrid___024root___eval_debug_assertions(VDecoderGrid___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderGrid___024root___eval_debug_assertions\n"); );
    VDecoderGrid__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.io_syndromeFrame & 0xf0U)))) {
        Verilated::overWidthError("io_syndromeFrame");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_loadEnable & 0xfeU)))) {
        Verilated::overWidthError("io_loadEnable");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_start & 0xfeU)))) {
        Verilated::overWidthError("io_start");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_reset_n & 0xfeU)))) {
        Verilated::overWidthError("io_reset_n");
    }
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.reset & 0xfeU)))) {
        Verilated::overWidthError("reset");
    }
}
#endif  // VL_DEBUG
