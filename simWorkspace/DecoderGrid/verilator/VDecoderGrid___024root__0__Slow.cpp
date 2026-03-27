// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VDecoderGrid.h for the primary calling header

#include "VDecoderGrid__pch.h"

VL_ATTR_COLD void VDecoderGrid___024root___eval_static(VDecoderGrid___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderGrid___024root___eval_static\n"); );
    VDecoderGrid__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__reset__0 = vlSelfRef.reset;
}

VL_ATTR_COLD void VDecoderGrid___024root___eval_initial(VDecoderGrid___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderGrid___024root___eval_initial\n"); );
    VDecoderGrid__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void VDecoderGrid___024root___eval_final(VDecoderGrid___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderGrid___024root___eval_final\n"); );
    VDecoderGrid__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VDecoderGrid___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool VDecoderGrid___024root___eval_phase__stl(VDecoderGrid___024root* vlSelf);

VL_ATTR_COLD void VDecoderGrid___024root___eval_settle(VDecoderGrid___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderGrid___024root___eval_settle\n"); );
    VDecoderGrid__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            VDecoderGrid___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("/Users/natashaprabhoo/git/QEC-Decoder-Sim/./simWorkspace/tmp/job_1/DecoderGrid.v", 7, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 100 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        vlSelfRef.__VstlPhaseResult = VDecoderGrid___024root___eval_phase__stl(vlSelf);
        vlSelfRef.__VstlFirstIteration = 0U;
    } while (vlSelfRef.__VstlPhaseResult);
}

VL_ATTR_COLD void VDecoderGrid___024root___eval_triggers_vec__stl(VDecoderGrid___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderGrid___024root___eval_triggers_vec__stl\n"); );
    VDecoderGrid__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
}

VL_ATTR_COLD bool VDecoderGrid___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void VDecoderGrid___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderGrid___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(VDecoderGrid___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool VDecoderGrid___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderGrid___024root___trigger_anySet__stl\n"); );
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

VL_ATTR_COLD void VDecoderGrid___024root___stl_sequent__TOP__0(VDecoderGrid___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderGrid___024root___stl_sequent__TOP__0\n"); );
    VDecoderGrid__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.io_nodeSyndromes_0 = vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__syndromeReg;
    vlSelfRef.io_nodeSyndromes_1 = vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__syndromeReg;
    vlSelfRef.io_nodeSyndromes_2 = vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__syndromeReg;
    vlSelfRef.io_nodeSyndromes_3 = vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__syndromeReg;
    vlSelfRef.io_correction_valid = vlSelfRef.DecoderGrid__DOT__doneReg;
    vlSelfRef.io_done = vlSelfRef.DecoderGrid__DOT__doneReg;
    vlSelfRef.io_gridPhase = vlSelfRef.DecoderGrid__DOT__phaseReg;
    vlSelfRef.io_stall = vlSelfRef.DecoderGrid__DOT__stallReg;
    vlSelfRef.DecoderGrid__DOT__when_DecoderGrid_l185 
        = (4U <= (IData)(vlSelfRef.DecoderGrid__DOT__cycleCount));
    vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__when_DecoderNode_l144 
        = ((0U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__stateReg)) 
           & (IData)(vlSelfRef.DecoderGrid__DOT__nodeStartPeel));
    vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__when_DecoderNode_l144 
        = ((0U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__stateReg)) 
           & (IData)(vlSelfRef.DecoderGrid__DOT__nodeStartPeel));
    vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__when_DecoderNode_l144 
        = ((0U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__stateReg)) 
           & (IData)(vlSelfRef.DecoderGrid__DOT__nodeStartPeel));
    vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__when_DecoderNode_l144 
        = ((0U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__stateReg)) 
           & (IData)(vlSelfRef.DecoderGrid__DOT__nodeStartPeel));
    vlSelfRef.DecoderGrid__DOT__when_DecoderGrid_l201 
        = ((4U <= (IData)(vlSelfRef.DecoderGrid__DOT__cycleCount)) 
           | (IData)(vlSelfRef.DecoderGrid__DOT__peelingDone));
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
    vlSelfRef.io_nodeRegionIds_0 = vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__regionIdReg;
    vlSelfRef.io_nodeRegionIds_1 = vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__regionIdReg;
    vlSelfRef.io_nodeRegionIds_2 = vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__regionIdReg;
    vlSelfRef.io_nodeRegionIds_3 = vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__regionIdReg;
    vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__when_DecoderNode_l78 
        = ((1U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__stateReg)) 
           & (0U != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__stateReg)));
    vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__when_DecoderNode_l78_3 
        = ((1U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__stateReg)) 
           & (0U != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__stateReg)));
    vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__when_DecoderNode_l78_1 
        = ((1U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__stateReg)) 
           & (0U != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__stateReg)));
    vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__when_DecoderNode_l78_3 
        = ((1U == (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__stateReg)) 
           & (0U != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__stateReg)));
    vlSelfRef.io_nodeParentDirs_0 = vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__parentDirReg;
    vlSelfRef.io_nodeParentDirs_1 = vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__parentDirReg;
    vlSelfRef.io_nodeParentDirs_2 = vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__parentDirReg;
    vlSelfRef.io_nodeParentDirs_3 = vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__parentDirReg;
    vlSelfRef.io_nodeMatchDirs_0 = vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__matchDirReg;
    vlSelfRef.io_nodeMatchDirs_1 = vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__matchDirReg;
    vlSelfRef.io_nodeMatchDirs_2 = vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__matchDirReg;
    vlSelfRef.io_nodeMatchDirs_3 = vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__matchDirReg;
    vlSelfRef.io_nodeStates_0 = vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__stateReg;
    vlSelfRef.io_nodeStates_1 = vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__stateReg;
    vlSelfRef.io_nodeStates_2 = vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__stateReg;
    vlSelfRef.io_nodeStates_3 = vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__stateReg;
    vlSelfRef.io_nodePeeled_0 = vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__peeledReg;
    vlSelfRef.io_nodePeeled_1 = vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__peeledReg;
    vlSelfRef.io_nodePeeled_2 = vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__peeledReg;
    vlSelfRef.io_nodePeeled_3 = vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__peeledReg;
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
}

