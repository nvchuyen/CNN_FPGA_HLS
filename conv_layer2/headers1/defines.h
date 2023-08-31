/******************************************************************************
 * (C) Copyright 2020 AMIQ Consulting
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * NAME:        defines.h
 * PROJECT:     nnet_stream
 * Description: CNN related parameters (hyper-parameters)
 *******************************************************************************/
#ifndef __DEFINES_H
#define __DEFINES_H

#include "ap_fixed.h"

//#define FLOAT_IDTH			32
//#define INT_WIDTH			8
//
//typedef ap_fixed<FLOAT_IDTH, INT_WIDTH> float24_t;

typedef float  				float24_t;

#define IMAGE_SIZE 			12
#define IMAGE_CHANNELS		16



#define CONV2_KERNEL_SIZE 	5
#define CONV2_CHANNELS 		16
#define CONV2_FILTERS 		32
#define CONV2_BIAS_SIZE		32
#define CONV2_STRIDE 		1


#define A2_SIZE				8
#define A2_CHANNELS			32



#define IMAGE_SIZE 			12
#define IMAGE_CHANNELS		16

//#define CONV1_KERNEL_SIZE 	5
//#define CONV1_CHANNELS 		16
//#define CONV1_FILTERS 		32
//#define CONV1_BIAS_SIZE 	32
//#define CONV1_STRIDE 		1
#endif

