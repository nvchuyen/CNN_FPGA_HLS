
//
//#include <stdio.h>
//#include <stdlib.h>
//#include "headers1/defines.h"
//#include "headers1/input.h"
//#include "C:\Xilinx\Vivado\2020.2\data\ip\xilinx\v_axi4s_remap_v1_0\src\hls_video.h"
//
//#include "ap_fixed.h"
//
//#define EXP_WIDTH	16
//#define INT_WIDTH	4
//
//typedef float float24_t;
//
//#define eps 0.1
//#define test_arry 10
//void cnn( hls::stream<float24_t> &in_stream, hls::stream<float24_t> &out_stream );
//
//int main()
//{
//	hls::stream<float24_t> in_stream("test_in_stream");
//	hls::stream<float24_t> out_stream("test_out_stream");
//
//	float24_t fc_layer2_out[test_arry];
//
//	int i;
//	int correct_values, total_values;
//
//
//	for(i = 0; i < 1024; i++) {
//			in_stream << image[i];
//			printf("%d %0.06f\n", i, image[i]);
//		}
//
//	cnn(in_stream, out_stream);
//
//	for(i = 0; i < test_arry; i++) {
//		out_stream >> fc_layer2_out[i];
//		printf("%d %0.06f\n", i, fc_layer2_out[i]);
//	}
//
//	printf("DONE: %d out of %d are correct\n\n", correct_values, total_values);
//	return 0;
//}


//
//#include <stdio.h>
//#include <stdlib.h>
//#include "headers1/defines.h"
//#include "headers1/input.h"
//#include "headers1/output.h"
//#include "C:\Xilinx\Vivado\2020.2\data\ip\xilinx\v_axi4s_remap_v1_0\src\hls_video.h"
//
//#include "ap_fixed.h"
//
//#define EXP_WIDTH	16
//#define INT_WIDTH	4
//
//typedef float float24_t;
//
//#define eps 0.1
//#define output_size 14*14*8
//void cnn( hls::stream<float24_t> &in_stream, hls::stream<float24_t> &out_stream );
//
//int main()
//{
//	hls::stream <float24_t> in_stream ("test_in_stream");
//	hls::stream <float24_t> out_stream ("test_out_stream");
//
//	float24_t output_test[14][14][8];
//
//	int i;
//	int m, n, p;
//	int correct_values = 0;
//	int error_values =0;
//
//	for(i = 0; i < 1024; i++)
//	{
//		in_stream << image[i];
////		printf("%d %0.06f\n", i, image[i]);
//	}
//
//	cnn(in_stream, out_stream);
//
//	for(m = 0; m<14; m++)
//		{
//			for (n = 0 ; n< 14; n++)
//			{
//				for(p = 0; p<8; p++)
//				{
//					out_stream >> output_test[m][n][p];
//					printf("%d %0.06f\n", i, output_test[i]);
//				}
//			}
//		}
//
//	printf("\n \n");
//	for(m = 0; m<14; m++)
//	{
//		for (n = 0 ; n< 14; n++)
//		{
//			for(p = 0; p<8; p++)
//			{
//				if((output_test[m][n][p] - output_pooling[m][n][p]) > 0.002 || (output_pooling[m][n][p] - output_test[m][n][p] ) > 0.002)
//				{
//					printf(" output_pooling[%d][%d][%d] - output_test[%d]  = %f -  %f \n", m, n, p, m+n+p, output_pooling[m][n][p], output_test[m+n+p]);
//					error_values++;
//				}
//				else
//				{
//					correct_values++;
//				}
//			}
//		}
//	}
//	printf("ouput pooling 0-1-3: %f \n", output_pooling[0][1][3] );
//	printf("DONE: %d are values error,  %d are correct\n\n", error_values, correct_values);
//	return 0;
//}
//

//
//#include <stdio.h>
//#include <stdlib.h>
//#include "headers1/defines.h"
//#include "headers1/input.h"
//#include "headers1/output.h"
//#include "C:\Xilinx\Vivado\2020.2\data\ip\xilinx\v_axi4s_remap_v1_0\src\hls_video.h"
//
//#include "ap_fixed.h"
//
//#define EXP_WIDTH	16
//#define INT_WIDTH	4
//
//typedef float float24_t;
//
//#define eps 0.1
//#define output_size 14*14*8
//void cnn( hls::stream<float24_t> &in_stream, hls::stream<float24_t> &out_stream );
//
//int main()
//{
//	hls::stream <float24_t> in_stream ("test_in_stream");
//	hls::stream <float24_t> out_stream ("test_out_stream");
//
//	float24_t output_test[14][14][8];
//
//	int i;
//	int m, n, p;
//	int correct_values = 0;
//	int error_values =0;
//
//	for(i = 0; i < 1024; i++)
//	{
//		in_stream << image[i];
////		printf("%d %0.06f\n", i, image[i]);
//	}
//
//	cnn(in_stream, out_stream);
//
//	for(m = 0; m<14; m++)
//		{
//			for (n = 0 ; n< 14; n++)
//			{
//				for(p = 0; p<8; p++)
//				{
//					out_stream >> output_test[m][n][p];
//					printf("%d %0.06f\n", i, output_test[i]);
//				}
//			}
//		}
//
//	printf("\n \n");
//	for(m = 0; m<14; m++)
//	{
//		for (n = 0 ; n< 14; n++)
//		{
//			for(p = 0; p<8; p++)
//			{
//				if((output_test[m][n][p] - output_pooling[m][n][p]) > 0.002 || (output_pooling[m][n][p] - output_test[m][n][p] ) > 0.002)
//				{
//					printf(" output_pooling[%d][%d][%d] - output_test[%d]  = %f -  %f \n", m, n, p, m+n+p, output_pooling[m][n][p], output_test[m+n+p]);
//					error_values++;
//				}
//				else
//				{
//					correct_values++;
//				}
//			}
//		}
//	}
//	printf("ouput pooling 0-1-3: %f \n", output_pooling[0][1][3] );
//	printf("DONE: %d are values error,  %d are correct\n\n", error_values, correct_values);
//	return 0;
//}





#include <stdio.h>
#include <stdlib.h>
#include "headers1/defines.h"
#include "headers1/input.h"
#include "headers1/output.h"
#include "C:\Xilinx\Vivado\2020.2\data\ip\xilinx\v_axi4s_remap_v1_0\src\hls_video.h"
#include "ap_fixed.h"


typedef float float24_t;

#define eps 0.1
#define output_size 14*14*8
void cnn( hls::stream<float24_t> &in_stream, hls::stream<float24_t> &out_stream );

int main()
{
	hls::stream <float24_t> in_stream ("test_in_stream");
	hls::stream <float24_t> out_stream ("test_out_stream");

	float24_t output_test[10];

	int i;
	int m, n, p;
	int correct_values = 0;
	int error_values =0;

	for(i = 0; i < 32*32*1; i++)
	{
		in_stream << image[i];
//		printf("%d %0.06f\n", i, image[i]);
	}

	cnn(in_stream, out_stream);

	for(m = 0; m<10; m++)
		{
		out_stream >> output_test[m];
		printf("%d %0.06f\n", i, output_test[i]);
		}

	printf("\n \n");
	for(m = 0; m<10; m++)
	{
		if((output_test[m] - output_fully1[m]) > 0.002 || (output_fully1[m] - output_test[m]) > 0.002)
		{
			printf(" output_fully1[%d] - output_test[%d]  = %f -  %f \n", m, m, output_fully1[m], output_test[m]);
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














