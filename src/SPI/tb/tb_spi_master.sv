`include "../src/nandland/spi_master.sv"

module tb_spi_master
    (
        input clk,
        input rstn
    );

    parameter unsigned SPI_MODE = 0;
    parameter unsigned CLKS_PER_HALF_BIT = 2;       // 6.25 MHz
    parameter unsigend MAX_BYTES_PER_CS = 2;        // 2 bytes per CS
    parameter unsgined CS_INACTIVE_CLKS = 10;       // Delay between bytes

    logic w_SCK;
    logic r_SPI_En = 1'b0;
    logic w_CS_n;
    logic w_SPI_MOSI;

    // Master Spesific
    logic [7:0] r_Master_TX_Byte = 0;
    logic r_Master_TX_DV = 1'b0;
    logic w_Master_TX_Ready;
    logic w_Master_RX_DV;
    logic [7:0] w_Master_RX_Byte;
    logic [$clog2(MAX_BYTES_PER_CS+1)-1:0] w_Master_RX_Count, r_Master_TX_Count = 2'b10;

    spi_master_multibyte
        #(
            .SPI_MODE(SPI_MODE),
            .CLKS_PER_HALF_BIT(CLKS_PER_HALF_BIT),
            .MAX_BYTES_PER_CS(MAX_BYTES_PER_CS),
            .CS_INACTIVE_CLKS(CS_INACTIVE_CLKS)
        ) GoldenSample
        (
            .i_Rst_L(rstn),
            .i_Clk(clk),
            .i_TX_Count(r_Master_TX_Count),
            .i_TX_Byte(r_Master_TX_Byte),
            .i_TX_DV(r_Master_TX_DV),
            .o_TX_Ready(w_Master_TX_Ready),

            // RX (MISO) Signals
            .o_RX_Count(w_Master_RX_Count),
            .o_RX_DV(w_Master_RX_DV),
            .o_RX_Byte(w_Master_RX_Byte),

            // SPI Interface
            .o_SPI_Clk(w_SCK),
            .i_SPI_MISO(w_SPI_MOSI),
            .o_SPI_MOSI(w_SPI_MOSI),
            .o_SPI_CS_n(w_CS_n)
       );

   task static SendSingleByte(input byte [7:0] data);
       @(posedge r_Clk);
       r_Master_TX_Byte <= data;
       r_Master_TX_DV   <= 1'b1;
       @(posedge r_Clk);
       r_Master_TX_DV <= 1'b0;
       @(posedge r_Clk);
       @(posedge w_Master_TX_Ready);
   endtask // SendSingleByte


   initial
   begin
       repeat(10) @(posedge r_Clk);
       r_Rst_L  = 1'b0;
       repeat(10) @(posedge r_Clk);
       r_Rst_L          = 1'b1;

       // Test sending 2 bytes
       SendSingleByte(8'hC1);
       $display("Sent out 0xC1, Received 0x%X", w_Master_RX_Byte);
       SendSingleByte(8'hC2);
       $display("Sent out 0xC2, Received 0x%X", w_Master_RX_Byte);

       repeat(100) @(posedge r_Clk);
       $finish();
   end

endmodule
