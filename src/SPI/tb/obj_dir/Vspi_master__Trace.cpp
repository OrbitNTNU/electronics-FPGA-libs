// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vspi_master__Syms.h"


void Vspi_master::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vspi_master__Syms* __restrict vlSymsp = static_cast<Vspi_master__Syms*>(userp);
    Vspi_master* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vspi_master::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vspi_master__Syms* __restrict vlSymsp = static_cast<Vspi_master__Syms*>(userp);
    Vspi_master* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgCData(oldp+0,(vlTOPp->spi_master_multibyte__DOT__r_SM_CS),2);
            tracep->chgCData(oldp+1,(vlTOPp->spi_master_multibyte__DOT__r_CS_Inactive_Count),2);
            tracep->chgCData(oldp+2,(vlTOPp->spi_master_multibyte__DOT__r_TX_Count),2);
            tracep->chgBit(oldp+3,(vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_TX_DV));
            tracep->chgCData(oldp+4,(vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_TX_Byte),8);
            tracep->chgCData(oldp+5,(vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_TX_Bit_Count),3);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgBit(oldp+6,(vlTOPp->spi_master_multibyte__DOT__r_CS_n));
            tracep->chgBit(oldp+7,(vlTOPp->spi_master_multibyte__DOT__w_Master_Ready));
            tracep->chgCData(oldp+8,(vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_SPI_Clk_Count),2);
            tracep->chgBit(oldp+9,(vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_SPI_Clk));
            tracep->chgCData(oldp+10,(vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_SPI_Clk_Edges),5);
            tracep->chgBit(oldp+11,(vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_Leading_Edge));
            tracep->chgBit(oldp+12,(vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_Trailing_Edge));
            tracep->chgCData(oldp+13,(vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_RX_Bit_Count),3);
        }
        tracep->chgBit(oldp+14,(vlTOPp->rstn));
        tracep->chgBit(oldp+15,(vlTOPp->clk));
        tracep->chgCData(oldp+16,(vlTOPp->i_TX_Count),2);
        tracep->chgCData(oldp+17,(vlTOPp->i_TX_Byte),8);
        tracep->chgBit(oldp+18,(vlTOPp->i_TX_DV));
        tracep->chgBit(oldp+19,(vlTOPp->o_TX_Ready));
        tracep->chgCData(oldp+20,(vlTOPp->o_RX_Count),2);
        tracep->chgBit(oldp+21,(vlTOPp->o_RX_DV));
        tracep->chgCData(oldp+22,(vlTOPp->o_RX_Byte),8);
        tracep->chgBit(oldp+23,(vlTOPp->o_SPI_Clk));
        tracep->chgBit(oldp+24,(vlTOPp->i_SPI_MISO));
        tracep->chgBit(oldp+25,(vlTOPp->o_SPI_MOSI));
        tracep->chgBit(oldp+26,(vlTOPp->o_SPI_CS_n));
    }
}

void Vspi_master::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vspi_master__Syms* __restrict vlSymsp = static_cast<Vspi_master__Syms*>(userp);
    Vspi_master* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
        vlTOPp->__Vm_traceActivity[2U] = 0U;
    }
}
