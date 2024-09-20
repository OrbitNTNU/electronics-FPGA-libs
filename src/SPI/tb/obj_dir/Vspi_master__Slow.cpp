// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vspi_master.h for the primary calling header

#include "Vspi_master.h"
#include "Vspi_master__Syms.h"

//==========

VL_CTOR_IMP(Vspi_master) {
    Vspi_master__Syms* __restrict vlSymsp = __VlSymsp = new Vspi_master__Syms(this, name());
    Vspi_master* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vspi_master::__Vconfigure(Vspi_master__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vspi_master::~Vspi_master() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vspi_master::_settle__TOP__3(Vspi_master__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_master::_settle__TOP__3\n"); );
    Vspi_master* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->o_SPI_CS_n = vlTOPp->spi_master_multibyte__DOT__r_CS_n;
    vlTOPp->o_TX_Ready = (((0U == (IData)(vlTOPp->spi_master_multibyte__DOT__r_SM_CS)) 
                           | (((1U == (IData)(vlTOPp->spi_master_multibyte__DOT__r_SM_CS)) 
                               & (IData)(vlTOPp->spi_master_multibyte__DOT__w_Master_Ready)) 
                              & (0U < (IData)(vlTOPp->spi_master_multibyte__DOT__r_TX_Count)))) 
                          & (~ (IData)(vlTOPp->i_TX_DV)));
}

void Vspi_master::_eval_initial(Vspi_master__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_master::_eval_initial\n"); );
    Vspi_master* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__rstn = vlTOPp->rstn;
}

void Vspi_master::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_master::final\n"); );
    // Variables
    Vspi_master__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vspi_master* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vspi_master::_eval_settle(Vspi_master__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_master::_eval_settle\n"); );
    Vspi_master* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
}

void Vspi_master::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_master::_ctor_var_reset\n"); );
    // Body
    rstn = VL_RAND_RESET_I(1);
    clk = VL_RAND_RESET_I(1);
    i_TX_Count = VL_RAND_RESET_I(2);
    i_TX_Byte = VL_RAND_RESET_I(8);
    i_TX_DV = VL_RAND_RESET_I(1);
    o_TX_Ready = VL_RAND_RESET_I(1);
    o_RX_Count = VL_RAND_RESET_I(2);
    o_RX_DV = VL_RAND_RESET_I(1);
    o_RX_Byte = VL_RAND_RESET_I(8);
    o_SPI_Clk = VL_RAND_RESET_I(1);
    i_SPI_MISO = VL_RAND_RESET_I(1);
    o_SPI_MOSI = VL_RAND_RESET_I(1);
    o_SPI_CS_n = VL_RAND_RESET_I(1);
    spi_master_multibyte__DOT__r_SM_CS = VL_RAND_RESET_I(2);
    spi_master_multibyte__DOT__r_CS_n = VL_RAND_RESET_I(1);
    spi_master_multibyte__DOT__r_CS_Inactive_Count = VL_RAND_RESET_I(2);
    spi_master_multibyte__DOT__r_TX_Count = VL_RAND_RESET_I(2);
    spi_master_multibyte__DOT__w_Master_Ready = VL_RAND_RESET_I(1);
    spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_SPI_Clk_Count = VL_RAND_RESET_I(2);
    spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_SPI_Clk = VL_RAND_RESET_I(1);
    spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_SPI_Clk_Edges = VL_RAND_RESET_I(5);
    spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_Leading_Edge = VL_RAND_RESET_I(1);
    spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_Trailing_Edge = VL_RAND_RESET_I(1);
    spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_TX_DV = VL_RAND_RESET_I(1);
    spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_TX_Byte = VL_RAND_RESET_I(8);
    spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_RX_Bit_Count = VL_RAND_RESET_I(3);
    spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_TX_Bit_Count = VL_RAND_RESET_I(3);
    __Vdly__spi_master_multibyte__DOT__r_CS_n = VL_RAND_RESET_I(1);
    __Vdly__spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_SPI_Clk_Edges = VL_RAND_RESET_I(5);
    __Vdly__spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_SPI_Clk = VL_RAND_RESET_I(1);
    __Vdly__spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_SPI_Clk_Count = VL_RAND_RESET_I(2);
    __Vdly__spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_RX_Bit_Count = VL_RAND_RESET_I(3);
    { int __Vi0=0; for (; __Vi0<3; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
