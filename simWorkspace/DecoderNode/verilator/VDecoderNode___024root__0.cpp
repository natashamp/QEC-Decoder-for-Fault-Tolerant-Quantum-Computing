// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VDecoderNode.h for the primary calling header

#include "VDecoderNode__pch.h"

void VDecoderNode___024root___eval_triggers_vec__ico(VDecoderNode___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderNode___024root___eval_triggers_vec__ico\n"); );
    VDecoderNode__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered[0U]) 
                                     | (IData)((IData)(vlSelfRef.__VicoFirstIteration)));
}

bool VDecoderNode___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderNode___024root___trigger_anySet__ico\n"); );
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

void VDecoderNode___024root___ico_sequent__TOP__0(VDecoderNode___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderNode___024root___ico_sequent__TOP__0\n"); );
    VDecoderNode__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.DecoderNode__DOT__when_DecoderNode_l141 
        = ((0U == (7U & (((~ (IData)(vlSelfRef.io_neighborIn_north_peeled)) 
                          & ((IData)(vlSelfRef.io_neighborIn_north_valid) 
                             & ((2U == (IData)(vlSelfRef.io_neighborIn_north_parentDir)) 
                                & (0U != (IData)(vlSelfRef.io_neighborIn_north_regionId))))) 
                         + (((~ (IData)(vlSelfRef.io_neighborIn_south_peeled)) 
                             & ((IData)(vlSelfRef.io_neighborIn_south_valid) 
                                & ((1U == (IData)(vlSelfRef.io_neighborIn_south_parentDir)) 
                                   & (0U != (IData)(vlSelfRef.io_neighborIn_south_regionId))))) 
                            + (((~ (IData)(vlSelfRef.io_neighborIn_east_peeled)) 
                                & ((IData)(vlSelfRef.io_neighborIn_east_valid) 
                                   & ((4U == (IData)(vlSelfRef.io_neighborIn_east_parentDir)) 
                                      & (0U != (IData)(vlSelfRef.io_neighborIn_east_regionId))))) 
                               + ((~ (IData)(vlSelfRef.io_neighborIn_west_peeled)) 
                                  & ((IData)(vlSelfRef.io_neighborIn_west_valid) 
                                     & ((3U == (IData)(vlSelfRef.io_neighborIn_west_parentDir)) 
                                        & (0U != (IData)(vlSelfRef.io_neighborIn_west_regionId)))))))))) 
           & ((~ (IData)(vlSelfRef.DecoderNode__DOT__syndromeReg)) 
              & (~ (IData)(vlSelfRef.DecoderNode__DOT__peeledReg))));
    vlSelfRef.DecoderNode__DOT__when_DecoderNode_l78 
        = ((IData)(vlSelfRef.io_neighborIn_west_grown) 
           & (IData)(vlSelfRef.io_neighborIn_west_valid));
    vlSelfRef.DecoderNode__DOT__when_DecoderNode_l78_1 
        = ((IData)(vlSelfRef.io_neighborIn_east_grown) 
           & (IData)(vlSelfRef.io_neighborIn_east_valid));
    vlSelfRef.DecoderNode__DOT__when_DecoderNode_l78_2 
        = ((IData)(vlSelfRef.io_neighborIn_south_grown) 
           & (IData)(vlSelfRef.io_neighborIn_south_valid));
    vlSelfRef.DecoderNode__DOT__when_DecoderNode_l78_3 
        = ((IData)(vlSelfRef.io_neighborIn_north_grown) 
           & (IData)(vlSelfRef.io_neighborIn_north_valid));
    vlSelfRef.DecoderNode__DOT__when_DecoderNode_l118_3 
        = ((IData)(vlSelfRef.DecoderNode__DOT__when_DecoderNode_l78) 
           & (((IData)(vlSelfRef.io_neighborIn_west_regionId) 
               != (IData)(vlSelfRef.DecoderNode__DOT__regionIdReg)) 
              & (0U != (IData)(vlSelfRef.io_neighborIn_west_regionId))));
    vlSelfRef.DecoderNode__DOT__when_DecoderNode_l118_2 
        = ((IData)(vlSelfRef.DecoderNode__DOT__when_DecoderNode_l78_1) 
           & (((IData)(vlSelfRef.io_neighborIn_east_regionId) 
               != (IData)(vlSelfRef.DecoderNode__DOT__regionIdReg)) 
              & (0U != (IData)(vlSelfRef.io_neighborIn_east_regionId))));
    vlSelfRef.DecoderNode__DOT__when_DecoderNode_l118_1 
        = ((IData)(vlSelfRef.DecoderNode__DOT__when_DecoderNode_l78_2) 
           & (((IData)(vlSelfRef.io_neighborIn_south_regionId) 
               != (IData)(vlSelfRef.DecoderNode__DOT__regionIdReg)) 
              & (0U != (IData)(vlSelfRef.io_neighborIn_south_regionId))));
    vlSelfRef.DecoderNode__DOT__when_DecoderNode_l118 
        = ((IData)(vlSelfRef.DecoderNode__DOT__when_DecoderNode_l78_3) 
           & (((IData)(vlSelfRef.io_neighborIn_north_regionId) 
               != (IData)(vlSelfRef.DecoderNode__DOT__regionIdReg)) 
              & (0U != (IData)(vlSelfRef.io_neighborIn_north_regionId))));
    vlSelfRef.DecoderNode__DOT__absorbParentDirComb = 0U;
    if (vlSelfRef.DecoderNode__DOT__when_DecoderNode_l78) {
        vlSelfRef.DecoderNode__DOT__absorbParentDirComb = 4U;
    }
    if (vlSelfRef.DecoderNode__DOT__when_DecoderNode_l78_1) {
        vlSelfRef.DecoderNode__DOT__absorbParentDirComb = 3U;
    }
    if (vlSelfRef.DecoderNode__DOT__when_DecoderNode_l78_2) {
        vlSelfRef.DecoderNode__DOT__absorbParentDirComb = 2U;
    }
    vlSelfRef.DecoderNode__DOT__absorbRegionIdComb = 0U;
    if (vlSelfRef.DecoderNode__DOT__when_DecoderNode_l78) {
        vlSelfRef.DecoderNode__DOT__absorbRegionIdComb 
            = vlSelfRef.io_neighborIn_west_regionId;
    }
    if (vlSelfRef.DecoderNode__DOT__when_DecoderNode_l78_1) {
        vlSelfRef.DecoderNode__DOT__absorbRegionIdComb 
            = vlSelfRef.io_neighborIn_east_regionId;
    }
    if (vlSelfRef.DecoderNode__DOT__when_DecoderNode_l78_2) {
        vlSelfRef.DecoderNode__DOT__absorbRegionIdComb 
            = vlSelfRef.io_neighborIn_south_regionId;
    }
    if (vlSelfRef.DecoderNode__DOT__when_DecoderNode_l78_3) {
        vlSelfRef.DecoderNode__DOT__absorbParentDirComb = 1U;
        vlSelfRef.DecoderNode__DOT__absorbRegionIdComb 
            = vlSelfRef.io_neighborIn_north_regionId;
    }
}

