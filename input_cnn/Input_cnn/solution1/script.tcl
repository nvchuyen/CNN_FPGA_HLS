############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
open_project Input_cnn
set_top input_cnn
add_files input_cnn.cpp
open_solution "solution1" -flow_target vivado
set_part {xczu7ev-ffvc1156-2-e}
create_clock -period 10 -name default
config_export -format ip_catalog -output E:/CMC/CNN/Vivado/Ipcore/input_cnn.zip -rtl vhdl
source "./Input_cnn/solution1/directives.tcl"
#csim_design
csynth_design
#cosim_design
export_design -rtl vhdl -format ip_catalog -output E:/CMC/CNN/Vivado/Ipcore/input_cnn.zip
