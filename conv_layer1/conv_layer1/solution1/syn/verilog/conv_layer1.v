// ==============================================================
// RTL generated by Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Version: 2020.2
// Copyright (C) Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

(* CORE_GENERATION_INFO="conv_layer1_conv_layer1,hls_ip_2020_2,{HLS_INPUT_TYPE=cxx,HLS_INPUT_FLOAT=0,HLS_INPUT_FIXED=0,HLS_INPUT_PART=xczu7ev-ffvc1156-2-e,HLS_INPUT_CLOCK=10.000000,HLS_INPUT_ARCH=others,HLS_SYN_CLOCK=7.704800,HLS_SYN_LAT=39372,HLS_SYN_TPT=none,HLS_SYN_MEM=0,HLS_SYN_DSP=0,HLS_SYN_FF=54908,HLS_SYN_LUT=28076,HLS_VERSION=2020_2}" *)

module conv_layer1 (
        ap_clk,
        ap_rst_n,
        ap_start,
        ap_done,
        ap_idle,
        ap_ready,
        in_stream_V_TDATA,
        in_stream_V_TVALID,
        in_stream_V_TREADY,
        out_stream_V_TDATA,
        out_stream_V_TVALID,
        out_stream_V_TREADY
);

parameter    ap_ST_fsm_state1 = 4'd1;
parameter    ap_ST_fsm_state2 = 4'd2;
parameter    ap_ST_fsm_state3 = 4'd4;
parameter    ap_ST_fsm_state4 = 4'd8;

input   ap_clk;
input   ap_rst_n;
input   ap_start;
output   ap_done;
output   ap_idle;
output   ap_ready;
input  [31:0] in_stream_V_TDATA;
input   in_stream_V_TVALID;
output   in_stream_V_TREADY;
output  [31:0] out_stream_V_TDATA;
output   out_stream_V_TVALID;
input   out_stream_V_TREADY;

reg ap_done;
reg ap_idle;
reg ap_ready;

 reg    ap_rst_n_inv;
(* fsm_encoding = "none" *) reg   [3:0] ap_CS_fsm;
wire    ap_CS_fsm_state1;
wire    grp_convolution_fu_24_ap_start;
wire    grp_convolution_fu_24_ap_done;
wire    grp_convolution_fu_24_ap_idle;
wire    grp_convolution_fu_24_ap_ready;
wire    grp_convolution_fu_24_in_stream_V_TREADY;
wire   [31:0] grp_convolution_fu_24_out_stream_V_TDATA;
wire    grp_convolution_fu_24_out_stream_V_TVALID;
wire    grp_convolution_fu_24_out_stream_V_TREADY;
reg    grp_convolution_fu_24_ap_start_reg;
wire    ap_CS_fsm_state2;
wire    ap_CS_fsm_state3;
wire    ap_CS_fsm_state4;
wire    regslice_both_out_stream_V_U_apdone_blk;
reg   [3:0] ap_NS_fsm;
wire    regslice_both_in_stream_V_U_apdone_blk;
wire   [31:0] in_stream_V_TDATA_int_regslice;
wire    in_stream_V_TVALID_int_regslice;
reg    in_stream_V_TREADY_int_regslice;
wire    regslice_both_in_stream_V_U_ack_in;
wire    out_stream_V_TREADY_int_regslice;
wire    regslice_both_out_stream_V_U_vld_out;
wire    ap_ce_reg;

// power-on initialization
initial begin
#0 ap_CS_fsm = 4'd1;
#0 grp_convolution_fu_24_ap_start_reg = 1'b0;
end

conv_layer1_convolution grp_convolution_fu_24(
    .ap_clk(ap_clk),
    .ap_rst(ap_rst_n_inv),
    .ap_start(grp_convolution_fu_24_ap_start),
    .ap_done(grp_convolution_fu_24_ap_done),
    .ap_idle(grp_convolution_fu_24_ap_idle),
    .ap_ready(grp_convolution_fu_24_ap_ready),
    .in_stream_V_TDATA(in_stream_V_TDATA_int_regslice),
    .in_stream_V_TVALID(in_stream_V_TVALID_int_regslice),
    .in_stream_V_TREADY(grp_convolution_fu_24_in_stream_V_TREADY),
    .out_stream_V_TDATA(grp_convolution_fu_24_out_stream_V_TDATA),
    .out_stream_V_TVALID(grp_convolution_fu_24_out_stream_V_TVALID),
    .out_stream_V_TREADY(grp_convolution_fu_24_out_stream_V_TREADY)
);

conv_layer1_regslice_both #(
    .DataWidth( 32 ))
