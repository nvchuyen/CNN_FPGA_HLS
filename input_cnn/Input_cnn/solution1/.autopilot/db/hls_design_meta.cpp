#include "hls_design_meta.h"
const Port_Property HLS_Design_Meta::port_props[]={
	Port_Property("ap_clk", 1, hls_in, -1, "", "", 1),
	Port_Property("ap_rst_n", 1, hls_in, -1, "", "", 1),
	Port_Property("out_str_V_TDATA", 32, hls_out, 0, "axis", "out_data", 1),
	Port_Property("out_str_V_TVALID", 1, hls_out, 0, "axis", "out_vld", 1),
	Port_Property("out_str_V_TREADY", 1, hls_in, 0, "axis", "out_acc", 1),
	Port_Property("enable", 1, hls_out, 1, "ap_vld", "out_data", 1),
	Port_Property("enable_ap_vld", 1, hls_out, 1, "ap_vld", "out_vld", 1),
};
const char* HLS_Design_Meta::dut_name = "input_cnn";
