// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VDecoderNode__pch.h"

//============================================================
// Constructors

VDecoderNode::VDecoderNode(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VDecoderNode__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , reset{vlSymsp->TOP.reset}
    , io_syndromeIn{vlSymsp->TOP.io_syndromeIn}
    , io_loadEnable{vlSymsp->TOP.io_loadEnable}
    , io_start{vlSymsp->TOP.io_start}
    , io_startPeel{vlSymsp->TOP.io_startPeel}
    , io_reset_n{vlSymsp->TOP.io_reset_n}
    , io_neighborIn_north_valid{vlSymsp->TOP.io_neighborIn_north_valid}
    , io_neighborIn_north_regionId{vlSymsp->TOP.io_neighborIn_north_regionId}
    , io_neighborIn_north_grown{vlSymsp->TOP.io_neighborIn_north_grown}
    , io_neighborIn_north_parentDir{vlSymsp->TOP.io_neighborIn_north_parentDir}
    , io_neighborIn_north_peeled{vlSymsp->TOP.io_neighborIn_north_peeled}
    , io_neighborIn_south_valid{vlSymsp->TOP.io_neighborIn_south_valid}
    , io_neighborIn_south_regionId{vlSymsp->TOP.io_neighborIn_south_regionId}
    , io_neighborIn_south_grown{vlSymsp->TOP.io_neighborIn_south_grown}
    , io_neighborIn_south_parentDir{vlSymsp->TOP.io_neighborIn_south_parentDir}
    , io_neighborIn_south_peeled{vlSymsp->TOP.io_neighborIn_south_peeled}
    , io_neighborIn_east_valid{vlSymsp->TOP.io_neighborIn_east_valid}
    , io_neighborIn_east_regionId{vlSymsp->TOP.io_neighborIn_east_regionId}
    , io_neighborIn_east_grown{vlSymsp->TOP.io_neighborIn_east_grown}
    , io_neighborIn_east_parentDir{vlSymsp->TOP.io_neighborIn_east_parentDir}
    , io_neighborIn_east_peeled{vlSymsp->TOP.io_neighborIn_east_peeled}
    , io_neighborIn_west_valid{vlSymsp->TOP.io_neighborIn_west_valid}
    , io_neighborIn_west_regionId{vlSymsp->TOP.io_neighborIn_west_regionId}
    , io_neighborIn_west_grown{vlSymsp->TOP.io_neighborIn_west_grown}
    , io_neighborIn_west_parentDir{vlSymsp->TOP.io_neighborIn_west_parentDir}
    , io_neighborIn_west_peeled{vlSymsp->TOP.io_neighborIn_west_peeled}
    , io_linkOut_valid{vlSymsp->TOP.io_linkOut_valid}
    , io_linkOut_regionId{vlSymsp->TOP.io_linkOut_regionId}
    , io_linkOut_grown{vlSymsp->TOP.io_linkOut_grown}
    , io_linkOut_parentDir{vlSymsp->TOP.io_linkOut_parentDir}
    , io_linkOut_peeled{vlSymsp->TOP.io_linkOut_peeled}
    , io_state{vlSymsp->TOP.io_state}
    , io_regionId{vlSymsp->TOP.io_regionId}
    , io_correctionFlag{vlSymsp->TOP.io_correctionFlag}
    , io_parentDir{vlSymsp->TOP.io_parentDir}
    , io_matchDir{vlSymsp->TOP.io_matchDir}
    , io_matchedWithId{vlSymsp->TOP.io_matchedWithId}
    , io_peeled{vlSymsp->TOP.io_peeled}
    , io_syndrome{vlSymsp->TOP.io_syndrome}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VDecoderNode::VDecoderNode(const char* _vcname__)
    : VDecoderNode(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VDecoderNode::~VDecoderNode() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VDecoderNode___024root___eval_debug_assertions(VDecoderNode___024root* vlSelf);
#endif  // VL_DEBUG
void VDecoderNode___024root___eval_static(VDecoderNode___024root* vlSelf);
void VDecoderNode___024root___eval_initial(VDecoderNode___024root* vlSelf);
void VDecoderNode___024root___eval_settle(VDecoderNode___024root* vlSelf);
void VDecoderNode___024root___eval(VDecoderNode___024root* vlSelf);

void VDecoderNode::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VDecoderNode::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VDecoderNode___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VDecoderNode___024root___eval_static(&(vlSymsp->TOP));
        VDecoderNode___024root___eval_initial(&(vlSymsp->TOP));
        VDecoderNode___024root___eval_settle(&(vlSymsp->TOP));
        vlSymsp->__Vm_didInit = true;
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VDecoderNode___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VDecoderNode::eventsPending() { return false; }

uint64_t VDecoderNode::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VDecoderNode::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VDecoderNode___024root___eval_final(VDecoderNode___024root* vlSelf);

VL_ATTR_COLD void VDecoderNode::final() {
    VDecoderNode___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VDecoderNode::hierName() const { return vlSymsp->name(); }
const char* VDecoderNode::modelName() const { return "VDecoderNode"; }
unsigned VDecoderNode::threads() const { return 1; }
void VDecoderNode::prepareClone() const { contextp()->prepareClone(); }
void VDecoderNode::atClone() const {
    contextp()->threadPoolpOnClone();
}
