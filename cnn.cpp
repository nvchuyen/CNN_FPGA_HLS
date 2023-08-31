#include "headers/buffer.h"
//#include "headers/input.h"
#include "headers/weights.h"
#include "headers/defines.h"
#include "headers/activations.h"
#include "C:\Xilinx\Vivado\2020.2\data\ip\xilinx\v_axi4s_remap_v1_0\src\hls_video.h"
#include "ap_fixed.h"

#define POOL1_BUFFER_SIZE (P1_SIZE*P1_CHANNELS)

typedef float  float24_t;

#define CONV1_BUFFER_SIZE (IMAGE_SIZE * IMAGE_CHANNELS * (CONV1_KERNEL_SIZE -1) + CONV1_KERNEL_SIZE * IMAGE_CHANNELS)

float24_t bias[8] = { -0.4841, -0.5488, -0.1868, -0.4800, -0.2518, -0.3664, -0.3803, -0.1135 };

float24_t weight [8][1][4][4] =
	   {{{{ 0.2786, -0.0426, -0.2268, -0.5301},
          { 0.0320,  0.6261,  0.0993, -0.7795},
          {-0.1014,  0.5605,  0.5536, -0.2107},
          {-0.5452,  0.3395,  0.3114, -0.4605}}},


        {{{-0.2137, -0.3598, -0.7553, -0.2262},
          {-0.0375, -0.0784, -0.3340, -0.2696},
          {-0.0398,  0.0705,  0.3364,  0.5264},
          {-0.0722, -0.0227,  0.6754,  0.5053}}},


        {{{-0.0755, -0.2647, -0.0916,  0.7590},
          { 0.3023,  0.0996, -0.5787, -0.4078},
          {-0.2254,  0.4859, -0.1433, -0.4601},
          {-0.2650,  0.4975,  0.2370,  0.0491}}},


        {{{-0.0211,  0.1498,  0.2061,  0.3223},
          {-0.2056, -0.2040, -0.2143, -0.1042},
          {-0.1509, -0.1810, -0.0180, -0.2896},
          {-0.3059, -0.1462, -0.1386, -0.0748}}},


        {{{ 0.1497,  0.1197,  0.1574,  0.2538},
          { 0.2980,  0.2673,  0.3865,  0.1982},
          { 0.0974, -0.0964,  0.1274,  0.0934},
          {-0.1862, -0.0808, -0.3384, -0.2036}}},


        {{{-0.2240, -0.4834, -0.4727, -0.0349},
          { 0.5162,  0.1327, -0.0277, -0.3062},
          { 0.2217,  0.3580, -0.0419, -0.1235},
          {-0.4040,  0.1843,  0.3819,  0.3485}}},


        {{{ 0.2014,  0.5189,  0.4031, -0.0502},
          { 0.3310,  0.3275, -0.2120, -0.3727},
          { 0.3066, -0.2929, -0.3928, -0.2654},
          {-0.1208, -0.2840, -0.1152, -0.1291}}},


        {{{ 0.3645,  0.2516,  0.0923, -0.4367},
          {-0.5267,  0.0399,  0.7877, -0.3260},
          {-0.4858, -0.2301,  0.4087,  0.4380},
          { 0.1991, -0.1594, -0.5831,  0.1830}}}};

