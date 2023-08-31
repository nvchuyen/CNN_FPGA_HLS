

#ifndef __CONVOLUTION_H_
#define __CONVOLUTION_H_


#include "headers1/buffer.h"
#include "headers1/weights.h"
#include "headers1/defines.h"
#include "headers1/activations.h"
#include "C:\Xilinx\Vivado\2020.2\data\ip\xilinx\v_axi4s_remap_v1_0\src\hls_video.h"
#include "ap_fixed.h"


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



void conv_layer1(hls::stream<float24_t> &in, hls::stream<float24_t> &out) {
	static int i, j, k, filter;
	staic float24_t sum, placeholder;
	static int row_offset, col_offset, channel_offset;
	static int p ;
	buffer<CONV1_BUFFER_SIZE> conv_buff;
#pragma HLS ARRAY_PARTITION variable=conv_buff complete
	/*
	 * Read the initial buffer
	 * */
	conv_init_buffer:for (i = 0; i < CONV1_BUFFER_SIZE; i++) {
		if (in.empty() == 0) {
			in >> placeholder;
//			conv_buff.shift_up(0);
//			conv_buff.insert_top(placeholder, 0);
			conv_buff.InsertBack(placeholder);
		}
	}

	conv_layer1_label_stride:for (i = 0; i < (IMAGE_SIZE - CONV1_KERNEL_SIZE + 1); i += CONV1_STRIDE)
		conv_layer1_label9: for (j = 0;	j < (IMAGE_SIZE - CONV1_KERNEL_SIZE + 1); j += CONV1_STRIDE)
		{
#pragma HLS PIPELINE II=32
			conv_layer1_label2: for (filter = 0; filter < CONV1_FILTERS; filter++)
			{
#pragma HLS UNROLL
				sum = 0;
				conv_layer1_label6: for (row_offset = 0; row_offset < CONV1_KERNEL_SIZE; row_offset++)
				{
#pragma HLS UNROLL
					conv_layer1_label7: for (col_offset = 0; col_offset < CONV1_KERNEL_SIZE; col_offset++)
					{
#pragma HLS UNROLL
						conv_layer1_label8: for (channel_offset = 0; channel_offset < CONV1_CHANNELS; channel_offset++)
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
				out << relu(sum + bias[filter]);
			}

			if ((j + CONV1_STRIDE < (IMAGE_SIZE - CONV1_KERNEL_SIZE + 1)))
			{
				conv_layer1_label1: for (p = 0; p < IMAGE_CHANNELS; p++)
					if (in.empty() == 0)
					{
						in>>placeholder;
						conv_buff.InsertBack(placeholder);
//						conv_buff.shift_up(0);
//						conv_buff.insert_top(placeholder, 0);
					}
			}
			else if ((i + CONV1_STRIDE < (IMAGE_SIZE - CONV1_KERNEL_SIZE + 1)) && (j + CONV1_STRIDE >= (IMAGE_SIZE - CONV1_KERNEL_SIZE + 1)))
				conv_layer1_label0: for (p = 0; p < CONV1_KERNEL_SIZE * IMAGE_CHANNELS; p++)
					if (in.empty() == 0)
					{
						in >> placeholder;
						conv_buff.InsertBack(placeholder);
//						conv_buff.shift_up(0);
//						conv_buff.insert_top(placeholder, 0);
					}
		}
}

#endif





