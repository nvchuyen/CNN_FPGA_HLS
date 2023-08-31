#include "ap_fixed.h"
#include "headers1/buffer.h"
#include "headers1/defines.h"
#include "C:\Xilinx\Vivado\2020.2\data\ip\xilinx\v_axi4s_remap_v1_0\src\hls_video.h"

//typedef float  float24_t;

#define OUTPUT_BUFFER_SIZE 2

void display_led( hls::stream<float24_t> &in_stream,
		bool  *outTop1, bool  *outTop2
		)
{
#pragma HLS BIND_OP variable = outTop1 op=add
#pragma HLS BIND_OP variable = outTop2 op=add
#pragma HLS INTERFACE axis port = in_stream
#pragma HLS INTERFACE ap_ctrl_none port = return

static	buffer<OUTPUT_BUFFER_SIZE> out_buff;
#pragma HLS ARRAY_PARTITION variable = out_buff complete

static	bool  out_val1 = 0;
static 	bool  out_val2 = 0;
		float24_t in_val = 0;
		int i = 0;


	buffer_in:for (i = 0; i< OUTPUT_BUFFER_SIZE; i++){
		if(in_stream.empty() == 0){
			 in_stream >> in_val ;
			out_buff.InsertBack(in_val);
		}
	}

	if (out_buff.GetValue(0) > out_buff.GetValue(1)){
		out_val1 = 1;
		out_val2 = 0;
	}
	else if (out_buff.GetValue(0) < out_buff.GetValue(1)){
		out_val1 = 0;
		out_val2 = 1;
	}
	else{
		out_val1 = 0;
		out_val2 = 0;
	}

	*outTop1 = out_val1;
	*outTop2 = out_val2;
}

