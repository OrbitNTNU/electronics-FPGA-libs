// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSPI_S_TEST.h for the primary calling header

#include "VSPI_S_TEST.h"
#include "VSPI_S_TEST__Syms.h"

//==========

void VSPI_S_TEST::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VSPI_S_TEST::eval\n"); );
    VSPI_S_TEST__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VSPI_S_TEST* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("src/SPI_S_TEST.sv", 3, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VSPI_S_TEST::_eval_initial_loop(VSPI_S_TEST__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("src/SPI_S_TEST.sv", 3, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VSPI_S_TEST::_sequent__TOP__3(VSPI_S_TEST__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSPI_S_TEST::_sequent__TOP__3\n"); );
    VSPI_S_TEST* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*4:0*/ __Vdly__SPI_S_TEST__DOT__SPI_INST__DOT__send_bit_counter;
    // Body
    __Vdly__SPI_S_TEST__DOT__SPI_INST__DOT__send_bit_counter 
        = vlTOPp->SPI_S_TEST__DOT__SPI_INST__DOT__send_bit_counter;
    if (vlTOPp->SC_t) {
        __Vdly__SPI_S_TEST__DOT__SPI_INST__DOT__send_bit_counter = 0U;
    } else {
        if (vlTOPp->SC_t) {
            __Vdly__SPI_S_TEST__DOT__SPI_INST__DOT__send_bit_counter = 0U;
        } else {
            if (vlTOPp->SPI_S_TEST__DOT__send_enable) {
                if ((0x1fU > (IData)(vlTOPp->SPI_S_TEST__DOT__SPI_INST__DOT__send_bit_counter))) {
                    vlTOPp->SPI_S_TEST__DOT__SPI_INST__DOT__MISO_o 
                        = (1U & (vlTOPp->SPI_S_TEST__DOT__output_data 
                                 >> (IData)(vlTOPp->SPI_S_TEST__DOT__SPI_INST__DOT__send_bit_counter)));
                    vlTOPp->SPI_S_TEST__DOT__SPI_INST__DOT__msg_sendt = 0U;
                    __Vdly__SPI_S_TEST__DOT__SPI_INST__DOT__send_bit_counter 
                        = (0x1fU & ((IData)(1U) + (IData)(vlTOPp->SPI_S_TEST__DOT__SPI_INST__DOT__send_bit_counter)));
                } else {
                    __Vdly__SPI_S_TEST__DOT__SPI_INST__DOT__send_bit_counter = 0U;
                    vlTOPp->SPI_S_TEST__DOT__SPI_INST__DOT__MISO_o 
                        = (1U & (vlTOPp->SPI_S_TEST__DOT__output_data 
                                 >> (IData)(vlTOPp->SPI_S_TEST__DOT__SPI_INST__DOT__send_bit_counter)));
                    vlTOPp->SPI_S_TEST__DOT__SPI_INST__DOT__msg_sendt = 1U;
                }
            } else {
                vlTOPp->SPI_S_TEST__DOT__SPI_INST__DOT__msg_sendt = 1U;
            }
        }
    }
    vlTOPp->SPI_S_TEST__DOT__SPI_INST__DOT__send_bit_counter 
        = __Vdly__SPI_S_TEST__DOT__SPI_INST__DOT__send_bit_counter;
    vlTOPp->MISO_t = vlTOPp->SPI_S_TEST__DOT__SPI_INST__DOT__MISO_o;
    vlTOPp->SPI_S_TEST__DOT__msg_sendt = vlTOPp->SPI_S_TEST__DOT__SPI_INST__DOT__msg_sendt;
}

VL_INLINE_OPT void VSPI_S_TEST::_sequent__TOP__4(VSPI_S_TEST__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSPI_S_TEST::_sequent__TOP__4\n"); );
    VSPI_S_TEST* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*4:0*/ __Vdly__SPI_S_TEST__DOT__SPI_INST__DOT__recieve_bit_counter;
    // Body
    __Vdly__SPI_S_TEST__DOT__SPI_INST__DOT__recieve_bit_counter 
        = vlTOPp->SPI_S_TEST__DOT__SPI_INST__DOT__recieve_bit_counter;
    if (vlTOPp->SC_t) {
        vlTOPp->SPI_S_TEST__DOT__SPI_INST__DOT__MOSI_Data = 0U;
        vlTOPp->SPI_S_TEST__DOT__SPI_INST__DOT__msg_recieved = 0U;
        __Vdly__SPI_S_TEST__DOT__SPI_INST__DOT__recieve_bit_counter = 0U;
    } else {
        if (vlTOPp->SC_t) {
            __Vdly__SPI_S_TEST__DOT__SPI_INST__DOT__recieve_bit_counter = 0U;
        } else {
            if ((0x1fU == (IData)(vlTOPp->SPI_S_TEST__DOT__SPI_INST__DOT__recieve_bit_counter))) {
                vlTOPp->SPI_S_TEST__DOT__SPI_INST__DOT__MOSI_Data 
                    = (((~ ((IData)(1U) << (IData)(vlTOPp->SPI_S_TEST__DOT__SPI_INST__DOT__recieve_bit_counter))) 
                        & vlTOPp->SPI_S_TEST__DOT__SPI_INST__DOT__MOSI_Data) 
                       | ((IData)(vlTOPp->MOSI_t) << (IData)(vlTOPp->SPI_S_TEST__DOT__SPI_INST__DOT__recieve_bit_counter)));
                vlTOPp->SPI_S_TEST__DOT__SPI_INST__DOT__msg_recieved = 1U;
                __Vdly__SPI_S_TEST__DOT__SPI_INST__DOT__recieve_bit_counter = 0U;
            } else {
                vlTOPp->SPI_S_TEST__DOT__SPI_INST__DOT__msg_recieved = 0U;
                vlTOPp->SPI_S_TEST__DOT__SPI_INST__DOT__MOSI_Data 
                    = (((~ ((IData)(1U) << (IData)(vlTOPp->SPI_S_TEST__DOT__SPI_INST__DOT__recieve_bit_counter))) 
                        & vlTOPp->SPI_S_TEST__DOT__SPI_INST__DOT__MOSI_Data) 
                       | ((IData)(vlTOPp->MOSI_t) << (IData)(vlTOPp->SPI_S_TEST__DOT__SPI_INST__DOT__recieve_bit_counter)));
                __Vdly__SPI_S_TEST__DOT__SPI_INST__DOT__recieve_bit_counter 
                    = (0x1fU & ((IData)(1U) + (IData)(vlTOPp->SPI_S_TEST__DOT__SPI_INST__DOT__recieve_bit_counter)));
            }
        }
    }
    vlTOPp->SPI_S_TEST__DOT__SPI_INST__DOT__recieve_bit_counter 
        = __Vdly__SPI_S_TEST__DOT__SPI_INST__DOT__recieve_bit_counter;
    vlTOPp->SPI_S_TEST__DOT__data_recieved = vlTOPp->SPI_S_TEST__DOT__SPI_INST__DOT__MOSI_Data;
    vlTOPp->SPI_S_TEST__DOT__msg_recieved = vlTOPp->SPI_S_TEST__DOT__SPI_INST__DOT__msg_recieved;
    if (vlTOPp->SPI_S_TEST__DOT__msg_recieved) {
        vlTOPp->SPI_S_TEST__DOT__output_data = vlTOPp->SPI_S_TEST__DOT__data_recieved;
    }
}

VL_INLINE_OPT void VSPI_S_TEST::_multiclk__TOP__6(VSPI_S_TEST__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSPI_S_TEST::_multiclk__TOP__6\n"); );
    VSPI_S_TEST* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->SPI_S_TEST__DOT__msg_recieved) {
        vlTOPp->SPI_S_TEST__DOT__send_enable = 1U;
    } else {
        if (vlTOPp->SPI_S_TEST__DOT__msg_sendt) {
            vlTOPp->SPI_S_TEST__DOT__send_enable = 0U;
        }
    }
}

void VSPI_S_TEST::_eval(VSPI_S_TEST__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSPI_S_TEST::_eval\n"); );
    VSPI_S_TEST* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((~ (IData)(vlTOPp->CLK_t)) & (IData)(vlTOPp->__Vclklast__TOP__CLK_t))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    if (((IData)(vlTOPp->CLK_t) & (~ (IData)(vlTOPp->__Vclklast__TOP__CLK_t)))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
        vlTOPp->__Vm_traceActivity[2U] = 1U;
    }
    if (((IData)(vlTOPp->CLK_t) ^ (IData)(vlTOPp->__Vclklast__TOP__CLK_t))) {
        vlTOPp->_multiclk__TOP__6(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__CLK_t = vlTOPp->CLK_t;
}

VL_INLINE_OPT QData VSPI_S_TEST::_change_request(VSPI_S_TEST__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSPI_S_TEST::_change_request\n"); );
    VSPI_S_TEST* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData VSPI_S_TEST::_change_request_1(VSPI_S_TEST__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSPI_S_TEST::_change_request_1\n"); );
    VSPI_S_TEST* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VSPI_S_TEST::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSPI_S_TEST::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((CLK_t & 0xfeU))) {
        Verilated::overWidthError("CLK_t");}
    if (VL_UNLIKELY((MOSI_t & 0xfeU))) {
        Verilated::overWidthError("MOSI_t");}
    if (VL_UNLIKELY((SC_t & 0xfeU))) {
        Verilated::overWidthError("SC_t");}
}
#endif  // VL_DEBUG
