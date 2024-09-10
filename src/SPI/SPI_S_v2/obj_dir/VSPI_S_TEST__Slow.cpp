// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSPI_S_TEST.h for the primary calling header

#include "VSPI_S_TEST.h"
#include "VSPI_S_TEST__Syms.h"

//==========

VL_CTOR_IMP(VSPI_S_TEST) {
    VSPI_S_TEST__Syms* __restrict vlSymsp = __VlSymsp = new VSPI_S_TEST__Syms(this, name());
    VSPI_S_TEST* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VSPI_S_TEST::__Vconfigure(VSPI_S_TEST__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

VSPI_S_TEST::~VSPI_S_TEST() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void VSPI_S_TEST::_settle__TOP__1(VSPI_S_TEST__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSPI_S_TEST::_settle__TOP__1\n"); );
    VSPI_S_TEST* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->led = 1U;
    vlTOPp->SPI_S_TEST__DOT__msg_sendt = vlTOPp->SPI_S_TEST__DOT__SPI_INST__DOT__msg_sendt;
    vlTOPp->SPI_S_TEST__DOT__msg_recieved = vlTOPp->SPI_S_TEST__DOT__SPI_INST__DOT__msg_recieved;
}

void VSPI_S_TEST::_initial__TOP__2(VSPI_S_TEST__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSPI_S_TEST::_initial__TOP__2\n"); );
    VSPI_S_TEST* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->SPI_S_TEST__DOT__SPI_INST__DOT__MISO_o = 0U;
    vlTOPp->SPI_S_TEST__DOT__data_recieved = 0U;
    vlTOPp->SPI_S_TEST__DOT__msg_sendt = 0U;
    vlTOPp->SPI_S_TEST__DOT__msg_recieved = 0U;
    vlTOPp->SPI_S_TEST__DOT__SPI_INST__DOT__MOSI_Data = 0U;
    vlTOPp->SPI_S_TEST__DOT__SPI_INST__DOT__recieve_bit_counter = 0U;
    vlTOPp->SPI_S_TEST__DOT__SPI_INST__DOT__send_bit_counter = 0U;
    vlTOPp->SPI_S_TEST__DOT__send_enable = 0U;
}

void VSPI_S_TEST::_settle__TOP__5(VSPI_S_TEST__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSPI_S_TEST::_settle__TOP__5\n"); );
    VSPI_S_TEST* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->MISO_t = vlTOPp->SPI_S_TEST__DOT__SPI_INST__DOT__MISO_o;
    if (vlTOPp->SPI_S_TEST__DOT__msg_recieved) {
        vlTOPp->SPI_S_TEST__DOT__send_enable = 1U;
    } else {
        if (vlTOPp->SPI_S_TEST__DOT__msg_sendt) {
            vlTOPp->SPI_S_TEST__DOT__send_enable = 0U;
        }
    }
    vlTOPp->SPI_S_TEST__DOT__data_recieved = vlTOPp->SPI_S_TEST__DOT__SPI_INST__DOT__MOSI_Data;
    if (vlTOPp->SPI_S_TEST__DOT__msg_recieved) {
        vlTOPp->SPI_S_TEST__DOT__output_data = vlTOPp->SPI_S_TEST__DOT__data_recieved;
    }
}

void VSPI_S_TEST::_eval_initial(VSPI_S_TEST__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSPI_S_TEST::_eval_initial\n"); );
    VSPI_S_TEST* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__2(vlSymsp);
    vlTOPp->__Vm_traceActivity[2U] = 1U;
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
    vlTOPp->__Vclklast__TOP__CLK_t = vlTOPp->CLK_t;
}

void VSPI_S_TEST::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSPI_S_TEST::final\n"); );
    // Variables
    VSPI_S_TEST__Syms* __restrict vlSymsp = this->__VlSymsp;
    VSPI_S_TEST* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VSPI_S_TEST::_eval_settle(VSPI_S_TEST__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSPI_S_TEST::_eval_settle\n"); );
    VSPI_S_TEST* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity[2U] = 1U;
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
    vlTOPp->_settle__TOP__5(vlSymsp);
}

void VSPI_S_TEST::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSPI_S_TEST::_ctor_var_reset\n"); );
    // Body
    CLK_t = VL_RAND_RESET_I(1);
    MOSI_t = VL_RAND_RESET_I(1);
    SC_t = VL_RAND_RESET_I(1);
    MISO_t = VL_RAND_RESET_I(1);
    led = VL_RAND_RESET_I(1);
    SPI_S_TEST__DOT__output_data = VL_RAND_RESET_I(32);
    SPI_S_TEST__DOT__send_enable = VL_RAND_RESET_I(1);
    SPI_S_TEST__DOT__msg_recieved = VL_RAND_RESET_I(1);
    SPI_S_TEST__DOT__msg_sendt = VL_RAND_RESET_I(1);
    SPI_S_TEST__DOT__data_recieved = VL_RAND_RESET_I(32);
    SPI_S_TEST__DOT__SPI_INST__DOT__MOSI_Data = VL_RAND_RESET_I(32);
    SPI_S_TEST__DOT__SPI_INST__DOT__recieve_bit_counter = VL_RAND_RESET_I(5);
    SPI_S_TEST__DOT__SPI_INST__DOT__send_bit_counter = VL_RAND_RESET_I(5);
    SPI_S_TEST__DOT__SPI_INST__DOT__msg_recieved = VL_RAND_RESET_I(1);
    SPI_S_TEST__DOT__SPI_INST__DOT__msg_sendt = VL_RAND_RESET_I(1);
    SPI_S_TEST__DOT__SPI_INST__DOT__MISO_o = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<3; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
