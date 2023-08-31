############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
open_project pooling_layer2
set_top pooling_layer2
add_files pooling_layer2.cpp
add_files -tb pooling_layer2_test.cpp -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
open_solution "solution1" -flow_target vivado
set_part {xczu7ev-ffvc1156-2-e}
create_clock -period 10 -name default
source "./pooling_layer2/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