VL_ATTR_COLD void VDecoderGrid___024root___stl_sequent__TOP__1(VDecoderGrid___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderGrid___024root___stl_sequent__TOP__1\n"); );
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
    vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__absorbParentDirComb = 0U;
    vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__absorbParentDirComb = 0U;
    if (vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__when_DecoderNode_l78_3) {
        vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__when_DecoderNode_l114_2 
            = (((IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__regionIdReg) 
                != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__regionIdReg)) 
               & (0U != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__regionIdReg)));
        vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__when_DecoderNode_l114 
            = (((IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__regionIdReg) 
                != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__regionIdReg)) 
               & (0U != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__regionIdReg)));
        vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__absorbRegionIdComb = 0U;
        vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__absorbParentDirComb = 3U;
    } else {
        vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__when_DecoderNode_l114_2 = 0U;
        vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__when_DecoderNode_l114 = 0U;
        vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__absorbRegionIdComb = 0U;
    }
    if (vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__when_DecoderNode_l78) {
        vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__absorbParentDirComb = 2U;
        vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__absorbParentDirComb = 4U;
    }
    vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__absorbRegionIdComb = 0U;
    if (vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__when_DecoderNode_l78_3) {
        vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__absorbParentDirComb = 1U;
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
    vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__absorbParentDirComb = 0U;
    vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__absorbParentDirComb = 0U;
    if (vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__when_DecoderNode_l78_3) {
        vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__when_DecoderNode_l114_3 
            = (((IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__regionIdReg) 
                != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__regionIdReg)) 
               & (0U != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__regionIdReg)));
        vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__when_DecoderNode_l114 
            = (((IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__regionIdReg) 
                != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__regionIdReg)) 
               & (0U != (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__regionIdReg)));
        vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__absorbRegionIdComb = 0U;
        vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__absorbParentDirComb = 4U;
    } else {
        vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__when_DecoderNode_l114_3 = 0U;
        vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__when_DecoderNode_l114 = 0U;
        vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__absorbRegionIdComb = 0U;
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
    vlSelfRef.DecoderGrid__DOT__extractor__DOT____VdfgRegularize_hb2993a7d_0_3 
        = ((~ (IData)(vlSelfRef.io_nodePeeled_0)) & 
           (3U == (IData)(vlSelfRef.io_nodeStates_0)));
    vlSelfRef.DecoderGrid__DOT__extractor__DOT____VdfgRegularize_hb2993a7d_0_2 
        = ((~ (IData)(vlSelfRef.io_nodePeeled_1)) & 
           (3U == (IData)(vlSelfRef.io_nodeStates_1)));
    DecoderGrid__DOT__extractor__DOT____VdfgRegularize_hb2993a7d_0_1 
        = ((~ (IData)(vlSelfRef.io_nodePeeled_2)) & 
           (3U == (IData)(vlSelfRef.io_nodeStates_2)));
    vlSelfRef.DecoderGrid__DOT__extractor__DOT____VdfgRegularize_hb2993a7d_0_0 
        = ((~ (IData)(vlSelfRef.io_nodePeeled_3)) & 
           (3U == (IData)(vlSelfRef.io_nodeStates_3)));
    vlSelfRef.DecoderGrid__DOT__extractor__DOT___zz_correctionBits_2 
        = ((IData)(vlSelfRef.DecoderGrid__DOT__extractor__DOT____VdfgRegularize_hb2993a7d_0_3) 
           & (0U != (IData)(vlSelfRef.io_nodeParentDirs_0)));
    vlSelfRef.DecoderGrid__DOT__extractor__DOT___zz_correctionBits_3 
        = ((IData)(vlSelfRef.DecoderGrid__DOT__extractor__DOT____VdfgRegularize_hb2993a7d_0_3) 
           & ((0U != (IData)(vlSelfRef.io_nodeMatchDirs_0)) 
              & ((IData)(vlSelfRef.io_nodeRegionIds_0) 
                 < (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_0__DOT__matchedWith))));
    DecoderGrid__DOT__extractor__DOT___zz_correctionBits_6 
        = ((IData)(vlSelfRef.DecoderGrid__DOT__extractor__DOT____VdfgRegularize_hb2993a7d_0_2) 
           & (0U != (IData)(vlSelfRef.io_nodeParentDirs_1)));
    DecoderGrid__DOT__extractor__DOT___zz_correctionBits_7 
        = ((IData)(vlSelfRef.DecoderGrid__DOT__extractor__DOT____VdfgRegularize_hb2993a7d_0_2) 
           & ((0U != (IData)(vlSelfRef.io_nodeMatchDirs_1)) 
              & ((IData)(vlSelfRef.io_nodeRegionIds_1) 
                 < (IData)(vlSelfRef.DecoderGrid__DOT__nodes_0_1__DOT__matchedWith))));
    DecoderGrid__DOT__extractor__DOT___zz_correctionBits_10 
        = ((IData)(DecoderGrid__DOT__extractor__DOT____VdfgRegularize_hb2993a7d_0_1) 
           & (0U != (IData)(vlSelfRef.io_nodeParentDirs_2)));
    DecoderGrid__DOT__extractor__DOT___zz_correctionBits_11 
        = ((IData)(DecoderGrid__DOT__extractor__DOT____VdfgRegularize_hb2993a7d_0_1) 
           & ((0U != (IData)(vlSelfRef.io_nodeMatchDirs_2)) 
              & ((IData)(vlSelfRef.io_nodeRegionIds_2) 
                 < (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_0__DOT__matchedWith))));
    vlSelfRef.DecoderGrid__DOT__extractor__DOT___zz_correctionBits_14 
        = ((IData)(vlSelfRef.DecoderGrid__DOT__extractor__DOT____VdfgRegularize_hb2993a7d_0_0) 
           & (0U != (IData)(vlSelfRef.io_nodeParentDirs_3)));
    vlSelfRef.DecoderGrid__DOT__extractor__DOT___zz_correctionBits_15 
        = ((IData)(vlSelfRef.DecoderGrid__DOT__extractor__DOT____VdfgRegularize_hb2993a7d_0_0) 
           & ((0U != (IData)(vlSelfRef.io_nodeMatchDirs_3)) 
              & ((IData)(vlSelfRef.io_nodeRegionIds_3) 
                 < (IData)(vlSelfRef.DecoderGrid__DOT__nodes_1_1__DOT__matchedWith))));
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

VL_ATTR_COLD void VDecoderGrid___024root___eval_stl(VDecoderGrid___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderGrid___024root___eval_stl\n"); );
    VDecoderGrid__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        VDecoderGrid___024root___stl_sequent__TOP__0(vlSelf);
        VDecoderGrid___024root___stl_sequent__TOP__1(vlSelf);
    }
}

