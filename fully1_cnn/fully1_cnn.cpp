
#include "headers1/buffer.h"
#include "headers1/weights.h"
#include "headers1/defines.h"
#include "headers1/activations.h"
#include <hls_stream.h>
#include "ap_fixed.h"


void fc_layer1(hls::stream<float24_t> &in, hls::stream<float24_t> &out,
		float24_t weight[FC1_WEIGHTS_H][FC1_WEIGHTS_W],
		float24_t bias[FC1_BIAS_SIZE]){
float24_t read;
float24_t output[FC1_ACT_SIZE] = { 0 };
int i, j, channel;

	for (i = 0; i < FC1_WEIGHTS_W; i++)
		output[i] = 0;

	fc_layer1_label0: for (j = 0; j < 14*14; j++)
	{
#pragma HLS PIPELINE II=64
		fc_layer1_label1:for(channel = 0; channel <8; channel ++)
		{
#pragma HLS UNROLL
			in >> read;
			fc_layer1_label2: for (i = 0; i < FC1_WEIGHTS_W; i++)
			{
#pragma HLS UNROLL
				output[i] += weight[j + 14*14*channel][i] * read;
			}
		}
	}

	fc_layer1_label3: for (i = 0; i < FC1_WEIGHTS_W; i++)
	{
		out << relu(output[i] + bias[i]);
	}
}


void fully1_cnn(hls::stream<float24_t> &in, hls::stream<float24_t> &out)
{

#pragma HLS INTERFACE axis port=in
#pragma HLS INTERFACE axis port=out
#pragma HLS INTERFACE ap_ctrl_none port=return

	fc_layer1(in, out, fc_layer1_weights, fc_layer1_bias);
}







