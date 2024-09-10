// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VSPI_S_TEST__Syms.h"


void VSPI_S_TEST::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    VSPI_S_TEST__Syms* __restrict vlSymsp = static_cast<VSPI_S_TEST__Syms*>(userp);
    VSPI_S_TEST* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void VSPI_S_TEST::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    VSPI_S_TEST__Syms* __restrict vlSymsp = static_cast<VSPI_S_TEST__Syms*>(userp);
    VSPI_S_TEST* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgBit(oldp+0,(vlTOPp->SPI_S_TEST__DOT__msg_sendt));
            tracep->chgCData(oldp+1,(vlTOPp->SPI_S_TEST__DOT__SPI_INST__DOT__send_bit_counter),5);
            tracep->chgBit(oldp+2,(vlTOPp->SPI_S_TEST__DOT__SPI_INST__DOT__msg_sendt));
            tracep->chgBit(oldp+3,(vlTOPp->SPI_S_TEST__DOT__SPI_INST__DOT__MISO_o));
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgIData(oldp+4,(vlTOPp->SPI_S_TEST__DOT__output_data),32);
            tracep->chgBit(oldp+5,(vlTOPp->SPI_S_TEST__DOT__msg_recieved));
            tracep->chgIData(oldp+6,(vlTOPp->SPI_S_TEST__DOT__data_recieved),32);
            tracep->chgIData(oldp+7,(vlTOPp->SPI_S_TEST__DOT__SPI_INST__DOT__MOSI_Data),32);
            tracep->chgCData(oldp+8,(vlTOPp->SPI_S_TEST__DOT__SPI_INST__DOT__recieve_bit_counter),5);
            tracep->chgBit(oldp+9,(vlTOPp->SPI_S_TEST__DOT__SPI_INST__DOT__msg_recieved));
        }
        tracep->chgBit(oldp+10,(vlTOPp->CLK_t));
        tracep->chgBit(oldp+11,(vlTOPp->MOSI_t));
        tracep->chgBit(oldp+12,(vlTOPp->SC_t));
        tracep->chgBit(oldp+13,(vlTOPp->MISO_t));
        tracep->chgBit(oldp+14,(vlTOPp->led));
        tracep->chgBit(oldp+15,(vlTOPp->SPI_S_TEST__DOT__send_enable));
    }
}

void VSPI_S_TEST::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    VSPI_S_TEST__Syms* __restrict vlSymsp = static_cast<VSPI_S_TEST__Syms*>(userp);
    VSPI_S_TEST* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
        vlTOPp->__Vm_traceActivity[2U] = 0U;
    }
}
