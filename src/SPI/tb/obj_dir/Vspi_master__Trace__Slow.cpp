// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vspi_master__Syms.h"


//======================

void Vspi_master::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vspi_master::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vspi_master__Syms* __restrict vlSymsp = static_cast<Vspi_master__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vspi_master::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vspi_master::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vspi_master__Syms* __restrict vlSymsp = static_cast<Vspi_master__Syms*>(userp);
    Vspi_master* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vspi_master::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vspi_master__Syms* __restrict vlSymsp = static_cast<Vspi_master__Syms*>(userp);
    Vspi_master* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+15,"rstn", false,-1);
        tracep->declBit(c+16,"clk", false,-1);
        tracep->declBus(c+17,"i_TX_Count", false,-1, 1,0);
        tracep->declBus(c+18,"i_TX_Byte", false,-1, 7,0);
        tracep->declBit(c+19,"i_TX_DV", false,-1);
        tracep->declBit(c+20,"o_TX_Ready", false,-1);
        tracep->declBus(c+21,"o_RX_Count", false,-1, 1,0);
        tracep->declBit(c+22,"o_RX_DV", false,-1);
        tracep->declBus(c+23,"o_RX_Byte", false,-1, 7,0);
        tracep->declBit(c+24,"o_SPI_Clk", false,-1);
        tracep->declBit(c+25,"i_SPI_MISO", false,-1);
        tracep->declBit(c+26,"o_SPI_MOSI", false,-1);
        tracep->declBit(c+27,"o_SPI_CS_n", false,-1);
        tracep->declBus(c+28,"spi_master_multibyte SPI_MODE", false,-1, 31,0);
        tracep->declBus(c+29,"spi_master_multibyte CLKS_PER_HALF_BIT", false,-1, 31,0);
        tracep->declBus(c+29,"spi_master_multibyte MAX_BYTES_PER_CS", false,-1, 31,0);
        tracep->declBus(c+30,"spi_master_multibyte CS_INACTIVE_CLKS", false,-1, 31,0);
        tracep->declBit(c+15,"spi_master_multibyte rstn", false,-1);
        tracep->declBit(c+16,"spi_master_multibyte clk", false,-1);
        tracep->declBus(c+17,"spi_master_multibyte i_TX_Count", false,-1, 1,0);
        tracep->declBus(c+18,"spi_master_multibyte i_TX_Byte", false,-1, 7,0);
        tracep->declBit(c+19,"spi_master_multibyte i_TX_DV", false,-1);
        tracep->declBit(c+20,"spi_master_multibyte o_TX_Ready", false,-1);
        tracep->declBus(c+21,"spi_master_multibyte o_RX_Count", false,-1, 1,0);
        tracep->declBit(c+22,"spi_master_multibyte o_RX_DV", false,-1);
        tracep->declBus(c+23,"spi_master_multibyte o_RX_Byte", false,-1, 7,0);
        tracep->declBit(c+24,"spi_master_multibyte o_SPI_Clk", false,-1);
        tracep->declBit(c+25,"spi_master_multibyte i_SPI_MISO", false,-1);
        tracep->declBit(c+26,"spi_master_multibyte o_SPI_MOSI", false,-1);
        tracep->declBit(c+27,"spi_master_multibyte o_SPI_CS_n", false,-1);
        tracep->declBus(c+31,"spi_master_multibyte IDLE", false,-1, 1,0);
        tracep->declBus(c+32,"spi_master_multibyte TRANSFER", false,-1, 1,0);
        tracep->declBus(c+33,"spi_master_multibyte CSInactive", false,-1, 1,0);
        tracep->declBus(c+1,"spi_master_multibyte r_SM_CS", false,-1, 1,0);
        tracep->declBit(c+7,"spi_master_multibyte r_CS_n", false,-1);
        tracep->declBus(c+2,"spi_master_multibyte r_CS_Inactive_Count", false,-1, -1,0);
        tracep->declBus(c+3,"spi_master_multibyte r_TX_Count", false,-1, 1,0);
        tracep->declBit(c+8,"spi_master_multibyte w_Master_Ready", false,-1);
        tracep->declBus(c+28,"spi_master_multibyte SPI_Master_Inst SPI_MODE", false,-1, 31,0);
        tracep->declBus(c+29,"spi_master_multibyte SPI_Master_Inst CLKS_PER_HALF_BIT", false,-1, 31,0);
        tracep->declBit(c+15,"spi_master_multibyte SPI_Master_Inst rstn", false,-1);
        tracep->declBit(c+16,"spi_master_multibyte SPI_Master_Inst clk", false,-1);
        tracep->declBus(c+18,"spi_master_multibyte SPI_Master_Inst i_TX_Byte", false,-1, 7,0);
        tracep->declBit(c+19,"spi_master_multibyte SPI_Master_Inst i_TX_DV", false,-1);
        tracep->declBit(c+8,"spi_master_multibyte SPI_Master_Inst o_TX_Ready", false,-1);
        tracep->declBit(c+22,"spi_master_multibyte SPI_Master_Inst o_RX_DV", false,-1);
        tracep->declBus(c+23,"spi_master_multibyte SPI_Master_Inst o_RX_Byte", false,-1, 7,0);
        tracep->declBit(c+24,"spi_master_multibyte SPI_Master_Inst o_SPI_Clk", false,-1);
        tracep->declBit(c+25,"spi_master_multibyte SPI_Master_Inst i_SPI_MISO", false,-1);
        tracep->declBit(c+26,"spi_master_multibyte SPI_Master_Inst o_SPI_MOSI", false,-1);
        tracep->declBit(c+34,"spi_master_multibyte SPI_Master_Inst w_CPOL", false,-1);
        tracep->declBit(c+34,"spi_master_multibyte SPI_Master_Inst w_CPHA", false,-1);
        tracep->declBus(c+9,"spi_master_multibyte SPI_Master_Inst r_SPI_Clk_Count", false,-1, 1,0);
        tracep->declBit(c+10,"spi_master_multibyte SPI_Master_Inst r_SPI_Clk", false,-1);
        tracep->declBus(c+11,"spi_master_multibyte SPI_Master_Inst r_SPI_Clk_Edges", false,-1, 4,0);
        tracep->declBit(c+12,"spi_master_multibyte SPI_Master_Inst r_Leading_Edge", false,-1);
        tracep->declBit(c+13,"spi_master_multibyte SPI_Master_Inst r_Trailing_Edge", false,-1);
        tracep->declBit(c+4,"spi_master_multibyte SPI_Master_Inst r_TX_DV", false,-1);
        tracep->declBus(c+5,"spi_master_multibyte SPI_Master_Inst r_TX_Byte", false,-1, 7,0);
        tracep->declBus(c+14,"spi_master_multibyte SPI_Master_Inst r_RX_Bit_Count", false,-1, 2,0);
        tracep->declBus(c+6,"spi_master_multibyte SPI_Master_Inst r_TX_Bit_Count", false,-1, 2,0);
    }
}

