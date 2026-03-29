// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VDECODERNODE__SYMS_H_
#define VERILATED_VDECODERNODE__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "VDecoderNode.h"

// INCLUDE MODULE CLASSES
#include "VDecoderNode___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) VDecoderNode__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VDecoderNode* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VDecoderNode___024root         TOP;

    // CONSTRUCTORS
    VDecoderNode__Syms(VerilatedContext* contextp, const char* namep, VDecoderNode* modelp);
    ~VDecoderNode__Syms();

    // METHODS
    const char* name() const { return TOP.vlNamep; }
};

#endif  // guard
