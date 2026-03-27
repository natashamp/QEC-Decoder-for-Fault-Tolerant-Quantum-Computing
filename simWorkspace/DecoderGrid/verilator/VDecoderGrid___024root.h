// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VDecoderGrid.h for the primary calling header

#ifndef VERILATED_VDECODERGRID___024ROOT_H_
#define VERILATED_VDECODERGRID___024ROOT_H_  // guard

#include "verilated.h"


class VDecoderGrid__Syms;

class alignas(VL_CACHE_LINE_BYTES) VDecoderGrid___024root final {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(reset,0,0);
        VL_IN8(io_syndromeFrame,3,0);
        VL_IN8(io_loadEnable,0,0);
        VL_IN8(io_start,0,0);
        VL_IN8(io_reset_n,0,0);
        VL_OUT8(io_nodeStates_0,1,0);
        VL_OUT8(io_nodeStates_1,1,0);
        VL_OUT8(io_nodeStates_2,1,0);
        VL_OUT8(io_nodeStates_3,1,0);
        VL_OUT8(io_nodeRegionIds_0,2,0);
        VL_OUT8(io_nodeRegionIds_1,2,0);
        VL_OUT8(io_nodeRegionIds_2,2,0);
        VL_OUT8(io_nodeRegionIds_3,2,0);
        VL_OUT8(io_nodeParentDirs_0,2,0);
        VL_OUT8(io_nodeParentDirs_1,2,0);
        VL_OUT8(io_nodeParentDirs_2,2,0);
        VL_OUT8(io_nodeParentDirs_3,2,0);
        VL_OUT8(io_nodeMatchDirs_0,2,0);
        VL_OUT8(io_nodeMatchDirs_1,2,0);
        VL_OUT8(io_nodeMatchDirs_2,2,0);
        VL_OUT8(io_nodeMatchDirs_3,2,0);
        VL_OUT8(io_nodePeeled_0,0,0);
        VL_OUT8(io_nodePeeled_1,0,0);
        VL_OUT8(io_nodePeeled_2,0,0);
        VL_OUT8(io_nodePeeled_3,0,0);
        VL_OUT8(io_nodeSyndromes_0,0,0);
        VL_OUT8(io_nodeSyndromes_1,0,0);
        VL_OUT8(io_nodeSyndromes_2,0,0);
        VL_OUT8(io_nodeSyndromes_3,0,0);
        VL_OUT8(io_correctionFlags,3,0);
        VL_OUT8(io_correction_valid,0,0);
        VL_OUT8(io_gridPhase,2,0);
        VL_OUT8(io_allMatched,0,0);
        VL_OUT8(io_anyGrowing,0,0);
        VL_OUT8(io_stall,0,0);
        VL_OUT8(io_done,0,0);
        CData/*2:0*/ DecoderGrid__DOT__phaseReg;
        CData/*3:0*/ DecoderGrid__DOT__cycleCount;
        CData/*0:0*/ DecoderGrid__DOT__stallReg;
        CData/*0:0*/ DecoderGrid__DOT__doneReg;
        CData/*0:0*/ DecoderGrid__DOT__peelingDone;
        CData/*0:0*/ DecoderGrid__DOT__nodeStart;
        CData/*0:0*/ DecoderGrid__DOT__nodeStartPeel;
        CData/*0:0*/ DecoderGrid__DOT__when_DecoderGrid_l185;
        CData/*0:0*/ DecoderGrid__DOT__when_DecoderGrid_l201;
        CData/*1:0*/ DecoderGrid__DOT__nodes_0_0__DOT__stateReg;
        CData/*0:0*/ DecoderGrid__DOT__nodes_0_0__DOT__syndromeReg;
        CData/*2:0*/ DecoderGrid__DOT__nodes_0_0__DOT__regionIdReg;
        CData/*2:0*/ DecoderGrid__DOT__nodes_0_0__DOT__matchedWith;
        CData/*2:0*/ DecoderGrid__DOT__nodes_0_0__DOT__parentDirReg;
        CData/*2:0*/ DecoderGrid__DOT__nodes_0_0__DOT__matchDirReg;
        CData/*0:0*/ DecoderGrid__DOT__nodes_0_0__DOT__peeledReg;
        CData/*2:0*/ DecoderGrid__DOT__nodes_0_0__DOT__absorbRegionIdComb;
        CData/*2:0*/ DecoderGrid__DOT__nodes_0_0__DOT__absorbParentDirComb;
        CData/*0:0*/ DecoderGrid__DOT__nodes_0_0__DOT__when_DecoderNode_l114_1;
        CData/*0:0*/ DecoderGrid__DOT__nodes_0_0__DOT__when_DecoderNode_l114_2;
        CData/*0:0*/ DecoderGrid__DOT__nodes_0_0__DOT__when_DecoderNode_l137;
        CData/*0:0*/ DecoderGrid__DOT__nodes_0_0__DOT__when_DecoderNode_l144;
        CData/*1:0*/ DecoderGrid__DOT__nodes_0_1__DOT__stateReg;
        CData/*0:0*/ DecoderGrid__DOT__nodes_0_1__DOT__syndromeReg;
        CData/*2:0*/ DecoderGrid__DOT__nodes_0_1__DOT__regionIdReg;
        CData/*2:0*/ DecoderGrid__DOT__nodes_0_1__DOT__matchedWith;
        CData/*2:0*/ DecoderGrid__DOT__nodes_0_1__DOT__parentDirReg;
    };
    struct {
        CData/*2:0*/ DecoderGrid__DOT__nodes_0_1__DOT__matchDirReg;
        CData/*0:0*/ DecoderGrid__DOT__nodes_0_1__DOT__peeledReg;
        CData/*2:0*/ DecoderGrid__DOT__nodes_0_1__DOT__absorbRegionIdComb;
        CData/*2:0*/ DecoderGrid__DOT__nodes_0_1__DOT__absorbParentDirComb;
        CData/*0:0*/ DecoderGrid__DOT__nodes_0_1__DOT__when_DecoderNode_l114_1;
        CData/*0:0*/ DecoderGrid__DOT__nodes_0_1__DOT__when_DecoderNode_l114_3;
        CData/*0:0*/ DecoderGrid__DOT__nodes_0_1__DOT__when_DecoderNode_l137;
        CData/*0:0*/ DecoderGrid__DOT__nodes_0_1__DOT__when_DecoderNode_l144;
        CData/*1:0*/ DecoderGrid__DOT__nodes_1_0__DOT__stateReg;
        CData/*0:0*/ DecoderGrid__DOT__nodes_1_0__DOT__syndromeReg;
        CData/*2:0*/ DecoderGrid__DOT__nodes_1_0__DOT__regionIdReg;
        CData/*2:0*/ DecoderGrid__DOT__nodes_1_0__DOT__matchedWith;
        CData/*2:0*/ DecoderGrid__DOT__nodes_1_0__DOT__parentDirReg;
        CData/*2:0*/ DecoderGrid__DOT__nodes_1_0__DOT__matchDirReg;
        CData/*0:0*/ DecoderGrid__DOT__nodes_1_0__DOT__peeledReg;
        CData/*2:0*/ DecoderGrid__DOT__nodes_1_0__DOT__absorbRegionIdComb;
        CData/*2:0*/ DecoderGrid__DOT__nodes_1_0__DOT__absorbParentDirComb;
        CData/*0:0*/ DecoderGrid__DOT__nodes_1_0__DOT__when_DecoderNode_l78_1;
        CData/*0:0*/ DecoderGrid__DOT__nodes_1_0__DOT__when_DecoderNode_l78_3;
        CData/*0:0*/ DecoderGrid__DOT__nodes_1_0__DOT__when_DecoderNode_l114;
        CData/*0:0*/ DecoderGrid__DOT__nodes_1_0__DOT__when_DecoderNode_l114_2;
        CData/*0:0*/ DecoderGrid__DOT__nodes_1_0__DOT__when_DecoderNode_l137;
        CData/*0:0*/ DecoderGrid__DOT__nodes_1_0__DOT__when_DecoderNode_l144;
        CData/*1:0*/ DecoderGrid__DOT__nodes_1_1__DOT__stateReg;
        CData/*0:0*/ DecoderGrid__DOT__nodes_1_1__DOT__syndromeReg;
        CData/*2:0*/ DecoderGrid__DOT__nodes_1_1__DOT__regionIdReg;
        CData/*2:0*/ DecoderGrid__DOT__nodes_1_1__DOT__matchedWith;
        CData/*2:0*/ DecoderGrid__DOT__nodes_1_1__DOT__parentDirReg;
        CData/*2:0*/ DecoderGrid__DOT__nodes_1_1__DOT__matchDirReg;
        CData/*0:0*/ DecoderGrid__DOT__nodes_1_1__DOT__peeledReg;
        CData/*2:0*/ DecoderGrid__DOT__nodes_1_1__DOT__absorbRegionIdComb;
        CData/*2:0*/ DecoderGrid__DOT__nodes_1_1__DOT__absorbParentDirComb;
        CData/*0:0*/ DecoderGrid__DOT__nodes_1_1__DOT__when_DecoderNode_l78;
        CData/*0:0*/ DecoderGrid__DOT__nodes_1_1__DOT__when_DecoderNode_l78_3;
        CData/*0:0*/ DecoderGrid__DOT__nodes_1_1__DOT__when_DecoderNode_l114;
        CData/*0:0*/ DecoderGrid__DOT__nodes_1_1__DOT__when_DecoderNode_l114_3;
        CData/*0:0*/ DecoderGrid__DOT__nodes_1_1__DOT__when_DecoderNode_l137;
        CData/*0:0*/ DecoderGrid__DOT__nodes_1_1__DOT__when_DecoderNode_l144;
        CData/*0:0*/ DecoderGrid__DOT__extractor__DOT___zz_correctionBits_2;
        CData/*0:0*/ DecoderGrid__DOT__extractor__DOT___zz_correctionBits_3;
        CData/*0:0*/ DecoderGrid__DOT__extractor__DOT___zz_correctionBits_14;
        CData/*0:0*/ DecoderGrid__DOT__extractor__DOT___zz_correctionBits_15;
        CData/*0:0*/ DecoderGrid__DOT__extractor__DOT____VdfgRegularize_hb2993a7d_0_0;
        CData/*0:0*/ DecoderGrid__DOT__extractor__DOT____VdfgRegularize_hb2993a7d_0_2;
        CData/*0:0*/ DecoderGrid__DOT__extractor__DOT____VdfgRegularize_hb2993a7d_0_3;
        CData/*0:0*/ __Vdly__DecoderGrid__DOT__nodeStart;
        CData/*0:0*/ __Vdly__DecoderGrid__DOT__nodeStartPeel;
        CData/*1:0*/ __Vdly__DecoderGrid__DOT__nodes_0_0__DOT__stateReg;
        CData/*2:0*/ __Vdly__DecoderGrid__DOT__nodes_0_0__DOT__regionIdReg;
        CData/*1:0*/ __Vdly__DecoderGrid__DOT__nodes_0_1__DOT__stateReg;
        CData/*1:0*/ __Vdly__DecoderGrid__DOT__nodes_1_0__DOT__stateReg;
        CData/*1:0*/ __Vdly__DecoderGrid__DOT__nodes_1_1__DOT__stateReg;
        CData/*2:0*/ __Vdly__DecoderGrid__DOT__nodes_1_1__DOT__regionIdReg;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VstlPhaseResult;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__reset__0;
        CData/*0:0*/ __VactDidInit;
        CData/*0:0*/ __VactPhaseResult;
        CData/*0:0*/ __VnbaPhaseResult;
        VL_OUT16(io_correction_bits,8,0);
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    };
    struct {
        VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    };

    // INTERNAL VARIABLES
    VDecoderGrid__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    VDecoderGrid___024root(VDecoderGrid__Syms* symsp, const char* namep);
    ~VDecoderGrid___024root();
    VL_UNCOPYABLE(VDecoderGrid___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
