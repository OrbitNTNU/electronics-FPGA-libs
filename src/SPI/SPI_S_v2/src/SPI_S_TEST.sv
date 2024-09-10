`include "src/Slave_modul.sv"

module SPI_S_TEST (
    input clock_100Mhz, // 100 Mhz clock source on Basys 3 FPGA
    input CLK_t,
    input MOSI_t,
    input SC_t,
    output MISO_t,

    output led,
    output led_CLK_t,
    output led_MOSI_t,
    output led_SC_t,


    output led_recieved,

    output reg [3:0] Anode_Activate, // anode signals of the 7-segment LED display
    output reg [6:0] LED_out// cathode patterns of the 7-segment LED display
);



reg[31:0] output_data;


logic msg_recieved;

reg[31:0] data_recieved;


reg led_state = 0;

// DISPLAY COUNTER AND INPUT ---------------------

reg [26:0] one_second_counter; // counter for generating 1 second clock enable

reg [15:0] displayed_number = 16'h000F; // counting number to be displayed
reg [3:0] LED_BCD;
reg [19:0] refresh_counter; // 20-bit for creating 10.5ms refresh period or 380Hz refresh rate
             // the first 2 MSB bits for creating 4 LED-activating signals with 2.6ms digit period
wire [1:0] LED_activating_counter; 
                 // count     0    ->  1  ->  2  ->  3
              // activates    LED1    LED2   LED3   LED4
             // and repeat
    always @(posedge clock_100Mhz)
    begin
         
            if(one_second_counter>=99999999) 
                 one_second_counter <= 0;
            else
                one_second_counter <= one_second_counter + 1;
        
    end 

  

    always @(posedge clock_100Mhz)
    begin 
            refresh_counter <= refresh_counter + 1;
    end 
    assign LED_activating_counter = refresh_counter[19:18];
    // anode activating signals for 4 LEDs, digit period of 2.6ms
    // decoder to generate anode signals 
    always @(*)
    begin
        case(LED_activating_counter)
        2'b00: begin
            Anode_Activate = 4'b0111; 
            // activate LED1 and Deactivate LED2, LED3, LED4
            LED_BCD = displayed_number/1000;
            // the first digit of the 16-bit number
              end
        2'b01: begin
            Anode_Activate = 4'b1011; 
            // activate LED2 and Deactivate LED1, LED3, LED4
            LED_BCD = (displayed_number % 1000)/100;
            // the second digit of the 16-bit number
              end
        2'b10: begin
            Anode_Activate = 4'b1101; 
            // activate LED3 and Deactivate LED2, LED1, LED4
            LED_BCD = ((displayed_number % 1000)%100)/10;
            // the third digit of the 16-bit number
                end
        2'b11: begin
            Anode_Activate = 4'b1110; 
            // activate LED4 and Deactivate LED2, LED3, LED1
            LED_BCD = ((displayed_number % 1000)%100)%10;
            // the fourth digit of the 16-bit number    
               end
        endcase
    end
    // Cathode patterns of the 7-segment LED display 
    always @(*)
    begin
        case(LED_BCD)
        4'b0000: LED_out = 7'b0000001; // "0"     
        4'b0001: LED_out = 7'b1001111; // "1" 
        4'b0010: LED_out = 7'b0010010; // "2" 
        4'b0011: LED_out = 7'b0000110; // "3" 
        4'b0100: LED_out = 7'b1001100; // "4" 
        4'b0101: LED_out = 7'b0100100; // "5" 
        4'b0110: LED_out = 7'b0100000; // "6" 
        4'b0111: LED_out = 7'b0001111; // "7" 
        4'b1000: LED_out = 7'b0000000; // "8"     
        4'b1001: LED_out = 7'b0000100; // "9" 
        default: LED_out = 7'b0000001; // "0"
        endcase
    end

     
//SPI MODULE INTERACTION -------------------


    Slave_modul #(.frame_size(31)) SPI_INST
    (
         //Internal signals
    .clk(clock_100Mhz), //The FPGA clock
    .msg_recieved(msg_recieved),
    .MOSI_DATA(data_recieved),
    .MISO_DATA(output_data),

    //External signals

    .SCK(CLK_t), //Clock input from OBC
    .SSEL(SC_t), // slave select
    .MOSI(MOSI_t), // Data input from OBC
    .MISO(MISO_t) // Data output to OBC
    );

    always @(posedge clock_100Mhz) begin 
        if(msg_recieved) begin
            output_data <= data_recieved;
            displayed_number <= data_recieved[15:0];
            led_state <= 1;
        end
        else
        begin
            led_state <= 0;
        end
    end

assign led = led_state;

    
assign led_CLK_t = CLK_t;
assign led_SC_t = SC_t;
assign led_MOSI_t = MOSI_t;



assign led_recieved = msg_recieved;


endmodule
