############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
open_project fully_layer
set_top fully_layer
add_files fully_layer.cpp
add_files headers1/defines.h
add_files -tb fully_layer_test.cpp -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
open_solution "solution1" -flow_target vivado
set_part {xczu7ev-ffvc1156-2-e}
create_clock -period 10 -name default
#source "./fully_layer/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