void VDecoderNode___024root___eval_ico(VDecoderNode___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderNode___024root___eval_ico\n"); );
    VDecoderNode__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered[0U])) {
        vlSelfRef.DecoderNode__DOT__when_DecoderNode_l141 
            = ((0U == (7U & (((~ (IData)(vlSelfRef.io_neighborIn_north_peeled)) 
                              & ((IData)(vlSelfRef.io_neighborIn_north_valid) 
                                 & ((2U == (IData)(vlSelfRef.io_neighborIn_north_parentDir)) 
                                    & (0U != (IData)(vlSelfRef.io_neighborIn_north_regionId))))) 
                             + (((~ (IData)(vlSelfRef.io_neighborIn_south_peeled)) 
                                 & ((IData)(vlSelfRef.io_neighborIn_south_valid) 
                                    & ((1U == (IData)(vlSelfRef.io_neighborIn_south_parentDir)) 
                                       & (0U != (IData)(vlSelfRef.io_neighborIn_south_regionId))))) 
                                + (((~ (IData)(vlSelfRef.io_neighborIn_east_peeled)) 
                                    & ((IData)(vlSelfRef.io_neighborIn_east_valid) 
                                       & ((4U == (IData)(vlSelfRef.io_neighborIn_east_parentDir)) 
                                          & (0U != (IData)(vlSelfRef.io_neighborIn_east_regionId))))) 
                                   + ((~ (IData)(vlSelfRef.io_neighborIn_west_peeled)) 
                                      & ((IData)(vlSelfRef.io_neighborIn_west_valid) 
                                         & ((3U == (IData)(vlSelfRef.io_neighborIn_west_parentDir)) 
                                            & (0U != (IData)(vlSelfRef.io_neighborIn_west_regionId)))))))))) 
               & ((~ (IData)(vlSelfRef.DecoderNode__DOT__syndromeReg)) 
                  & (~ (IData)(vlSelfRef.DecoderNode__DOT__peeledReg))));
        vlSelfRef.DecoderNode__DOT__when_DecoderNode_l78 
            = ((IData)(vlSelfRef.io_neighborIn_west_grown) 
               & (IData)(vlSelfRef.io_neighborIn_west_valid));
        vlSelfRef.DecoderNode__DOT__when_DecoderNode_l78_1 
            = ((IData)(vlSelfRef.io_neighborIn_east_grown) 
               & (IData)(vlSelfRef.io_neighborIn_east_valid));
        vlSelfRef.DecoderNode__DOT__when_DecoderNode_l78_2 
            = ((IData)(vlSelfRef.io_neighborIn_south_grown) 
               & (IData)(vlSelfRef.io_neighborIn_south_valid));
        vlSelfRef.DecoderNode__DOT__when_DecoderNode_l78_3 
            = ((IData)(vlSelfRef.io_neighborIn_north_grown) 
               & (IData)(vlSelfRef.io_neighborIn_north_valid));
        vlSelfRef.DecoderNode__DOT__when_DecoderNode_l118_3 
            = ((IData)(vlSelfRef.DecoderNode__DOT__when_DecoderNode_l78) 
               & (((IData)(vlSelfRef.io_neighborIn_west_regionId) 
                   != (IData)(vlSelfRef.DecoderNode__DOT__regionIdReg)) 
                  & (0U != (IData)(vlSelfRef.io_neighborIn_west_regionId))));
        vlSelfRef.DecoderNode__DOT__when_DecoderNode_l118_2 
            = ((IData)(vlSelfRef.DecoderNode__DOT__when_DecoderNode_l78_1) 
               & (((IData)(vlSelfRef.io_neighborIn_east_regionId) 
                   != (IData)(vlSelfRef.DecoderNode__DOT__regionIdReg)) 
                  & (0U != (IData)(vlSelfRef.io_neighborIn_east_regionId))));
        vlSelfRef.DecoderNode__DOT__when_DecoderNode_l118_1 
            = ((IData)(vlSelfRef.DecoderNode__DOT__when_DecoderNode_l78_2) 
               & (((IData)(vlSelfRef.io_neighborIn_south_regionId) 
                   != (IData)(vlSelfRef.DecoderNode__DOT__regionIdReg)) 
                  & (0U != (IData)(vlSelfRef.io_neighborIn_south_regionId))));
        vlSelfRef.DecoderNode__DOT__when_DecoderNode_l118 
            = ((IData)(vlSelfRef.DecoderNode__DOT__when_DecoderNode_l78_3) 
               & (((IData)(vlSelfRef.io_neighborIn_north_regionId) 
                   != (IData)(vlSelfRef.DecoderNode__DOT__regionIdReg)) 
                  & (0U != (IData)(vlSelfRef.io_neighborIn_north_regionId))));
        vlSelfRef.DecoderNode__DOT__absorbParentDirComb = 0U;
        if (vlSelfRef.DecoderNode__DOT__when_DecoderNode_l78) {
            vlSelfRef.DecoderNode__DOT__absorbParentDirComb = 4U;
        }
        if (vlSelfRef.DecoderNode__DOT__when_DecoderNode_l78_1) {
            vlSelfRef.DecoderNode__DOT__absorbParentDirComb = 3U;
        }
        if (vlSelfRef.DecoderNode__DOT__when_DecoderNode_l78_2) {
            vlSelfRef.DecoderNode__DOT__absorbParentDirComb = 2U;
        }
        vlSelfRef.DecoderNode__DOT__absorbRegionIdComb = 0U;
        if (vlSelfRef.DecoderNode__DOT__when_DecoderNode_l78) {
            vlSelfRef.DecoderNode__DOT__absorbRegionIdComb 
                = vlSelfRef.io_neighborIn_west_regionId;
        }
        if (vlSelfRef.DecoderNode__DOT__when_DecoderNode_l78_1) {
            vlSelfRef.DecoderNode__DOT__absorbRegionIdComb 
                = vlSelfRef.io_neighborIn_east_regionId;
        }
        if (vlSelfRef.DecoderNode__DOT__when_DecoderNode_l78_2) {
            vlSelfRef.DecoderNode__DOT__absorbRegionIdComb 
                = vlSelfRef.io_neighborIn_south_regionId;
        }
        if (vlSelfRef.DecoderNode__DOT__when_DecoderNode_l78_3) {
            vlSelfRef.DecoderNode__DOT__absorbParentDirComb = 1U;
            vlSelfRef.DecoderNode__DOT__absorbRegionIdComb 
                = vlSelfRef.io_neighborIn_north_regionId;
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VDecoderNode___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool VDecoderNode___024root___eval_phase__ico(VDecoderNode___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderNode___024root___eval_phase__ico\n"); );
    VDecoderNode__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VicoExecute;
    // Body
    VDecoderNode___024root___eval_triggers_vec__ico(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VDecoderNode___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    __VicoExecute = VDecoderNode___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        VDecoderNode___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void VDecoderNode___024root___eval_triggers_vec__act(VDecoderNode___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderNode___024root___eval_triggers_vec__act\n"); );
    VDecoderNode__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

bool VDecoderNode___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderNode___024root___trigger_anySet__act\n"); );
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

void VDecoderNode___024root___nba_sequent__TOP__0(VDecoderNode___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderNode___024root___nba_sequent__TOP__0\n"); );
    VDecoderNode__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*1:0*/ __Vdly__DecoderNode__DOT__stateReg;
    __Vdly__DecoderNode__DOT__stateReg = 0;
    // Body
    __Vdly__DecoderNode__DOT__stateReg = vlSelfRef.DecoderNode__DOT__stateReg;
    if (vlSelfRef.reset) {
        __Vdly__DecoderNode__DOT__stateReg = 0U;
        vlSelfRef.DecoderNode__DOT__regionIdReg = 0U;
        vlSelfRef.DecoderNode__DOT__matchedWith = 0U;
        vlSelfRef.DecoderNode__DOT__parentDirReg = 0U;
        vlSelfRef.DecoderNode__DOT__matchDirReg = 0U;
        vlSelfRef.DecoderNode__DOT__peeledReg = 0U;
        vlSelfRef.DecoderNode__DOT__syndromeReg = 0U;
    } else {
        if (vlSelfRef.io_loadEnable) {
            __Vdly__DecoderNode__DOT__stateReg = 0U;
            vlSelfRef.DecoderNode__DOT__regionIdReg = 0U;
            vlSelfRef.DecoderNode__DOT__matchedWith = 0U;
            vlSelfRef.DecoderNode__DOT__parentDirReg = 0U;
            vlSelfRef.DecoderNode__DOT__matchDirReg = 0U;
            vlSelfRef.DecoderNode__DOT__peeledReg = 0U;
        }
        if ((0U == (IData)(vlSelfRef.DecoderNode__DOT__stateReg))) {
            if (vlSelfRef.io_startPeel) {
                __Vdly__DecoderNode__DOT__stateReg = 3U;
                vlSelfRef.DecoderNode__DOT__peeledReg = 1U;
            } else if (((IData)(vlSelfRef.DecoderNode__DOT__syndromeReg) 
                        & (IData)(vlSelfRef.io_start))) {
                __Vdly__DecoderNode__DOT__stateReg = 1U;
                vlSelfRef.DecoderNode__DOT__regionIdReg = 1U;
                vlSelfRef.DecoderNode__DOT__parentDirReg = 0U;
            } else if (((IData)(vlSelfRef.io_start) 
                        & ((~ (IData)(vlSelfRef.DecoderNode__DOT__syndromeReg)) 
                           & ((IData)(vlSelfRef.DecoderNode__DOT__when_DecoderNode_l78) 
                              | ((IData)(vlSelfRef.DecoderNode__DOT__when_DecoderNode_l78_1) 
                                 | ((IData)(vlSelfRef.DecoderNode__DOT__when_DecoderNode_l78_2) 
                                    | (IData)(vlSelfRef.DecoderNode__DOT__when_DecoderNode_l78_3))))))) {
                __Vdly__DecoderNode__DOT__stateReg = 1U;
                vlSelfRef.DecoderNode__DOT__regionIdReg 
                    = vlSelfRef.DecoderNode__DOT__absorbRegionIdComb;
                vlSelfRef.DecoderNode__DOT__parentDirReg 
                    = vlSelfRef.DecoderNode__DOT__absorbParentDirComb;
            }
        } else if ((1U == (IData)(vlSelfRef.DecoderNode__DOT__stateReg))) {
            if (vlSelfRef.DecoderNode__DOT__when_DecoderNode_l118) {
                __Vdly__DecoderNode__DOT__stateReg = 2U;
                vlSelfRef.DecoderNode__DOT__matchedWith 
                    = vlSelfRef.io_neighborIn_north_regionId;
                vlSelfRef.DecoderNode__DOT__matchDirReg = 1U;
            }
            if (vlSelfRef.DecoderNode__DOT__when_DecoderNode_l118_1) {
                __Vdly__DecoderNode__DOT__stateReg = 2U;
                vlSelfRef.DecoderNode__DOT__matchedWith 
                    = vlSelfRef.io_neighborIn_south_regionId;
                vlSelfRef.DecoderNode__DOT__matchDirReg = 2U;
            }
            if (vlSelfRef.DecoderNode__DOT__when_DecoderNode_l118_2) {
                __Vdly__DecoderNode__DOT__stateReg = 2U;
                vlSelfRef.DecoderNode__DOT__matchedWith 
                    = vlSelfRef.io_neighborIn_east_regionId;
                vlSelfRef.DecoderNode__DOT__matchDirReg = 3U;
            }
            if (vlSelfRef.DecoderNode__DOT__when_DecoderNode_l118_3) {
                __Vdly__DecoderNode__DOT__stateReg = 2U;
                vlSelfRef.DecoderNode__DOT__matchedWith 
                    = vlSelfRef.io_neighborIn_west_regionId;
                vlSelfRef.DecoderNode__DOT__matchDirReg = 4U;
            }
            if (vlSelfRef.io_startPeel) {
                __Vdly__DecoderNode__DOT__stateReg = 3U;
                vlSelfRef.DecoderNode__DOT__peeledReg = 1U;
            }
        } else if ((2U == (IData)(vlSelfRef.DecoderNode__DOT__stateReg))) {
            if (vlSelfRef.io_startPeel) {
                __Vdly__DecoderNode__DOT__stateReg = 3U;
                vlSelfRef.DecoderNode__DOT__peeledReg = 0U;
            }
        } else if (vlSelfRef.DecoderNode__DOT__when_DecoderNode_l141) {
            vlSelfRef.DecoderNode__DOT__peeledReg = 1U;
        }
        if (vlSelfRef.io_loadEnable) {
            vlSelfRef.DecoderNode__DOT__syndromeReg 
                = vlSelfRef.io_syndromeIn;
        }
        if ((1U & (~ (IData)(vlSelfRef.io_reset_n)))) {
            __Vdly__DecoderNode__DOT__stateReg = 0U;
            vlSelfRef.DecoderNode__DOT__regionIdReg = 0U;
            vlSelfRef.DecoderNode__DOT__matchedWith = 0U;
            vlSelfRef.DecoderNode__DOT__parentDirReg = 0U;
            vlSelfRef.DecoderNode__DOT__matchDirReg = 0U;
            vlSelfRef.DecoderNode__DOT__peeledReg = 0U;
            vlSelfRef.DecoderNode__DOT__syndromeReg = 0U;
        }
    }
    vlSelfRef.DecoderNode__DOT__stateReg = __Vdly__DecoderNode__DOT__stateReg;
    vlSelfRef.io_matchedWithId = vlSelfRef.DecoderNode__DOT__matchedWith;
    vlSelfRef.io_matchDir = vlSelfRef.DecoderNode__DOT__matchDirReg;
    vlSelfRef.io_linkOut_parentDir = vlSelfRef.DecoderNode__DOT__parentDirReg;
    vlSelfRef.io_parentDir = vlSelfRef.DecoderNode__DOT__parentDirReg;
    vlSelfRef.io_linkOut_valid = (0U != (IData)(vlSelfRef.DecoderNode__DOT__stateReg));
    vlSelfRef.io_linkOut_grown = (1U == (IData)(vlSelfRef.DecoderNode__DOT__stateReg));
    vlSelfRef.io_state = vlSelfRef.DecoderNode__DOT__stateReg;
    vlSelfRef.io_linkOut_regionId = vlSelfRef.DecoderNode__DOT__regionIdReg;
    vlSelfRef.io_regionId = vlSelfRef.DecoderNode__DOT__regionIdReg;
    vlSelfRef.DecoderNode__DOT__when_DecoderNode_l118 
        = ((IData)(vlSelfRef.DecoderNode__DOT__when_DecoderNode_l78_3) 
           & (((IData)(vlSelfRef.io_neighborIn_north_regionId) 
               != (IData)(vlSelfRef.DecoderNode__DOT__regionIdReg)) 
              & (0U != (IData)(vlSelfRef.io_neighborIn_north_regionId))));
    vlSelfRef.DecoderNode__DOT__when_DecoderNode_l118_1 
        = ((IData)(vlSelfRef.DecoderNode__DOT__when_DecoderNode_l78_2) 
           & (((IData)(vlSelfRef.io_neighborIn_south_regionId) 
               != (IData)(vlSelfRef.DecoderNode__DOT__regionIdReg)) 
              & (0U != (IData)(vlSelfRef.io_neighborIn_south_regionId))));
    vlSelfRef.DecoderNode__DOT__when_DecoderNode_l118_2 
        = ((IData)(vlSelfRef.DecoderNode__DOT__when_DecoderNode_l78_1) 
           & (((IData)(vlSelfRef.io_neighborIn_east_regionId) 
               != (IData)(vlSelfRef.DecoderNode__DOT__regionIdReg)) 
              & (0U != (IData)(vlSelfRef.io_neighborIn_east_regionId))));
    vlSelfRef.DecoderNode__DOT__when_DecoderNode_l118_3 
        = ((IData)(vlSelfRef.DecoderNode__DOT__when_DecoderNode_l78) 
           & (((IData)(vlSelfRef.io_neighborIn_west_regionId) 
               != (IData)(vlSelfRef.DecoderNode__DOT__regionIdReg)) 
              & (0U != (IData)(vlSelfRef.io_neighborIn_west_regionId))));
    vlSelfRef.io_linkOut_peeled = vlSelfRef.DecoderNode__DOT__peeledReg;
    vlSelfRef.io_peeled = vlSelfRef.DecoderNode__DOT__peeledReg;
    vlSelfRef.io_syndrome = vlSelfRef.DecoderNode__DOT__syndromeReg;
    vlSelfRef.io_correctionFlag = (((2U == (IData)(vlSelfRef.DecoderNode__DOT__stateReg)) 
                                    & (IData)(vlSelfRef.DecoderNode__DOT__syndromeReg)) 
                                   | ((3U == (IData)(vlSelfRef.DecoderNode__DOT__stateReg)) 
                                      & ((~ (IData)(vlSelfRef.DecoderNode__DOT__peeledReg)) 
                                         & ((0U != (IData)(vlSelfRef.DecoderNode__DOT__parentDirReg)) 
                                            | (0U != (IData)(vlSelfRef.DecoderNode__DOT__matchDirReg))))));
    vlSelfRef.DecoderNode__DOT__when_DecoderNode_l141 
        = ((0U == (7U & (((~ (IData)(vlSelfRef.io_neighborIn_north_peeled)) 
                          & ((IData)(vlSelfRef.io_neighborIn_north_valid) 
                             & ((2U == (IData)(vlSelfRef.io_neighborIn_north_parentDir)) 
                                & (0U != (IData)(vlSelfRef.io_neighborIn_north_regionId))))) 
                         + (((~ (IData)(vlSelfRef.io_neighborIn_south_peeled)) 
                             & ((IData)(vlSelfRef.io_neighborIn_south_valid) 
                                & ((1U == (IData)(vlSelfRef.io_neighborIn_south_parentDir)) 
                                   & (0U != (IData)(vlSelfRef.io_neighborIn_south_regionId))))) 
                            + (((~ (IData)(vlSelfRef.io_neighborIn_east_peeled)) 
                                & ((IData)(vlSelfRef.io_neighborIn_east_valid) 
                                   & ((4U == (IData)(vlSelfRef.io_neighborIn_east_parentDir)) 
                                      & (0U != (IData)(vlSelfRef.io_neighborIn_east_regionId))))) 
                               + ((~ (IData)(vlSelfRef.io_neighborIn_west_peeled)) 
                                  & ((IData)(vlSelfRef.io_neighborIn_west_valid) 
                                     & ((3U == (IData)(vlSelfRef.io_neighborIn_west_parentDir)) 
                                        & (0U != (IData)(vlSelfRef.io_neighborIn_west_regionId)))))))))) 
           & ((~ (IData)(vlSelfRef.DecoderNode__DOT__syndromeReg)) 
              & (~ (IData)(vlSelfRef.DecoderNode__DOT__peeledReg))));
}

void VDecoderNode___024root___eval_nba(VDecoderNode___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderNode___024root___eval_nba\n"); );
    VDecoderNode__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        VDecoderNode___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void VDecoderNode___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderNode___024root___trigger_orInto__act_vec_vec\n"); );
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
VL_ATTR_COLD void VDecoderNode___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool VDecoderNode___024root___eval_phase__act(VDecoderNode___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderNode___024root___eval_phase__act\n"); );
    VDecoderNode__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VDecoderNode___024root___eval_triggers_vec__act(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VDecoderNode___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    VDecoderNode___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void VDecoderNode___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderNode___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool VDecoderNode___024root___eval_phase__nba(VDecoderNode___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderNode___024root___eval_phase__nba\n"); );
    VDecoderNode__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = VDecoderNode___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        VDecoderNode___024root___eval_nba(vlSelf);
        VDecoderNode___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void VDecoderNode___024root___eval(VDecoderNode___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderNode___024root___eval\n"); );
    VDecoderNode__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            VDecoderNode___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("/Users/natashaprabhoo/git/QEC-Decoder-Sim/./simWorkspace/tmp/job_1/DecoderNode.v", 7, "", "DIDNOTCONVERGE: Input combinational region did not converge after '--converge-limit' of 100 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        vlSelfRef.__VicoPhaseResult = VDecoderNode___024root___eval_phase__ico(vlSelf);
        vlSelfRef.__VicoFirstIteration = 0U;
    } while (vlSelfRef.__VicoPhaseResult);
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            VDecoderNode___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("/Users/natashaprabhoo/git/QEC-Decoder-Sim/./simWorkspace/tmp/job_1/DecoderNode.v", 7, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                VDecoderNode___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("/Users/natashaprabhoo/git/QEC-Decoder-Sim/./simWorkspace/tmp/job_1/DecoderNode.v", 7, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactPhaseResult = VDecoderNode___024root___eval_phase__act(vlSelf);
        } while (vlSelfRef.__VactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = VDecoderNode___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

#ifdef VL_DEBUG
void VDecoderNode___024root___eval_debug_assertions(VDecoderNode___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderNode___024root___eval_debug_assertions\n"); );
    VDecoderNode__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.io_syndromeIn & 0xfeU)))) {
        Verilated::overWidthError("io_syndromeIn");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_loadEnable & 0xfeU)))) {
        Verilated::overWidthError("io_loadEnable");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_start & 0xfeU)))) {
        Verilated::overWidthError("io_start");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_startPeel & 0xfeU)))) {
        Verilated::overWidthError("io_startPeel");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_reset_n & 0xfeU)))) {
        Verilated::overWidthError("io_reset_n");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_neighborIn_north_valid 
                      & 0xfeU)))) {
        Verilated::overWidthError("io_neighborIn_north_valid");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_neighborIn_north_regionId 
                      & 0xf8U)))) {
        Verilated::overWidthError("io_neighborIn_north_regionId");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_neighborIn_north_grown 
                      & 0xfeU)))) {
        Verilated::overWidthError("io_neighborIn_north_grown");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_neighborIn_north_parentDir 
                      & 0xf8U)))) {
        Verilated::overWidthError("io_neighborIn_north_parentDir");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_neighborIn_north_peeled 
                      & 0xfeU)))) {
        Verilated::overWidthError("io_neighborIn_north_peeled");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_neighborIn_south_valid 
                      & 0xfeU)))) {
        Verilated::overWidthError("io_neighborIn_south_valid");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_neighborIn_south_regionId 
                      & 0xf8U)))) {
        Verilated::overWidthError("io_neighborIn_south_regionId");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_neighborIn_south_grown 
                      & 0xfeU)))) {
        Verilated::overWidthError("io_neighborIn_south_grown");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_neighborIn_south_parentDir 
                      & 0xf8U)))) {
        Verilated::overWidthError("io_neighborIn_south_parentDir");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_neighborIn_south_peeled 
                      & 0xfeU)))) {
        Verilated::overWidthError("io_neighborIn_south_peeled");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_neighborIn_east_valid 
                      & 0xfeU)))) {
        Verilated::overWidthError("io_neighborIn_east_valid");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_neighborIn_east_regionId 
                      & 0xf8U)))) {
        Verilated::overWidthError("io_neighborIn_east_regionId");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_neighborIn_east_grown 
                      & 0xfeU)))) {
        Verilated::overWidthError("io_neighborIn_east_grown");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_neighborIn_east_parentDir 
                      & 0xf8U)))) {
        Verilated::overWidthError("io_neighborIn_east_parentDir");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_neighborIn_east_peeled 
                      & 0xfeU)))) {
        Verilated::overWidthError("io_neighborIn_east_peeled");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_neighborIn_west_valid 
                      & 0xfeU)))) {
        Verilated::overWidthError("io_neighborIn_west_valid");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_neighborIn_west_regionId 
                      & 0xf8U)))) {
        Verilated::overWidthError("io_neighborIn_west_regionId");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_neighborIn_west_grown 
                      & 0xfeU)))) {
        Verilated::overWidthError("io_neighborIn_west_grown");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_neighborIn_west_parentDir 
                      & 0xf8U)))) {
        Verilated::overWidthError("io_neighborIn_west_parentDir");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_neighborIn_west_peeled 
                      & 0xfeU)))) {
        Verilated::overWidthError("io_neighborIn_west_peeled");
    }
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.reset & 0xfeU)))) {
        Verilated::overWidthError("reset");
    }
}
#endif  // VL_DEBUG
