
#include "headers1/buffer.h"
#include "headers1/weights.h"
#include "headers1/defines.h"
#include "headers1/activations.h"
#include <hls_stream.h>
#include <math.h>
#include "ap_fixed.h"
#include "C:\Xilinx\Vivado\2020.2\data\ip\xilinx\v_axi4s_remap_v1_0\src\hls_video.h"

#define POOL1_BUFFER_SIZE (P2_SIZE*P2_CHANNELS)

void pooling(hls::stream<float24_t>& out, hls::stream<float24_t>& in)
{
	int tem;
	int i, j, k, l, m;
	float24_t val_out;
	float24_t read;
	hls::LineBuffer<POOL1_BUFFER_SIZE, 1, float24_t> pool_buff;
#pragma HLS ARRAY_PARTITION variable=conv_buff complete

	pool_layer1_label0:for (i = 0; i < P2_SIZE; i++)
		pool_layer1_label1: for (l = 0; l < P2_KERNEL_SIZE; l++) {
			pool_layer1_label2: for (j = 0; j < P2_SIZE; j++)
				pool_layer1_label3: for (m = 0; m < P2_KERNEL_SIZE; m++)
					 pool_layer1_label4: for (k = 0; k < P2_CHANNELS; k++)
					 {
						in >> read;
						if (l == 0 && m == 0)
							pool_buff.val[j * P2_CHANNELS + k][0] = read;

						else
							pool_buff.val[j * P2_CHANNELS + k][0] = pool_buff.val[j * P2_CHANNELS + k][0] > read ? pool_buff.val[j * P2_CHANNELS + k][0] : read;

						if (l == (P2_KERNEL_SIZE - 1) && m == (P2_KERNEL_SIZE - 1))
						{
							out << pool_buff.val[j * P2_CHANNELS + k][0];
							tem = j * P2_CHANNELS + k;
							val_out = pool_buff.val[j * P2_CHANNELS + k][0];
						}
					}
			pool_layer1_label5: for (int skip = P2_SIZE * P2_STRIDE; skip < A1_SIZE; skip++)
				pool_layer1_label6: for (int channel = 0; channel < P2_CHANNELS; channel++)
					in >> read;
		}
	pool_layer1_label7: for (int skip_row = P2_SIZE * P2_STRIDE; skip_row < A1_SIZE; skip_row++)
		pool_layer1_label8: for (int skip_col = 0; skip_col < A1_SIZE; skip_col++)
			pool_layer1_label9: for (int skip_channel = 0;	skip_channel < A1_CHANNELS; skip_channel++)
				in >> read;
}


void pooling_layer2(hls::stream<float24_t>& in, hls::stream<float24_t>& out )
{
#pragma HLS INTERFACE axis port=in
#pragma HLS INTERFACE axis port=out
#pragma HLS INTERFACE ap_ctrl_none port=return

	pooling(out, in);
}









