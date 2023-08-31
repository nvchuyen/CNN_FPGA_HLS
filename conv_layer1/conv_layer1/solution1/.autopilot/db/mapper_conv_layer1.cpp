#include <systemc>
#include <vector>
#include <iostream>
#include "hls_stream.h"
#include "ap_int.h"
#include "ap_fixed.h"
using namespace std;
using namespace sc_dt;
class AESL_RUNTIME_BC {
  public:
    AESL_RUNTIME_BC(const char* name) {
      file_token.open( name);
      if (!file_token.good()) {
        cout << "Failed to open tv file " << name << endl;
        exit (1);
      }
      file_token >> mName;//[[[runtime]]]
    }
    ~AESL_RUNTIME_BC() {
      file_token.close();
    }
    int read_size () {
      int size = 0;
      file_token >> mName;//[[transaction]]
      file_token >> mName;//transaction number
      file_token >> mName;//pop_size
      size = atoi(mName.c_str());
      file_token >> mName;//[[/transaction]]
      return size;
    }
  public:
    fstream file_token;
    string mName;
};
unsigned int ap_apatb_in_stream_V_cap_bc;
static AESL_RUNTIME_BC __xlx_in_stream_V_size_Reader("../tv/stream_size/stream_size_in_in_stream_V.dat");
unsigned int ap_apatb_out_stream_V_cap_bc;
static AESL_RUNTIME_BC __xlx_out_stream_V_size_Reader("../tv/stream_size/stream_size_out_out_stream_V.dat");
extern "C" void conv_layer1(float*, float*);
extern "C" void apatb_conv_layer1_hw(volatile void * __xlx_apatb_param_in_stream, volatile void * __xlx_apatb_param_out_stream) {
  // collect __xlx_in_stream_tmp_vec
  unsigned __xlx_in_stream_V_tmp_Count = 0;
  unsigned __xlx_in_stream_V_read_Size = __xlx_in_stream_V_size_Reader.read_size();
  vector<float> __xlx_in_stream_tmp_vec;
  while (!((hls::stream<float>*)__xlx_apatb_param_in_stream)->empty() && __xlx_in_stream_V_tmp_Count < __xlx_in_stream_V_read_Size) {
    __xlx_in_stream_tmp_vec.push_back(((hls::stream<float>*)__xlx_apatb_param_in_stream)->read());
    __xlx_in_stream_V_tmp_Count++;
  }
  ap_apatb_in_stream_V_cap_bc = __xlx_in_stream_tmp_vec.size();
  // store input buffer
  float* __xlx_in_stream_input_buffer= new float[__xlx_in_stream_tmp_vec.size()];
  for (int i = 0; i < __xlx_in_stream_tmp_vec.size(); ++i) {
    __xlx_in_stream_input_buffer[i] = __xlx_in_stream_tmp_vec[i];
  }
  //Create input buffer for out_stream
  ap_apatb_out_stream_V_cap_bc = __xlx_out_stream_V_size_Reader.read_size();
  float* __xlx_out_stream_input_buffer= new float[ap_apatb_out_stream_V_cap_bc];
  // DUT call
  conv_layer1(__xlx_in_stream_input_buffer, __xlx_out_stream_input_buffer);
  for (unsigned i = 0; i <ap_apatb_out_stream_V_cap_bc; ++i)
    ((hls::stream<float>*)__xlx_apatb_param_out_stream)->write(__xlx_out_stream_input_buffer[i]);
}
