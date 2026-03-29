// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VDecoderNode.h for the primary calling header

#include "VDecoderNode__pch.h"

VL_ATTR_COLD void VDecoderNode___024root___eval_static(VDecoderNode___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderNode___024root___eval_static\n"); );
    VDecoderNode__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__reset__0 = vlSelfRef.reset;
}

VL_ATTR_COLD void VDecoderNode___024root___eval_initial(VDecoderNode___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderNode___024root___eval_initial\n"); );
    VDecoderNode__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void VDecoderNode___024root___eval_final(VDecoderNode___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderNode___024root___eval_final\n"); );
    VDecoderNode__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VDecoderNode___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool VDecoderNode___024root___eval_phase__stl(VDecoderNode___024root* vlSelf);

VL_ATTR_COLD void VDecoderNode___024root___eval_settle(VDecoderNode___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderNode___024root___eval_settle\n"); );
    VDecoderNode__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            VDecoderNode___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("/Users/natashaprabhoo/git/QEC-Decoder-Sim/./simWorkspace/tmp/job_1/DecoderNode.v", 7, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 100 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        vlSelfRef.__VstlPhaseResult = VDecoderNode___024root___eval_phase__stl(vlSelf);
        vlSelfRef.__VstlFirstIteration = 0U;
    } while (vlSelfRef.__VstlPhaseResult);
}

VL_ATTR_COLD void VDecoderNode___024root___eval_triggers_vec__stl(VDecoderNode___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderNode___024root___eval_triggers_vec__stl\n"); );
    VDecoderNode__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
}

VL_ATTR_COLD bool VDecoderNode___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void VDecoderNode___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderNode___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(VDecoderNode___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool VDecoderNode___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderNode___024root___trigger_anySet__stl\n"); );
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

VL_ATTR_COLD void VDecoderNode___024root___stl_sequent__TOP__0(VDecoderNode___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderNode___024root___stl_sequent__TOP__0\n"); );
    VDecoderNode__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.io_linkOut_valid = (0U != (IData)(vlSelfRef.DecoderNode__DOT__stateReg));
    vlSelfRef.io_linkOut_regionId = vlSelfRef.DecoderNode__DOT__regionIdReg;
    vlSelfRef.io_linkOut_grown = (1U == (IData)(vlSelfRef.DecoderNode__DOT__stateReg));
    vlSelfRef.io_linkOut_parentDir = vlSelfRef.DecoderNode__DOT__parentDirReg;
    vlSelfRef.io_linkOut_peeled = vlSelfRef.DecoderNode__DOT__peeledReg;
    vlSelfRef.io_state = vlSelfRef.DecoderNode__DOT__stateReg;
    vlSelfRef.io_regionId = vlSelfRef.DecoderNode__DOT__regionIdReg;
    vlSelfRef.io_parentDir = vlSelfRef.DecoderNode__DOT__parentDirReg;
    vlSelfRef.io_matchDir = vlSelfRef.DecoderNode__DOT__matchDirReg;
    vlSelfRef.io_peeled = vlSelfRef.DecoderNode__DOT__peeledReg;
    vlSelfRef.io_syndrome = vlSelfRef.DecoderNode__DOT__syndromeReg;
    vlSelfRef.io_matchedWithId = vlSelfRef.DecoderNode__DOT__matchedWith;
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

VL_ATTR_COLD void VDecoderNode___024root___eval_stl(VDecoderNode___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderNode___024root___eval_stl\n"); );
    VDecoderNode__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        VDecoderNode___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD bool VDecoderNode___024root___eval_phase__stl(VDecoderNode___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderNode___024root___eval_phase__stl\n"); );
    VDecoderNode__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    VDecoderNode___024root___eval_triggers_vec__stl(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VDecoderNode___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = VDecoderNode___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        VDecoderNode___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool VDecoderNode___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void VDecoderNode___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderNode___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(VDecoderNode___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool VDecoderNode___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void VDecoderNode___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderNode___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(VDecoderNode___024root___trigger_anySet__act(triggers))))) {
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

VL_ATTR_COLD void VDecoderNode___024root___ctor_var_reset(VDecoderNode___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDecoderNode___024root___ctor_var_reset\n"); );
    VDecoderNode__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->io_syndromeIn = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6048825752748188398ull);
    vlSelf->io_loadEnable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13799997085412980206ull);
    vlSelf->io_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9567792102730658101ull);
    vlSelf->io_startPeel = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13957826559436008944ull);
    vlSelf->io_reset_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15308010548512525927ull);
    vlSelf->io_neighborIn_north_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4850430040548048305ull);
    vlSelf->io_neighborIn_north_regionId = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 1120746899119278496ull);
    vlSelf->io_neighborIn_north_grown = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10016412010850801968ull);
    vlSelf->io_neighborIn_north_parentDir = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 3357570873345413099ull);
    vlSelf->io_neighborIn_north_peeled = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6769591417312092354ull);
    vlSelf->io_neighborIn_south_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13434465725796697035ull);
    vlSelf->io_neighborIn_south_regionId = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 7289465230444996847ull);
    vlSelf->io_neighborIn_south_grown = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1343598169491783609ull);
    vlSelf->io_neighborIn_south_parentDir = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 14247260579269988971ull);
    vlSelf->io_neighborIn_south_peeled = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17532576915378123504ull);
    vlSelf->io_neighborIn_east_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8340179365316119301ull);
    vlSelf->io_neighborIn_east_regionId = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 5022682688515862710ull);
    vlSelf->io_neighborIn_east_grown = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17203382229463969521ull);
    vlSelf->io_neighborIn_east_parentDir = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 11534578671751826822ull);
    vlSelf->io_neighborIn_east_peeled = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10809129139369623620ull);
    vlSelf->io_neighborIn_west_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14063641620995912519ull);
    vlSelf->io_neighborIn_west_regionId = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 5616091787876939041ull);
    vlSelf->io_neighborIn_west_grown = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 50986693305766562ull);
    vlSelf->io_neighborIn_west_parentDir = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 11557613345202489633ull);
    vlSelf->io_neighborIn_west_peeled = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5939396055908871487ull);
    vlSelf->io_linkOut_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8035518897892699205ull);
    vlSelf->io_linkOut_regionId = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 5968303373343270519ull);
    vlSelf->io_linkOut_grown = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12434771013211126807ull);
    vlSelf->io_linkOut_parentDir = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 7320632065956020231ull);
    vlSelf->io_linkOut_peeled = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11084276296983756205ull);
    vlSelf->io_state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 812261662441317844ull);
    vlSelf->io_regionId = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 17214941769361243014ull);
    vlSelf->io_correctionFlag = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4443560791757935648ull);
    vlSelf->io_parentDir = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 7908868295631537095ull);
    vlSelf->io_matchDir = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 2632958189118044931ull);
    vlSelf->io_matchedWithId = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 12051577463437916784ull);
    vlSelf->io_peeled = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14764377340717545751ull);
    vlSelf->io_syndrome = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17502824005840546288ull);
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9928399931838511862ull);
    vlSelf->DecoderNode__DOT__stateReg = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 3851618104315874518ull);
    vlSelf->DecoderNode__DOT__syndromeReg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2138551325699185393ull);
    vlSelf->DecoderNode__DOT__regionIdReg = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 15791514750148025651ull);
    vlSelf->DecoderNode__DOT__matchedWith = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 5597151246174251436ull);
    vlSelf->DecoderNode__DOT__parentDirReg = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 17692355425445325846ull);
    vlSelf->DecoderNode__DOT__matchDirReg = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 9237480103324702161ull);
    vlSelf->DecoderNode__DOT__peeledReg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8502221142936314514ull);
    vlSelf->DecoderNode__DOT__absorbRegionIdComb = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 13995696072618987536ull);
    vlSelf->DecoderNode__DOT__absorbParentDirComb = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 510822528606419093ull);
    vlSelf->DecoderNode__DOT__when_DecoderNode_l78 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12661114078224690750ull);
    vlSelf->DecoderNode__DOT__when_DecoderNode_l78_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2480336525967616389ull);
    vlSelf->DecoderNode__DOT__when_DecoderNode_l78_2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9066612199391391595ull);
    vlSelf->DecoderNode__DOT__when_DecoderNode_l78_3 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 266123755539383338ull);
    vlSelf->DecoderNode__DOT__when_DecoderNode_l118 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8774111059165262485ull);
    vlSelf->DecoderNode__DOT__when_DecoderNode_l118_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11565585103753527289ull);
    vlSelf->DecoderNode__DOT__when_DecoderNode_l118_2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8418363465492799597ull);
    vlSelf->DecoderNode__DOT__when_DecoderNode_l118_3 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 473481579521086684ull);
    vlSelf->DecoderNode__DOT__when_DecoderNode_l141 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15838394666697610758ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
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
