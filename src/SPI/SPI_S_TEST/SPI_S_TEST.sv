
`include "Slave_modul.sv"

module SPI_S_TEST (
    input CLK_t,
    input MOSI_t,
    input SC_t,
    output MISO_t
);

reg[31:0] output_data = 0;
logic send_enable = 0;
logic transit_done_t = 0;
logic msg_recieved = 0;
logic msg_sendt = 0;
reg[31:0] data_recieved = 0;

    
    Slave_modul #(.frame_size(32)) SPI_INST
    (
        .i_clock(CLK_t),
        .MOSI(MOSI_t),
        .MISO_frame(output_data),
        .SC(SC_t),
        .MISO_send_enable(send_enable),
        // verilator lint_off UNSIGNED
        .Module_ready(),
        // verilator lint_on UNSIGNED
        //OUTPUTS
        .MISO(MISO_t),
        .MOSI_frame(data_recieved),
        // verilator lint_off UNSIGNED
        .transit_done(transit_done_t),
        // verilator lint_on UNSIGNED
        .msg_r(msg_recieved),
        .msg_s(msg_sendt)
    );

    always_ff @(CLK_t) begin 
        if(msg_recieved == 1) begin
            output_data = data_recieved;
            send_enable = 1;
        end else begin
        if(msg_sendt == 1) begin
            send_enable = 0;
        end
        end
    end
endmodule