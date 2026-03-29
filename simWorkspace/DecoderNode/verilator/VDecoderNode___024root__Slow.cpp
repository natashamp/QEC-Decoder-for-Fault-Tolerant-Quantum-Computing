// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VDecoderNode.h for the primary calling header

#include "VDecoderNode__pch.h"

void VDecoderNode___024root___ctor_var_reset(VDecoderNode___024root* vlSelf);

VDecoderNode___024root::VDecoderNode___024root(VDecoderNode__Syms* symsp, const char* namep)
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    VDecoderNode___024root___ctor_var_reset(this);
}

void VDecoderNode___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VDecoderNode___024root::~VDecoderNode___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
