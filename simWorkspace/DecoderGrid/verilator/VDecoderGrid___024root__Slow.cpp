// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VDecoderGrid.h for the primary calling header

#include "VDecoderGrid__pch.h"

void VDecoderGrid___024root___ctor_var_reset(VDecoderGrid___024root* vlSelf);

VDecoderGrid___024root::VDecoderGrid___024root(VDecoderGrid__Syms* symsp, const char* namep)
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    VDecoderGrid___024root___ctor_var_reset(this);
}

void VDecoderGrid___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VDecoderGrid___024root::~VDecoderGrid___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
