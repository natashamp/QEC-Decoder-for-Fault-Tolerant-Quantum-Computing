// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VDecoderNode.h for the primary calling header

#ifndef VERILATED_VDECODERNODE___024ROOT_H_
#define VERILATED_VDECODERNODE___024ROOT_H_  // guard

#include "verilated.h"


class VDecoderNode__Syms;

class alignas(VL_CACHE_LINE_BYTES) VDecoderNode___024root final {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(reset,0,0);
        VL_IN8(io_syndromeIn,0,0);
        VL_IN8(io_loadEnable,0,0);
        VL_IN8(io_start,0,0);
        VL_IN8(io_startPeel,0,0);
        VL_IN8(io_reset_n,0,0);
        VL_IN8(io_neighborIn_north_valid,0,0);
        VL_IN8(io_neighborIn_north_regionId,2,0);
        VL_IN8(io_neighborIn_north_grown,0,0);
        VL_IN8(io_neighborIn_north_parentDir,2,0);
        VL_IN8(io_neighborIn_north_peeled,0,0);
        VL_IN8(io_neighborIn_south_valid,0,0);
        VL_IN8(io_neighborIn_south_regionId,2,0);
        VL_IN8(io_neighborIn_south_grown,0,0);
        VL_IN8(io_neighborIn_south_parentDir,2,0);
        VL_IN8(io_neighborIn_south_peeled,0,0);
        VL_IN8(io_neighborIn_east_valid,0,0);
        VL_IN8(io_neighborIn_east_regionId,2,0);
        VL_IN8(io_neighborIn_east_grown,0,0);
        VL_IN8(io_neighborIn_east_parentDir,2,0);
        VL_IN8(io_neighborIn_east_peeled,0,0);
        VL_IN8(io_neighborIn_west_valid,0,0);
        VL_IN8(io_neighborIn_west_regionId,2,0);
        VL_IN8(io_neighborIn_west_grown,0,0);
        VL_IN8(io_neighborIn_west_parentDir,2,0);
        VL_IN8(io_neighborIn_west_peeled,0,0);
        VL_OUT8(io_linkOut_valid,0,0);
        VL_OUT8(io_linkOut_regionId,2,0);
        VL_OUT8(io_linkOut_grown,0,0);
        VL_OUT8(io_linkOut_parentDir,2,0);
        VL_OUT8(io_linkOut_peeled,0,0);
        VL_OUT8(io_state,1,0);
        VL_OUT8(io_regionId,2,0);
        VL_OUT8(io_correctionFlag,0,0);
        VL_OUT8(io_parentDir,2,0);
        VL_OUT8(io_matchDir,2,0);
        VL_OUT8(io_matchedWithId,2,0);
        VL_OUT8(io_peeled,0,0);
        VL_OUT8(io_syndrome,0,0);
        CData/*1:0*/ DecoderNode__DOT__stateReg;
        CData/*0:0*/ DecoderNode__DOT__syndromeReg;
        CData/*2:0*/ DecoderNode__DOT__regionIdReg;
        CData/*2:0*/ DecoderNode__DOT__matchedWith;
        CData/*2:0*/ DecoderNode__DOT__parentDirReg;
        CData/*2:0*/ DecoderNode__DOT__matchDirReg;
        CData/*0:0*/ DecoderNode__DOT__peeledReg;
        CData/*2:0*/ DecoderNode__DOT__absorbRegionIdComb;
        CData/*2:0*/ DecoderNode__DOT__absorbParentDirComb;
        CData/*0:0*/ DecoderNode__DOT__when_DecoderNode_l78;
        CData/*0:0*/ DecoderNode__DOT__when_DecoderNode_l78_1;
        CData/*0:0*/ DecoderNode__DOT__when_DecoderNode_l78_2;
        CData/*0:0*/ DecoderNode__DOT__when_DecoderNode_l78_3;
        CData/*0:0*/ DecoderNode__DOT__when_DecoderNode_l118;
        CData/*0:0*/ DecoderNode__DOT__when_DecoderNode_l118_1;
        CData/*0:0*/ DecoderNode__DOT__when_DecoderNode_l118_2;
        CData/*0:0*/ DecoderNode__DOT__when_DecoderNode_l118_3;
        CData/*0:0*/ DecoderNode__DOT__when_DecoderNode_l141;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VstlPhaseResult;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __VicoPhaseResult;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__reset__0;
    };
    struct {
        CData/*0:0*/ __VactDidInit;
        CData/*0:0*/ __VactPhaseResult;
        CData/*0:0*/ __VnbaPhaseResult;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    };

    // INTERNAL VARIABLES
    VDecoderNode__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    VDecoderNode___024root(VDecoderNode__Syms* symsp, const char* namep);
    ~VDecoderNode___024root();
    VL_UNCOPYABLE(VDecoderNode___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
