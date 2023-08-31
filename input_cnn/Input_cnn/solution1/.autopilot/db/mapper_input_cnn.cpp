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
unsigned int ap_apatb_out_str_V_cap_bc;
static AESL_RUNTIME_BC __xlx_out_str_V_size_Reader("../tv/stream_size/stream_size_out_out_str_V.dat");
extern "C" void input_cnn(float*, volatile void *);
extern "C" void apatb_input_cnn_hw(volatile void * __xlx_apatb_param_out_str, volatile void * __xlx_apatb_param_enable) {
  //Create input buffer for out_str
  ap_apatb_out_str_V_cap_bc = __xlx_out_str_V_size_Reader.read_size();
  float* __xlx_out_str_input_buffer= new float[ap_apatb_out_str_V_cap_bc];
  // DUT call
  input_cnn(__xlx_out_str_input_buffer, __xlx_apatb_param_enable);
  for (unsigned i = 0; i <ap_apatb_out_str_V_cap_bc; ++i)
    ((hls::stream<float>*)__xlx_apatb_param_out_str)->write(__xlx_out_str_input_buffer[i]);
}