void conv_layer1(hls::stream<float24_t> &out, hls::stream<float24_t> &in) {
	int i, j, k, filter;
	float24_t sum, placeholder;
	int row_offset, col_offset, channel_offset;
//	static float test;

	buffer<CONV1_BUFFER_SIZE> conv_buff;
#pragma HLS ARRAY_PARTITION variable=conv_buff complete
	/*
	 * Read the initial buffer
	 * */
	conv_init_buffer:for (i = 0; i < CONV1_BUFFER_SIZE; i++)
	{
		if (in.empty() == 0)
		{
			placeholder = in.read();
			conv_buff.InsertBack(placeholder);
		}
	}

	conv_layer1_label_stride0:for (i = 0; i < (IMAGE_SIZE - CONV1_KERNEL_SIZE + 1); i += CONV1_STRIDE)
		conv_layer1_label_stride1: for (j = 0;	j < (IMAGE_SIZE - CONV1_KERNEL_SIZE + 1); j += CONV1_STRIDE)
		{
#pragma HLS PIPELINE II=32
			conv_layer1_label_filter: for (filter = 0; filter < CONV1_FILTERS; filter++)
			{
#pragma HLS UNROLL
				sum = 0;
				conv_layer1_label6_kernelrow: for (row_offset = 0; row_offset < CONV1_KERNEL_SIZE; row_offset++)
				{
#pragma HLS UNROLL
					conv_layer1_label7_kernelcol: for (col_offset = 0; col_offset < CONV1_KERNEL_SIZE; col_offset++)
					{
#pragma HLS UNROLL
						conv_layer1_label_channel: for (channel_offset = 0; channel_offset < CONV1_CHANNELS; channel_offset++)
						{
#pragma HLS UNROLL
							int t1, t2;
							static float24_t val1, val2;
							t1 = row_offset * IMAGE_SIZE * IMAGE_CHANNELS;
							t2 = col_offset * IMAGE_CHANNELS;
							val1 = conv_buff.GetValue(t1 + t2 + channel_offset);
							val2 = weight[filter][channel_offset][row_offset][col_offset];

							sum += val1 * val2;
						}
					}
				 }
				//test = relu(sum + bias[filter]);
				out << sum;// relu(sum + bias[filter]);
			  }

			if ((j + CONV1_STRIDE < (IMAGE_SIZE - CONV1_KERNEL_SIZE + 1)))
			{
				conv_layer1_label_buff0: for (int p = 0; p < IMAGE_CHANNELS; p++)
					if (in.empty() == 0)
					{
						placeholder = in.read();
						conv_buff.InsertBack(placeholder);
					}
			}
			else if ((i + CONV1_STRIDE < (IMAGE_SIZE - CONV1_KERNEL_SIZE + 1)) && (j + CONV1_STRIDE >= (IMAGE_SIZE - CONV1_KERNEL_SIZE + 1)))
				conv_layer1_label_buff1: for (int p = 0; p < CONV1_KERNEL_SIZE * IMAGE_CHANNELS; p++)
					if (in.empty() == 0)
					{
						placeholder = in.read();
						conv_buff.InsertBack(placeholder);
					}
		}
}


