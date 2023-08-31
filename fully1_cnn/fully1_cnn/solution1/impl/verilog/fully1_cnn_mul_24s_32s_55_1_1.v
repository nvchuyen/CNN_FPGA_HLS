// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================

`timescale 1 ns / 1 ps

module fully1_cnn_mul_24s_32s_55_1_1_Multiplier_2(a, b, p);
input[24 - 1 : 0] a; 
input[32 - 1 : 0] b; 
output[55 - 1 : 0] p;

assign p = $signed(a) * $signed(b);
endmodule
`timescale 1 ns / 1 ps
module fully1_cnn_mul_24s_32s_55_1_1(
    din0,
    din1,
    dout);

parameter ID = 32'd1;
parameter NUM_STAGE = 32'd1;
parameter din0_WIDTH = 32'd1;
parameter din1_WIDTH = 32'd1;
parameter dout_WIDTH = 32'd1;
input[din0_WIDTH - 1:0] din0;
input[din1_WIDTH - 1:0] din1;
output[dout_WIDTH - 1:0] dout;



fully1_cnn_mul_24s_32s_55_1_1_Multiplier_2 fully1_cnn_mul_24s_32s_55_1_1_Multiplier_2_U(
    .a( din0 ),
    .b( din1 ),
    .p( dout ));

endmodule

