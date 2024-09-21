#include <verilated.h>
#include <verilated_vcd_c.h>
#include "obj_dir/Vspi_master.h"

#define MAX_SIM_TIME 1600
vluint64_t sim_time = 0;
vluint64_t posedge_cnt = 0;

void dut_reset(Vspi_master* dut, vluint64_t& posedge_cnt) {
    dut->rstn = 1;
    if (posedge_cnt < 4) {
        dut->rstn = 0;
        dut->i_SPI_MISO = 0;
        dut->i_TX_DV = 0;
        dut->i_TX_Byte = 0;
    }
}

vluint8_t send_bytes(Vspi_master* dut, vluint8_t num_bytes, vluint8_t* bytes) {
    static int current_byte = 0;

    dut->i_TX_Count = num_bytes;
    dut->i_TX_DV = 0;
    if (dut->o_TX_Ready && current_byte < num_bytes) {
        dut->i_TX_Byte = bytes[current_byte++];
        dut->i_TX_DV = 1;
    }

    if (current_byte == num_bytes) {
        current_byte = 0;
        return 1;
    }

    return 0;
}

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    Vspi_master *dut = new Vspi_master;

    Verilated::traceEverOn(true);
    VerilatedVcdC* m_trace = new VerilatedVcdC;
    dut->trace(m_trace, 5);
    m_trace->open("waveform.vcd");

    int current_packet = 0;

    vluint8_t* data_1 = (vluint8_t*)malloc(2 * sizeof(vluint8_t));
    data_1[0] = 134;
    data_1[1] = 29;

    vluint8_t* data_2 = (vluint8_t*)malloc(8 * sizeof(vluint8_t));
    for (int i = 0; i < 8; i++) {
        data_2[i] = 2 * data_1[i%2] + 5;
    }

    while (sim_time < MAX_SIM_TIME) {
        dut_reset(dut, posedge_cnt);

        dut->clk ^= 1;
        dut->eval();
        
        // Test MISO
        dut->i_SPI_MISO = dut->o_SPI_MOSI;

        if (dut->clk == 1) {
            posedge_cnt++;

            if (posedge_cnt >= 4) {
                int finished;
                switch (current_packet) {
                    case 0:
                        finished = send_bytes(dut, 2, data_1);
                        current_packet += finished;
                        break;
                    case 1:
                        finished = send_bytes(dut, 8, data_2);
                        current_packet += finished;
                        break;
                    default:
                        finished = send_bytes(dut, 0, data_1);
                        break;
                }
            }
        }

        m_trace->dump(sim_time);
        sim_time++;
    }

    free(data_1);
    free(data_2);

    m_trace->close();
    delete dut;
    exit(EXIT_SUCCESS);
}

