// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vspi_master.h for the primary calling header

#include "Vspi_master.h"
#include "Vspi_master__Syms.h"

//==========

void Vspi_master::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vspi_master::eval\n"); );
    Vspi_master__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vspi_master* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("../src/nandland/spi_master_multibyte.sv", 37, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vspi_master::_eval_initial_loop(Vspi_master__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("../src/nandland/spi_master_multibyte.sv", 37, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vspi_master::_sequent__TOP__1(Vspi_master__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_master::_sequent__TOP__1\n"); );
    Vspi_master* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*1:0*/ __Vdly__spi_master_multibyte__DOT__r_TX_Count;
    CData/*1:0*/ __Vdly__spi_master_multibyte__DOT__r_SM_CS;
    CData/*1:0*/ __Vdly__spi_master_multibyte__DOT__r_CS_Inactive_Count;
    CData/*2:0*/ __Vdly__spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_TX_Bit_Count;
    // Body
    vlTOPp->__Vdly__spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_SPI_Clk_Count 
        = vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_SPI_Clk_Count;
    vlTOPp->__Vdly__spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_SPI_Clk 
        = vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_SPI_Clk;
    vlTOPp->__Vdly__spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_SPI_Clk_Edges 
        = vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_SPI_Clk_Edges;
    __Vdly__spi_master_multibyte__DOT__r_CS_Inactive_Count 
        = vlTOPp->spi_master_multibyte__DOT__r_CS_Inactive_Count;
    vlTOPp->__Vdly__spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_RX_Bit_Count 
        = vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_RX_Bit_Count;
    vlTOPp->__Vdly__spi_master_multibyte__DOT__r_CS_n 
        = vlTOPp->spi_master_multibyte__DOT__r_CS_n;
    __Vdly__spi_master_multibyte__DOT__r_SM_CS = vlTOPp->spi_master_multibyte__DOT__r_SM_CS;
    __Vdly__spi_master_multibyte__DOT__r_TX_Count = vlTOPp->spi_master_multibyte__DOT__r_TX_Count;
    __Vdly__spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_TX_Bit_Count 
        = vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_TX_Bit_Count;
    vlTOPp->o_SPI_Clk = ((IData)(vlTOPp->rstn) & (IData)(vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_SPI_Clk));
    if (vlTOPp->rstn) {
        if ((0U == (IData)(vlTOPp->spi_master_multibyte__DOT__r_SM_CS))) {
            if (((IData)(vlTOPp->spi_master_multibyte__DOT__r_CS_n) 
                 & (IData)(vlTOPp->i_TX_DV))) {
                __Vdly__spi_master_multibyte__DOT__r_TX_Count 
                    = (3U & ((IData)(vlTOPp->i_TX_Count) 
                             - (IData)(1U)));
                vlTOPp->__Vdly__spi_master_multibyte__DOT__r_CS_n = 0U;
                __Vdly__spi_master_multibyte__DOT__r_SM_CS = 1U;
            }
        } else {
            if ((1U == (IData)(vlTOPp->spi_master_multibyte__DOT__r_SM_CS))) {
                if (vlTOPp->spi_master_multibyte__DOT__w_Master_Ready) {
                    if ((0U < (IData)(vlTOPp->spi_master_multibyte__DOT__r_TX_Count))) {
                        if (vlTOPp->i_TX_DV) {
                            __Vdly__spi_master_multibyte__DOT__r_TX_Count 
                                = (3U & ((IData)(vlTOPp->spi_master_multibyte__DOT__r_TX_Count) 
                                         - (IData)(1U)));
                        }
                    } else {
                        vlTOPp->__Vdly__spi_master_multibyte__DOT__r_CS_n = 1U;
                        __Vdly__spi_master_multibyte__DOT__r_CS_Inactive_Count = 1U;
                        __Vdly__spi_master_multibyte__DOT__r_SM_CS = 2U;
                    }
                }
            } else {
                if ((2U == (IData)(vlTOPp->spi_master_multibyte__DOT__r_SM_CS))) {
                    if ((0U < (IData)(vlTOPp->spi_master_multibyte__DOT__r_CS_Inactive_Count))) {
                        __Vdly__spi_master_multibyte__DOT__r_CS_Inactive_Count 
                            = (3U & ((IData)(vlTOPp->spi_master_multibyte__DOT__r_CS_Inactive_Count) 
                                     - (IData)(1U)));
                    } else {
                        __Vdly__spi_master_multibyte__DOT__r_SM_CS = 0U;
                    }
                } else {
                    vlTOPp->__Vdly__spi_master_multibyte__DOT__r_CS_n = 1U;
                    __Vdly__spi_master_multibyte__DOT__r_SM_CS = 0U;
                }
            }
        }
    } else {
        __Vdly__spi_master_multibyte__DOT__r_SM_CS = 0U;
        vlTOPp->__Vdly__spi_master_multibyte__DOT__r_CS_n = 1U;
        __Vdly__spi_master_multibyte__DOT__r_TX_Count = 0U;
        __Vdly__spi_master_multibyte__DOT__r_CS_Inactive_Count = 1U;
    }
    if (vlTOPp->rstn) {
        if (vlTOPp->spi_master_multibyte__DOT__w_Master_Ready) {
            __Vdly__spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_TX_Bit_Count = 7U;
        } else {
            if (vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_TX_DV) {
                vlTOPp->o_SPI_MOSI = (1U & ((IData)(vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_TX_Byte) 
                                            >> 7U));
                __Vdly__spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_TX_Bit_Count = 6U;
            } else {
                if (vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_Trailing_Edge) {
                    __Vdly__spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_TX_Bit_Count 
                        = (7U & ((IData)(vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_TX_Bit_Count) 
                                 - (IData)(1U)));
                    vlTOPp->o_SPI_MOSI = (1U & ((IData)(vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_TX_Byte) 
                                                >> (IData)(vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_TX_Bit_Count)));
                }
            }
        }
    } else {
        vlTOPp->o_SPI_MOSI = 0U;
        __Vdly__spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_TX_Bit_Count = 7U;
    }
    vlTOPp->spi_master_multibyte__DOT__r_CS_Inactive_Count 
        = __Vdly__spi_master_multibyte__DOT__r_CS_Inactive_Count;
    vlTOPp->spi_master_multibyte__DOT__r_TX_Count = __Vdly__spi_master_multibyte__DOT__r_TX_Count;
    vlTOPp->spi_master_multibyte__DOT__r_SM_CS = __Vdly__spi_master_multibyte__DOT__r_SM_CS;
    vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_TX_Bit_Count 
        = __Vdly__spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_TX_Bit_Count;
    vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_TX_DV 
        = ((IData)(vlTOPp->rstn) & (IData)(vlTOPp->i_TX_DV));
    if (vlTOPp->rstn) {
        if (vlTOPp->i_TX_DV) {
            vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_TX_Byte 
                = vlTOPp->i_TX_Byte;
        }
    } else {
        vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_TX_Byte = 0U;
    }
}

VL_INLINE_OPT void Vspi_master::_sequent__TOP__2(Vspi_master__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_master::_sequent__TOP__2\n"); );
    Vspi_master* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*1:0*/ __Vdly__o_RX_Count;
    // Body
    __Vdly__o_RX_Count = vlTOPp->o_RX_Count;
    if (vlTOPp->spi_master_multibyte__DOT__r_CS_n) {
        __Vdly__o_RX_Count = 0U;
    } else {
        if (vlTOPp->o_RX_DV) {
            __Vdly__o_RX_Count = (3U & ((IData)(1U) 
                                        + (IData)(vlTOPp->o_RX_Count)));
        }
    }
    vlTOPp->o_RX_Count = __Vdly__o_RX_Count;
}

VL_INLINE_OPT void Vspi_master::_sequent__TOP__4(Vspi_master__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_master::_sequent__TOP__4\n"); );
    Vspi_master* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->spi_master_multibyte__DOT__r_CS_n = vlTOPp->__Vdly__spi_master_multibyte__DOT__r_CS_n;
    vlTOPp->o_SPI_CS_n = vlTOPp->spi_master_multibyte__DOT__r_CS_n;
    if (vlTOPp->rstn) {
        vlTOPp->o_RX_DV = 0U;
        if (vlTOPp->spi_master_multibyte__DOT__w_Master_Ready) {
            vlTOPp->__Vdly__spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_RX_Bit_Count = 7U;
        } else {
            if (vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_Leading_Edge) {
                vlTOPp->o_RX_Byte = (((~ ((IData)(1U) 
                                          << (IData)(vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_RX_Bit_Count))) 
                                      & (IData)(vlTOPp->o_RX_Byte)) 
                                     | ((IData)(vlTOPp->i_SPI_MISO) 
                                        << (IData)(vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_RX_Bit_Count)));
                vlTOPp->__Vdly__spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_RX_Bit_Count 
                    = (7U & ((IData)(vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_RX_Bit_Count) 
                             - (IData)(1U)));
                if ((0U == (IData)(vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_RX_Bit_Count))) {
                    vlTOPp->o_RX_DV = 1U;
                }
            }
        }
    } else {
        vlTOPp->__Vdly__spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_RX_Bit_Count = 7U;
        vlTOPp->o_RX_Byte = 0U;
        vlTOPp->o_RX_DV = 0U;
    }
    vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_RX_Bit_Count 
        = vlTOPp->__Vdly__spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_RX_Bit_Count;
    if (vlTOPp->rstn) {
        vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_Leading_Edge = 0U;
        vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_Trailing_Edge = 0U;
        if (vlTOPp->i_TX_DV) {
            vlTOPp->spi_master_multibyte__DOT__w_Master_Ready = 0U;
            vlTOPp->__Vdly__spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_SPI_Clk_Edges = 0x10U;
        } else {
            if ((0U < (IData)(vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_SPI_Clk_Edges))) {
                vlTOPp->spi_master_multibyte__DOT__w_Master_Ready = 0U;
                if ((3U == (IData)(vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_SPI_Clk_Count))) {
                    vlTOPp->__Vdly__spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_SPI_Clk_Edges 
                        = (0x1fU & ((IData)(vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_SPI_Clk_Edges) 
                                    - (IData)(1U)));
                    vlTOPp->__Vdly__spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_SPI_Clk 
                        = (1U & (~ (IData)(vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_SPI_Clk)));
                    vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_Trailing_Edge = 1U;
                    vlTOPp->__Vdly__spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_SPI_Clk_Count = 0U;
                } else {
                    if ((1U == (IData)(vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_SPI_Clk_Count))) {
                        vlTOPp->__Vdly__spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_SPI_Clk_Edges 
                            = (0x1fU & ((IData)(vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_SPI_Clk_Edges) 
                                        - (IData)(1U)));
                        vlTOPp->__Vdly__spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_SPI_Clk_Count 
                            = (3U & ((IData)(1U) + (IData)(vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_SPI_Clk_Count)));
                        vlTOPp->__Vdly__spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_SPI_Clk 
                            = (1U & (~ (IData)(vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_SPI_Clk)));
                        vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_Leading_Edge = 1U;
                    } else {
                        vlTOPp->__Vdly__spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_SPI_Clk_Count 
                            = (3U & ((IData)(1U) + (IData)(vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_SPI_Clk_Count)));
                    }
                }
            } else {
                vlTOPp->spi_master_multibyte__DOT__w_Master_Ready = 1U;
            }
        }
    } else {
        vlTOPp->__Vdly__spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_SPI_Clk = 0U;
        vlTOPp->spi_master_multibyte__DOT__w_Master_Ready = 0U;
        vlTOPp->__Vdly__spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_SPI_Clk_Edges = 0U;
        vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_Leading_Edge = 0U;
        vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_Trailing_Edge = 0U;
        vlTOPp->__Vdly__spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_SPI_Clk_Count = 0U;
    }
    vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_SPI_Clk_Edges 
        = vlTOPp->__Vdly__spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_SPI_Clk_Edges;
    vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_SPI_Clk 
        = vlTOPp->__Vdly__spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_SPI_Clk;
    vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_SPI_Clk_Count 
        = vlTOPp->__Vdly__spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_SPI_Clk_Count;
}

VL_INLINE_OPT void Vspi_master::_combo__TOP__5(Vspi_master__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_master::_combo__TOP__5\n"); );
    Vspi_master* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->o_TX_Ready = (((0U == (IData)(vlTOPp->spi_master_multibyte__DOT__r_SM_CS)) 
                           | (((1U == (IData)(vlTOPp->spi_master_multibyte__DOT__r_SM_CS)) 
                               & (IData)(vlTOPp->spi_master_multibyte__DOT__w_Master_Ready)) 
                              & (0U < (IData)(vlTOPp->spi_master_multibyte__DOT__r_TX_Count)))) 
                          & (~ (IData)(vlTOPp->i_TX_DV)));
}

void Vspi_master::_eval(Vspi_master__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_master::_eval\n"); );
    Vspi_master* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((~ (IData)(vlTOPp->rstn)) & (IData)(vlTOPp->__Vclklast__TOP__rstn)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((~ (IData)(vlTOPp->rstn)) & (IData)(vlTOPp->__Vclklast__TOP__rstn)))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
        vlTOPp->__Vm_traceActivity[2U] = 1U;
    }
    vlTOPp->_combo__TOP__5(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__rstn = vlTOPp->rstn;
}

VL_INLINE_OPT QData Vspi_master::_change_request(Vspi_master__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_master::_change_request\n"); );
    Vspi_master* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vspi_master::_change_request_1(Vspi_master__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_master::_change_request_1\n"); );
    Vspi_master* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vspi_master::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_master::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((rstn & 0xfeU))) {
        Verilated::overWidthError("rstn");}
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((i_TX_Count & 0xfcU))) {
        Verilated::overWidthError("i_TX_Count");}
    if (VL_UNLIKELY((i_TX_DV & 0xfeU))) {
        Verilated::overWidthError("i_TX_DV");}
    if (VL_UNLIKELY((i_SPI_MISO & 0xfeU))) {
        Verilated::overWidthError("i_SPI_MISO");}
}
#endif  // VL_DEBUG
