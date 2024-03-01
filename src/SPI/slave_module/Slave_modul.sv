///SPI slave module for sending and recieving data from master in mode 0

module SPI_S_MODULE #(parameter frame_size)
 (
    input i_clock, //input clock
    input MOSI, //serial input from master
    input[frame_size-1:0] MISO_frame, // Data frame for sending to master
    input SC, // slave select
    input MISO_send_enable, // input to send data to master
    input Module_ready
    output MISO, //serial output for sending to master 
    output[frame_size-1:0] MOSI_frame, //output wire for the data recieved
    output transit_done, //for telling if the data is sendt
    output msg_r, // to tell when a message frame is recieved
    output msg_s // to tell when a message frame is sendt
 );
    
    reg[frame_size-1:0] MOSI_Data = 0; //input register med motatt data
    reg[frame_size-1:0] MISO_Data = 0; //output register for sending av data
    reg[7:0] recieve_bit_counter = 0; //counter for which bit is recieved
    reg[7:0] send_bit_counter = 0; // counter for which bit is sendt
    reg msg_recieved; //flag for when message is recieved
    reg msg_sendt; //flag for when message is sendt
    reg MISO_o = 0; //placeholder for data out (funker ikke uten den, vil ha den vekk)
    parameter standby = 1'b1; //state for when SC is high
    parameter active_data = 1'b0; //state for when SC is low

always_comb begin
    msg_r = msg_recieved && !Module_ready;
end


always @(negedge i_clock) begin

    case (SC) //case for recieving data
        standby:
            begin
                MOSI_Data <= 0; //empty data register if SC is 1
                msg_recieved <= 1'b0;
                recieve_bit_counter <= 0;
            end
    
        active_data:
            begin  

                if(recieve_bit_counter == frame_size-1) // to check that the full message is still not recieved
                    begin
                        MOSI_Data[recieve_bit_counter] <= MOSI; 
                        recieve_bit_counter <= 0;
                        msg_recieved <= 1'b1; // to signal that a message is recieved and the next one can start
                    end
                else
                    begin
                        msg_recieved <= 1'b0;
                        MOSI_Data[recieve_bit_counter] <= MOSI; //input bit from serial to recieve register
                        recieve_bit_counter <= recieve_bit_counter +1;
                    end
            end

        default: 
            recieve_bit_counter <= 0;
    endcase
end

always @(posedge i_clock) begin
    
    case (SC) //case for sending data
        standby:
            begin
                send_bit_counter <= 0; // resetter bit counter
            end

        active_data:
            begin
                if(MISO_send_enable == 1)
                    begin
                        if(send_bit_counter<frame_size-1)
                            begin
                                MISO_o <= MISO_frame[send_bit_counter];
                                send_bit_counter <= send_bit_counter +1;
                                msg_sendt <= 1'b0;
                            end
                        else
                            begin
                                MISO_o <= MISO_frame[send_bit_counter];
                                send_bit_counter <=0;
                                msg_sendt <= 1'b1;
                            end
                    end
                else
                    begin
                        msg_sendt <= 1'b1; //signal that a message is sendt to prepeare for the next
                        
                    end
            end

        default: 
            send_bit_counter <= 0;
    endcase
end

        

assign MOSI_frame = MOSI_Data;
assign msg_r = msg_recieved;
assign msg_s = msg_sendt;
assign MISO = MISO_o;

endmodule



parameter frame_width = 32;
parameter on = 1'b1;

reg[frame_width-1:0] noise = 0;
reg on_state = 1'b0;


