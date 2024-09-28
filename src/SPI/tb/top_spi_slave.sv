`timescale 1ns / 1ps
`include "../src/nandland/spi_slave.sv"

module top_spi_slave (
        input clk,
        input rstn,

        input SCK,
        input MOSI,
        output MISO,
        input CSn,

        input btn[4],
        input sw[4],
        output reg LED[4]
    );

    wire SCK_IBUF;
    IBUFG sck_ibuf_inst (.I(SCK), .O(SCK_IBUF));
    // assign SCK_IBUF = SCK;

    logic [7:0] w_RX_Byte;
    logic w_RX_DV;
    logic [7:0] r_TX_Byte = '0;
    logic r_TX_DV = 0;

    logic [7:0] r_RX_Byte;

    spi_slave spi_slave_inst (
        .clk(clk),
        .rstn(rstn),

        // Data signals
        .o_RX_DV(w_RX_DV),
        .o_RX_Byte(w_RX_Byte),
        .i_TX_DV(r_TX_DV),
        .i_TX_Byte(r_TX_Byte),

        // SPI Interface
        .SCK(SCK_IBUF),
        .MOSI(MOSI),
        .MISO(MISO),
        .CSn(CSn)
    );

    always @(posedge clk) begin
        if (~rstn) begin
            r_TX_Byte <= '0;
            r_TX_DV <= 1'b0;
        end else begin
            r_TX_Byte <= {sw[3], sw[2], sw[1], sw[0], btn[3], btn[2], btn[1], btn[0]};
            r_TX_DV <= 1'b1;
        end
    end

    always @(posedge w_RX_DV) begin
        r_RX_Byte <= w_RX_Byte;
    end

    assign LED[0] = r_RX_Byte[0];
    assign LED[1] = r_RX_Byte[1];
    assign LED[2] = r_RX_Byte[2];
    assign LED[3] = r_RX_Byte[3];
endmodule
