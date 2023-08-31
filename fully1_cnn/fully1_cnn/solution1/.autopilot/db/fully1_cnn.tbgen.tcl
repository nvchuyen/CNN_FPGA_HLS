set moduleName fully1_cnn
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
set C_modelName {fully1_cnn}
set C_modelType { void 0 }
set C_modelArgList {
	{ in_V int 32 regular {axi_s 0 volatile  { in_V Data } }  }
	{ out_V int 32 regular {axi_s 1 volatile  { out_V Data } }  }
}
set C_modelArgMapList {[ 
	{ "Name" : "in_V", "interface" : "axis", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "in.V","cData": "int","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "out_V", "interface" : "axis", "bitwidth" : 32, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "out.V","cData": "int","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} ]}
# RTL Port declarations: 
set portNum 8
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst_n sc_in sc_logic 1 reset -1 active_low_sync } 
	{ in_V_TDATA sc_in sc_lv 32 signal 0 } 
	{ in_V_TVALID sc_in sc_logic 1 invld 0 } 
	{ in_V_TREADY sc_out sc_logic 1 inacc 0 } 
	{ out_V_TDATA sc_out sc_lv 32 signal 1 } 
	{ out_V_TVALID sc_out sc_logic 1 outvld 1 } 
	{ out_V_TREADY sc_in sc_logic 1 outacc 1 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst_n", "role": "default" }} , 
 	{ "name": "in_V_TDATA", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "in_V", "role": "TDATA" }} , 
 	{ "name": "in_V_TVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "invld", "bundle":{"name": "in_V", "role": "TVALID" }} , 
 	{ "name": "in_V_TREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "inacc", "bundle":{"name": "in_V", "role": "TREADY" }} , 
 	{ "name": "out_V_TDATA", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "out_V", "role": "TDATA" }} , 
 	{ "name": "out_V_TVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "out_V", "role": "TVALID" }} , 
 	{ "name": "out_V_TREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "outacc", "bundle":{"name": "out_V", "role": "TREADY" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "94", "95"],
		"CDFG" : "fully1_cnn",
		"Protocol" : "ap_ctrl_none",
		"ControlExist" : "0", "ap_start" : "0", "ap_ready" : "0", "ap_done" : "0", "ap_continue" : "0", "ap_idle" : "0", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "8074", "EstimateLatencyMax" : "8074",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "in_V", "Type" : "Axis", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_fc_layer1_fu_48", "Port" : "in_V"}]},
			{"Name" : "out_V", "Type" : "Axis", "Direction" : "O",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_fc_layer1_fu_48", "Port" : "out_V"}]},
			{"Name" : "fc_layer1_weights_V_0", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_fc_layer1_fu_48", "Port" : "fc_layer1_weights_V_0"}]},
			{"Name" : "fc_layer1_weights_V_1", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_fc_layer1_fu_48", "Port" : "fc_layer1_weights_V_1"}]},
			{"Name" : "fc_layer1_weights_V_2", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_fc_layer1_fu_48", "Port" : "fc_layer1_weights_V_2"}]},
			{"Name" : "fc_layer1_weights_V_3", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_fc_layer1_fu_48", "Port" : "fc_layer1_weights_V_3"}]},
			{"Name" : "fc_layer1_weights_V_4", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_fc_layer1_fu_48", "Port" : "fc_layer1_weights_V_4"}]},
			{"Name" : "fc_layer1_weights_V_5", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_fc_layer1_fu_48", "Port" : "fc_layer1_weights_V_5"}]},
			{"Name" : "fc_layer1_weights_V_6", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_fc_layer1_fu_48", "Port" : "fc_layer1_weights_V_6"}]},
			{"Name" : "fc_layer1_weights_V_7", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_fc_layer1_fu_48", "Port" : "fc_layer1_weights_V_7"}]},
			{"Name" : "fc_layer1_weights_V_8", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_fc_layer1_fu_48", "Port" : "fc_layer1_weights_V_8"}]},
			{"Name" : "fc_layer1_weights_V_9", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_fc_layer1_fu_48", "Port" : "fc_layer1_weights_V_9"}]},
			{"Name" : "fc_layer1_bias_V", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_fc_layer1_fu_48", "Port" : "fc_layer1_bias_V"}]}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48", "Parent" : "0", "Child" : ["2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31", "32", "33", "34", "35", "36", "37", "38", "39", "40", "41", "42", "43", "44", "45", "46", "47", "48", "49", "50", "51", "52", "53", "54", "55", "56", "57", "58", "59", "60", "61", "62", "63", "64", "65", "66", "67", "68", "69", "70", "71", "72", "73", "74", "75", "76", "77", "78", "79", "80", "81", "82", "83", "84", "85", "86", "87", "88", "89", "90", "91", "92", "93"],
		"CDFG" : "fc_layer1",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "8071", "EstimateLatencyMax" : "8071",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "in_V", "Type" : "Axis", "Direction" : "I",
				"BlockSignal" : [
					{"Name" : "in_V_TDATA_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "out_V", "Type" : "Axis", "Direction" : "O",
				"BlockSignal" : [
					{"Name" : "out_V_TDATA_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "fc_layer1_weights_V_0", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "fc_layer1_weights_V_1", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "fc_layer1_weights_V_2", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "fc_layer1_weights_V_3", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "fc_layer1_weights_V_4", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "fc_layer1_weights_V_5", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "fc_layer1_weights_V_6", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "fc_layer1_weights_V_7", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "fc_layer1_weights_V_8", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "fc_layer1_weights_V_9", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "fc_layer1_bias_V", "Type" : "Memory", "Direction" : "I"}]},
	{"ID" : "2", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.fc_layer1_weights_V_0_U", "Parent" : "1"},
	{"ID" : "3", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.fc_layer1_weights_V_1_U", "Parent" : "1"},
	{"ID" : "4", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.fc_layer1_weights_V_2_U", "Parent" : "1"},
	{"ID" : "5", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.fc_layer1_weights_V_3_U", "Parent" : "1"},
	{"ID" : "6", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.fc_layer1_weights_V_4_U", "Parent" : "1"},
	{"ID" : "7", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.fc_layer1_weights_V_5_U", "Parent" : "1"},
	{"ID" : "8", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.fc_layer1_weights_V_6_U", "Parent" : "1"},
	{"ID" : "9", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.fc_layer1_weights_V_7_U", "Parent" : "1"},
	{"ID" : "10", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.fc_layer1_weights_V_8_U", "Parent" : "1"},
	{"ID" : "11", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.fc_layer1_weights_V_9_U", "Parent" : "1"},
	{"ID" : "12", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.fc_layer1_bias_V_U", "Parent" : "1"},
	{"ID" : "13", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.output_V_U", "Parent" : "1"},
	{"ID" : "14", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_22s_32s_53_1_1_U1", "Parent" : "1"},
	{"ID" : "15", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_23s_32s_54_1_1_U2", "Parent" : "1"},
	{"ID" : "16", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_23s_32s_54_1_1_U3", "Parent" : "1"},
	{"ID" : "17", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_23s_32s_54_1_1_U4", "Parent" : "1"},
	{"ID" : "18", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_24s_32s_55_1_1_U5", "Parent" : "1"},
	{"ID" : "19", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_23s_32s_54_1_1_U6", "Parent" : "1"},
	{"ID" : "20", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_21s_32s_52_1_1_U7", "Parent" : "1"},
	{"ID" : "21", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_22s_32s_53_1_1_U8", "Parent" : "1"},
	{"ID" : "22", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_20s_32s_51_1_1_U9", "Parent" : "1"},
	{"ID" : "23", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_23s_32s_54_1_1_U10", "Parent" : "1"},
	{"ID" : "24", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_22s_32s_53_1_1_U11", "Parent" : "1"},
	{"ID" : "25", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_23s_32s_54_1_1_U12", "Parent" : "1"},
	{"ID" : "26", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_23s_32s_54_1_1_U13", "Parent" : "1"},
	{"ID" : "27", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_23s_32s_54_1_1_U14", "Parent" : "1"},
	{"ID" : "28", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_24s_32s_55_1_1_U15", "Parent" : "1"},
	{"ID" : "29", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_23s_32s_54_1_1_U16", "Parent" : "1"},
	{"ID" : "30", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_21s_32s_52_1_1_U17", "Parent" : "1"},
	{"ID" : "31", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_22s_32s_53_1_1_U18", "Parent" : "1"},
	{"ID" : "32", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_20s_32s_51_1_1_U19", "Parent" : "1"},
	{"ID" : "33", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_23s_32s_54_1_1_U20", "Parent" : "1"},
	{"ID" : "34", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_22s_32s_53_1_1_U21", "Parent" : "1"},
	{"ID" : "35", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_23s_32s_54_1_1_U22", "Parent" : "1"},
	{"ID" : "36", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_23s_32s_54_1_1_U23", "Parent" : "1"},
	{"ID" : "37", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_23s_32s_54_1_1_U24", "Parent" : "1"},
	{"ID" : "38", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_24s_32s_55_1_1_U25", "Parent" : "1"},
	{"ID" : "39", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_23s_32s_54_1_1_U26", "Parent" : "1"},
	{"ID" : "40", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_21s_32s_52_1_1_U27", "Parent" : "1"},
	{"ID" : "41", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_22s_32s_53_1_1_U28", "Parent" : "1"},
	{"ID" : "42", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_20s_32s_51_1_1_U29", "Parent" : "1"},
	{"ID" : "43", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_23s_32s_54_1_1_U30", "Parent" : "1"},
	{"ID" : "44", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_22s_32s_53_1_1_U31", "Parent" : "1"},
	{"ID" : "45", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_23s_32s_54_1_1_U32", "Parent" : "1"},
	{"ID" : "46", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_23s_32s_54_1_1_U33", "Parent" : "1"},
	{"ID" : "47", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_23s_32s_54_1_1_U34", "Parent" : "1"},
	{"ID" : "48", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_24s_32s_55_1_1_U35", "Parent" : "1"},
	{"ID" : "49", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_23s_32s_54_1_1_U36", "Parent" : "1"},
	{"ID" : "50", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_21s_32s_52_1_1_U37", "Parent" : "1"},
	{"ID" : "51", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_22s_32s_53_1_1_U38", "Parent" : "1"},
	{"ID" : "52", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_20s_32s_51_1_1_U39", "Parent" : "1"},
	{"ID" : "53", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_23s_32s_54_1_1_U40", "Parent" : "1"},
	{"ID" : "54", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_22s_32s_53_1_1_U41", "Parent" : "1"},
	{"ID" : "55", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_23s_32s_54_1_1_U42", "Parent" : "1"},
	{"ID" : "56", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_23s_32s_54_1_1_U43", "Parent" : "1"},
	{"ID" : "57", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_23s_32s_54_1_1_U44", "Parent" : "1"},
	{"ID" : "58", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_24s_32s_55_1_1_U45", "Parent" : "1"},
	{"ID" : "59", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_23s_32s_54_1_1_U46", "Parent" : "1"},
	{"ID" : "60", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_21s_32s_52_1_1_U47", "Parent" : "1"},
	{"ID" : "61", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_22s_32s_53_1_1_U48", "Parent" : "1"},
	{"ID" : "62", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_20s_32s_51_1_1_U49", "Parent" : "1"},
	{"ID" : "63", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_23s_32s_54_1_1_U50", "Parent" : "1"},
	{"ID" : "64", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_22s_32s_53_1_1_U51", "Parent" : "1"},
	{"ID" : "65", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_23s_32s_54_1_1_U52", "Parent" : "1"},
	{"ID" : "66", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_23s_32s_54_1_1_U53", "Parent" : "1"},
	{"ID" : "67", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_23s_32s_54_1_1_U54", "Parent" : "1"},
	{"ID" : "68", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_24s_32s_55_1_1_U55", "Parent" : "1"},
	{"ID" : "69", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_23s_32s_54_1_1_U56", "Parent" : "1"},
	{"ID" : "70", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_21s_32s_52_1_1_U57", "Parent" : "1"},
	{"ID" : "71", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_22s_32s_53_1_1_U58", "Parent" : "1"},
	{"ID" : "72", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_20s_32s_51_1_1_U59", "Parent" : "1"},
	{"ID" : "73", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_23s_32s_54_1_1_U60", "Parent" : "1"},
	{"ID" : "74", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_22s_32s_53_1_1_U61", "Parent" : "1"},
	{"ID" : "75", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_23s_32s_54_1_1_U62", "Parent" : "1"},
	{"ID" : "76", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_23s_32s_54_1_1_U63", "Parent" : "1"},
	{"ID" : "77", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_23s_32s_54_1_1_U64", "Parent" : "1"},
	{"ID" : "78", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_24s_32s_55_1_1_U65", "Parent" : "1"},
	{"ID" : "79", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_23s_32s_54_1_1_U66", "Parent" : "1"},
	{"ID" : "80", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_21s_32s_52_1_1_U67", "Parent" : "1"},
	{"ID" : "81", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_22s_32s_53_1_1_U68", "Parent" : "1"},
	{"ID" : "82", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_20s_32s_51_1_1_U69", "Parent" : "1"},
	{"ID" : "83", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_23s_32s_54_1_1_U70", "Parent" : "1"},
	{"ID" : "84", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_22s_32s_53_1_1_U71", "Parent" : "1"},
	{"ID" : "85", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_23s_32s_54_1_1_U72", "Parent" : "1"},
	{"ID" : "86", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_23s_32s_54_1_1_U73", "Parent" : "1"},
	{"ID" : "87", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_23s_32s_54_1_1_U74", "Parent" : "1"},
	{"ID" : "88", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_24s_32s_55_1_1_U75", "Parent" : "1"},
	{"ID" : "89", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_23s_32s_54_1_1_U76", "Parent" : "1"},
	{"ID" : "90", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_21s_32s_52_1_1_U77", "Parent" : "1"},
	{"ID" : "91", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_22s_32s_53_1_1_U78", "Parent" : "1"},
	{"ID" : "92", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_20s_32s_51_1_1_U79", "Parent" : "1"},
	{"ID" : "93", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_fc_layer1_fu_48.mul_23s_32s_54_1_1_U80", "Parent" : "1"},
	{"ID" : "94", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.regslice_both_in_V_U", "Parent" : "0"},
	{"ID" : "95", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.regslice_both_out_V_U", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	fully1_cnn {
		in_V {Type I LastRead 16 FirstWrite -1}
		out_V {Type O LastRead -1 FirstWrite 15}
		fc_layer1_weights_V_0 {Type I LastRead -1 FirstWrite -1}
		fc_layer1_weights_V_1 {Type I LastRead -1 FirstWrite -1}
		fc_layer1_weights_V_2 {Type I LastRead -1 FirstWrite -1}
		fc_layer1_weights_V_3 {Type I LastRead -1 FirstWrite -1}
		fc_layer1_weights_V_4 {Type I LastRead -1 FirstWrite -1}
		fc_layer1_weights_V_5 {Type I LastRead -1 FirstWrite -1}
		fc_layer1_weights_V_6 {Type I LastRead -1 FirstWrite -1}
		fc_layer1_weights_V_7 {Type I LastRead -1 FirstWrite -1}
		fc_layer1_weights_V_8 {Type I LastRead -1 FirstWrite -1}
		fc_layer1_weights_V_9 {Type I LastRead -1 FirstWrite -1}
		fc_layer1_bias_V {Type I LastRead -1 FirstWrite -1}}
	fc_layer1 {
		in_V {Type I LastRead 16 FirstWrite -1}
		out_V {Type O LastRead -1 FirstWrite 15}
		fc_layer1_weights_V_0 {Type I LastRead -1 FirstWrite -1}
		fc_layer1_weights_V_1 {Type I LastRead -1 FirstWrite -1}
		fc_layer1_weights_V_2 {Type I LastRead -1 FirstWrite -1}
		fc_layer1_weights_V_3 {Type I LastRead -1 FirstWrite -1}
		fc_layer1_weights_V_4 {Type I LastRead -1 FirstWrite -1}
		fc_layer1_weights_V_5 {Type I LastRead -1 FirstWrite -1}
		fc_layer1_weights_V_6 {Type I LastRead -1 FirstWrite -1}
		fc_layer1_weights_V_7 {Type I LastRead -1 FirstWrite -1}
		fc_layer1_weights_V_8 {Type I LastRead -1 FirstWrite -1}
		fc_layer1_weights_V_9 {Type I LastRead -1 FirstWrite -1}
		fc_layer1_bias_V {Type I LastRead -1 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "8074", "Max" : "8074"}
	, {"Name" : "Interval", "Min" : "8075", "Max" : "8075"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
	in_V { axis {  { in_V_TDATA in_data 0 32 }  { in_V_TVALID in_vld 0 1 }  { in_V_TREADY in_acc 1 1 } } }
	out_V { axis {  { out_V_TDATA out_data 1 32 }  { out_V_TVALID out_vld 1 1 }  { out_V_TREADY out_acc 0 1 } } }
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
