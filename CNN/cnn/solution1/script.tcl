############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
open_project cnn
set_top cnn
add_files headers1/weights.h
add_files pooling.h
add_files headers1/output.h
add_files headers1/input.h
add_files fully.h
add_files headers1/defines.h
add_files cnn.cpp
add_files headers1/buffer.h
add_files headers1/activations.h
add_files Convolution.h
add_files -tb cnn_test.cpp -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
open_solution "solution1" -flow_target vivado
set_part {xczu7ev-ffvc1156-2-e}
create_clock -period 20 -name default
config_export -format ip_catalog -output F:/NVChuyen/CNN/Vivado/IpcoreTest/cnn_conv/cnn.zip -rtl vhdl
source "./cnn/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -rtl vhdl -format ip_catalog -output F:/NVChuyen/CNN/Vivado/IpcoreTest/cnn_conv/cnn.zip
