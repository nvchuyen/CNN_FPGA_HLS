

#ifndef __ACTIVATIONS_H
#define __ACTIVATIONS_H

#include "headers1/buffer.h"
#include "headers1/weights.h"
#include "headers1/defines.h"
#include "headers1/activations.h"
#include <hls_stream.h>
#include <hls_math.h>
#include "ap_fixed.h"



float24_t relu(float24_t a)
{
	return a > (float24_t)0 ? a : (float24_t)0;
}


float24_t sigmoid(float24_t a)
{
	float exp2a = expf(2*a)+1;
	return (exp2a-2)/(exp2a);
}


float _tanh(float x){
#pragma HLS INLINE
//#pragma HLS pipeline
	float exp2x = expf(2*x)+1;
	return (exp2x-2)/(exp2x);
}

#endif
