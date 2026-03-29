// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary model header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VDECODERNODE_H_
#define VERILATED_VDECODERNODE_H_  // guard

#include "verilated.h"

class VDecoderNode__Syms;
class VDecoderNode___024root;

// This class is the main interface to the Verilated model
class alignas(VL_CACHE_LINE_BYTES) VDecoderNode VL_NOT_FINAL : public VerilatedModel {
  private:
    // Symbol table holding complete model state (owned by this class)
    VDecoderNode__Syms* const vlSymsp;

  public:

    // CONSTEXPR CAPABILITIES
    // Verilated with --trace?
    static constexpr bool traceCapable = false;

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(&clk,0,0);
    VL_IN8(&reset,0,0);
    VL_IN8(&io_syndromeIn,0,0);
    VL_IN8(&io_loadEnable,0,0);
    VL_IN8(&io_start,0,0);
    VL_IN8(&io_startPeel,0,0);
    VL_IN8(&io_reset_n,0,0);
    VL_IN8(&io_neighborIn_north_valid,0,0);
    VL_IN8(&io_neighborIn_north_regionId,2,0);
    VL_IN8(&io_neighborIn_north_grown,0,0);
    VL_IN8(&io_neighborIn_north_parentDir,2,0);
    VL_IN8(&io_neighborIn_north_peeled,0,0);
    VL_IN8(&io_neighborIn_south_valid,0,0);
    VL_IN8(&io_neighborIn_south_regionId,2,0);
    VL_IN8(&io_neighborIn_south_grown,0,0);
    VL_IN8(&io_neighborIn_south_parentDir,2,0);
    VL_IN8(&io_neighborIn_south_peeled,0,0);
    VL_IN8(&io_neighborIn_east_valid,0,0);
    VL_IN8(&io_neighborIn_east_regionId,2,0);
    VL_IN8(&io_neighborIn_east_grown,0,0);
    VL_IN8(&io_neighborIn_east_parentDir,2,0);
    VL_IN8(&io_neighborIn_east_peeled,0,0);
    VL_IN8(&io_neighborIn_west_valid,0,0);
    VL_IN8(&io_neighborIn_west_regionId,2,0);
    VL_IN8(&io_neighborIn_west_grown,0,0);
    VL_IN8(&io_neighborIn_west_parentDir,2,0);
    VL_IN8(&io_neighborIn_west_peeled,0,0);
    VL_OUT8(&io_linkOut_valid,0,0);
    VL_OUT8(&io_linkOut_regionId,2,0);
    VL_OUT8(&io_linkOut_grown,0,0);
    VL_OUT8(&io_linkOut_parentDir,2,0);
    VL_OUT8(&io_linkOut_peeled,0,0);
    VL_OUT8(&io_state,1,0);
    VL_OUT8(&io_regionId,2,0);
    VL_OUT8(&io_correctionFlag,0,0);
    VL_OUT8(&io_parentDir,2,0);
    VL_OUT8(&io_matchDir,2,0);
    VL_OUT8(&io_matchedWithId,2,0);
    VL_OUT8(&io_peeled,0,0);
    VL_OUT8(&io_syndrome,0,0);

    // CELLS
    // Public to allow access to /* verilator public */ items.
    // Otherwise the application code can consider these internals.

    // Root instance pointer to allow access to model internals,
    // including inlined /* verilator public_flat_* */ items.
    VDecoderNode___024root* const rootp;

    // CONSTRUCTORS
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    explicit VDecoderNode(VerilatedContext* contextp, const char* name = "TOP");
    explicit VDecoderNode(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    virtual ~VDecoderNode();
  private:
    VL_UNCOPYABLE(VDecoderNode);  ///< Copying not allowed

  public:
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    /// Are there scheduled events to handle?
    bool eventsPending();
    /// Returns time at next time slot. Aborts if !eventsPending()
    uint64_t nextTimeSlot();
    /// Trace signals in the model; called by application code
    void trace(VerilatedTraceBaseC* tfp, int levels, int options = 0) { contextp()->trace(tfp, levels, options); }
    /// Retrieve name of this model instance (as passed to constructor).
    const char* name() const;

    // Abstract methods from VerilatedModel
    const char* hierName() const override final;
    const char* modelName() const override final;
    unsigned threads() const override final;
    /// Prepare for cloning the model at the process level (e.g. fork in Linux)
    /// Release necessary resources. Called before cloning.
    void prepareClone() const;
    /// Re-init after cloning the model at the process level (e.g. fork in Linux)
    /// Re-allocate necessary resources. Called after cloning.
    void atClone() const;
  private:
    // Internal functions - trace registration
    void traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options);
};

#endif  // guard
