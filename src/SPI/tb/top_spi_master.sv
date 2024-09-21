`timescale 1ns / 1ns
`include "../src/nandland/spi_master.sv"
`include "../src/nandland/spi_master_multibyte.sv"

module top_spi_master
    #()
    (
    input clk,
    input rstn,

    // Data input from switches/buttons
    /* verilator lint_off LITENDIAN */
    input [0:3] sw,
    input [0:3] btn,
    /* verilator lint_on LITENDIAN */

    // SPI I/O
    input MISO,
    output MOSI,
    output SCK,
    output CSn,

    output LED_rst
    );

    localparam unsigned ClksPerShownByte = 50_000_000;

    localparam unsigned MaxNumBytesPerCS = 8;
    localparam unsigned ClksPerHalfBit = 10;     // 1.0 Mhz
    localparam unsigned CSInactiveClks = 8;

    logic [$clog2(MaxNumBytesPerCS+1)-1:0] r_TX_Count = 1;
    logic [$clog2(MaxNumBytesPerCS+1)-1:0] w_RX_Count;
    logic r_TX_DV = 1'b0;
    logic w_RX_DV;
    logic w_TX_Ready;
    logic [7:0] r_TX_Byte = '0;
    logic [7:0] w_RX_Byte;

    logic led_state = 0;

    spi_master_multibyte
        #(
        .SPI_MODE(0),
        .CLKS_PER_HALF_BIT(ClksPerHalfBit),
        .MAX_BYTES_PER_CS(MaxNumBytesPerCS),
        .CS_INACTIVE_CLKS(CSInactiveClks)
        ) master (
        .clk(clk),
        .rstn(rstn),

        // RX/TX Byte counts
        .i_TX_Count(w_TX_Count),
        .o_RX_Count(w_RX_COunt),

        // I/O Data valid
        .i_TX_DV(r_TX_DV),
        .o_RX_DV(w_RX_DV),

        // TX ready signal
        .o_TX_Ready(w_TX_Ready),

        // RX/TX Byte
        .i_TX_Byte(r_TX_Byte),
        .o_RX_Byte(w_RX_Byte),

        // SPI Signals
        .o_SPI_Clk(SCK),
        .i_SPI_MISO(MISO),
        .o_SPI_MOSI(MOSI),
        .o_SPI_CS_n(CSn)
        );

    always @(posedge clk) begin
        r_TX_Byte = {btn, sw};
    end

    always @(posedge clk) begin
        if (~rstn) begin
            led_state <= 1'b1;

        end else begin
            led_state <= 1'b0;

            if (w_TX_Ready) begin
                r_TX_DV <= 1'b1;
            end else begin
                r_TX_DV <= 1'b0;
            end
        end
    end

    assign LED_rst = led_state;

endmodule