regslice_both_in_stream_V_U(
    .ap_clk(ap_clk),
    .ap_rst(ap_rst_n_inv),
    .data_in(in_stream_V_TDATA),
    .vld_in(in_stream_V_TVALID),
    .ack_in(regslice_both_in_stream_V_U_ack_in),
    .data_out(in_stream_V_TDATA_int_regslice),
    .vld_out(in_stream_V_TVALID_int_regslice),
    .ack_out(in_stream_V_TREADY_int_regslice),
    .apdone_blk(regslice_both_in_stream_V_U_apdone_blk)
);

conv_layer1_regslice_both #(
    .DataWidth( 32 ))
regslice_both_out_stream_V_U(
    .ap_clk(ap_clk),
    .ap_rst(ap_rst_n_inv),
    .data_in(grp_convolution_fu_24_out_stream_V_TDATA),
    .vld_in(grp_convolution_fu_24_out_stream_V_TVALID),
    .ack_in(out_stream_V_TREADY_int_regslice),
    .data_out(out_stream_V_TDATA),
    .vld_out(regslice_both_out_stream_V_U_vld_out),
    .ack_out(out_stream_V_TREADY),
    .apdone_blk(regslice_both_out_stream_V_U_apdone_blk)
);

always @ (posedge ap_clk) begin
    if (ap_rst_n_inv == 1'b1) begin
        ap_CS_fsm <= ap_ST_fsm_state1;
    end else begin
        ap_CS_fsm <= ap_NS_fsm;
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst_n_inv == 1'b1) begin
        grp_convolution_fu_24_ap_start_reg <= 1'b0;
    end else begin
        if ((1'b1 == ap_CS_fsm_state2)) begin
            grp_convolution_fu_24_ap_start_reg <= 1'b1;
        end else if ((grp_convolution_fu_24_ap_ready == 1'b1)) begin
            grp_convolution_fu_24_ap_start_reg <= 1'b0;
        end
    end
end

always @ (*) begin
    if (((regslice_both_out_stream_V_U_apdone_blk == 1'b0) & (1'b1 == ap_CS_fsm_state4))) begin
        ap_done = 1'b1;
    end else begin
        ap_done = 1'b0;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state1) & (ap_start == 1'b0))) begin
        ap_idle = 1'b1;
    end else begin
        ap_idle = 1'b0;
    end
end

always @ (*) begin
    if (((regslice_both_out_stream_V_U_apdone_blk == 1'b0) & (1'b1 == ap_CS_fsm_state4))) begin
        ap_ready = 1'b1;
    end else begin
        ap_ready = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state3)) begin
        in_stream_V_TREADY_int_regslice = grp_convolution_fu_24_in_stream_V_TREADY;
    end else begin
        in_stream_V_TREADY_int_regslice = 1'b0;
    end
end

always @ (*) begin
    case (ap_CS_fsm)
        ap_ST_fsm_state1 : begin
            if (((1'b1 == ap_CS_fsm_state1) & (ap_start == 1'b1))) begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end
        end
        ap_ST_fsm_state2 : begin
            ap_NS_fsm = ap_ST_fsm_state3;
        end
        ap_ST_fsm_state3 : begin
            if (((grp_convolution_fu_24_ap_done == 1'b1) & (1'b1 == ap_CS_fsm_state3))) begin
                ap_NS_fsm = ap_ST_fsm_state4;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state3;
            end
        end
        ap_ST_fsm_state4 : begin
            if (((regslice_both_out_stream_V_U_apdone_blk == 1'b0) & (1'b1 == ap_CS_fsm_state4))) begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state4;
            end
        end
        default : begin
            ap_NS_fsm = 'bx;
        end
    endcase
end

assign ap_CS_fsm_state1 = ap_CS_fsm[32'd0];

assign ap_CS_fsm_state2 = ap_CS_fsm[32'd1];

assign ap_CS_fsm_state3 = ap_CS_fsm[32'd2];

assign ap_CS_fsm_state4 = ap_CS_fsm[32'd3];

always @ (*) begin
    ap_rst_n_inv = ~ap_rst_n;
end

assign grp_convolution_fu_24_ap_start = grp_convolution_fu_24_ap_start_reg;

assign grp_convolution_fu_24_out_stream_V_TREADY = (out_stream_V_TREADY_int_regslice & ap_CS_fsm_state3);

assign in_stream_V_TREADY = regslice_both_in_stream_V_U_ack_in;

assign out_stream_V_TVALID = regslice_both_out_stream_V_U_vld_out;

endmodule //conv_layer1
