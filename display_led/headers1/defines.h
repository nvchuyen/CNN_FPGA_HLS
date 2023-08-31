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

#define FLOAT_IDTH			32
#define INT_WIDTH			8

typedef ap_fixed<FLOAT_IDTH, INT_WIDTH> float24_t;

#define IMAGE_SIZE 			32
#define IMAGE_CHANNELS		1

#define CONV1_KERNEL_SIZE 	4
#define CONV1_CHANNELS 		1
#define CONV1_FILTERS 		8
#define CONV1_BIAS_SIZE 	8
#define CONV1_STRIDE 		1

#define A1_SIZE				29
#define A1_CHANNELS			8


#define P1_SIZE				14
#define P1_CHANNELS			8
#define P1_KERNEL_SIZE		2
#define P1_STRIDE			2


#define FLATTEN_SIZE		1568 //14*14*8 // = 1568

#define FC1_WEIGHTS_H		1568 // 14*14*8
#define FC1_WEIGHTS_W		10
#define FC1_BIAS_SIZE		10

#define FC2_WEIGHTS_H		10
#define FC2_WEIGHTS_W		2
#define FC2_BIAS_SIZE		2


#define FC1_ACT_SIZE		10
#define FC2_ACT_SIZE		200
#define CONV_ACT_SIZE		29*29*8

#endif


