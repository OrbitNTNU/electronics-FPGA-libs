// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2023.2 (lin64) Build 4029153 Fri Oct 13 20:13:54 MDT 2023
// Date        : Fri Sep  6 18:54:32 2024
// Host        : eskilrl-Yoga-Pro-9-14IRP8 running 64-bit Ubuntu 22.04.4 LTS
// Command     : write_verilog -force ./out//netlist.v -mode timesim -sdf_anno true
// Design      : SPI_S_TEST
// Purpose     : This verilog netlist is a timing simulation representation of the design and should not be modified or
//               synthesized. Please ensure that this netlist is used with the corresponding SDF file.
// Device      : xc7a35tcpg236-1
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps
`define XIL_TIMING

(* ECO_CHECKSUM = "329c20a3" *) 
(* NotValidForBitStream *)
module SPI_S_TEST
   (clock_100Mhz,
    CLK_t,
    MOSI_t,
    SC_t,
    MISO_t,
    led,
    led_CLK_t,
    led_MOSI_t,
    led_SC_t,
    led_MISO_t,
    led_sendt,
    led_recieved,
    Anode_Activate,
    LED_out);
  input clock_100Mhz;
  input CLK_t;
  input MOSI_t;
  input SC_t;
  output MISO_t;
  output led;
  output led_CLK_t;
  output led_MOSI_t;
  output led_SC_t;
  output led_MISO_t;
  output led_sendt;
  output led_recieved;
  output [3:0]Anode_Activate;
  output [6:0]LED_out;

  wire [3:0]Anode_Activate;
  wire [3:0]Anode_Activate_OBUF;
  wire CLK_t;
  wire [1:0]LED_activating_counter;
  wire [6:0]LED_out;
  wire [6:0]LED_out_OBUF;
  wire \LED_out_OBUF[6]_inst_i_2_n_0 ;
  wire MISO_t;
  wire MOSI_t;
  wire SC_t;
  wire clock_100Mhz;
  wire clock_100Mhz_IBUF;
  wire clock_100Mhz_IBUF_BUFG;
  wire led;
  wire led_CLK_t;
  wire led_CLK_t_OBUF;
  wire led_MISO_t;
  wire led_MOSI_t;
  wire led_MOSI_t_OBUF;
  wire led_SC_t;
  wire led_SC_t_OBUF;
  wire led_recieved;
  wire led_sendt;
  wire \refresh_counter[0]_i_2_n_0 ;
  wire \refresh_counter_reg[0]_i_1_n_0 ;
  wire \refresh_counter_reg[0]_i_1_n_4 ;
  wire \refresh_counter_reg[0]_i_1_n_5 ;
  wire \refresh_counter_reg[0]_i_1_n_6 ;
  wire \refresh_counter_reg[0]_i_1_n_7 ;
  wire \refresh_counter_reg[12]_i_1_n_0 ;
  wire \refresh_counter_reg[12]_i_1_n_4 ;
  wire \refresh_counter_reg[12]_i_1_n_5 ;
  wire \refresh_counter_reg[12]_i_1_n_6 ;
  wire \refresh_counter_reg[12]_i_1_n_7 ;
  wire \refresh_counter_reg[16]_i_1_n_4 ;
  wire \refresh_counter_reg[16]_i_1_n_5 ;
  wire \refresh_counter_reg[16]_i_1_n_6 ;
  wire \refresh_counter_reg[16]_i_1_n_7 ;
  wire \refresh_counter_reg[4]_i_1_n_0 ;
  wire \refresh_counter_reg[4]_i_1_n_4 ;
  wire \refresh_counter_reg[4]_i_1_n_5 ;
  wire \refresh_counter_reg[4]_i_1_n_6 ;
  wire \refresh_counter_reg[4]_i_1_n_7 ;
  wire \refresh_counter_reg[8]_i_1_n_0 ;
  wire \refresh_counter_reg[8]_i_1_n_4 ;
  wire \refresh_counter_reg[8]_i_1_n_5 ;
  wire \refresh_counter_reg[8]_i_1_n_6 ;
  wire \refresh_counter_reg[8]_i_1_n_7 ;
  wire \refresh_counter_reg_n_0_[0] ;
  wire \refresh_counter_reg_n_0_[10] ;
  wire \refresh_counter_reg_n_0_[11] ;
  wire \refresh_counter_reg_n_0_[12] ;
  wire \refresh_counter_reg_n_0_[13] ;
  wire \refresh_counter_reg_n_0_[14] ;
  wire \refresh_counter_reg_n_0_[15] ;
  wire \refresh_counter_reg_n_0_[16] ;
  wire \refresh_counter_reg_n_0_[17] ;
  wire \refresh_counter_reg_n_0_[1] ;
  wire \refresh_counter_reg_n_0_[2] ;
  wire \refresh_counter_reg_n_0_[3] ;
  wire \refresh_counter_reg_n_0_[4] ;
  wire \refresh_counter_reg_n_0_[5] ;
  wire \refresh_counter_reg_n_0_[6] ;
  wire \refresh_counter_reg_n_0_[7] ;
  wire \refresh_counter_reg_n_0_[8] ;
  wire \refresh_counter_reg_n_0_[9] ;
  wire [2:0]\NLW_LED_out_OBUF[6]_inst_i_2_CO_UNCONNECTED ;
  wire [3:0]\NLW_LED_out_OBUF[6]_inst_i_2_O_UNCONNECTED ;
  wire [2:0]\NLW_refresh_counter_reg[0]_i_1_CO_UNCONNECTED ;
  wire [2:0]\NLW_refresh_counter_reg[12]_i_1_CO_UNCONNECTED ;
  wire [3:0]\NLW_refresh_counter_reg[16]_i_1_CO_UNCONNECTED ;
  wire [2:0]\NLW_refresh_counter_reg[4]_i_1_CO_UNCONNECTED ;
  wire [2:0]\NLW_refresh_counter_reg[8]_i_1_CO_UNCONNECTED ;

initial begin
 $sdf_annotate("netlist.sdf",,,,"tool_control");
end
  OBUF \Anode_Activate_OBUF[0]_inst 
       (.I(Anode_Activate_OBUF[0]),
        .O(Anode_Activate[0]));
  (* SOFT_HLUTNM = "soft_lutpair1" *) 
  LUT2 #(
    .INIT(4'h7)) 
    \Anode_Activate_OBUF[0]_inst_i_1 
       (.I0(LED_activating_counter[1]),
        .I1(LED_activating_counter[0]),
        .O(Anode_Activate_OBUF[0]));
  OBUF \Anode_Activate_OBUF[1]_inst 
       (.I(Anode_Activate_OBUF[1]),
        .O(Anode_Activate[1]));
  LUT2 #(
    .INIT(4'hB)) 
    \Anode_Activate_OBUF[1]_inst_i_1 
       (.I0(LED_activating_counter[0]),
        .I1(LED_activating_counter[1]),
        .O(Anode_Activate_OBUF[1]));
  OBUF \Anode_Activate_OBUF[2]_inst 
       (.I(Anode_Activate_OBUF[2]),
        .O(Anode_Activate[2]));
  (* SOFT_HLUTNM = "soft_lutpair1" *) 
  LUT2 #(
    .INIT(4'hB)) 
    \Anode_Activate_OBUF[2]_inst_i_1 
       (.I0(LED_activating_counter[1]),
        .I1(LED_activating_counter[0]),
        .O(Anode_Activate_OBUF[2]));
  OBUF \Anode_Activate_OBUF[3]_inst 
       (.I(Anode_Activate_OBUF[3]),
        .O(Anode_Activate[3]));
  (* SOFT_HLUTNM = "soft_lutpair0" *) 
  LUT2 #(
    .INIT(4'hE)) 
    \Anode_Activate_OBUF[3]_inst_i_1 
       (.I0(LED_activating_counter[1]),
        .I1(LED_activating_counter[0]),
        .O(Anode_Activate_OBUF[3]));
  IBUF CLK_t_IBUF_inst
       (.I(CLK_t),
        .O(led_CLK_t_OBUF));
  OBUF \LED_out_OBUF[0]_inst 
       (.I(LED_out_OBUF[0]),
        .O(LED_out[0]));
  (* OPT_MODIFIED = "PROPCONST" *) 
  LUT3 #(
    .INIT(8'h7B)) 
    \LED_out_OBUF[0]_inst_i_1 
       (.I0(LED_activating_counter[0]),
        .I1(LED_activating_counter[1]),
        .I2(\LED_out_OBUF[6]_inst_i_2_n_0 ),
        .O(LED_out_OBUF[0]));
  OBUF \LED_out_OBUF[1]_inst 
       (.I(LED_out_OBUF[1]),
        .O(LED_out[1]));
  (* OPT_MODIFIED = "PROPCONST" *) 
  LUT3 #(
    .INIT(8'h4C)) 
    \LED_out_OBUF[1]_inst_i_1 
       (.I0(LED_activating_counter[0]),
        .I1(LED_activating_counter[1]),
        .I2(\LED_out_OBUF[6]_inst_i_2_n_0 ),
        .O(LED_out_OBUF[1]));
  OBUF \LED_out_OBUF[2]_inst 
       (.I(LED_out_OBUF[2]),
        .O(LED_out[2]));
  (* OPT_MODIFIED = "PROPCONST" *) 
  LUT3 #(
    .INIT(8'hE0)) 
    \LED_out_OBUF[2]_inst_i_1 
       (.I0(LED_activating_counter[0]),
        .I1(\LED_out_OBUF[6]_inst_i_2_n_0 ),
        .I2(LED_activating_counter[1]),
        .O(LED_out_OBUF[2]));
  OBUF \LED_out_OBUF[3]_inst 
       (.I(LED_out_OBUF[3]),
        .O(LED_out[3]));
  (* OPT_MODIFIED = "PROPCONST" *) 
  LUT3 #(
    .INIT(8'h60)) 
    \LED_out_OBUF[3]_inst_i_1 
       (.I0(LED_activating_counter[0]),
        .I1(\LED_out_OBUF[6]_inst_i_2_n_0 ),
        .I2(LED_activating_counter[1]),
        .O(LED_out_OBUF[3]));
  OBUF \LED_out_OBUF[4]_inst 
       (.I(LED_out_OBUF[4]),
        .O(LED_out[4]));
  (* OPT_MODIFIED = "PROPCONST" *) 
  (* SOFT_HLUTNM = "soft_lutpair0" *) 
  LUT3 #(
    .INIT(8'h02)) 
    \LED_out_OBUF[4]_inst_i_1 
       (.I0(LED_activating_counter[1]),
        .I1(\LED_out_OBUF[6]_inst_i_2_n_0 ),
        .I2(LED_activating_counter[0]),
        .O(LED_out_OBUF[4]));
  OBUF \LED_out_OBUF[5]_inst 
       (.I(LED_out_OBUF[5]),
        .O(LED_out[5]));
  (* OPT_MODIFIED = "PROPCONST" *) 
  LUT3 #(
    .INIT(8'h80)) 
    \LED_out_OBUF[5]_inst_i_1 
       (.I0(LED_activating_counter[1]),
        .I1(\LED_out_OBUF[6]_inst_i_2_n_0 ),
        .I2(LED_activating_counter[0]),
        .O(LED_out_OBUF[5]));
  OBUF \LED_out_OBUF[6]_inst 
       (.I(LED_out_OBUF[6]),
        .O(LED_out[6]));
  (* OPT_MODIFIED = "PROPCONST" *) 
  LUT3 #(
    .INIT(8'h40)) 
    \LED_out_OBUF[6]_inst_i_1 
       (.I0(LED_activating_counter[0]),
        .I1(\LED_out_OBUF[6]_inst_i_2_n_0 ),
        .I2(LED_activating_counter[1]),
        .O(LED_out_OBUF[6]));
  (* OPT_MODIFIED = "PROPCONST" *) 
  CARRY4 \LED_out_OBUF[6]_inst_i_2 
       (.CI(1'b0),
        .CO({\LED_out_OBUF[6]_inst_i_2_n_0 ,\NLW_LED_out_OBUF[6]_inst_i_2_CO_UNCONNECTED [2:0]}),
        .CYINIT(1'b1),
        .DI({1'b0,1'b1,1'b1,1'b1}),
        .O(\NLW_LED_out_OBUF[6]_inst_i_2_O_UNCONNECTED [3:0]),
        .S({1'b1,1'b0,1'b0,1'b0}));
  OBUF MISO_t_OBUF_inst
       (.I(1'b0),
        .O(MISO_t));
  IBUF MOSI_t_IBUF_inst
       (.I(MOSI_t),
        .O(led_MOSI_t_OBUF));
  IBUF SC_t_IBUF_inst
       (.I(SC_t),
        .O(led_SC_t_OBUF));
  BUFG clock_100Mhz_IBUF_BUFG_inst
       (.I(clock_100Mhz_IBUF),
        .O(clock_100Mhz_IBUF_BUFG));
  IBUF clock_100Mhz_IBUF_inst
       (.I(clock_100Mhz),
        .O(clock_100Mhz_IBUF));
  OBUF led_CLK_t_OBUF_inst
       (.I(led_CLK_t_OBUF),
        .O(led_CLK_t));
  OBUFT led_MISO_t_OBUF_inst
       (.I(1'b0),
        .O(led_MISO_t),
        .T(1'b1));
  OBUF led_MOSI_t_OBUF_inst
       (.I(led_MOSI_t_OBUF),
        .O(led_MOSI_t));
  OBUF led_OBUF_inst
       (.I(1'b0),
        .O(led));
  OBUF led_SC_t_OBUF_inst
       (.I(led_SC_t_OBUF),
        .O(led_SC_t));
  OBUF led_recieved_OBUF_inst
       (.I(1'b0),
        .O(led_recieved));
  OBUF led_sendt_OBUF_inst
       (.I(1'b0),
        .O(led_sendt));
  LUT1 #(
    .INIT(2'h1)) 
    \refresh_counter[0]_i_2 
       (.I0(\refresh_counter_reg_n_0_[0] ),
        .O(\refresh_counter[0]_i_2_n_0 ));
  FDRE \refresh_counter_reg[0] 
       (.C(clock_100Mhz_IBUF_BUFG),
        .CE(1'b1),
        .D(\refresh_counter_reg[0]_i_1_n_7 ),
        .Q(\refresh_counter_reg_n_0_[0] ),
        .R(1'b0));
  (* ADDER_THRESHOLD = "11" *) 
  CARRY4 \refresh_counter_reg[0]_i_1 
       (.CI(1'b0),
        .CO({\refresh_counter_reg[0]_i_1_n_0 ,\NLW_refresh_counter_reg[0]_i_1_CO_UNCONNECTED [2:0]}),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b1}),
        .O({\refresh_counter_reg[0]_i_1_n_4 ,\refresh_counter_reg[0]_i_1_n_5 ,\refresh_counter_reg[0]_i_1_n_6 ,\refresh_counter_reg[0]_i_1_n_7 }),
        .S({\refresh_counter_reg_n_0_[3] ,\refresh_counter_reg_n_0_[2] ,\refresh_counter_reg_n_0_[1] ,\refresh_counter[0]_i_2_n_0 }));
  FDRE \refresh_counter_reg[10] 
       (.C(clock_100Mhz_IBUF_BUFG),
        .CE(1'b1),
        .D(\refresh_counter_reg[8]_i_1_n_5 ),
        .Q(\refresh_counter_reg_n_0_[10] ),
        .R(1'b0));
  FDRE \refresh_counter_reg[11] 
       (.C(clock_100Mhz_IBUF_BUFG),
        .CE(1'b1),
        .D(\refresh_counter_reg[8]_i_1_n_4 ),
        .Q(\refresh_counter_reg_n_0_[11] ),
        .R(1'b0));
  FDRE \refresh_counter_reg[12] 
       (.C(clock_100Mhz_IBUF_BUFG),
        .CE(1'b1),
        .D(\refresh_counter_reg[12]_i_1_n_7 ),
        .Q(\refresh_counter_reg_n_0_[12] ),
        .R(1'b0));
  (* ADDER_THRESHOLD = "11" *) 
  CARRY4 \refresh_counter_reg[12]_i_1 
       (.CI(\refresh_counter_reg[8]_i_1_n_0 ),
        .CO({\refresh_counter_reg[12]_i_1_n_0 ,\NLW_refresh_counter_reg[12]_i_1_CO_UNCONNECTED [2:0]}),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O({\refresh_counter_reg[12]_i_1_n_4 ,\refresh_counter_reg[12]_i_1_n_5 ,\refresh_counter_reg[12]_i_1_n_6 ,\refresh_counter_reg[12]_i_1_n_7 }),
        .S({\refresh_counter_reg_n_0_[15] ,\refresh_counter_reg_n_0_[14] ,\refresh_counter_reg_n_0_[13] ,\refresh_counter_reg_n_0_[12] }));
  FDRE \refresh_counter_reg[13] 
       (.C(clock_100Mhz_IBUF_BUFG),
        .CE(1'b1),
        .D(\refresh_counter_reg[12]_i_1_n_6 ),
        .Q(\refresh_counter_reg_n_0_[13] ),
        .R(1'b0));
  FDRE \refresh_counter_reg[14] 
       (.C(clock_100Mhz_IBUF_BUFG),
        .CE(1'b1),
        .D(\refresh_counter_reg[12]_i_1_n_5 ),
        .Q(\refresh_counter_reg_n_0_[14] ),
        .R(1'b0));
  FDRE \refresh_counter_reg[15] 
       (.C(clock_100Mhz_IBUF_BUFG),
        .CE(1'b1),
        .D(\refresh_counter_reg[12]_i_1_n_4 ),
        .Q(\refresh_counter_reg_n_0_[15] ),
        .R(1'b0));
  FDRE \refresh_counter_reg[16] 
       (.C(clock_100Mhz_IBUF_BUFG),
        .CE(1'b1),
        .D(\refresh_counter_reg[16]_i_1_n_7 ),
        .Q(\refresh_counter_reg_n_0_[16] ),
        .R(1'b0));
  (* ADDER_THRESHOLD = "11" *) 
  CARRY4 \refresh_counter_reg[16]_i_1 
       (.CI(\refresh_counter_reg[12]_i_1_n_0 ),
        .CO(\NLW_refresh_counter_reg[16]_i_1_CO_UNCONNECTED [3:0]),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O({\refresh_counter_reg[16]_i_1_n_4 ,\refresh_counter_reg[16]_i_1_n_5 ,\refresh_counter_reg[16]_i_1_n_6 ,\refresh_counter_reg[16]_i_1_n_7 }),
        .S({LED_activating_counter,\refresh_counter_reg_n_0_[17] ,\refresh_counter_reg_n_0_[16] }));
  FDRE \refresh_counter_reg[17] 
       (.C(clock_100Mhz_IBUF_BUFG),
        .CE(1'b1),
        .D(\refresh_counter_reg[16]_i_1_n_6 ),
        .Q(\refresh_counter_reg_n_0_[17] ),
        .R(1'b0));
  FDRE \refresh_counter_reg[18] 
       (.C(clock_100Mhz_IBUF_BUFG),
        .CE(1'b1),
        .D(\refresh_counter_reg[16]_i_1_n_5 ),
        .Q(LED_activating_counter[0]),
        .R(1'b0));
  FDRE \refresh_counter_reg[19] 
       (.C(clock_100Mhz_IBUF_BUFG),
        .CE(1'b1),
        .D(\refresh_counter_reg[16]_i_1_n_4 ),
        .Q(LED_activating_counter[1]),
        .R(1'b0));
  FDRE \refresh_counter_reg[1] 
       (.C(clock_100Mhz_IBUF_BUFG),
        .CE(1'b1),
        .D(\refresh_counter_reg[0]_i_1_n_6 ),
        .Q(\refresh_counter_reg_n_0_[1] ),
        .R(1'b0));
  FDRE \refresh_counter_reg[2] 
       (.C(clock_100Mhz_IBUF_BUFG),
        .CE(1'b1),
        .D(\refresh_counter_reg[0]_i_1_n_5 ),
        .Q(\refresh_counter_reg_n_0_[2] ),
        .R(1'b0));
  FDRE \refresh_counter_reg[3] 
       (.C(clock_100Mhz_IBUF_BUFG),
        .CE(1'b1),
        .D(\refresh_counter_reg[0]_i_1_n_4 ),
        .Q(\refresh_counter_reg_n_0_[3] ),
        .R(1'b0));
  FDRE \refresh_counter_reg[4] 
       (.C(clock_100Mhz_IBUF_BUFG),
        .CE(1'b1),
        .D(\refresh_counter_reg[4]_i_1_n_7 ),
        .Q(\refresh_counter_reg_n_0_[4] ),
        .R(1'b0));
  (* ADDER_THRESHOLD = "11" *) 
  CARRY4 \refresh_counter_reg[4]_i_1 
       (.CI(\refresh_counter_reg[0]_i_1_n_0 ),
        .CO({\refresh_counter_reg[4]_i_1_n_0 ,\NLW_refresh_counter_reg[4]_i_1_CO_UNCONNECTED [2:0]}),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O({\refresh_counter_reg[4]_i_1_n_4 ,\refresh_counter_reg[4]_i_1_n_5 ,\refresh_counter_reg[4]_i_1_n_6 ,\refresh_counter_reg[4]_i_1_n_7 }),
        .S({\refresh_counter_reg_n_0_[7] ,\refresh_counter_reg_n_0_[6] ,\refresh_counter_reg_n_0_[5] ,\refresh_counter_reg_n_0_[4] }));
  FDRE \refresh_counter_reg[5] 
       (.C(clock_100Mhz_IBUF_BUFG),
        .CE(1'b1),
        .D(\refresh_counter_reg[4]_i_1_n_6 ),
        .Q(\refresh_counter_reg_n_0_[5] ),
        .R(1'b0));
  FDRE \refresh_counter_reg[6] 
       (.C(clock_100Mhz_IBUF_BUFG),
        .CE(1'b1),
        .D(\refresh_counter_reg[4]_i_1_n_5 ),
        .Q(\refresh_counter_reg_n_0_[6] ),
        .R(1'b0));
  FDRE \refresh_counter_reg[7] 
       (.C(clock_100Mhz_IBUF_BUFG),
        .CE(1'b1),
        .D(\refresh_counter_reg[4]_i_1_n_4 ),
        .Q(\refresh_counter_reg_n_0_[7] ),
        .R(1'b0));
  FDRE \refresh_counter_reg[8] 
       (.C(clock_100Mhz_IBUF_BUFG),
        .CE(1'b1),
        .D(\refresh_counter_reg[8]_i_1_n_7 ),
        .Q(\refresh_counter_reg_n_0_[8] ),
        .R(1'b0));
  (* ADDER_THRESHOLD = "11" *) 
  CARRY4 \refresh_counter_reg[8]_i_1 
       (.CI(\refresh_counter_reg[4]_i_1_n_0 ),
        .CO({\refresh_counter_reg[8]_i_1_n_0 ,\NLW_refresh_counter_reg[8]_i_1_CO_UNCONNECTED [2:0]}),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O({\refresh_counter_reg[8]_i_1_n_4 ,\refresh_counter_reg[8]_i_1_n_5 ,\refresh_counter_reg[8]_i_1_n_6 ,\refresh_counter_reg[8]_i_1_n_7 }),
        .S({\refresh_counter_reg_n_0_[11] ,\refresh_counter_reg_n_0_[10] ,\refresh_counter_reg_n_0_[9] ,\refresh_counter_reg_n_0_[8] }));
  FDRE \refresh_counter_reg[9] 
       (.C(clock_100Mhz_IBUF_BUFG),
        .CE(1'b1),
        .D(\refresh_counter_reg[8]_i_1_n_6 ),
        .Q(\refresh_counter_reg_n_0_[9] ),
        .R(1'b0));
endmodule
`ifndef GLBL
`define GLBL
`timescale  1 ps / 1 ps

