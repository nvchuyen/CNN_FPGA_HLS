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
unsigned int ap_apatb_in_str_V_cap_bc;
static AESL_RUNTIME_BC __xlx_in_str_V_size_Reader("../tv/stream_size/stream_size_in_in_str_V.dat");
unsigned int ap_apatb_out_str_V_cap_bc;
static AESL_RUNTIME_BC __xlx_out_str_V_size_Reader("../tv/stream_size/stream_size_out_out_str_V.dat");
struct __cosim_s4__ { char data[4]; };
extern "C" void ram(__cosim_s4__*, __cosim_s4__*, volatile void *);
extern "C" void apatb_ram_hw(volatile void * __xlx_apatb_param_in_str, volatile void * __xlx_apatb_param_out_str, volatile void * __xlx_apatb_param_enable) {
  // collect __xlx_in_str_tmp_vec
  unsigned __xlx_in_str_V_tmp_Count = 0;
  unsigned __xlx_in_str_V_read_Size = __xlx_in_str_V_size_Reader.read_size();
  vector<__cosim_s4__> __xlx_in_str_tmp_vec;
  while (!((hls::stream<__cosim_s4__>*)__xlx_apatb_param_in_str)->empty() && __xlx_in_str_V_tmp_Count < __xlx_in_str_V_read_Size) {
    __xlx_in_str_tmp_vec.push_back(((hls::stream<__cosim_s4__>*)__xlx_apatb_param_in_str)->read());
    __xlx_in_str_V_tmp_Count++;
  }
  ap_apatb_in_str_V_cap_bc = __xlx_in_str_tmp_vec.size();
  // store input buffer
  __cosim_s4__* __xlx_in_str_input_buffer= new __cosim_s4__[__xlx_in_str_tmp_vec.size()];
  for (int i = 0; i < __xlx_in_str_tmp_vec.size(); ++i) {
    __xlx_in_str_input_buffer[i] = __xlx_in_str_tmp_vec[i];
  }
  //Create input buffer for out_str
  ap_apatb_out_str_V_cap_bc = __xlx_out_str_V_size_Reader.read_size();
  __cosim_s4__* __xlx_out_str_input_buffer= new __cosim_s4__[ap_apatb_out_str_V_cap_bc];
  // DUT call
  ram(__xlx_in_str_input_buffer, __xlx_out_str_input_buffer, __xlx_apatb_param_enable);
  for (unsigned i = 0; i <ap_apatb_out_str_V_cap_bc; ++i)
    ((hls::stream<__cosim_s4__>*)__xlx_apatb_param_out_str)->write(__xlx_out_str_input_buffer[i]);
}