
#include <stdio.h>
#include <stdlib.h>
#include "headers1/buffer.h"
//#include "headers1/weights.h"
#include "headers1/defines.h"
#include <hls_stream.h>


#define eps 0.00002

float image[IMAGE_SIZE][IMAGE_SIZE][IMAGE_CHANNELS]	=
	{{{0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0}},

	 {{0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.5645105,0.0,0.0,0.0,0.2519902,0.0,0.0,0.0,
	   0.4143693,0.0,0.0,0.0,0.0,0.0,0.0},
	  {0.11009526,0.868328,0.0,0.0,0.07701284,0.07126981,0.0,0.0,
	   0.0,0.0,0.52304196,0.0,0.0,0.0,0.0,0.0},
	  {0.0,0.62068397,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.8522887,
	   0.0,0.0,0.0,0.0,0.0},
	  {0.0,0.16781658,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.69729435,0.0,0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.5905274,0.0,
	   0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.27943105,0.0,
	   0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0}},

	 {{0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.22218126,0.0,0.0,0.14733134,0.0,0.0,0.0,0.36736745,0.0,
	   0.24717474,0.0,0.0,0.0,0.0,0.31678176,0.0},
	  {0.0,0.0,0.0,0.9200587,0.0,0.0,0.0,0.16940647,0.20899367,
	   0.0,0.0,0.0,0.0,0.0,0.618267,0.17051733},
	  {0.0,0.0,0.0,0.72269934,0.0,0.3121528,0.0,0.0,0.030566096,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.28972882,0.0,0.5033761,
	   0.0,0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.1660566,0.0,
	   0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.85994864,0.0,
	   0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0}},

	 {{0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.3169058,0.0,0.0,0.0,0.0,0.07450497,0.0,0.0,0.0,0.0,0.0,
	   0.21155101,0.0,0.0,0.41199565,0.0},
	  {0.0635674,0.0,0.0,0.0,0.0,1.4723191,0.0,0.28719914,0.0,
	   0.0,0.0,0.008041859,0.0,0.0,0.0,0.0},
	  {0.677757,0.0,0.0,0.0,0.0,0.4757511,0.0,0.0,0.0,0.0,0.0,
	   0.039032042,0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.41000944,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.87966204,0.0,0.90702444,0.0,0.0,0.18045563,
	   0.0,0.0,0.0,0.85100365,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.8107915,0.0,0.17670482,0.0,0.0,0.0,0.0,
	   0.090852916,0.0,0.9055526,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.23672244,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0}},

	 {{0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.46474934,0.0,0.0,0.0,0.06909323,0.0,0.0,0.0,
	   0.38639972,0.0,0.0,0.17661926,0.0,0.0,0.0},
	  {0.48786426,0.8254186,0.0,0.0,0.0,0.0,0.0,0.31541258,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.8099184},
	  {0.0,0.0,0.0,0.0,0.0,0.26084048,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,1.3459916,0.0,0.0,0.0,0.0,0.0,
	   0.5335285,0.48822197,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0559718,0.0,0.0,0.0,0.0,0.0,
	   0.349392,1.0000371,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.9373256,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.23912778,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0}},

	 {{0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.07418716,0.0,0.0,0.1787544,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.17661926,0.0,0.41366577,0.0},
	  {0.55588627,0.0,0.0,0.0,0.0,0.0,0.0,0.70590377,0.0,0.0,
	   0.0,0.58614665,0.0,0.0,0.3839792,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.016870141,0.0,1.276515,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.028768659,0.0,0.0,0.0,0.0,0.0,
	   0.5692314,0.027465641,0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.15230745,
	   0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.35989738,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0}},

	 {{0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.02387692,0.0},
	  {0.36809087,0.011036813,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.82040924,0.0,0.0,0.6682713,0.0},
	  {0.026863694,0.0,0.0,0.0,0.0,0.0,0.0,1.1016876,0.110438585,
	   0.0,0.0,0.8190028,0.0,0.0,0.7133897,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.5379033,0.70016056,0.0,
	   1.0499386,0.0,0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0015857,0.0,
	   0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0}},

	 {{0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.7087482,0.14259088,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.67295057,0.0,0.0,0.25122428,0.0},
	  {0.80809426,0.0,0.0,0.0,0.0,0.0,0.0,0.936996,0.14650643,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.7600403,0.0,
	   0.0,0.43940037,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.071534246,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0}},

	 {{0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.10288853,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.79489064,0.3235067,0.0,0.0,0.0,0.08508092,0.0,0.0,0.0,
	   0.49963817,0.0,0.0,0.0,0.0,0.0,0.0},
	  {1.2625548,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.95311105},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.62641,
	   0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0}},

	 {{0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0053333826,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.36712927,0.0,0.0,0.0,0.10695964,0.0,0.0,0.0,
	   0.26061386,0.0,0.0,0.16771105,0.0,0.0,0.0},
	  {0.0,0.05804369,0.0,0.0,0.12869167,0.0,0.0,0.0,0.0,0.0,
	   0.009508431,0.0,0.16439004,0.0,0.0,0.0},
	  {0.21482426,0.38912696,0.0,0.0,0.0,0.1528719,0.0,0.0,0.0,
	   0.4059674,0.12964731,0.0,0.0,0.0,0.0,0.0},
	  {0.9244585,0.3224088,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.01883316,0.0,0.0,0.0,0.0,0.0},
	  {0.37804973,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,1.1418488},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   1.0309278,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.79250824,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0}},

	 {{0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.05910045,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.015399158,0.8051363,0.0,0.0,0.0,0.0,0.0,0.73882854,
	   0.36967677,0.60421497,0.0423308,0.0,0.0,0.0,0.0,0.0},
	  {0.0,0.6450803,0.0,0.0,0.65170795,0.0,0.0,0.0,0.012549937,
	   0.0,0.89350903,0.0,0.0,0.0,0.0,0.0},
	  {0.46675563,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.46407282,0.0,0.0,0.0,0.0,0.0},
	  {0.32058865,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,1.1552536},
	  {0.0,0.0,0.0,0.0,0.0,0.96140116,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.8207762,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.13744225,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   1.0772202,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.40269238,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0}},

	 {{0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.3356362,0.0,0.0,0.24781285,0.0,0.0,0.0,0.8588432,0.0,
	   0.0,0.0,0.4405889,0.0,0.0,0.5816907,0.0},
	  {0.0,0.0,0.0,1.2910446,0.0,0.0,0.0,0.712291,0.557432,0.0,
	   0.0,0.20617014,0.0,0.0,1.201819,0.0},
	  {0.0,0.0,0.0,1.5465735,0.0,1.4168937,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,1.3998082,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.8955481,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.1831277,0.0,0.0,0.0,0.0,0.0,
	   0.009668171,1.0539786,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.7520577,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.18202247,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.17661926,0.0,0.0,0.0}}};




