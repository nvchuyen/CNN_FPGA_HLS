
#include "headers1/buffer.h"
#include "headers1/weights.h"
#include "headers1/defines.h"
#include "headers1/activations.h"
#include <hls_stream.h>
#include <hls_math.h>
#include "ap_fixed.h"
#include "Convolution.h"


void conv_cnn(hls::stream<float24_t> &in_stream,
			hls::stream<float24_t> &out_stream,

			hls::stream<float24_t> &test_input,
			hls::stream<float24_t> &test_sum,
			hls::stream<float24_t> &test_val1,
			hls::stream<float24_t> &test_val2,
			hls::stream<float24_t> &test_bias
//			hls::stream<float24_t> &test_buff
			)
{

#pragma HLS INTERFACE axis port = test_input
#pragma HLS INTERFACE axis port = test_sum
#pragma HLS INTERFACE axis port = test_val1
#pragma HLS INTERFACE axis port = test_val2
#pragma HLS INTERFACE axis port = test_bias
//#pragma HLS INTERFACE axis port = test_buff

#pragma HLS INTERFACE axis port=in_stream
#pragma HLS INTERFACE axis port=out_stream
//#pragma HLS INTERFACE ap_ctrl_none port=return

	conv_layer1( in_stream, out_stream, test_input, test_sum, test_val1, test_val2, test_bias);
}




