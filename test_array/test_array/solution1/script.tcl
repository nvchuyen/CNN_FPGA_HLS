############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
open_project test_array
set_top test_array
add_files test_array.cpp
open_solution "solution1" -flow_target vivado
set_part {xczu7ev-ffvc1156-2-e}
create_clock -period 10 -name default
config_export -format ip_catalog -output F:/NVChuyen/CNN/Vivado/IpcoreTest/test_array/test_array.zip -rtl vhdl
source "./test_array/solution1/directives.tcl"
#csim_design
csynth_design
#cosim_design
export_design -rtl vhdl -format ip_catalog -output F:/NVChuyen/CNN/Vivado/IpcoreTest/test_array/test_array.zip
