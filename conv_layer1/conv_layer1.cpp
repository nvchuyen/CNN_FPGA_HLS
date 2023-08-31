
#include "headers1/buffer.h"
#include "headers1/weights.h"
#include "headers1/defines.h"
#include "headers1/activations.h"
#include <hls_stream.h>
#include <hls_math.h>
#include "ap_fixed.h"
#include "Convolution.h"


void conv_layer1(hls::stream<float24_t> &in_stream,
			hls::stream<float24_t> &out_stream
			)
{

#pragma HLS INTERFACE axis port=in_stream
#pragma HLS INTERFACE axis port=out_stream

	convolution( in_stream, out_stream, conv_layer1_weights, conv_layer1_bias1);
}




