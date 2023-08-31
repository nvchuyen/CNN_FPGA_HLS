set moduleName cnn
set isTopModule 1
set isCombinational 0
set isDatapathOnly 0
set isPipelined 0
set pipeline_type none
set FunctionProtocol ap_ctrl_none
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set C_modelName {cnn}
set C_modelType { void 0 }
set C_modelArgList {
	{ in_stream_V int 32 regular {axi_s 0 volatile  { in_stream_V Data } }  }
	{ out_stream_V int 32 regular {axi_s 1 volatile  { out_stream_V Data } }  }
}
set C_modelArgMapList {[ 
	{ "Name" : "in_stream_V", "interface" : "axis", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "in_stream.V","cData": "int","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "out_stream_V", "interface" : "axis", "bitwidth" : 32, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "out_stream.V","cData": "int","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} ]}
# RTL Port declarations: 
set portNum 8
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst_n sc_in sc_logic 1 reset -1 active_low_sync } 
	{ in_stream_V_TDATA sc_in sc_lv 32 signal 0 } 
	{ in_stream_V_TVALID sc_in sc_logic 1 invld 0 } 
	{ in_stream_V_TREADY sc_out sc_logic 1 inacc 0 } 
	{ out_stream_V_TDATA sc_out sc_lv 32 signal 1 } 
	{ out_stream_V_TVALID sc_out sc_logic 1 outvld 1 } 
	{ out_stream_V_TREADY sc_in sc_logic 1 outacc 1 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst_n", "role": "default" }} , 
 	{ "name": "in_stream_V_TDATA", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "in_stream_V", "role": "TDATA" }} , 
 	{ "name": "in_stream_V_TVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "invld", "bundle":{"name": "in_stream_V", "role": "TVALID" }} , 
 	{ "name": "in_stream_V_TREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "inacc", "bundle":{"name": "in_stream_V", "role": "TREADY" }} , 
 	{ "name": "out_stream_V_TDATA", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "out_stream_V", "role": "TDATA" }} , 
 	{ "name": "out_stream_V_TVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "out_stream_V", "role": "TVALID" }} , 
 	{ "name": "out_stream_V_TREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "outacc", "bundle":{"name": "out_stream_V", "role": "TREADY" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2", "3", "5", "7", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31", "32", "33"],
		"CDFG" : "cnn",
		"Protocol" : "ap_ctrl_none",
		"ControlExist" : "0", "ap_start" : "0", "ap_ready" : "0", "ap_done" : "0", "ap_continue" : "0", "ap_idle" : "0", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "42670", "EstimateLatencyMax" : "52670",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "in_stream_V", "Type" : "Axis", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "5", "SubInstance" : "grp_conv_layer1_fu_293", "Port" : "in_stream_V"}]},
			{"Name" : "out_stream_V", "Type" : "Axis", "Direction" : "O",
				"BlockSignal" : [
					{"Name" : "out_stream_V_TDATA_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "fc_layer1_weights_0", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "7", "SubInstance" : "grp_fc_layer1_fu_300", "Port" : "fc_layer1_weights_0"}]},
			{"Name" : "fc_layer1_weights_1", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "7", "SubInstance" : "grp_fc_layer1_fu_300", "Port" : "fc_layer1_weights_1"}]},
			{"Name" : "fc_layer1_weights_2", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "7", "SubInstance" : "grp_fc_layer1_fu_300", "Port" : "fc_layer1_weights_2"}]},
			{"Name" : "fc_layer1_weights_3", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "7", "SubInstance" : "grp_fc_layer1_fu_300", "Port" : "fc_layer1_weights_3"}]},
			{"Name" : "fc_layer1_weights_4", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "7", "SubInstance" : "grp_fc_layer1_fu_300", "Port" : "fc_layer1_weights_4"}]},
			{"Name" : "fc_layer1_weights_5", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "7", "SubInstance" : "grp_fc_layer1_fu_300", "Port" : "fc_layer1_weights_5"}]},
			{"Name" : "fc_layer1_weights_6", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "7", "SubInstance" : "grp_fc_layer1_fu_300", "Port" : "fc_layer1_weights_6"}]},
			{"Name" : "fc_layer1_weights_7", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "7", "SubInstance" : "grp_fc_layer1_fu_300", "Port" : "fc_layer1_weights_7"}]},
			{"Name" : "fc_layer1_weights_8", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "7", "SubInstance" : "grp_fc_layer1_fu_300", "Port" : "fc_layer1_weights_8"}]},
			{"Name" : "fc_layer1_weights_9", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "7", "SubInstance" : "grp_fc_layer1_fu_300", "Port" : "fc_layer1_weights_9"}]},
			{"Name" : "fc_layer2_weights", "Type" : "Memory", "Direction" : "I"}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fc_layer2_weights_U", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.output_U", "Parent" : "0"},
	{"ID" : "3", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_pool_layer1_fu_287", "Parent" : "0", "Child" : ["4"],
		"CDFG" : "pool_layer1",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "6732", "EstimateLatencyMax" : "6732",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "out_r", "Type" : "Fifo", "Direction" : "O",
				"BlockSignal" : [
					{"Name" : "out_r_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "in_r", "Type" : "Fifo", "Direction" : "I",
				"BlockSignal" : [
					{"Name" : "in_r_blk_n", "Type" : "RtlSignal"}]}]},
	{"ID" : "4", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_pool_layer1_fu_287.fcmp_32ns_32ns_1_1_no_dsp_1_U16", "Parent" : "3"},
	{"ID" : "5", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_conv_layer1_fu_293", "Parent" : "0", "Child" : ["6"],
		"CDFG" : "conv_layer1",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "27232", "EstimateLatencyMax" : "37232",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "1",
		"Port" : [
			{"Name" : "out_r", "Type" : "Fifo", "Direction" : "O",
				"BlockSignal" : [
					{"Name" : "out_r_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "in_stream_V", "Type" : "Axis", "Direction" : "I",
				"BlockSignal" : [
					{"Name" : "in_stream_V_TDATA_blk_n", "Type" : "RtlSignal"}]}]},
	{"ID" : "6", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_conv_layer1_fu_293.fcmp_32ns_32ns_1_1_no_dsp_1_U10", "Parent" : "5"},
	{"ID" : "7", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_300", "Parent" : "0", "Child" : ["8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18"],
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
	{"ID" : "8", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_300.fc_layer1_weights_0_U", "Parent" : "7"},
	{"ID" : "9", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_300.fc_layer1_weights_1_U", "Parent" : "7"},
	{"ID" : "10", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_300.fc_layer1_weights_2_U", "Parent" : "7"},
	{"ID" : "11", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_300.fc_layer1_weights_3_U", "Parent" : "7"},
	{"ID" : "12", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_300.fc_layer1_weights_4_U", "Parent" : "7"},
	{"ID" : "13", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_300.fc_layer1_weights_5_U", "Parent" : "7"},
	{"ID" : "14", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_300.fc_layer1_weights_6_U", "Parent" : "7"},
	{"ID" : "15", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_300.fc_layer1_weights_7_U", "Parent" : "7"},
	{"ID" : "16", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_300.fc_layer1_weights_8_U", "Parent" : "7"},
	{"ID" : "17", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_300.fc_layer1_weights_9_U", "Parent" : "7"},
	{"ID" : "18", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_300.fcmp_32ns_32ns_1_1_no_dsp_1_U23", "Parent" : "7"},
	{"ID" : "19", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fadd_32ns_32ns_32_2_full_dsp_1_U36", "Parent" : "0"},
	{"ID" : "20", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fmul_32ns_32ns_32_2_max_dsp_1_U37", "Parent" : "0"},
	{"ID" : "21", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fcmp_32ns_32ns_1_1_no_dsp_1_U38", "Parent" : "0"},
	{"ID" : "22", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fadd_32ns_32ns_32_2_full_dsp_1_U39", "Parent" : "0"},
	{"ID" : "23", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fadd_32ns_32ns_32_2_full_dsp_1_U40", "Parent" : "0"},
	{"ID" : "24", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fadd_32ns_32ns_32_2_full_dsp_1_U41", "Parent" : "0"},
	{"ID" : "25", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fadd_32ns_32ns_32_2_full_dsp_1_U42", "Parent" : "0"},
	{"ID" : "26", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fmul_32ns_32ns_32_2_max_dsp_1_U43", "Parent" : "0"},
	{"ID" : "27", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fmul_32ns_32ns_32_2_max_dsp_1_U44", "Parent" : "0"},
	{"ID" : "28", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fmul_32ns_32ns_32_2_max_dsp_1_U45", "Parent" : "0"},
	{"ID" : "29", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.conv1_out_fifo_U", "Parent" : "0"},
	{"ID" : "30", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.pool1_out_fifo_U", "Parent" : "0"},
	{"ID" : "31", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fc1_out_fifo_U", "Parent" : "0"},
	{"ID" : "32", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.regslice_both_in_stream_V_U", "Parent" : "0"},
	{"ID" : "33", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.regslice_both_out_stream_V_U", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	cnn {
		in_stream_V {Type I LastRead 23 FirstWrite -1}
		out_stream_V {Type O LastRead -1 FirstWrite 15}
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
		fc_layer2_weights {Type I LastRead -1 FirstWrite -1}}
	pool_layer1 {
		out_r {Type O LastRead -1 FirstWrite 10}
		in_r {Type I LastRead 233 FirstWrite -1}}
	conv_layer1 {
		out_r {Type O LastRead -1 FirstWrite 39}
		in_stream_V {Type I LastRead 23 FirstWrite -1}}
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
	{"Name" : "Latency", "Min" : "42670", "Max" : "52670"}
	, {"Name" : "Interval", "Min" : "42671", "Max" : "52671"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "1", "EnableSignal" : "ap_enable_pp1"}
]}

set Spec2ImplPortList { 
	in_stream_V { axis {  { in_stream_V_TDATA in_data 0 32 }  { in_stream_V_TVALID in_vld 0 1 }  { in_stream_V_TREADY in_acc 1 1 } } }
	out_stream_V { axis {  { out_stream_V_TDATA out_data 1 32 }  { out_stream_V_TVALID out_vld 1 1 }  { out_stream_V_TREADY out_acc 0 1 } } }
}

set busDeadlockParameterList { 
}

# RTL port scheduling information:
set fifoSchedulingInfoList { 
}

# RTL bus port read request latency information:
set busReadReqLatencyList { 
}

# RTL bus port write response latency information:
set busWriteResLatencyList { 
}

# RTL array port load latency information:
set memoryLoadLatencyList { 
}
