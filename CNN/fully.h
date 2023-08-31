
#ifndef __FULLY_H_
#define __FULLY_H_

#include "headers1/buffer.h"
#include "headers1/weights.h"
#include "headers1/defines.h"
#include "headers1/activations.h"
#include "C:\Xilinx\Vivado\2020.2\data\ip\xilinx\v_axi4s_remap_v1_0\src\hls_video.h"
#include "ap_fixed.h"

void fc_layer1( hls::stream<float24_t> &in, hls::stream<float24_t> &out,
		float24_t weight[FC1_WEIGHTS_H][FC1_WEIGHTS_W],
		float24_t bias[FC1_BIAS_SIZE]) {
	float24_t read;
	float24_t output[FC1_ACT_SIZE] = { 0 };
	static int i, j, channel;

	for ( i = 0; i < FC1_WEIGHTS_W; i++)
		output[i] = 0;

	fc_layer1_label0: for ( j = 0; j < 14*14; j++) {
#pragma HLS PIPELINE II=64
		fc_layer1_label1:for( channel = 0; channel <8; channel ++){
#pragma HLS UNROLL
			in >> read;
			fc_layer1_label2: for ( i = 0; i < FC1_WEIGHTS_W; i++) {
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


void fc_layer2(hls::stream<float24_t> &in, hls::stream<float24_t> &out,
		float24_t weight[FC2_WEIGHTS_H][FC2_WEIGHTS_W],
		float24_t bias[FC2_BIAS_SIZE]) {
	float24_t read;
	float24_t output[FC2_ACT_SIZE] = { 0 };

	static int i, j;
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
#pragma HLS UNROLL
		out << relu(output[i] + bias[i]);
	}
}

#endif


