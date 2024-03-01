module SPI_MASTER #(parameter frame_size) (
    input ckl, //input ifra top modul
    input SE,
    input[frame_size-1:0] MOSI_data,
    input MISO,
    output msg_sendt,
    output MOSI,
    output i_clock
);

parameter standby = 1'b1; //state for when SE is high
parameter active_data = 1'b0; //state for when SE is low
reg[7:0] send_bit_counter = 0;
reg msg_sendt_flag;
reg MOSI_o;



always @(posedge ckl) begin
    
    case (SE) //case for sending data
        standby:
            begin
                send_bit_counter <= 0; // resetter bit counter
                msg_sendt_flag <= 1'b0;
            end

        active_data:
            begin
                        if(send_bit_counter<frame_size-1)
                            begin
                                MOSI_o <= MOSI_data[send_bit_counter]; //sending next bit
                                send_bit_counter <= send_bit_counter +1;
                                msg_sendt_flag <= 1'b0;
                            end
                        else
                            begin
                                MOSI_o <= MOSI_data[send_bit_counter]; //sending last bit
                                send_bit_counter <=0; 
                                msg_sendt_flag <= 1'b1;
                            end
                    end
        default: 
            begin
            send_bit_counter <= 0;
            msg_sendt_flag <= 1'b1;
            end
    endcase
end


assign MOSI = MOSI_o;
assign i_clock = ckl;
assign msg_sendt = msg_sendt_flag;


endmodule