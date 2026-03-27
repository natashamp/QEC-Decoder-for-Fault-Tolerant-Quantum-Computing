// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VDECODERGRID__SYMS_H_
#define VERILATED_VDECODERGRID__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "VDecoderGrid.h"

// INCLUDE MODULE CLASSES
#include "VDecoderGrid___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) VDecoderGrid__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VDecoderGrid* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VDecoderGrid___024root         TOP;

    // CONSTRUCTORS
    VDecoderGrid__Syms(VerilatedContext* contextp, const char* namep, VDecoderGrid* modelp);
    ~VDecoderGrid__Syms();

    // METHODS
    const char* name() const { return TOP.vlNamep; }
};

#endif  // guard
