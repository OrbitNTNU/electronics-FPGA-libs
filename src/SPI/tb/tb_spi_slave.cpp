#include <verilated.h>
#include <verilated_vcd_c.h>
#include "obj_dir/Vspi_slave.h"

#define MAX_SIM_TIME 1600
vluint64_t sim_time = 0;
vluint64_t posedge_cnt = 0;

void dut_reset(Vspi_slave* dut, vluint64_t& posedge_cnt) {
    dut->rstn = 1;
    if (posedge_cnt < 4) {
        dut->rstn = 0;
        dut->MOSI = 0;
        dut->i_TX_DV = 0;
        dut->i_TX_Byte = 0;
        dut->SCK = 0;
        dut->CSn = 1;
    }
}
int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    Vspi_slave *dut = new Vspi_slave;

    Verilated::traceEverOn(true);
    VerilatedVcdC* m_trace = new VerilatedVcdC;
    dut->trace(m_trace, 5);
    m_trace->open("waveform.vcd");

    while (sim_time < MAX_SIM_TIME) {
        dut_reset(dut, posedge_cnt);

        dut->clk ^= 1;
        dut->eval();
        
        if (dut->clk == 1) {
            posedge_cnt++;

        }

        m_trace->dump(sim_time);
        sim_time++;
    }

    m_trace->close();
    delete dut;
    exit(EXIT_SUCCESS);
}


