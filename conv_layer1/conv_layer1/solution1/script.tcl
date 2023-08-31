############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
open_project conv_layer1
set_top conv_layer1
add_files Convolution.h
add_files conv_layer1.cpp
add_files -tb conv_layer1_test.cpp -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
open_solution "solution1" -flow_target vivado
set_part {xczu7ev-ffvc1156-2-e}
create_clock -period 10 -name default
config_export -format ip_catalog -output E:/CMC/CNN/Vivado/Ipcore/conv_layer1.zip -rtl vhdl
source "./conv_layer1/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -rtl vhdl -format ip_catalog -output E:/CMC/CNN/Vivado/Ipcore/conv_layer1.zip