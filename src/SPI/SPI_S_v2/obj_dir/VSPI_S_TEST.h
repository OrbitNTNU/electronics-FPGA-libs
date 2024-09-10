// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VSPI_S_TEST_H_
#define _VSPI_S_TEST_H_  // guard

#include "verilated.h"

//==========

class VSPI_S_TEST__Syms;
class VSPI_S_TEST_VerilatedVcd;


//----------

VL_MODULE(VSPI_S_TEST) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(CLK_t,0,0);
    VL_IN8(MOSI_t,0,0);
    VL_IN8(SC_t,0,0);
    VL_OUT8(MISO_t,0,0);
    VL_OUT8(led,0,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ SPI_S_TEST__DOT__send_enable;
    CData/*0:0*/ SPI_S_TEST__DOT__msg_recieved;
    CData/*0:0*/ SPI_S_TEST__DOT__msg_sendt;
    CData/*4:0*/ SPI_S_TEST__DOT__SPI_INST__DOT__recieve_bit_counter;
    CData/*4:0*/ SPI_S_TEST__DOT__SPI_INST__DOT__send_bit_counter;
    CData/*0:0*/ SPI_S_TEST__DOT__SPI_INST__DOT__msg_recieved;
    CData/*0:0*/ SPI_S_TEST__DOT__SPI_INST__DOT__msg_sendt;
    CData/*0:0*/ SPI_S_TEST__DOT__SPI_INST__DOT__MISO_o;
    IData/*31:0*/ SPI_S_TEST__DOT__output_data;
    IData/*31:0*/ SPI_S_TEST__DOT__data_recieved;
    IData/*31:0*/ SPI_S_TEST__DOT__SPI_INST__DOT__MOSI_Data;
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__CLK_t;
    CData/*0:0*/ __Vm_traceActivity[3];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VSPI_S_TEST__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VSPI_S_TEST);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    VSPI_S_TEST(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VSPI_S_TEST();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
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
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VSPI_S_TEST__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VSPI_S_TEST__Syms* symsp, bool first);
  private:
    static QData _change_request(VSPI_S_TEST__Syms* __restrict vlSymsp);
    static QData _change_request_1(VSPI_S_TEST__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(VSPI_S_TEST__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(VSPI_S_TEST__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(VSPI_S_TEST__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__2(VSPI_S_TEST__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _multiclk__TOP__6(VSPI_S_TEST__Syms* __restrict vlSymsp);
    static void _sequent__TOP__3(VSPI_S_TEST__Syms* __restrict vlSymsp);
    static void _sequent__TOP__4(VSPI_S_TEST__Syms* __restrict vlSymsp);
    static void _settle__TOP__1(VSPI_S_TEST__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _settle__TOP__5(VSPI_S_TEST__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceChgSub0(void* userp, VerilatedVcd* tracep);
    static void traceChgTop0(void* userp, VerilatedVcd* tracep);
    static void traceCleanup(void* userp, VerilatedVcd* /*unused*/);
    static void traceFullSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceFullTop0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitTop(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    void traceRegister(VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