VL_ATTR_COLD bool VDecoderGrid___024root___eval_phase__stl(VDecoderGrid___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderGrid___024root___eval_phase__stl\n"); );
    VDecoderGrid__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    VDecoderGrid___024root___eval_triggers_vec__stl(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VDecoderGrid___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = VDecoderGrid___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        VDecoderGrid___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool VDecoderGrid___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void VDecoderGrid___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderGrid___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(VDecoderGrid___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(posedge reset)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VDecoderGrid___024root___ctor_var_reset(VDecoderGrid___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderGrid___024root___ctor_var_reset\n"); );
    VDecoderGrid__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->io_syndromeFrame = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 16567315907664085682ull);
    vlSelf->io_loadEnable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13799997085412980206ull);
    vlSelf->io_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9567792102730658101ull);
    vlSelf->io_reset_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15308010548512525927ull);
    vlSelf->io_nodeStates_0 = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 1097591530542591050ull);
    vlSelf->io_nodeStates_1 = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 15171257654326764248ull);
    vlSelf->io_nodeStates_2 = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 5180112009227850918ull);
    vlSelf->io_nodeStates_3 = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 14615039768483488308ull);
    vlSelf->io_nodeRegionIds_0 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 14869811760792767915ull);
    vlSelf->io_nodeRegionIds_1 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 14667503689698865002ull);
    vlSelf->io_nodeRegionIds_2 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 4718720263317153009ull);
    vlSelf->io_nodeRegionIds_3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 1829334864232695624ull);
    vlSelf->io_nodeParentDirs_0 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 18177025297169553392ull);
    vlSelf->io_nodeParentDirs_1 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 1964387669205348963ull);
    vlSelf->io_nodeParentDirs_2 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 5884249711566337296ull);
    vlSelf->io_nodeParentDirs_3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 16708231707659736179ull);
    vlSelf->io_nodeMatchDirs_0 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 6098636491705573174ull);
    vlSelf->io_nodeMatchDirs_1 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 4846298559870971207ull);
    vlSelf->io_nodeMatchDirs_2 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 415381184775172974ull);
    vlSelf->io_nodeMatchDirs_3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 6289755877034027689ull);
    vlSelf->io_nodePeeled_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6033075348400304827ull);
    vlSelf->io_nodePeeled_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13846483711163652347ull);
    vlSelf->io_nodePeeled_2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15938844921968219744ull);
    vlSelf->io_nodePeeled_3 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2501811625759683766ull);
    vlSelf->io_nodeSyndromes_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2097503093224875599ull);
    vlSelf->io_nodeSyndromes_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3604356267591698199ull);
    vlSelf->io_nodeSyndromes_2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2957759483382201102ull);
    vlSelf->io_nodeSyndromes_3 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15217232603861197159ull);
    vlSelf->io_correctionFlags = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 4398714236530212610ull);
    vlSelf->io_correction_bits = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 16776732036047606040ull);
    vlSelf->io_correction_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13218340254378961885ull);
    vlSelf->io_gridPhase = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 17785739860338481636ull);
    vlSelf->io_allMatched = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16911211021201006988ull);
    vlSelf->io_anyGrowing = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7942229743228194002ull);
    vlSelf->io_stall = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6299724908438797665ull);
    vlSelf->io_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3995589108428058558ull);
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9928399931838511862ull);
    vlSelf->DecoderGrid__DOT__phaseReg = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 14754136383925006962ull);
    vlSelf->DecoderGrid__DOT__cycleCount = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 17347947622324106483ull);
    vlSelf->DecoderGrid__DOT__stallReg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 508886496378962931ull);
    vlSelf->DecoderGrid__DOT__doneReg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5920111392944924737ull);
    vlSelf->DecoderGrid__DOT__peelingDone = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6334317694417964284ull);
    vlSelf->DecoderGrid__DOT__nodeStart = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12789675888385457932ull);
    vlSelf->DecoderGrid__DOT__nodeStartPeel = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2156046745931594609ull);
    vlSelf->DecoderGrid__DOT__when_DecoderGrid_l185 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11398936952622381464ull);
    vlSelf->DecoderGrid__DOT__when_DecoderGrid_l201 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14673246632913849240ull);
    vlSelf->DecoderGrid__DOT__nodes_0_0__DOT__stateReg = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 7645833566387280508ull);
    vlSelf->DecoderGrid__DOT__nodes_0_0__DOT__syndromeReg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6489948559309326856ull);
    vlSelf->DecoderGrid__DOT__nodes_0_0__DOT__regionIdReg = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 1285541922601107527ull);
    vlSelf->DecoderGrid__DOT__nodes_0_0__DOT__matchedWith = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 17451060599374520354ull);
    vlSelf->DecoderGrid__DOT__nodes_0_0__DOT__parentDirReg = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 9349908082329290062ull);
    vlSelf->DecoderGrid__DOT__nodes_0_0__DOT__matchDirReg = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 17736176150513611292ull);
    vlSelf->DecoderGrid__DOT__nodes_0_0__DOT__peeledReg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9408557797982565170ull);
    vlSelf->DecoderGrid__DOT__nodes_0_0__DOT__absorbRegionIdComb = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 4841384985970999856ull);
    vlSelf->DecoderGrid__DOT__nodes_0_0__DOT__absorbParentDirComb = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 9056082409357656115ull);
    vlSelf->DecoderGrid__DOT__nodes_0_0__DOT__when_DecoderNode_l114_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18209598545375227723ull);
    vlSelf->DecoderGrid__DOT__nodes_0_0__DOT__when_DecoderNode_l114_2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3210865785890303814ull);
    vlSelf->DecoderGrid__DOT__nodes_0_0__DOT__when_DecoderNode_l137 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1651870626913547237ull);
    vlSelf->DecoderGrid__DOT__nodes_0_0__DOT__when_DecoderNode_l144 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7413778565543590142ull);
    vlSelf->DecoderGrid__DOT__nodes_0_1__DOT__stateReg = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 3789615334502879143ull);
    vlSelf->DecoderGrid__DOT__nodes_0_1__DOT__syndromeReg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2897511282987768308ull);
    vlSelf->DecoderGrid__DOT__nodes_0_1__DOT__regionIdReg = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 3999549258553145593ull);
    vlSelf->DecoderGrid__DOT__nodes_0_1__DOT__matchedWith = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 5167093444841449321ull);
    vlSelf->DecoderGrid__DOT__nodes_0_1__DOT__parentDirReg = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 14609008188928245335ull);
    vlSelf->DecoderGrid__DOT__nodes_0_1__DOT__matchDirReg = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 3018592065457351828ull);
    vlSelf->DecoderGrid__DOT__nodes_0_1__DOT__peeledReg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4833325260994572513ull);
    vlSelf->DecoderGrid__DOT__nodes_0_1__DOT__absorbRegionIdComb = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 860472119984373456ull);
    vlSelf->DecoderGrid__DOT__nodes_0_1__DOT__absorbParentDirComb = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 11272619625274074311ull);
    vlSelf->DecoderGrid__DOT__nodes_0_1__DOT__when_DecoderNode_l114_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4213323105718145165ull);
    vlSelf->DecoderGrid__DOT__nodes_0_1__DOT__when_DecoderNode_l114_3 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2089776725313617940ull);
    vlSelf->DecoderGrid__DOT__nodes_0_1__DOT__when_DecoderNode_l137 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7456692050145817300ull);
    vlSelf->DecoderGrid__DOT__nodes_0_1__DOT__when_DecoderNode_l144 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3823201780666377428ull);
    vlSelf->DecoderGrid__DOT__nodes_1_0__DOT__stateReg = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 3653058803801416341ull);
    vlSelf->DecoderGrid__DOT__nodes_1_0__DOT__syndromeReg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 822330263521007452ull);
    vlSelf->DecoderGrid__DOT__nodes_1_0__DOT__regionIdReg = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 12423207816970843063ull);
    vlSelf->DecoderGrid__DOT__nodes_1_0__DOT__matchedWith = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 1060588731614823864ull);
    vlSelf->DecoderGrid__DOT__nodes_1_0__DOT__parentDirReg = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 3533337052329744560ull);
    vlSelf->DecoderGrid__DOT__nodes_1_0__DOT__matchDirReg = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 15620230553887807773ull);
    vlSelf->DecoderGrid__DOT__nodes_1_0__DOT__peeledReg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13351849933171506434ull);
    vlSelf->DecoderGrid__DOT__nodes_1_0__DOT__absorbRegionIdComb = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 1760107814883430378ull);
    vlSelf->DecoderGrid__DOT__nodes_1_0__DOT__absorbParentDirComb = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 8477751184427003348ull);
    vlSelf->DecoderGrid__DOT__nodes_1_0__DOT__when_DecoderNode_l78_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14882700770332641518ull);
    vlSelf->DecoderGrid__DOT__nodes_1_0__DOT__when_DecoderNode_l78_3 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17316039165090180395ull);
    vlSelf->DecoderGrid__DOT__nodes_1_0__DOT__when_DecoderNode_l114 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12960656145996662811ull);
    vlSelf->DecoderGrid__DOT__nodes_1_0__DOT__when_DecoderNode_l114_2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7421342009351731304ull);
    vlSelf->DecoderGrid__DOT__nodes_1_0__DOT__when_DecoderNode_l137 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4439961904450087385ull);
    vlSelf->DecoderGrid__DOT__nodes_1_0__DOT__when_DecoderNode_l144 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 587679801998568249ull);
    vlSelf->DecoderGrid__DOT__nodes_1_1__DOT__stateReg = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 12963254510245675637ull);
    vlSelf->DecoderGrid__DOT__nodes_1_1__DOT__syndromeReg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3042852532939630575ull);
    vlSelf->DecoderGrid__DOT__nodes_1_1__DOT__regionIdReg = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 5288732091361334919ull);
    vlSelf->DecoderGrid__DOT__nodes_1_1__DOT__matchedWith = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 14111599088326391747ull);
    vlSelf->DecoderGrid__DOT__nodes_1_1__DOT__parentDirReg = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 13757643766316243839ull);
    vlSelf->DecoderGrid__DOT__nodes_1_1__DOT__matchDirReg = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 1880776225744188407ull);
    vlSelf->DecoderGrid__DOT__nodes_1_1__DOT__peeledReg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14750967697795453887ull);
    vlSelf->DecoderGrid__DOT__nodes_1_1__DOT__absorbRegionIdComb = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 7598067860409695957ull);
    vlSelf->DecoderGrid__DOT__nodes_1_1__DOT__absorbParentDirComb = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 1988746617460279017ull);
    vlSelf->DecoderGrid__DOT__nodes_1_1__DOT__when_DecoderNode_l78 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3153009618623003680ull);
    vlSelf->DecoderGrid__DOT__nodes_1_1__DOT__when_DecoderNode_l78_3 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16388016692734744637ull);
    vlSelf->DecoderGrid__DOT__nodes_1_1__DOT__when_DecoderNode_l114 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18174276052579955777ull);
    vlSelf->DecoderGrid__DOT__nodes_1_1__DOT__when_DecoderNode_l114_3 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4863752532925676824ull);
    vlSelf->DecoderGrid__DOT__nodes_1_1__DOT__when_DecoderNode_l137 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7734601541987864461ull);
    vlSelf->DecoderGrid__DOT__nodes_1_1__DOT__when_DecoderNode_l144 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15701127230083604169ull);
    vlSelf->DecoderGrid__DOT__extractor__DOT___zz_correctionBits_2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3752639992737291531ull);
    vlSelf->DecoderGrid__DOT__extractor__DOT___zz_correctionBits_3 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1755910052131597448ull);
    vlSelf->DecoderGrid__DOT__extractor__DOT___zz_correctionBits_14 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11324606062235278198ull);
    vlSelf->DecoderGrid__DOT__extractor__DOT___zz_correctionBits_15 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16924026256183187965ull);
    vlSelf->DecoderGrid__DOT__extractor__DOT____VdfgRegularize_hb2993a7d_0_0 = 0;
    vlSelf->DecoderGrid__DOT__extractor__DOT____VdfgRegularize_hb2993a7d_0_2 = 0;
    vlSelf->DecoderGrid__DOT__extractor__DOT____VdfgRegularize_hb2993a7d_0_3 = 0;
    vlSelf->__Vdly__DecoderGrid__DOT__nodeStart = 0;
    vlSelf->__Vdly__DecoderGrid__DOT__nodeStartPeel = 0;
    vlSelf->__Vdly__DecoderGrid__DOT__nodes_0_0__DOT__stateReg = 0;
    vlSelf->__Vdly__DecoderGrid__DOT__nodes_0_0__DOT__regionIdReg = 0;
    vlSelf->__Vdly__DecoderGrid__DOT__nodes_0_1__DOT__stateReg = 0;
    vlSelf->__Vdly__DecoderGrid__DOT__nodes_1_0__DOT__stateReg = 0;
    vlSelf->__Vdly__DecoderGrid__DOT__nodes_1_1__DOT__stateReg = 0;
    vlSelf->__Vdly__DecoderGrid__DOT__nodes_1_1__DOT__regionIdReg = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__reset__0 = 0;
    vlSelf->__VactDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
