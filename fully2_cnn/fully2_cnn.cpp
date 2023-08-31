
#include "headers1/buffer.h"
#include "headers1/weights.h"
#include "headers1/defines.h"
#include "headers1/activations.h"
#include "hls_stream.h"
#include "ap_fixed.h"

//typedef ap_fixed<8, 24> float24_t;

void fc_layer2(hls::stream<float24_t> &out, hls::stream<float24_t> &in,
		float24_t weight[FC2_WEIGHTS_H][FC2_WEIGHTS_W],
		float24_t bias[FC2_BIAS_SIZE]) {
	float24_t read;
	float24_t output[FC2_ACT_SIZE] = { 0 };
	int i, j;

	in >> read;
	for ( i = 0; i < FC2_WEIGHTS_W; i++)
		output[i] = weight[0][i] * read;

	fc_layer2_label1: for ( j = 1; j < FC2_WEIGHTS_H; j++) {
#pragma HLS PIPELINE II=64
		in >> read;
		fc_layer2_label42: for ( i = 0; i < FC2_WEIGHTS_W; i++) {
#pragma HLS UNROLL
			output[i] += weight[j][i] * read;
		}
	}
	fc_layer2_label2: for ( i = 0; i < FC2_WEIGHTS_W; i++)
	{
		out << relu(output[i] + bias[i]);
	}
}



void fully2_cnn(hls::stream<float24_t> &in, hls::stream<float24_t> &out)
{

#pragma HLS INTERFACE axis port=in
#pragma HLS INTERFACE axis port=out
#pragma HLS INTERFACE ap_ctrl_none port=return

	fc_layer2(out, in, fc_layer2_weights, fc_layer2_bias);
}











