// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VDecoderGrid__pch.h"

//============================================================
// Constructors

VDecoderGrid::VDecoderGrid(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VDecoderGrid__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , reset{vlSymsp->TOP.reset}
    , io_syndromeFrame{vlSymsp->TOP.io_syndromeFrame}
    , io_loadEnable{vlSymsp->TOP.io_loadEnable}
    , io_start{vlSymsp->TOP.io_start}
    , io_reset_n{vlSymsp->TOP.io_reset_n}
    , io_nodeStates_0{vlSymsp->TOP.io_nodeStates_0}
    , io_nodeStates_1{vlSymsp->TOP.io_nodeStates_1}
    , io_nodeStates_2{vlSymsp->TOP.io_nodeStates_2}
    , io_nodeStates_3{vlSymsp->TOP.io_nodeStates_3}
    , io_nodeRegionIds_0{vlSymsp->TOP.io_nodeRegionIds_0}
    , io_nodeRegionIds_1{vlSymsp->TOP.io_nodeRegionIds_1}
    , io_nodeRegionIds_2{vlSymsp->TOP.io_nodeRegionIds_2}
    , io_nodeRegionIds_3{vlSymsp->TOP.io_nodeRegionIds_3}
    , io_nodeParentDirs_0{vlSymsp->TOP.io_nodeParentDirs_0}
    , io_nodeParentDirs_1{vlSymsp->TOP.io_nodeParentDirs_1}
    , io_nodeParentDirs_2{vlSymsp->TOP.io_nodeParentDirs_2}
    , io_nodeParentDirs_3{vlSymsp->TOP.io_nodeParentDirs_3}
    , io_nodeMatchDirs_0{vlSymsp->TOP.io_nodeMatchDirs_0}
    , io_nodeMatchDirs_1{vlSymsp->TOP.io_nodeMatchDirs_1}
    , io_nodeMatchDirs_2{vlSymsp->TOP.io_nodeMatchDirs_2}
    , io_nodeMatchDirs_3{vlSymsp->TOP.io_nodeMatchDirs_3}
    , io_nodePeeled_0{vlSymsp->TOP.io_nodePeeled_0}
    , io_nodePeeled_1{vlSymsp->TOP.io_nodePeeled_1}
    , io_nodePeeled_2{vlSymsp->TOP.io_nodePeeled_2}
    , io_nodePeeled_3{vlSymsp->TOP.io_nodePeeled_3}
    , io_nodeSyndromes_0{vlSymsp->TOP.io_nodeSyndromes_0}
    , io_nodeSyndromes_1{vlSymsp->TOP.io_nodeSyndromes_1}
    , io_nodeSyndromes_2{vlSymsp->TOP.io_nodeSyndromes_2}
    , io_nodeSyndromes_3{vlSymsp->TOP.io_nodeSyndromes_3}
    , io_correctionFlags{vlSymsp->TOP.io_correctionFlags}
    , io_correction_valid{vlSymsp->TOP.io_correction_valid}
    , io_gridPhase{vlSymsp->TOP.io_gridPhase}
    , io_allMatched{vlSymsp->TOP.io_allMatched}
    , io_anyGrowing{vlSymsp->TOP.io_anyGrowing}
    , io_stall{vlSymsp->TOP.io_stall}
    , io_done{vlSymsp->TOP.io_done}
    , io_correction_bits{vlSymsp->TOP.io_correction_bits}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VDecoderGrid::VDecoderGrid(const char* _vcname__)
    : VDecoderGrid(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VDecoderGrid::~VDecoderGrid() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VDecoderGrid___024root___eval_debug_assertions(VDecoderGrid___024root* vlSelf);
#endif  // VL_DEBUG
void VDecoderGrid___024root___eval_static(VDecoderGrid___024root* vlSelf);
void VDecoderGrid___024root___eval_initial(VDecoderGrid___024root* vlSelf);
void VDecoderGrid___024root___eval_settle(VDecoderGrid___024root* vlSelf);
void VDecoderGrid___024root___eval(VDecoderGrid___024root* vlSelf);

void VDecoderGrid::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VDecoderGrid::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VDecoderGrid___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VDecoderGrid___024root___eval_static(&(vlSymsp->TOP));
        VDecoderGrid___024root___eval_initial(&(vlSymsp->TOP));
        VDecoderGrid___024root___eval_settle(&(vlSymsp->TOP));
        vlSymsp->__Vm_didInit = true;
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VDecoderGrid___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VDecoderGrid::eventsPending() { return false; }

uint64_t VDecoderGrid::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VDecoderGrid::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VDecoderGrid___024root___eval_final(VDecoderGrid___024root* vlSelf);

VL_ATTR_COLD void VDecoderGrid::final() {
    VDecoderGrid___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VDecoderGrid::hierName() const { return vlSymsp->name(); }
const char* VDecoderGrid::modelName() const { return "VDecoderGrid"; }
unsigned VDecoderGrid::threads() const { return 1; }
void VDecoderGrid::prepareClone() const { contextp()->prepareClone(); }
void VDecoderGrid::atClone() const {
    contextp()->threadPoolpOnClone();
}