//
//void pool_layer1(hls::stream<float24_t>& out, hls::stream<float24_t>& in) {
//
//	int tem;
//	float val_out;
//	int i, j, k, l, m;
//	float24_t read;
//	hls::LineBuffer<POOL1_BUFFER_SIZE, 1, float24_t> pool_buff;
//
//	for (i = 0; i < P1_SIZE; i++)
//		pool_layer1_label1: for (l = 0; l < P1_KERNEL_SIZE; l++) {
//#pragma HLS PIPELINE II=32
//			pool_layer1_label2: for (j = 0; j < P1_SIZE; j++)
//#pragma HLS UNROLL
//				pool_layer1_label3: for (m = 0; m < P1_KERNEL_SIZE; m++)
//#pragma HLS UNROLL
//					 pool_layer1_label4: for (k = 0; k < P1_CHANNELS; k++)
//					 {
//#pragma HLS UNROLL
//						in >> read;
//						if (l == 0 && m == 0)
//							pool_buff.val[j * P1_CHANNELS + k][0] = read;
//
//						else
//							pool_buff.val[j * P1_CHANNELS + k][0] = pool_buff.val[j * P1_CHANNELS + k][0] > read ? pool_buff.val[j * P1_CHANNELS + k][0] : read;
//
//						if (l == (P1_KERNEL_SIZE - 1) && m == (P1_KERNEL_SIZE - 1))
//						{
//							out << pool_buff.val[j * P1_CHANNELS + k][0];
//							tem = j * P1_CHANNELS + k;
//							val_out = pool_buff.val[j * P1_CHANNELS + k][0];
//						}
//					}
//			pool_layer1_label5: for (int skip = P1_SIZE * P1_STRIDE; skip < A1_SIZE; skip++)
//				pool_layer1_label6: for (int channel = 0; channel < P1_CHANNELS; channel++)
//					in >> read;
//		}
//	pool_layer1_label7: for (int skip_row = P1_SIZE * P1_STRIDE; skip_row < A1_SIZE; skip_row++)
//		pool_layer1_label8: for (int skip_col = 0; skip_col < A1_SIZE; skip_col++)
//			pool_layer1_label9: for (int skip_channel = 0;	skip_channel < A1_CHANNELS; skip_channel++)
//				in >> read;
//}
//
//void fc_layer1(hls::stream<float24_t> &out, hls::stream<float24_t> &in,
//		float24_t weight[FC1_WEIGHTS_H][FC1_WEIGHTS_W],
//		float24_t bias[FC1_BIAS_SIZE]) {
//	float24_t read;
//	float24_t output[FC1_ACT_SIZE] = { 0 };
//
////	in >> read;
////	for (int i = 0; i < FC1_WEIGHTS_W; i++)
////		output[i] = weight[0][i] * read;
//
//	fc_layer1_label0: for (int j = 0; j < 14*14; j++) {
//#pragma HLS PIPELINE II=64
//		fc_layer1_label1:for(int channel = 0; channel <8; channel ++){
//#pragma HLS UNROLL
//			in >> read;
//			fc_layer1_label2: for (int i = 0; i < FC1_WEIGHTS_W; i++) {
//#pragma HLS UNROLL
//				output[i] += weight[j + 14*14*channel][i] * read;
//			}
//		}
//	}
//	fc_layer1_label3: for (int i = 0; i < FC1_WEIGHTS_W; i++)
//	{
//#pragma HLS UNROLL
//		out << relu(output[i] + bias[i]);
//	}
//}
//
//
//void fc_layer2(hls::stream<float24_t> &out, hls::stream<float24_t> &in,
//		float24_t weight[FC2_WEIGHTS_H][FC2_WEIGHTS_W],
//		float24_t bias[FC2_BIAS_SIZE]) {
//	float24_t read;
//	float24_t output[FC2_ACT_SIZE] = { 0 };
//
//	in >> read;
//	for (int i = 0; i < FC2_WEIGHTS_W; i++)
//		output[i] = weight[0][i] * read;
//
//	fc_layer2_label1: for (int j = 1; j < FC2_WEIGHTS_H; j++) {
//#pragma HLS PIPELINE II=64
//		in >> read;
//		fc_layer2_label42: for (int i = 0; i < FC2_WEIGHTS_W; i++) {
//#pragma HLS UNROLL
//			output[i] += weight[j][i] * read;
//		}
//	}
//	fc_layer2_label2: for (int i = 0; i < FC2_WEIGHTS_W; i++)
//	{
//#pragma HLS UNROLL
//		out << relu(output[i] + bias[i]);
//	}
//}
//


void cnn(hls::stream<float24_t> &in_stream, hls::stream<float24_t> &out_stream)
{

#pragma HLS INTERFACE axis port=in_stream depth=1024
#pragma HLS INTERFACE axis port=out_stream depth=6728
#pragma HLS INTERFACE ap_ctrl_none port=return



//	hls::stream<float24_t> conv1_out("conv1_out");
//	hls::stream<float24_t> pool1_out("pool1_out");
//	hls::stream<float24_t> fc1_out("fc1_out");
//	hls::stream<float24_t> image_in("image_in");


//	for (int i = 0; i < IMAGE_SIZE * IMAGE_SIZE * IMAGE_CHANNELS; i++)
//			image_in << image[i];

	conv_layer1(out_stream, in_stream);
//	pool_layer1(pool1_out, conv1_out);
//
//	fc_layer1(fc1_out, pool1_out, fc_layer1_weights, fc_layer1_bias);
//	fc_layer2(out_stream, fc1_out, fc_layer2_weights, fc_layer2_bias);
}








