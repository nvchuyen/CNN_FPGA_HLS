
#include <stdio.h>
#include <stdlib.h>
#include "headers1/defines.h"
#include "headers1/input.h"
#include "headers1/output.h"
#include "C:\Xilinx\Vivado\2020.2\data\ip\xilinx\v_axi4s_remap_v1_0\src\hls_video.h"
#include "ap_fixed.h"


//typedef float float24_t;

#define eps 0.1
#define output_size 14*14*8
void fully1_cnn( hls::stream<float24_t> &in_stream, hls::stream<float24_t> &out_stream );

int main()
{
	hls::stream <float24_t> in_stream ("test_in_stream");
	hls::stream <float24_t> out_stream ("test_out_stream");

	float24_t output_test[10];

	int i;
	int m, n, p;
	int correct_values = 0;
	int error_values =0;

	for(i = 0; i < 14*14*8; i++)
	{
		in_stream << image[i];
//		printf("%d %0.06f\n", i, image[i]);
	}

	fully1_cnn(in_stream, out_stream);

	for(m = 0; m<10; m++)
		{
		out_stream >> output_test[m];
		printf("%d    %0.06f\n", m, output_test[m]);
		}

	printf("\n \n");
	for(m = 0; m<10; m++)
	{
		if((output_test[m] - output_fully[m]) > 0.002 || (output_fully[m] - output_test[m]) > 0.002)
		{
			printf(" output_fully[%d] - output_test[%d]  = %f -  %f \n", m, m, output_fully[m], output_test[m]);
			error_values++;
		}
		else
		{
			correct_values++;
		}
	}

	printf("DONE: %d are values error,  %d are correct\n\n", error_values, correct_values);
	return 0;
}









