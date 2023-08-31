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
	{ fc1_out5 int 32 regular {fifo 1 volatile }  }
	{ pool1_out4 int 32 regular {fifo 0 volatile }  }
}
set C_modelArgMapList {[ 
	{ "Name" : "fc1_out5", "interface" : "fifo", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "pool1_out4", "interface" : "fifo", "bitwidth" : 32, "direction" : "READONLY"} ]}
# RTL Port declarations: 
set portNum 30
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ fc1_out5_din sc_out sc_lv 32 signal 0 } 
	{ fc1_out5_full_n sc_in sc_logic 1 signal 0 } 
	{ fc1_out5_write sc_out sc_logic 1 signal 0 } 
	{ pool1_out4_dout sc_in sc_lv 32 signal 1 } 
	{ pool1_out4_empty_n sc_in sc_logic 1 signal 1 } 
	{ pool1_out4_read sc_out sc_logic 1 signal 1 } 
	{ grp_fu_326_p_din0 sc_out sc_lv 32 signal -1 } 
	{ grp_fu_326_p_din1 sc_out sc_lv 32 signal -1 } 
	{ grp_fu_326_p_opcode sc_out sc_lv 2 signal -1 } 
	{ grp_fu_326_p_dout0 sc_in sc_lv 32 signal -1 } 
	{ grp_fu_326_p_ce sc_out sc_logic 1 signal -1 } 
	{ grp_fu_659_p_din0 sc_out sc_lv 32 signal -1 } 
	{ grp_fu_659_p_din1 sc_out sc_lv 32 signal -1 } 
	{ grp_fu_659_p_opcode sc_out sc_lv 2 signal -1 } 
	{ grp_fu_659_p_dout0 sc_in sc_lv 32 signal -1 } 
	{ grp_fu_659_p_ce sc_out sc_logic 1 signal -1 } 
	{ grp_fu_334_p_din0 sc_out sc_lv 32 signal -1 } 
	{ grp_fu_334_p_din1 sc_out sc_lv 32 signal -1 } 
	{ grp_fu_334_p_dout0 sc_in sc_lv 32 signal -1 } 
	{ grp_fu_334_p_ce sc_out sc_logic 1 signal -1 } 
	{ grp_fu_675_p_din0 sc_out sc_lv 32 signal -1 } 
	{ grp_fu_675_p_din1 sc_out sc_lv 32 signal -1 } 
	{ grp_fu_675_p_dout0 sc_in sc_lv 32 signal -1 } 
	{ grp_fu_675_p_ce sc_out sc_logic 1 signal -1 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "fc1_out5_din", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc1_out5", "role": "din" }} , 
 	{ "name": "fc1_out5_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc1_out5", "role": "full_n" }} , 
 	{ "name": "fc1_out5_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc1_out5", "role": "write" }} , 
 	{ "name": "pool1_out4_dout", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "pool1_out4", "role": "dout" }} , 
 	{ "name": "pool1_out4_empty_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "pool1_out4", "role": "empty_n" }} , 
 	{ "name": "pool1_out4_read", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "pool1_out4", "role": "read" }} , 
 	{ "name": "grp_fu_326_p_din0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_326_p_din0", "role": "default" }} , 
 	{ "name": "grp_fu_326_p_din1", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_326_p_din1", "role": "default" }} , 
 	{ "name": "grp_fu_326_p_opcode", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "grp_fu_326_p_opcode", "role": "default" }} , 
 	{ "name": "grp_fu_326_p_dout0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_326_p_dout0", "role": "default" }} , 
 	{ "name": "grp_fu_326_p_ce", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "grp_fu_326_p_ce", "role": "default" }} , 
 	{ "name": "grp_fu_659_p_din0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_659_p_din0", "role": "default" }} , 
 	{ "name": "grp_fu_659_p_din1", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_659_p_din1", "role": "default" }} , 
 	{ "name": "grp_fu_659_p_opcode", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "grp_fu_659_p_opcode", "role": "default" }} , 
 	{ "name": "grp_fu_659_p_dout0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_659_p_dout0", "role": "default" }} , 
 	{ "name": "grp_fu_659_p_ce", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "grp_fu_659_p_ce", "role": "default" }} , 
 	{ "name": "grp_fu_334_p_din0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_334_p_din0", "role": "default" }} , 
 	{ "name": "grp_fu_334_p_din1", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_334_p_din1", "role": "default" }} , 
 	{ "name": "grp_fu_334_p_dout0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_334_p_dout0", "role": "default" }} , 
 	{ "name": "grp_fu_334_p_ce", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "grp_fu_334_p_ce", "role": "default" }} , 
 	{ "name": "grp_fu_675_p_din0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_675_p_din0", "role": "default" }} , 
 	{ "name": "grp_fu_675_p_din1", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_675_p_din1", "role": "default" }} , 
 	{ "name": "grp_fu_675_p_dout0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_675_p_dout0", "role": "default" }} , 
 	{ "name": "grp_fu_675_p_ce", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "grp_fu_675_p_ce", "role": "default" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11"],
		"CDFG" : "fc_layer1",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "8441", "EstimateLatencyMax" : "8441",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "fc1_out5", "Type" : "Fifo", "Direction" : "O",
				"BlockSignal" : [
					{"Name" : "fc1_out5_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "pool1_out4", "Type" : "Fifo", "Direction" : "I",
				"BlockSignal" : [
					{"Name" : "pool1_out4_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "fc_layer1_weights_0", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "fc_layer1_weights_1", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "fc_layer1_weights_2", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "fc_layer1_weights_3", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "fc_layer1_weights_4", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "fc_layer1_weights_5", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "fc_layer1_weights_6", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "fc_layer1_weights_7", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "fc_layer1_weights_8", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "fc_layer1_weights_9", "Type" : "Memory", "Direction" : "I"}]},
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
	{"ID" : "11", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fcmp_32ns_32ns_1_1_no_dsp_1_U23", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	fc_layer1 {
		fc1_out5 {Type O LastRead -1 FirstWrite 4}
		pool1_out4 {Type I LastRead 9 FirstWrite -1}
		fc_layer1_weights_0 {Type I LastRead -1 FirstWrite -1}
		fc_layer1_weights_1 {Type I LastRead -1 FirstWrite -1}
		fc_layer1_weights_2 {Type I LastRead -1 FirstWrite -1}
		fc_layer1_weights_3 {Type I LastRead -1 FirstWrite -1}
		fc_layer1_weights_4 {Type I LastRead -1 FirstWrite -1}
		fc_layer1_weights_5 {Type I LastRead -1 FirstWrite -1}
		fc_layer1_weights_6 {Type I LastRead -1 FirstWrite -1}
		fc_layer1_weights_7 {Type I LastRead -1 FirstWrite -1}
		fc_layer1_weights_8 {Type I LastRead -1 FirstWrite -1}
		fc_layer1_weights_9 {Type I LastRead -1 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "8441", "Max" : "8441"}
	, {"Name" : "Interval", "Min" : "8441", "Max" : "8441"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
	fc1_out5 { ap_fifo {  { fc1_out5_din fifo_data 1 32 }  { fc1_out5_full_n fifo_status 0 1 }  { fc1_out5_write fifo_update 1 1 } } }
	pool1_out4 { ap_fifo {  { pool1_out4_dout fifo_data 0 32 }  { pool1_out4_empty_n fifo_status 0 1 }  { pool1_out4_read fifo_update 1 1 } } }
}
