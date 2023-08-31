
#include "headers1/buffer.h"
#include "headers1/weights.h"
//#include "headers1/defines.h"
#include "headers1/activations.h"
//#include "C:\Xilinx\Vivado\2020.2\data\ip\xilinx\v_axi4s_remap_v1_0\src\hls_video.h"
#include <hls_stream.h>
#include "ap_fixed.h"

typedef float float24_t;
void fully_connected(hls::stream<float24_t> &in, hls::stream<float24_t> &out,
		float24_t weight[FC1_WEIGHTS_H][FC1_WEIGHTS_W],
		float24_t bias[FC1_BIAS_SIZE]){
float24_t read;
float24_t output[FC1_ACT_SIZE]; //= { 0.0 };
int i, j, channel;
float test_weight = 0;
float test_out =0;

	for (i = 0; i < FC1_WEIGHTS_H; i++)
		output[i] = 0;

//	fc_layer1_label0: for (i = 0; i < FC1_WEIGHTS_H; i++)
//	{
//#pragma HLS PIPELINE II=64

	fc_layer1_label1:for(channel = 0; channel < CHANNEL; channel ++)
	{
#pragma HLS PIPELINE II=64
		fc_layer1_label2: for (j = 0; j < 32; j++) //(j = 0; j < FC1_WEIGHTS_W; j++)
		{
#pragma HLS UNROLL
			in >> read;
			fc_layer1_label0: for (i = 0; i < FC1_WEIGHTS_H; i++)
			{

				test_weight = weight [i][j + 15 *j + channel];
				output[i] += weight [i][j + 15 * j + channel] * read;

				printf("%d in*weight %f * %f \n",j + 15 * j + channel, read, test_weight);
			}
		}
	}
	for (i = 0; i<FC1_WEIGHTS_H; i++ )
	{
		test_out = output[i] + bias [i];
		out << output[i] + bias [i];
	}

}



void fully_layer(hls::stream<float24_t> &in, hls::stream<float24_t> &out)
{

#pragma HLS INTERFACE axis port=in
#pragma HLS INTERFACE axis port=out
#pragma HLS INTERFACE ap_ctrl_none port=return

	fully_connected(in, out, fc_layer1_weights, fc_layer1_bias);
}







