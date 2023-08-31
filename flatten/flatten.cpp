

#include "headers1/buffer.h"
#include "headers1/weights.h"
#include "headers1/defines.h"
#include "headers1/activations.h"
#include <hls_stream.h>
#include <hls_math.h>
#include "ap_fixed.h"

void convolution(hls::stream<float24_t> &in, hls::stream<float24_t> &out,
		) {

	static int i =0, j =0, k =0, filter =0;
	static float24_t sum  = 0;
	static float24_t  placeholder =0;
	static int row_offset, col_offset, channel_offset;
	static int p ;
	static int t1, t2;
	static float24_t val1, val2;
	static int test;

	buffer<CONV1_BUFFER_SIZE> conv_buff;
#pragma HLS ARRAY_PARTITION variable=conv_buff complete

	/*
	 * Read the initial buffer
	 * */
	conv_init_buffer:for (i = 0; i < CONV1_BUFFER_SIZE; i++) {
		if (in.empty() == 0) {
			placeholder = in.read();
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
							t1 = row_offset * IMAGE_SIZE * IMAGE_CHANNELS;
							t2 = col_offset * IMAGE_CHANNELS;
							test = t1 + t2 + channel_offset;
 							val1 = conv_buff.GetValue(t1 + t2 + channel_offset);
							val2 = weights[filter][channel_offset][row_offset][col_offset];
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
						placeholder = in.read();
						conv_buff.InsertBack(placeholder);
					}
			}
			else if ((i + CONV1_STRIDE < (IMAGE_SIZE - CONV1_KERNEL_SIZE + 1)) && (j + CONV1_STRIDE >= (IMAGE_SIZE - CONV1_KERNEL_SIZE + 1)))
				conv_layer1_label0: for (p = 0; p < CONV1_KERNEL_SIZE * IMAGE_CHANNELS; p++)
					if (in.empty() == 0)
					{
						placeholder  = in.read();
						conv_buff.InsertBack(placeholder);
					}
		}
}
