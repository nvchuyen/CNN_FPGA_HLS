
#include "ap_fixed.h"
//#include "defines.h"

#ifndef __WEIGHTS_H
#define __WEIGHTS_H


//#include "E:\CMC\CNN\VitisHLS\conv_layer1"
typedef float  				float24_t;

float24_t conv_layer1_bias1[16] = {-0.66229796,-0.37027013,-0.26610014,-0.22001697,-0.50498134,
												 -0.49019486,-0.0950407,-0.50239086,-0.6185853,-0.04615406,
												 -0.67819965,-0.98230964,0.17661926,-0.384116,-0.22167784,
												 -0.6104758};


float24_t conv_layer1_weights [16][1][5][5] =
		{{{{0.23421748,-0.54811376,-0.06400125,0.38588893,0.15234528},
		   {0.0043292562,-0.9541949,-0.43835956,0.03667154,0.33880234},
		   {-0.0688677,-0.9319937,-0.21971017,-0.15254933,0.3949919},
		   {-0.16537791,-0.20945738,0.07634407,-0.0011223303,
			0.32882106},
		   {-0.027042728,-0.103996314,0.24858755,0.26005495,
			0.036405563}}},


		 {{{-0.5917337,-0.70105,-0.07936934,0.4657202,0.49100226},
		   {-0.32742384,-1.2655289,-1.5797107,-1.8658156,-0.9625751},
		   {-0.6433083,0.074372075,-0.33465487,-0.06384567,
			-0.49386272},
		   {-0.30929142,-0.18388085,-0.05386981,0.14646798,
			-0.12767534},
		   {-0.54933447,0.17771511,-0.056836046,0.6176583,0.5761338}}},


		 {{{-0.13514985,0.05640137,-0.20535009,-0.1938129,0.026272982},
		   {-0.020820105,-0.14432266,0.025980042,0.05669345,
			-0.049285747},
		   {-0.025378373,-0.0022871522,0.039889134,-0.19380322,
			0.10156889},
		   {-0.112744026,-0.25722903,-0.066204034,-0.13673891,
			-0.16372398},
		   {0.114347026,-0.2008965,-0.07323861,0.17778142,
			-0.088440046}}},


		 {{{-0.3910903,-0.20690927,-0.116243616,-0.7181655,
			-0.32821068},
		   {0.15589161,0.27703863,-0.23595476,-0.10883365,0.15197},
		   {0.39260632,0.5846511,0.62307113,0.20263472,0.63534933},
		   {-0.44625726,0.0060016885,-0.031048119,-0.322832,
			-0.46117213},
		   {-1.2693951,-1.1510612,-0.5693065,-1.1656567,-0.78287107}}},


		 {{{-0.12490381,0.16404057,0.09198179,0.18968682,0.17481968},
		   {0.10418908,-0.18721193,-0.7956642,-0.5443994,0.21904337},
		   {-0.53407013,-0.2235043,-0.284734,-0.8585532,-0.9760096},
		   {-1.1553296,0.057203487,0.654837,0.47830907,-0.94364315},
		   {-1.3654886,-0.31023866,0.62839586,0.52751285,-0.491276}}},


		 {{{-0.31005904,-0.14062883,0.24152686,0.09083685,0.18475711},
		   {-0.23048346,0.2045694,0.3425257,0.37232643,-0.22321504},
		   {0.24118425,0.5346952,0.45274118,-0.21936175,-0.7769528},
		   {-0.13636236,-0.015237961,-0.65476334,-1.3632264,
			-0.08179041},
		   {-1.278467,-1.6109551,-0.48851538,0.25433418,0.595911}}},


		 {{{-0.29801837,-0.07260761,-0.7136034,-0.89592063,
			-0.45213526},
		   {-1.0062217,-0.8256978,-1.1511596,0.14409861,-0.03806094},
		   {-0.31163782,-0.25634193,0.4750214,0.54903877,-0.6067612},
		   {0.28614208,0.11733116,0.37758416,-0.97256404,-0.7812725},
		   {-0.5382717,-0.46933052,-0.6117964,-0.3515281,-0.6135657}}},


		 {{{-0.44569787,0.036604572,0.113204524,0.4148269,-0.30728224},
		   {-0.73718977,0.08270847,0.107497476,0.44121122,-0.99441427},
		   {-1.2498987,-0.73891735,0.15607563,0.70277214,-0.08629439},
		   {-0.44245234,-1.5449705,-0.6192423,0.53695536,0.32135615},
		   {0.5597726,-0.21401706,-0.65115595,-0.18759029,
			-0.030824281}}},


		 {{{-0.20460053,-0.36659366,-0.9121414,-1.1122766,-1.0335164},
		   {0.0010299613,0.38178667,0.4834822,-0.39709017,-0.97091115},
		   {0.057996713,0.036889154,0.6953735,0.8100201,-0.51613873},
		   {-0.061986744,-0.644154,-0.34422436,0.35930112,-0.10276262},
		   {-0.28678367,-0.3525039,-0.31080443,0.14466253,
			0.0056301574}}},


		 {{{-0.05029853,-0.46884748,-0.0712704,-0.51327455,-1.136672},
		   {-0.6274538,-0.6647253,-0.68311626,-0.27961472,-0.7857348},
		   {-0.45451283,-0.53154683,-0.9874563,-0.23647077,
			-0.07976114},
		   {-0.29358846,-0.76730895,-0.97798103,-0.4096247,0.4426361},
		   {-0.25982732,-0.4913349,-0.69229245,-0.18182226,0.34550783}}},


		 {{{-0.15074138,-0.4278825,-0.18838063,-0.65652996,0.51894206},
		   {0.29973885,0.26683423,-0.24126555,-1.5034983,0.044995014},
		   {0.061243948,0.5448456,-0.009032296,-0.25417155,
			-0.70699567},
		   {-0.3296745,0.11347667,-0.06109519,0.056630604,0.18996485},
		   {0.18484089,0.4514331,0.2851037,0.49363723,0.16177592}}},


		 {{{0.5686063,0.09959352,0.41563988,0.43052328,0.2966236},
		   {0.19763647,-0.20812659,-0.30597347,0.26637182,0.14293352},
		   {0.0012327704,-0.45681694,-0.093618885,0.13898174,
			0.4556167},
		   {-0.100296065,-0.70011467,-1.1473113,-0.6761909,0.2682397},
		   {0.14834872,-0.06806495,0.07288409,-0.30619064,-0.45221248}}},


		 {{{0.27556348,0.2909094,-0.021153782,-0.07414573,-1.0499817},
		   {0.2325537,0.06047961,-0.024333457,-0.16765046,-1.0205191},
		   {0.14180566,-0.10937075,-0.22970277,-2.2040894,-0.7574257},
		   {-0.13449726,-0.446497,-1.0945859,-1.7633783,-0.0414547},
		   {-1.3556498,-0.9752424,-0.5111816,-0.28127077,-0.4543186}}},


		 {{{0.1033178,0.2403857,-0.41602585,-0.911411,-1.150074},
		   {-0.13432543,0.392644,0.12903687,-0.28063703,-0.589144},
		   {-1.3644958,-0.12208992,0.17439164,0.08951602,-0.42960882},
		   {-1.2672786,0.09467641,-0.0006953592,-0.566127,-0.18309118},
		   {-0.062760696,0.35886103,0.010035805,-0.81044704,
			-0.93115556}}},


		 {{{-0.5606661,-0.1562918,0.32125086,-0.108739585,-0.04733336},
		   {-0.6295735,0.032923177,0.1747622,-0.12564592,0.5902748},
		   {-0.8369429,0.23213494,0.18613057,0.095138654,0.3753982},
		   {-1.5201699,-0.9528757,0.017424896,-0.021083295,
			-0.49112958},
		   {0.035815343,-0.9920798,-1.0501634,-1.5715014,-0.7422531}}},


		 {{{0.2574519,-0.20531741,-0.3057102,0.1385014,-0.03506856},
		   {0.27627528,-1.1403893,-0.26956928,0.31848177,0.11603713},
		   {-0.62030643,-0.37900656,0.73286295,0.21279411,-0.0545956},
		   {-0.6534852,0.10094096,0.7642596,-0.23129538,-0.883155},
		   {0.27498683,0.11418033,-0.2221909,-0.49936903,-0.10858602}}}};




#endif

