// Module for SPI Master
// Based on https://github.com/nandland/spi-master

`timescale 1ns / 1ps

module spi_master
    #(
    parameter signed FRAMEWIDTH = 8,
    parameter signed SPI_MODE = 0,          // Which SPI mode should it run
    parameter signed CLKS_PER_HALF_BIT = 2  // How much do we over-clock the controller clock
    ) (
    // Control Signals
    input rstn,   // Controller reset
    input clk,    // Controller input clock

    // MOSI Signals
    input       [FRAMEWIDTH-1:0] i_TX_Byte,   // Send data
    input       i_TX_dv,                      // TX Data valid
    output reg  r_TX_Ready,

    // MISO Signals
    output reg  r_RX_dv,                      // RX Data valid
    output reg  [FRAMEWIDTH-1:0] r_RX_Byte,   // Receive data

    // SPI Interface
    output reg  r_SPI_Clk,
    input       i_SPI_MISO,
    output reg  r_SPI_MOSI
    );

    // SPI Interface ~~ SPI Clock Domain
    wire w_CPOL;        // Clock polarity
    wire w_CPHA;        // Clock phase

    reg [$clog2(CLKS_PER_HALF_BIT*2)-1:0] r_SPI_Clk_Count;
    reg r_SPI_Clk;
    reg [4:0] r_SPI_Clk_Edges;
    reg r_Leading_Edge;
    reg r_Trailing_Edge;
    reg r_TX_dv;
    reg [FRAMEWIDTH-1:0] r_TX_Byte;

    reg [$clog2(FRAMEWIDTH)-1:0] r_RX_Bit_Count;
    reg [$clog2(FRAMEWIDTH)-1:0] r_TX_Bit_Count;

    // CPOL = 0 -> idle at 0, leading edge is rising edge
    // CPOL = 1 -> idle at 1, leading edge is falling edge
    assign w_CPOL = (SPI_MODE == 2) | (SPI_MODE == 3);

    // CPOL = 0 -> out side changes the data on trailing edge of clock
    //             in side captures data on leading edge of clock
    // CPOL = 1 -> out side changes the data on leading edge of clock
    //             in side captures the data on the trailing edge of clock
    assign w_CHPA = (SPI_MODE == 1) | (SPI_MODE == 3);

    always @(posedge clk or negedge rstn) begin
        if (~rstn) begin
            o_TX_Ready      <= 1'b0;
            r_SPI_Clk_Edges <= 0;
            r_Leading_Edge  <= 1'b0;
            r_Trailing_Edge <= 1'b0;
            r_SPI_Clk       <= w_CPOL;
            r_SPI_Clk_Count <= 0;
        end else begin
            r_Leading_Edge  <= 1'b0;
            r_Trailing_Edge <= 1'b0;

            if (i_TX_dv) begin
                o_TX_Ready      <= 1'b0;
                r_SPI_Clk_Edges <= 16;
            end else if (r_SPI_Clk_Edges > 0) begin
                o_TX_Ready <= 1'b0;

                if (r_SPI_Clk_Count == CLKS_PER_HALF_BIT*2 - 1) begin
                    r_SPI_Clk_Edges <= r_SPI_Clk_Edges - 1'b1;
                    r_Trailing_Edge <= 1'b1;
                    r_SPI_Clk_Count <= 0;
                    r_SPI_Clk       <= ~r_SPI_Clk;
                end else if (r_SPI_Clk_Count == CLKS_PER_HALF_BIT-1) begin
                    r_SPI_Clk_Edges <= r_SPI_Clk_Edges - 1'b1;
                    r_Leading_edge  <= 1'b1;
                    r_SPI_Clk_Count <= r_SPI_Clk_Count + 1'b1;
                    r_SPI_Clk       <= ~r_SPI_Clk;
                end else begin
                    r_SPI_Clk_Count <= r_SPI_Clk_Count + 1'b1;
                end
            end else begin
                o_TX_Ready <= 1'b1;
            end
        end
    end

    // Generate MOSI data

endmodule
