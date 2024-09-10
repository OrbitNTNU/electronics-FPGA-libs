///SPI slave module for sending and recieving data from master in mode 0

module Slave_modul #(parameter frame_size)
(
    //Internal signals
    input clk, //The FPGA clock
    input [frame_size:0] MISO_DATA,

    output [frame_size:0] MOSI_DATA,
    output msg_recieved,
    

    //External signals

    input SCK, //Clock input from OBC
    input SSEL, // slave select
    input MOSI, // Data input from OBC

    output MISO // Data output to OBC
);


//Sampling input signals from OBC - - - - - - - - - - - - - - - - - -

reg [2:0] SCKr; always @(posedge clk) SCKr <= {SCKr[1:0], SSEL}; // Shift SCKr register one to the left
wire SCK_risingedge = (SCKr[2:1] == 2'b01); // 0 - 1 bit sequence indicates a rising edge
wire SCK_fallingedge = (SCKr[2:1] == 2'b10); // 1 - 0 bit sequence indicates a falling edge


reg [2:0] SSELr; always @(posedge clk) SSELr <= {SSELr[1:0], SSEL}; // Shift SSELr register one to the left
wire SSEL_active = ~SSELr[1]; //SSEL is set to active low
wire SSEL_startmessage = (SSELr[2:1] == 2'b01); // Detect rising edge
wire SSEL_endmessage = (SSELr[2:1] == 2'b10); // Detect falling edge

reg [1:0] MOSIr; always @(posedge clk) MOSIr <= {MOSIr[0], MOSI};
wire MOSI_data = MOSIr[1];

//Handling MOSI - - - - - - - - - - - - - - - - - -

reg[4:0] bit_count;

reg byte_recieved; // Set high when data recieved
reg [frame_size:0] byte_data_recieved;

always @(posedge clk)
begin
    if(~SSEL_active)
        bit_count <= 5'b00000;
    else
    if(SCK_risingedge)
    begin
        bit_count <= bit_count + 5'b00001;

        byte_data_recieved <= {byte_data_recieved[frame_size-1:0], MOSI_data};
    end
end

always @(posedge clk) byte_recieved <= SSEL_active && SCK_risingedge && (bit_count == 5'b11111);


//Handling MISO - - - - - - - - - - - - - - - - - -


reg [frame_size:0] byte_data_sendt;

reg [frame_size:0] cnt;

always @(posedge clk) if(SSEL_startmessage) cnt <= cnt+32'h1;

always @(posedge clk)
if(SSEL_active)
begin
    if(SSEL_startmessage)
        byte_data_sendt <= cnt;
    else
    if(SCK_fallingedge)
    begin
        if(bit_count == 5'b00000)
            byte_data_sendt <= 32'h00000000;
        else
            byte_data_sendt <= {byte_data_sendt[frame_size-1:0], 1'b0};
    end
end

//Assignments - - - - - - - - - - - - - - - - - -

assign MISO = byte_data_sendt[frame_size];  
assign MOSI_DATA = byte_recieved;
assign msg_recieved = byte_recieved;  
endmodule