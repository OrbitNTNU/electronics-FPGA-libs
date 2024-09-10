// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VSPI_S_TEST__Syms.h"


//======================

void VSPI_S_TEST::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void VSPI_S_TEST::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VSPI_S_TEST__Syms* __restrict vlSymsp = static_cast<VSPI_S_TEST__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    VSPI_S_TEST::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void VSPI_S_TEST::traceInitTop(void* userp, VerilatedVcd* tracep) {
    VSPI_S_TEST__Syms* __restrict vlSymsp = static_cast<VSPI_S_TEST__Syms*>(userp);
    VSPI_S_TEST* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void VSPI_S_TEST::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    VSPI_S_TEST__Syms* __restrict vlSymsp = static_cast<VSPI_S_TEST__Syms*>(userp);
    VSPI_S_TEST* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+11,"CLK_t", false,-1);
        tracep->declBit(c+12,"MOSI_t", false,-1);
        tracep->declBit(c+13,"SC_t", false,-1);
        tracep->declBit(c+14,"MISO_t", false,-1);
        tracep->declBit(c+15,"led", false,-1);
        tracep->declBit(c+11,"SPI_S_TEST CLK_t", false,-1);
        tracep->declBit(c+12,"SPI_S_TEST MOSI_t", false,-1);
        tracep->declBit(c+13,"SPI_S_TEST SC_t", false,-1);
        tracep->declBit(c+14,"SPI_S_TEST MISO_t", false,-1);
        tracep->declBit(c+15,"SPI_S_TEST led", false,-1);
        tracep->declBus(c+5,"SPI_S_TEST output_data", false,-1, 31,0);
        tracep->declBit(c+16,"SPI_S_TEST send_enable", false,-1);
        tracep->declBit(c+6,"SPI_S_TEST msg_recieved", false,-1);
        tracep->declBit(c+1,"SPI_S_TEST msg_sendt", false,-1);
        tracep->declBus(c+7,"SPI_S_TEST data_recieved", false,-1, 31,0);
        tracep->declBit(c+17,"SPI_S_TEST m_ready", false,-1);
        tracep->declBit(c+18,"SPI_S_TEST led_state", false,-1);
        tracep->declBus(c+19,"SPI_S_TEST SPI_INST frame_size", false,-1, 31,0);
        tracep->declBit(c+11,"SPI_S_TEST SPI_INST i_clock", false,-1);
        tracep->declBit(c+12,"SPI_S_TEST SPI_INST MOSI", false,-1);
        tracep->declBus(c+5,"SPI_S_TEST SPI_INST MISO_Data_To_Master", false,-1, 31,0);
        tracep->declBit(c+13,"SPI_S_TEST SPI_INST SC", false,-1);
        tracep->declBit(c+16,"SPI_S_TEST SPI_INST MISO_send_enable", false,-1);
        tracep->declBit(c+17,"SPI_S_TEST SPI_INST Module_ready", false,-1);
        tracep->declBit(c+14,"SPI_S_TEST SPI_INST MISO", false,-1);
        tracep->declBus(c+7,"SPI_S_TEST SPI_INST MOSI_Data_To_FPGA", false,-1, 31,0);
        tracep->declBit(c+6,"SPI_S_TEST SPI_INST msg_r", false,-1);
        tracep->declBit(c+1,"SPI_S_TEST SPI_INST msg_s", false,-1);
        tracep->declBus(c+8,"SPI_S_TEST SPI_INST MOSI_Data", false,-1, 31,0);
        tracep->declBus(c+5,"SPI_S_TEST SPI_INST MISO_Data", false,-1, 31,0);
        tracep->declBus(c+9,"SPI_S_TEST SPI_INST recieve_bit_counter", false,-1, 4,0);
        tracep->declBus(c+2,"SPI_S_TEST SPI_INST send_bit_counter", false,-1, 4,0);
        tracep->declBit(c+10,"SPI_S_TEST SPI_INST msg_recieved", false,-1);
        tracep->declBit(c+3,"SPI_S_TEST SPI_INST msg_sendt", false,-1);
        tracep->declBit(c+4,"SPI_S_TEST SPI_INST MISO_o", false,-1);
        tracep->declBus(c+20,"SPI_S_TEST SPI_INST standby", false,-1, 0,0);
        tracep->declBus(c+21,"SPI_S_TEST SPI_INST active_data", false,-1, 0,0);
        tracep->declBit(c+10,"SPI_S_TEST SPI_INST msg_r_l", false,-1);
    }
}

void VSPI_S_TEST::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void VSPI_S_TEST::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    VSPI_S_TEST__Syms* __restrict vlSymsp = static_cast<VSPI_S_TEST__Syms*>(userp);
    VSPI_S_TEST* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void VSPI_S_TEST::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    VSPI_S_TEST__Syms* __restrict vlSymsp = static_cast<VSPI_S_TEST__Syms*>(userp);
    VSPI_S_TEST* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->SPI_S_TEST__DOT__msg_sendt));
        tracep->fullCData(oldp+2,(vlTOPp->SPI_S_TEST__DOT__SPI_INST__DOT__send_bit_counter),5);
        tracep->fullBit(oldp+3,(vlTOPp->SPI_S_TEST__DOT__SPI_INST__DOT__msg_sendt));
        tracep->fullBit(oldp+4,(vlTOPp->SPI_S_TEST__DOT__SPI_INST__DOT__MISO_o));
        tracep->fullIData(oldp+5,(vlTOPp->SPI_S_TEST__DOT__output_data),32);
        tracep->fullBit(oldp+6,(vlTOPp->SPI_S_TEST__DOT__msg_recieved));
        tracep->fullIData(oldp+7,(vlTOPp->SPI_S_TEST__DOT__data_recieved),32);
        tracep->fullIData(oldp+8,(vlTOPp->SPI_S_TEST__DOT__SPI_INST__DOT__MOSI_Data),32);
        tracep->fullCData(oldp+9,(vlTOPp->SPI_S_TEST__DOT__SPI_INST__DOT__recieve_bit_counter),5);
        tracep->fullBit(oldp+10,(vlTOPp->SPI_S_TEST__DOT__SPI_INST__DOT__msg_recieved));
        tracep->fullBit(oldp+11,(vlTOPp->CLK_t));
        tracep->fullBit(oldp+12,(vlTOPp->MOSI_t));
        tracep->fullBit(oldp+13,(vlTOPp->SC_t));
        tracep->fullBit(oldp+14,(vlTOPp->MISO_t));
        tracep->fullBit(oldp+15,(vlTOPp->led));
        tracep->fullBit(oldp+16,(vlTOPp->SPI_S_TEST__DOT__send_enable));
        tracep->fullBit(oldp+17,(0U));
        tracep->fullBit(oldp+18,(1U));
        tracep->fullIData(oldp+19,(0x20U),32);
        tracep->fullBit(oldp+20,(1U));
        tracep->fullBit(oldp+21,(0U));
    }
}
