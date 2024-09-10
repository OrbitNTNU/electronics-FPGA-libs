
#INPUTS

#clock, pin 1
set_property PACKAGE_PIN A14 [get_ports {SC_t}]                              
   set_property IOSTANDARD LVCMOS33 [get_ports {SC_t}]

#set_property -dict { PACKAGE_PIN A14   IOSTANDARD LVCMOS33 } [get_ports {SC_t}];

#SC, pin2
set_property PACKAGE_PIN A16 [get_ports {CLK_t}]                    
   set_property IOSTANDARD LVCMOS33 [get_ports {CLK_t}]

#set_property -dict { PACKAGE_PIN A16   IOSTANDARD LVCMOS33 } [get_ports {CLK_t}];

#MISO, pin3
set_property PACKAGE_PIN B15 [get_ports {MOSI_t}]               
   set_property IOSTANDARD LVCMOS33 [get_ports {MOSI_t}]

#set_property -dict { PACKAGE_PIN B15   IOSTANDARD LVCMOS33 } [get_ports {MOSI_t}];

#OUTPUTS

#MOSI, pin4
set_property PACKAGE_PIN B16 [get_ports {MISO_t}]          
   set_property IOSTANDARD LVCMOS33 [get_ports {MISO_t}]

#set_property -dict { PACKAGE_PIN B16   IOSTANDARD LVCMOS33 } [get_ports {MISO_t}];


#test led


#set_property -dict { PACKAGE_PIN L1   IOSTANDARD LVCMOS33 } [get_ports {led_state}];

set_property PACKAGE_PIN U16 [get_ports {led}]          
   set_property IOSTANDARD LVCMOS33 [get_ports {led}]




#Status leds

set_property PACKAGE_PIN L1 [get_ports {led_CLK_t}]          
   set_property IOSTANDARD LVCMOS33 [get_ports {led_CLK_t}]

set_property PACKAGE_PIN P1 [get_ports {led_SC_t}]          
   set_property IOSTANDARD LVCMOS33 [get_ports {led_SC_t}]

set_property PACKAGE_PIN N3 [get_ports {led_MOSI_t}]          
   set_property IOSTANDARD LVCMOS33 [get_ports {led_MOSI_t}]

set_property PACKAGE_PIN P3 [get_ports {led_MISO_t}]          
   set_property IOSTANDARD LVCMOS33 [get_ports {led_MISO_t}]

set_property PACKAGE_PIN U3 [get_ports {led_recieved}]          
   set_property IOSTANDARD LVCMOS33 [get_ports {led_recieved}]

#set_property PACKAGE_PIN W3 [get_ports {led_sendt}]          
#   set_property IOSTANDARD LVCMOS33 [get_ports {led_sendt}]





# LED CONFIG ------------------------

#CLOCK

set_property PACKAGE_PIN W5 [get_ports clock_100Mhz]       
 set_property IOSTANDARD LVCMOS33 [get_ports clock_100Mhz]

#LED

set_property PACKAGE_PIN W7 [get_ports {LED_out[6]}]                    
   set_property IOSTANDARD LVCMOS33 [get_ports {LED_out[6]}]
set_property PACKAGE_PIN W6 [get_ports {LED_out[5]}]                    
   set_property IOSTANDARD LVCMOS33 [get_ports {LED_out[5]}]
set_property PACKAGE_PIN U8 [get_ports {LED_out[4]}]                    
   set_property IOSTANDARD LVCMOS33 [get_ports {LED_out[4]}]
set_property PACKAGE_PIN V8 [get_ports {LED_out[3]}]                    
   set_property IOSTANDARD LVCMOS33 [get_ports {LED_out[3]}]
set_property PACKAGE_PIN U5 [get_ports {LED_out[2]}]                    
   set_property IOSTANDARD LVCMOS33 [get_ports {LED_out[2]}]
set_property PACKAGE_PIN V5 [get_ports {LED_out[1]}]                    
   set_property IOSTANDARD LVCMOS33 [get_ports {LED_out[1]}]
set_property PACKAGE_PIN U7 [get_ports {LED_out[0]}]                    
   set_property IOSTANDARD LVCMOS33 [get_ports {LED_out[0]}]

#ANODE

set_property PACKAGE_PIN U2 [get_ports {Anode_Activate[0]}]                    
   set_property IOSTANDARD LVCMOS33 [get_ports {Anode_Activate[0]}]
set_property PACKAGE_PIN U4 [get_ports {Anode_Activate[1]}]                    
   set_property IOSTANDARD LVCMOS33 [get_ports {Anode_Activate[1]}]
set_property PACKAGE_PIN V4 [get_ports {Anode_Activate[2]}]               
   set_property IOSTANDARD LVCMOS33 [get_ports {Anode_Activate[2]}]
set_property PACKAGE_PIN W4 [get_ports {Anode_Activate[3]}]          
   set_property IOSTANDARD LVCMOS33 [get_ports {Anode_Activate[3]}]



