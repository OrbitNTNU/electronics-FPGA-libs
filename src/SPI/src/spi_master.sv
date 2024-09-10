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
    input       i_TX_DV,                      // TX Data valid
    output reg  o_TX_Ready,

    // MISO Signals
    output reg  o_RX_DV,                      // RX Data valid
    output reg  [FRAMEWIDTH-1:0] o_RX_Byte,   // Receive data

    // SPI Interface
    output reg  o_SPI_Clk,
    input       i_SPI_MISO,
    output reg  o_SPI_MOSI
    );

    // Params
    localparam unsigned CounterMaxVal = $clog2(FRAMEWIDTH);

    // SPI Interface ~~ SPI Clock Domain
    wire w_CPOL;        // Clock polarity
    wire w_CPHA;        // Clock phase

    reg [$clog2(CLKS_PER_HALF_BIT*2)-1:0] r_SPI_Clk_Count;
    reg r_SPI_Clk;
    reg [4:0] r_SPI_Clk_Edges;
    reg r_Leading_Edge;
    reg r_Trailing_Edge;
    reg r_TX_DV;
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
    assign w_CPHA = (SPI_MODE == 1) | (SPI_MODE == 3);

    always @(posedge clk or negedge rstn) begin
        if (~rstn) begin
            o_TX_Ready      <= 0;
            r_SPI_Clk_Edges <= 0;
            r_Leading_Edge  <= 0;
            r_Trailing_Edge <= 0;
            r_SPI_Clk       <= w_CPOL;
            r_SPI_Clk_Count <= 0;
        end else begin
            r_Leading_Edge  <= 0;
            r_Trailing_Edge <= 0;

            if (i_TX_DV) begin
                o_TX_Ready      <= 0;
                r_SPI_Clk_Edges <= 16;
            end else if (r_SPI_Clk_Edges > 0) begin
                o_TX_Ready <= 0;

                if (r_SPI_Clk_Count == CLKS_PER_HALF_BIT*2 - 1) begin
                    r_SPI_Clk_Edges <= r_SPI_Clk_Edges - 1;
                    r_Trailing_Edge <= 1;
                    r_SPI_Clk_Count <= 0;
                    r_SPI_Clk       <= ~r_SPI_Clk;
                end else if (r_SPI_Clk_Count == CLKS_PER_HALF_BIT-1) begin
                    r_SPI_Clk_Edges <= r_SPI_Clk_Edges - 1;
                    r_Leading_Edge  <= 1;
                    r_SPI_Clk_Count <= r_SPI_Clk_Count + 1;
                    r_SPI_Clk       <= ~r_SPI_Clk;
                end else begin
                    r_SPI_Clk_Count <= r_SPI_Clk_Count + 1;
                end
            end else begin
                o_TX_Ready <= 1;
            end
        end
    end

    // Register i_TX_Byte when Data Valid is pulsed
    always @(posedge clk or negedge rstn) begin
        if (~rstn) begin
            r_TX_Byte <= 0;
            r_TX_DV   <= 0;
        end else begin
            r_TX_DV <= i_TX_DV;
            if (i_TX_DV) begin
                r_TX_Byte <= i_TX_Byte;
            end
        end
    end

    // Generate MOSI data
    always @(posedge clk or negedge rstn) begin
        if (~rstn) begin
            o_SPI_MOSI     <= 0;
            r_TX_Bit_Count <= CounterMaxVal;   // Send MSB first
        end else begin
            if (o_TX_Ready) begin
                r_TX_Bit_Count <= CounterMaxVal;
            end else if (r_TX_DV & ~w_CPHA) begin
                o_SPI_MOSI     <= r_TX_Byte[CounterMaxVal];
                r_TX_Bit_Count <= CounterMaxVal - 1;
            end else if ((r_Leading_Edge & w_CPHA) | (r_Trailing_Edge & ~w_CPHA)) begin
                r_TX_Bit_Count <= r_TX_Bit_Count - 1;
                o_SPI_MOSI     <= r_TX_Byte[r_TX_Bit_Count];
            end
        end
    end

    // Read MISO data
    always @(posedge clk or negedge rstn) begin
        if (~rstn) begin
            o_RX_Byte      <= 0;
            o_RX_DV        <= 0;
            r_RX_Bit_Count <= CounterMaxVal;
        end else begin
            o_RX_DV <= 0;

            if (o_TX_Ready) begin
                r_RX_Bit_Count <= CounterMaxVal;
            end else if ((r_Leading_Edge & ~w_CPHA) | (r_Trailing_Edge & w_CPHA)) begin
                o_RX_Byte[r_RX_Bit_Count] <= i_SPI_MISO;  // Sample data
                r_RX_Bit_Count            <= r_RX_Bit_Count - 1;

                if (r_RX_Bit_Count == 0) begin
                    o_RX_DV <= 1;
                end
            end
        end
    end

    // Add clock delay to signals for alignment
    always @(posedge clk or negedge rstn) begin
        if (~rstn) begin
            o_SPI_Clk <= w_CPOL;
        end else begin
            o_SPI_Clk <= r_SPI_Clk;
        end
    end
endmodule
