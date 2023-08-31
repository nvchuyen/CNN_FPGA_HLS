############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
open_project fully1_cnn
set_top fully1_cnn
add_files headers1/defines.h
add_files fully1_cnn.cpp
add_files headers1/input.h
add_files headers1/output.h
add_files -tb fully1_test.cpp -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
open_solution "solution1" -flow_target vivado
set_part {xczu7ev-ffvc1156-2-e}
create_clock -period 20 -name default
config_export -format ip_catalog -output F:/NVChuyen/CNN/Vivado/IpcoreTest/test_fix_point/fully1_cnn.zip -rtl vhdl
source "./fully1_cnn/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -rtl vhdl -format ip_catalog -output F:/NVChuyen/CNN/Vivado/IpcoreTest/test_fix_point/fully1_cnn.zip
