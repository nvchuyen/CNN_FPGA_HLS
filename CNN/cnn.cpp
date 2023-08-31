
#include "headers1/buffer.h"
#include "headers1/weights.h"
#include "headers1/defines.h"
#include "headers1/activations.h"
#include "C:\Xilinx\Vivado\2020.2\data\ip\xilinx\v_axi4s_remap_v1_0\src\hls_video.h"
#include "ap_fixed.h"
#include "pooling.h"
#include "fully.h"
#include "Convolution.h"

typedef float  float24_t;


void cnn(hls::stream<float24_t> &in_stream, hls::stream<float24_t> &out_stream)
{

#pragma HLS INTERFACE axis port=in_stream
#pragma HLS INTERFACE axis port=out_stream
#pragma HLS INTERFACE ap_ctrl_none port=return

	hls::stream<float24_t> conv1_out("conv1_out");
	hls::stream<float24_t> pool1_out("pool1_out");
	hls::stream<float24_t> fc1_out("fc1_out");


	conv_layer1( in_stream, conv1_out);
	pool_layer1( conv1_out, pool1_out);

	fc_layer1(pool1_out, out_stream, fc_layer1_weights, fc_layer1_bias);
//	fc_layer2(fc1_out, out_stream, fc_layer2_weights, fc_layer2_bias);
}