float output_ref [A2_SIZE][A2_SIZE][A2_CHANNELS]=
	{{{0.0,0.0,0.0,0.7821629,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0},
	  {0.8070439,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.7943852,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0},
	  {1.6912414,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,1.2992958,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0},
	  {1.9781452,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,1.2126435,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.47265643,0.0,0.0,0.0,0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,1.7548473,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0}},

	 {{0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,2.1032712,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.6625899,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,6.3268204,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0},
	  {1.3027036,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.8112439,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0},
	  {2.0600982,0.0,0.0,0.0,0.053962946,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.5780189,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.6687673,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0}},

	 {{0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.11442512,0.0},
	  {0.0,0.0,0.0,0.0,0.0,1.6489718,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,2.7954829,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   2.4821653,0.0,0.0,0.0,0.0,0.0,0.93576515,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   2.4510741,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.1860026,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,2.2987258,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0}},

	 {{0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,1.1699009,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.9172008,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,3.292277,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0}},

	 {{0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0},
	  {0.0,0.20522863,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0},
	  {0.0,4.603656,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,3.9726608,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,6.553823,0.14291477,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,6.2972517,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.64429617,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.8062671,0.0,0.0,0.0,0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.25882745,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.05350828,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.1712248,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0}},

	 {{0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.85193855,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0},
	  {0.0,2.6802566,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,4.4428673,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,1.4857734,0.0,0.0,0.0,5.2930813,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,5.767952,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,2.144994,0.0,0.0,0.0,0.0,1.7022734,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   1.548046,0.0,0.0,0.0,0.0,0.0}},

	 {{0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.30969477,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.33956492,0.0,0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,1.5559452,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,4.153136,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,1.8820939,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,1.8956494,0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,1.4090488,0.0,0.0,0.0,0.0,0.0,0.0,
	   1.1493245,0.6438469,0.0,0.0,0.0,0.0}},

	 {{0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.15063477,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   1.0321834,0.0,0.0,0.0,0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   1.2620618,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,2.046446,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   1.9925451,0.0,0.0,0.0,0.0},
	  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
	   0.1158694,1.837673,0.0,0.0,0.0,0.0}}};



void conv_layer2(hls::stream<float24_t> &in, hls::stream<float24_t> &out);

int main()
{
	float24_t conv_out[A2_SIZE * A2_SIZE * A2_CHANNELS];
	float24_t conv_ref[A2_SIZE][A2_SIZE][A2_CHANNELS];
	float24_t output_result[A2_SIZE][A2_SIZE][A2_CHANNELS];


	int i,j,k;
	float24_t x  =0 ;
	hls::stream<float24_t> out("output_stream");
	hls::stream<float24_t> in("input_stream");
	float a;

	int m, n, p;
	int correct_values = 0;
	int error_values =0;



	for(m = 0; m<IMAGE_SIZE ; m++)
		{
			for (n = 0 ; n< IMAGE_SIZE; n++)
			{
				for(p = 0; p < IMAGE_CHANNELS; p++)
				{
					in<<image[m][n][p];
//					printf("%d  %d   %d   %f    \n", m, n, p ,image[m][n][p]);
				}
			}
		}


	conv_layer2(in, out);


	for(m = 0; m < A2_SIZE ; m++)
		{
			for (n = 0 ; n < A2_SIZE; n++)
			{
				for(p = 0; p < A2_CHANNELS; p++)
				{
					out >> output_result[m][n][p];
					printf("%d   %d   %d \n", m, n, p);
					if((output_result[m][n][p] - output_ref[m][n][p]) > 0.002 || (output_ref[m][n][p] - output_result[m][n][p] ) > 0.002)
					{
						printf(" output_result[%d][%d][%d] - output_ref[%d][%d][%d] = %f -  %f \n", m, n, p, m,n,p, output_result[m][n][p], output_ref[m][n][p]);
						error_values++;
					}
					else
					{
						correct_values++;
					}
				}
			}
		}

	return 0;
}


