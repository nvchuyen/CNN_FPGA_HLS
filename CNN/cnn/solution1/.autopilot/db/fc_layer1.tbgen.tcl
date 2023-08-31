set moduleName fc_layer1
set isTopModule 0
set isCombinational 0
set isDatapathOnly 0
set isPipelined 0
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set C_modelName {fc_layer1}
set C_modelType { void 0 }
set C_modelArgList {
	{ pool1_out5 int 32 regular {fifo 0 volatile }  }
	{ out_stream_V int 32 regular {axi_s 1 volatile  { out_stream_V Data } }  }
}
set C_modelArgMapList {[ 
	{ "Name" : "pool1_out5", "interface" : "fifo", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "out_stream_V", "interface" : "axis", "bitwidth" : 32, "direction" : "WRITEONLY"} ]}
# RTL Port declarations: 
set portNum 30
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ pool1_out5_dout sc_in sc_lv 32 signal 0 } 
	{ pool1_out5_empty_n sc_in sc_logic 1 signal 0 } 
	{ pool1_out5_read sc_out sc_logic 1 signal 0 } 
	{ out_stream_V_TDATA sc_out sc_lv 32 signal 1 } 
	{ out_stream_V_TVALID sc_out sc_logic 1 outvld 1 } 
	{ out_stream_V_TREADY sc_in sc_logic 1 outacc 1 } 
	{ grp_fu_5480_p_din0 sc_out sc_lv 32 signal -1 } 
	{ grp_fu_5480_p_din1 sc_out sc_lv 32 signal -1 } 
	{ grp_fu_5480_p_opcode sc_out sc_lv 2 signal -1 } 
	{ grp_fu_5480_p_dout0 sc_in sc_lv 32 signal -1 } 
	{ grp_fu_5480_p_ce sc_out sc_logic 1 signal -1 } 
	{ grp_fu_5484_p_din0 sc_out sc_lv 32 signal -1 } 
	{ grp_fu_5484_p_din1 sc_out sc_lv 32 signal -1 } 
	{ grp_fu_5484_p_opcode sc_out sc_lv 2 signal -1 } 
	{ grp_fu_5484_p_dout0 sc_in sc_lv 32 signal -1 } 
	{ grp_fu_5484_p_ce sc_out sc_logic 1 signal -1 } 
	{ grp_fu_5500_p_din0 sc_out sc_lv 32 signal -1 } 
	{ grp_fu_5500_p_din1 sc_out sc_lv 32 signal -1 } 
	{ grp_fu_5500_p_dout0 sc_in sc_lv 32 signal -1 } 
	{ grp_fu_5500_p_ce sc_out sc_logic 1 signal -1 } 
	{ grp_fu_5504_p_din0 sc_out sc_lv 32 signal -1 } 
	{ grp_fu_5504_p_din1 sc_out sc_lv 32 signal -1 } 
	{ grp_fu_5504_p_dout0 sc_in sc_lv 32 signal -1 } 
	{ grp_fu_5504_p_ce sc_out sc_logic 1 signal -1 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "pool1_out5_dout", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "pool1_out5", "role": "dout" }} , 
 	{ "name": "pool1_out5_empty_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "pool1_out5", "role": "empty_n" }} , 
 	{ "name": "pool1_out5_read", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "pool1_out5", "role": "read" }} , 
 	{ "name": "out_stream_V_TDATA", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "out_stream_V", "role": "TDATA" }} , 
 	{ "name": "out_stream_V_TVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "out_stream_V", "role": "TVALID" }} , 
 	{ "name": "out_stream_V_TREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "outacc", "bundle":{"name": "out_stream_V", "role": "TREADY" }} , 
 	{ "name": "grp_fu_5480_p_din0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_5480_p_din0", "role": "default" }} , 
 	{ "name": "grp_fu_5480_p_din1", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_5480_p_din1", "role": "default" }} , 
 	{ "name": "grp_fu_5480_p_opcode", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "grp_fu_5480_p_opcode", "role": "default" }} , 
 	{ "name": "grp_fu_5480_p_dout0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_5480_p_dout0", "role": "default" }} , 
 	{ "name": "grp_fu_5480_p_ce", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "grp_fu_5480_p_ce", "role": "default" }} , 
 	{ "name": "grp_fu_5484_p_din0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_5484_p_din0", "role": "default" }} , 
 	{ "name": "grp_fu_5484_p_din1", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_5484_p_din1", "role": "default" }} , 
 	{ "name": "grp_fu_5484_p_opcode", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "grp_fu_5484_p_opcode", "role": "default" }} , 
 	{ "name": "grp_fu_5484_p_dout0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_5484_p_dout0", "role": "default" }} , 
 	{ "name": "grp_fu_5484_p_ce", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "grp_fu_5484_p_ce", "role": "default" }} , 
 	{ "name": "grp_fu_5500_p_din0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_5500_p_din0", "role": "default" }} , 
 	{ "name": "grp_fu_5500_p_din1", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_5500_p_din1", "role": "default" }} , 
 	{ "name": "grp_fu_5500_p_dout0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_5500_p_dout0", "role": "default" }} , 
 	{ "name": "grp_fu_5500_p_ce", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "grp_fu_5500_p_ce", "role": "default" }} , 
 	{ "name": "grp_fu_5504_p_din0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_5504_p_din0", "role": "default" }} , 
 	{ "name": "grp_fu_5504_p_din1", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_5504_p_din1", "role": "default" }} , 
 	{ "name": "grp_fu_5504_p_dout0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_5504_p_dout0", "role": "default" }} , 
 	{ "name": "grp_fu_5504_p_ce", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "grp_fu_5504_p_ce", "role": "default" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13"],
		"CDFG" : "fc_layer1",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "8664", "EstimateLatencyMax" : "8664",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "pool1_out5", "Type" : "Fifo", "Direction" : "I",
				"BlockSignal" : [
					{"Name" : "pool1_out5_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "out_stream_V", "Type" : "Axis", "Direction" : "O",
				"BlockSignal" : [
					{"Name" : "out_stream_V_TDATA_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "fc_layer1_weights_0", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "fc_layer1_weights_1", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "fc_layer1_weights_2", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "fc_layer1_weights_3", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "fc_layer1_weights_4", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "fc_layer1_weights_5", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "fc_layer1_weights_6", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "fc_layer1_weights_7", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "fc_layer1_weights_8", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "fc_layer1_weights_9", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "fc_layer1_bias", "Type" : "Memory", "Direction" : "I"}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fc_layer1_weights_0_U", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fc_layer1_weights_1_U", "Parent" : "0"},
	{"ID" : "3", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fc_layer1_weights_2_U", "Parent" : "0"},
	{"ID" : "4", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fc_layer1_weights_3_U", "Parent" : "0"},
	{"ID" : "5", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fc_layer1_weights_4_U", "Parent" : "0"},
	{"ID" : "6", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fc_layer1_weights_5_U", "Parent" : "0"},
	{"ID" : "7", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fc_layer1_weights_6_U", "Parent" : "0"},
	{"ID" : "8", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fc_layer1_weights_7_U", "Parent" : "0"},
	{"ID" : "9", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fc_layer1_weights_8_U", "Parent" : "0"},
	{"ID" : "10", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fc_layer1_weights_9_U", "Parent" : "0"},
	{"ID" : "11", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fc_layer1_bias_U", "Parent" : "0"},
	{"ID" : "12", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.output_U", "Parent" : "0"},
	{"ID" : "13", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fcmp_32ns_32ns_1_1_no_dsp_1_U20", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	fc_layer1 {
		pool1_out5 {Type I LastRead 13 FirstWrite -1}
		out_stream_V {Type O LastRead -1 FirstWrite 10}
		fc_layer1_weights_0 {Type I LastRead -1 FirstWrite -1}
		fc_layer1_weights_1 {Type I LastRead -1 FirstWrite -1}
		fc_layer1_weights_2 {Type I LastRead -1 FirstWrite -1}
		fc_layer1_weights_3 {Type I LastRead -1 FirstWrite -1}
		fc_layer1_weights_4 {Type I LastRead -1 FirstWrite -1}
		fc_layer1_weights_5 {Type I LastRead -1 FirstWrite -1}
		fc_layer1_weights_6 {Type I LastRead -1 FirstWrite -1}
		fc_layer1_weights_7 {Type I LastRead -1 FirstWrite -1}
		fc_layer1_weights_8 {Type I LastRead -1 FirstWrite -1}
		fc_layer1_weights_9 {Type I LastRead -1 FirstWrite -1}
		fc_layer1_bias {Type I LastRead -1 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "8664", "Max" : "8664"}
	, {"Name" : "Interval", "Min" : "8664", "Max" : "8664"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "3", "EnableSignal" : "ap_enable_pp3"}
]}

set Spec2ImplPortList { 
	pool1_out5 { ap_fifo {  { pool1_out5_dout fifo_data 0 32 }  { pool1_out5_empty_n fifo_status 0 1 }  { pool1_out5_read fifo_update 1 1 } } }
	out_stream_V { axis {  { out_stream_V_TDATA out_data 1 32 }  { out_stream_V_TVALID out_vld 1 1 }  { out_stream_V_TREADY out_acc 0 1 } } }
}
