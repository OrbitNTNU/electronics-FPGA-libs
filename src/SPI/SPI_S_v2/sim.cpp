#include "VSPI_S_TEST.h"
#include "verilated.h"
#include <verilated_vcd_c.h>

#include <cassert>
#include <vector>
#include <iostream>

void SendFrame(VSPI_S_TEST *top,VerilatedVcdC *trace, unsigned long &tickcount, uint32_t data);


int main(int argc, char** argv) {
    
    VSPI_S_TEST* top = new VSPI_S_TEST;
    Verilated::commandArgs(argc, argv);

    unsigned long tickcount = 0;
    Verilated::traceEverOn(true);
    // Initialization of trace
    VerilatedVcdC *trace = new VerilatedVcdC;
    top->trace(trace, 99);
    trace->open("trace.vcd");
    /*
    
    
    int stimuli_a[] = { 2, -1, 1, -6 };
    int stimuli_b[] = { 4,  5, 2,  7 }; 

    for (int i = 0; i < sizeof(stimuli_a) / sizeof(stimuli_a[0]); i++) {
        if (Verilated::gotFinish()) break;
        
        top->a = stimuli_a[i];
        top->b = stimuli_b[i];
        
        top->eval();

        assert(top->c == (stimuli_a[i] + stimuli_b[i]));
    }
    */
    trace->dump(1*tickcount++);
    uint32_t data = 0x304445FF;
    top->SC_t = 0;
    SendFrame(top,trace,tickcount,data);
    top->eval();
    data = 0x0000FF00;
    SendFrame(top,trace,tickcount,data);
    top->eval();
    data = 0xBBEEFF00;
    SendFrame(top,trace,tickcount,data);
    top->eval();
    trace->dump(1*tickcount++);
    top->CLK_t = 0;
    top->MOSI_t = data & 1;
    top->eval();
    trace->dump(1*tickcount++);
    top->CLK_t = 1;
    top->eval();
    data = data >> 1;
    top->eval();
    trace->close();
    delete trace;
    
    delete top;
    return 0;
}



void SendFrame(VSPI_S_TEST *top,VerilatedVcdC *trace, unsigned long &tickcount,uint32_t data){
    for(int i = 0; i<32;i++){
    trace->dump(1*tickcount++);
    top->CLK_t = 0;
    top->MOSI_t = data & 1;
    top->eval();
    trace->dump(1*tickcount++);
    top->CLK_t = 1;
    top->eval();
    data = data >> 1;
    }
}