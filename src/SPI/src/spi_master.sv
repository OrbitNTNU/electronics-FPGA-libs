// SPI Master Module
// SCK is a quarter of the clock rate of the input clock clk

// `timescale 1ns/1ps
typedef enum logic [1:0] {
    IDLE = 2'b00,
    TRANSFER = 2'b01,
    CS_INACTIVE = 2'b10
} spi_master_state_t /*verilator public*/;

module spi_master
    #(
    parameter unsigned CLKS_PER_HALF_BIT = 2,
    parameter unsigned CS_INACTIVE_CLKS  = 1
    ) (
    input clk,
    input rstn,

    // MOSI Signals
    input [7:0]  i_TX_Byte,
    input        i_TX_DV,
    output       o_TX_Ready,

    // MISO
    output reg [$clog2(MAX_BYTES_PER_CS+1)-1:0] o_RX_Count,
    output       o_RX_DV,
    output [7:0] o_RX_Byte,

    // SPI Interface
    output o_SCK,
    input  i_MISO,
    output o_MOSI,
    output o_CS_n
    );

    spi_master_state_t current_state = IDLE;

    reg r_CS_n;
    reg [$clog2(CS_INACTIVE_CLKS)-1:0] r_CS_Inactive_Count;

    reg [$clog2(CLKS_PER_HALF_BIT*2)-1:0] r_SCK_Count;
    reg r_SCK;
    reg [4:0] r_SCK_Edges;
    reg r_Leading_Edge;
    reg r_Trailing_Edge;
    reg r_TX_DV;
    reg [7:0] r_TX_Byte;

    reg [2:0] r_RX_Bit_Count;
    reg [2:0] r_TX_Bit_Count;

    always_ff @(posedge clk or negedge rstn) begin
        if (~rstn) begin
            o_TX_Ready <= 1'b0;
            r_SCK_Edges <= '0;
            r_Leading_Edge <= 1'b0;
            r_Trailing_Edge <= 1'b0;
            r_SCK <= 1'b0;
            r_SCK_Count <= '0;
        end else begin
            
        end
    end

    always_ff @(posedge clk or negedge rstn) begin
        if (~rstn) begin
            current_state <= IDLE;
            r_CS_Inactive_count <= CS_INACTIVE_CLKS;
        end else begin
            case (current_state)
                IDLE: begin
                    if (r_CS_n & i_TX_DV) begin
                        r_CS_n <= 1'b0;
                        current_state <= TRANSFER;
                    end
                end

                TRANSFER: begin
                    if (ready_r) begin
                        r_CS_n <= 1'b1;
                        r_CS_Inactive_count <= CS_INACTIVE_CLKS;
                        current_state <= CS_INACTIVE;
                    end
                end

                CS_INACTIVE: begin
                    r_CS_n <= 1'b1;
                    current_state <= IDLE;
                end

                default: current_state <= IDLE;
            endcase
        end
    end

    assign o_CS_n = r_CS_n;
    assign o_TX_Ready = r_SM_CS == IDLE & ~i_TX_DV;
endmodule
