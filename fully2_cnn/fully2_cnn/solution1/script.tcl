############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
open_project fully2_cnn
set_top fully2_cnn
add_files fully2_cnn.cpp
open_solution "solution1" -flow_target vivado
set_part {xczu7ev-ffvc1156-2-e}
create_clock -period 10 -name default
config_export -format ip_catalog -output F:/NVChuyen/CNN/Vivado/IpcoreTest/test_fix_point/fully2_cnn.zip -rtl vhdl
source "./fully2_cnn/solution1/directives.tcl"
#csim_design
csynth_design
#cosim_design
export_design -rtl vhdl -format ip_catalog -output F:/NVChuyen/CNN/Vivado/IpcoreTest/test_fix_point/fully2_cnn.zip