module glbl ();

    parameter ROC_WIDTH = 100000;
    parameter TOC_WIDTH = 0;
    parameter GRES_WIDTH = 10000;
    parameter GRES_START = 10000;

//--------   STARTUP Globals --------------
    wire GSR;
    wire GTS;
    wire GWE;
    wire PRLD;
    wire GRESTORE;
    tri1 p_up_tmp;
    tri (weak1, strong0) PLL_LOCKG = p_up_tmp;

    wire PROGB_GLBL;
    wire CCLKO_GLBL;
    wire FCSBO_GLBL;
    wire [3:0] DO_GLBL;
    wire [3:0] DI_GLBL;
   
    reg GSR_int;
    reg GTS_int;
    reg PRLD_int;
    reg GRESTORE_int;

//--------   JTAG Globals --------------
    wire JTAG_TDO_GLBL;
    wire JTAG_TCK_GLBL;
    wire JTAG_TDI_GLBL;
    wire JTAG_TMS_GLBL;
    wire JTAG_TRST_GLBL;

    reg JTAG_CAPTURE_GLBL;
    reg JTAG_RESET_GLBL;
    reg JTAG_SHIFT_GLBL;
    reg JTAG_UPDATE_GLBL;
    reg JTAG_RUNTEST_GLBL;

    reg JTAG_SEL1_GLBL = 0;
    reg JTAG_SEL2_GLBL = 0 ;
    reg JTAG_SEL3_GLBL = 0;
    reg JTAG_SEL4_GLBL = 0;

    reg JTAG_USER_TDO1_GLBL = 1'bz;
    reg JTAG_USER_TDO2_GLBL = 1'bz;
    reg JTAG_USER_TDO3_GLBL = 1'bz;
    reg JTAG_USER_TDO4_GLBL = 1'bz;

    assign (strong1, weak0) GSR = GSR_int;
    assign (strong1, weak0) GTS = GTS_int;
    assign (weak1, weak0) PRLD = PRLD_int;
    assign (strong1, weak0) GRESTORE = GRESTORE_int;

    initial begin
	GSR_int = 1'b1;
	PRLD_int = 1'b1;
	#(ROC_WIDTH)
	GSR_int = 1'b0;
	PRLD_int = 1'b0;
    end

    initial begin
	GTS_int = 1'b1;
	#(TOC_WIDTH)
	GTS_int = 1'b0;
    end

    initial begin 
	GRESTORE_int = 1'b0;
	#(GRES_START);
	GRESTORE_int = 1'b1;
	#(GRES_WIDTH);
	GRESTORE_int = 1'b0;
    end

endmodule
`endif
