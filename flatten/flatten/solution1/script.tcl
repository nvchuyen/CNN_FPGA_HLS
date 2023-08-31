############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
open_project flatten
set_top flattent.cpp
add_files flatten.cpp
open_solution "solution1" -flow_target vivado
set_part {xczu7ev-ffvc1156-2-e}
create_clock -period 10 -name default
#source "./flatten/solution1/directives.tcl"
#csim_design
csynth_design
#cosim_design
export_design -format ip_catalog
