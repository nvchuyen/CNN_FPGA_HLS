
#ifndef __POOLING_H_
#define __POOLING_H_

#include "headers1/buffer.h"
#include "headers1/weights.h"
#include "headers1/defines.h"
#include "headers1/activations.h"
#include "C:\Xilinx\Vivado\2020.2\data\ip\xilinx\v_axi4s_remap_v1_0\src\hls_video.h"
#include "ap_fixed.h"

#define POOL1_BUFFER_SIZE (P1_SIZE*P1_CHANNELS)

typedef float  float24_t;

void pool_layer1(hls::stream<float24_t>& in, hls::stream<float24_t>& out)
{
	int tem;
	float val_out;
	int i, j, k, l, m;
	int skip,channel, skip_row, skip_col, skip_channel;
	float24_t read;
	hls::LineBuffer<POOL1_BUFFER_SIZE, 1, float24_t> pool_buff;
#pragma HLS ARRAY_PARTITION variable=conv_buff complete

	pool_layer1_label0:for (i = 0; i < P1_SIZE; i++)
		pool_layer1_label1: for (l = 0; l < P1_KERNEL_SIZE; l++) {
			pool_layer1_label2: for (j = 0; j < P1_SIZE; j++)
				pool_layer1_label3: for (m = 0; m < P1_KERNEL_SIZE; m++)
					 pool_layer1_label4: for (k = 0; k < P1_CHANNELS; k++)
					 {
						in >> read;
						if (l == 0 && m == 0)
							pool_buff.val[j * P1_CHANNELS + k][0] = read;

						else
							pool_buff.val[j * P1_CHANNELS + k][0] = pool_buff.val[j * P1_CHANNELS + k][0] > read ? pool_buff.val[j * P1_CHANNELS + k][0] : read;

						if (l == (P1_KERNEL_SIZE - 1) && m == (P1_KERNEL_SIZE - 1))
						{
							out << pool_buff.val[j * P1_CHANNELS + k][0];

							val_out = pool_buff.val[j * P1_CHANNELS + k][0];
							tem = j * P1_CHANNELS + k;
						}
					}
			pool_layer1_label5: for ( skip = P1_SIZE * P1_STRIDE; skip < A1_SIZE; skip++)
				pool_layer1_label6: for ( channel = 0; channel < P1_CHANNELS; channel++)
					in >> read;
		}
	pool_layer1_label7: for (skip_row = P1_SIZE * P1_STRIDE; skip_row < A1_SIZE; skip_row++)
		pool_layer1_label8: for (skip_col = 0; skip_col < A1_SIZE; skip_col++)
			pool_layer1_label9: for (skip_channel = 0;	skip_channel < A1_CHANNELS; skip_channel++)
				in >> read;
}

#endif




