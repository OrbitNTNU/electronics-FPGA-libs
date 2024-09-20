#include <verilated.h>
#include <verilated_vcd_c.h>
#include "obj_dir/Vspi_master.h"

#define MAX_SIM_TIME 400
vluint64_t sim_time = 0;
vluint64_t posedge_cnt = 0;

void dut_reset(Vspi_master* dut, vluint64_t& sim_time) {
    dut->rstn = 1;
    if (sim_time >= 3 && sim_time < 6) {
        dut->rstn = 0;
        dut->i_SPI_MISO = 0;
        dut->i_TX_DV = 0;
        dut->i_TX_Byte = 0;
    }
}

void send_bytes(Vspi_master* dut, vluint64_t start_clk_cnt, vluint64_t& current_clk_cnt, vluint8_t byte) {
    dut->i_TX_DV = 0;
    if (start_clk_cnt == current_clk_cnt) {
        dut->i_TX_Byte = byte;
        dut->i_TX_DV = 1;
    }
}

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    Vspi_master *dut = new Vspi_master;

    Verilated::traceEverOn(true);
    VerilatedVcdC* m_trace = new VerilatedVcdC;
    dut->trace(m_trace, 5);
    m_trace->open("waveform.vcd");

    vluint8_t data = 113;

    while (sim_time < MAX_SIM_TIME) {
        dut_reset(dut, sim_time);

        dut->clk ^= 1;
        dut->eval();

        if (dut->clk == 1) {
            posedge_cnt++;

            send_bytes(dut, 8, posedge_cnt, data);
        }

        m_trace->dump(sim_time);
        sim_time++;
    }

    m_trace->close();
    delete dut;
    exit(EXIT_SUCCESS);
}

