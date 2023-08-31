
#include <stdio.h>
#include <stdlib.h>
#include "headers/defines.h"
#include "headers/input.h"
#include "headers/output.h"
#include "C:\Xilinx\Vivado\2020.2\data\ip\xilinx\v_axi4s_remap_v1_0\src\hls_video.h"

#include "ap_fixed.h"

#define EXP_WIDTH	16
#define INT_WIDTH	4

typedef float float24_t;

#define eps 0.1

void cnn( hls::stream<float24_t> &in_stream, hls::stream<float24_t> &out_stream);

int main()
{
	hls::stream <float24_t> in_stream ("test_out_stream");
	hls::stream <float24_t> out_stream ("test_out_stream");

	float24_t fc_layer2_out[5];

	int i;
	int m, n, p;
	int correct_values = 0;

	for(i = 0; i < 2; i++) {
			in_stream << image[i];
//			printf("%d %0.06f\n", i, image[i]);
		}

	cnn( in_stream, out_stream);

	for(i = 0; i < 5; i++)
	{
		out_stream >> fc_layer2_out[i];
		printf("%d %0.06f\n", i, fc_layer2_out[i]);
	}
	printf("\n \n");
//	for(m = 0; m<29; m++)
//	{
//		for (n = 0 ; n< 29; n++)
//		{
//			for(p = 0; p<8; p++)
//			{
//				if((fc_layer2_out[m+n+p] - output[m][n][p]) > 0.0002)
//				{
//					printf(" output[%d][%d][%d] - fc_layer2_out[%d]  = %f -  %f \n", m,n,p,m+n+p,output[m][n][p], fc_layer2_out[m+n+p]);
//					//return 0;
//				}
//				else
//				{
//					correct_values++;
//				}
//			}
//		}
//	}
	printf("DONE: %d out of ... are correct\n\n", correct_values);
	return 0;
}