void Vspi_master::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vspi_master::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vspi_master__Syms* __restrict vlSymsp = static_cast<Vspi_master__Syms*>(userp);
    Vspi_master* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vspi_master::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vspi_master__Syms* __restrict vlSymsp = static_cast<Vspi_master__Syms*>(userp);
    Vspi_master* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullCData(oldp+1,(vlTOPp->spi_master_multibyte__DOT__r_SM_CS),2);
        tracep->fullCData(oldp+2,(vlTOPp->spi_master_multibyte__DOT__r_CS_Inactive_Count),2);
        tracep->fullCData(oldp+3,(vlTOPp->spi_master_multibyte__DOT__r_TX_Count),2);
        tracep->fullBit(oldp+4,(vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_TX_DV));
        tracep->fullCData(oldp+5,(vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_TX_Byte),8);
        tracep->fullCData(oldp+6,(vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_TX_Bit_Count),3);
        tracep->fullBit(oldp+7,(vlTOPp->spi_master_multibyte__DOT__r_CS_n));
        tracep->fullBit(oldp+8,(vlTOPp->spi_master_multibyte__DOT__w_Master_Ready));
        tracep->fullCData(oldp+9,(vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_SPI_Clk_Count),2);
        tracep->fullBit(oldp+10,(vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_SPI_Clk));
        tracep->fullCData(oldp+11,(vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_SPI_Clk_Edges),5);
        tracep->fullBit(oldp+12,(vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_Leading_Edge));
        tracep->fullBit(oldp+13,(vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_Trailing_Edge));
        tracep->fullCData(oldp+14,(vlTOPp->spi_master_multibyte__DOT__SPI_Master_Inst__DOT__r_RX_Bit_Count),3);
        tracep->fullBit(oldp+15,(vlTOPp->rstn));
        tracep->fullBit(oldp+16,(vlTOPp->clk));
        tracep->fullCData(oldp+17,(vlTOPp->i_TX_Count),2);
        tracep->fullCData(oldp+18,(vlTOPp->i_TX_Byte),8);
        tracep->fullBit(oldp+19,(vlTOPp->i_TX_DV));
        tracep->fullBit(oldp+20,(vlTOPp->o_TX_Ready));
        tracep->fullCData(oldp+21,(vlTOPp->o_RX_Count),2);
        tracep->fullBit(oldp+22,(vlTOPp->o_RX_DV));
        tracep->fullCData(oldp+23,(vlTOPp->o_RX_Byte),8);
        tracep->fullBit(oldp+24,(vlTOPp->o_SPI_Clk));
        tracep->fullBit(oldp+25,(vlTOPp->i_SPI_MISO));
        tracep->fullBit(oldp+26,(vlTOPp->o_SPI_MOSI));
        tracep->fullBit(oldp+27,(vlTOPp->o_SPI_CS_n));
        tracep->fullIData(oldp+28,(0U),32);
        tracep->fullIData(oldp+29,(2U),32);
        tracep->fullIData(oldp+30,(1U),32);
        tracep->fullCData(oldp+31,(0U),2);
        tracep->fullCData(oldp+32,(1U),2);
        tracep->fullCData(oldp+33,(2U),2);
        tracep->fullBit(oldp+34,(0U));
    }
}
