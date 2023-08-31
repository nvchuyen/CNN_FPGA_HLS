#include <systemc>
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <stdint.h>
#include "SysCFileHandler.h"
#include "ap_int.h"
#include "ap_fixed.h"
#include <complex>
#include <stdbool.h>
#include "autopilot_cbe.h"
#include "hls_stream.h"
#include "hls_half.h"
#include "hls_signal_handler.h"

using namespace std;
using namespace sc_core;
using namespace sc_dt;

// wrapc file define:
#define AUTOTB_TVIN_in_V "../tv/cdatafile/c.test_array.autotvin_in_V.dat"
#define AUTOTB_TVOUT_in_V "../tv/cdatafile/c.test_array.autotvout_in_V.dat"
#define WRAPC_STREAM_SIZE_IN_in_V "../tv/stream_size/stream_size_in_in_V.dat"
#define WRAPC_STREAM_INGRESS_STATUS_in_V "../tv/stream_size/stream_ingress_status_in_V.dat"
// wrapc file define:
#define AUTOTB_TVIN_out_V "../tv/cdatafile/c.test_array.autotvin_out_V.dat"
#define AUTOTB_TVOUT_out_V "../tv/cdatafile/c.test_array.autotvout_out_V.dat"
#define WRAPC_STREAM_SIZE_OUT_out_V "../tv/stream_size/stream_size_out_out_V.dat"
#define WRAPC_STREAM_EGRESS_STATUS_out_V "../tv/stream_size/stream_egress_status_out_V.dat"
// wrapc file define:
#define AUTOTB_TVIN_test_val2 "../tv/cdatafile/c.test_array.autotvin_test_val2.dat"
#define AUTOTB_TVOUT_test_val2 "../tv/cdatafile/c.test_array.autotvout_test_val2.dat"
// wrapc file define:
#define AUTOTB_TVIN_test_bias "../tv/cdatafile/c.test_array.autotvin_test_bias.dat"
#define AUTOTB_TVOUT_test_bias "../tv/cdatafile/c.test_array.autotvout_test_bias.dat"

#define INTER_TCL "../tv/cdatafile/ref.tcl"

// tvout file define:
#define AUTOTB_TVOUT_PC_in_V "../tv/rtldatafile/rtl.test_array.autotvout_in_V.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_out_V "../tv/rtldatafile/rtl.test_array.autotvout_out_V.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_test_val2 "../tv/rtldatafile/rtl.test_array.autotvout_test_val2.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_test_bias "../tv/rtldatafile/rtl.test_array.autotvout_test_bias.dat"

class INTER_TCL_FILE {
  public:
INTER_TCL_FILE(const char* name) {
  mName = name; 
  in_V_depth = 0;
  out_V_depth = 0;
  test_val2_depth = 0;
  test_bias_depth = 0;
  trans_num =0;
}
~INTER_TCL_FILE() {
  mFile.open(mName);
  if (!mFile.good()) {
    cout << "Failed to open file ref.tcl" << endl;
    exit (1); 
  }
  string total_list = get_depth_list();
  mFile << "set depth_list {\n";
  mFile << total_list;
  mFile << "}\n";
  mFile << "set trans_num "<<trans_num<<endl;
  mFile.close();
}
string get_depth_list () {
  stringstream total_list;
  total_list << "{in_V " << in_V_depth << "}\n";
  total_list << "{out_V " << out_V_depth << "}\n";
  total_list << "{test_val2 " << test_val2_depth << "}\n";
  total_list << "{test_bias " << test_bias_depth << "}\n";
  return total_list.str();
}
void set_num (int num , int* class_num) {
  (*class_num) = (*class_num) > num ? (*class_num) : num;
}
void set_string(std::string list, std::string* class_list) {
  (*class_list) = list;
}
  public:
    int in_V_depth;
    int out_V_depth;
    int test_val2_depth;
    int test_bias_depth;
    int trans_num;
  private:
    ofstream mFile;
    const char* mName;
};

static void RTLOutputCheckAndReplacement(std::string &AESL_token, std::string PortName) {
  bool no_x = false;
  bool err = false;

  no_x = false;
  // search and replace 'X' with '0' from the 3rd char of token
  while (!no_x) {
    size_t x_found = AESL_token.find('X', 0);
    if (x_found != string::npos) {
      if (!err) { 
        cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port" 
             << PortName << ", possible cause: There are uninitialized variables in the C design."
             << endl; 
        err = true;
      }
      AESL_token.replace(x_found, 1, "0");
    } else
      no_x = true;
  }
  no_x = false;
  // search and replace 'x' with '0' from the 3rd char of token
  while (!no_x) {
    size_t x_found = AESL_token.find('x', 2);
    if (x_found != string::npos) {
      if (!err) { 
        cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' on port" 
             << PortName << ", possible cause: There are uninitialized variables in the C design."
             << endl; 
        err = true;
      }
      AESL_token.replace(x_found, 1, "0");
    } else
      no_x = true;
  }
}
extern "C" void test_array_hw_stub_wrapper(volatile void *, volatile void *, volatile void *, volatile void *);

extern "C" void apatb_test_array_hw(volatile void * __xlx_apatb_param_in, volatile void * __xlx_apatb_param_out, volatile void * __xlx_apatb_param_test_val2, volatile void * __xlx_apatb_param_test_bias) {
  refine_signal_handler();
  fstream wrapc_switch_file_token;
  wrapc_switch_file_token.open(".hls_cosim_wrapc_switch.log");
  int AESL_i;
  if (wrapc_switch_file_token.good())
  {

    CodeState = ENTER_WRAPC_PC;
    static unsigned AESL_transaction_pc = 0;
    string AESL_token;
    string AESL_num;long __xlx_apatb_param_in_V_stream_buf_final_size;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(WRAPC_STREAM_SIZE_IN_in_V);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){__xlx_apatb_param_in_V_stream_buf_final_size = atoi(AESL_token.c_str());

            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  for (long i = 0; i < __xlx_apatb_param_in_V_stream_buf_final_size; ++i)((hls::stream<float>*)__xlx_apatb_param_in)->read();
long __xlx_apatb_param_out_V_stream_buf_final_size;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(WRAPC_STREAM_SIZE_OUT_out_V);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){__xlx_apatb_param_out_V_stream_buf_final_size = atoi(AESL_token.c_str());

            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_out_V);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<32> > out_V_pc_buffer;
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "out_V");
  
            // push token into output port buffer
            if (AESL_token != "") {
              out_V_pc_buffer.push_back(AESL_token.c_str());
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {for (int j = 0, e = i; j != e; ++j) {
float xlx_stream_elt;

            ((int*)&xlx_stream_elt)[0] = out_V_pc_buffer[j].to_int64();
          ((hls::stream<float>*)__xlx_apatb_param_out)->write(xlx_stream_elt);
}
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_test_val2);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<32> > test_val2_pc_buffer(1);
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "test_val2");
  
            // push token into output port buffer
            if (AESL_token != "") {
              test_val2_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {
            ((int*)__xlx_apatb_param_test_val2)[0] = test_val2_pc_buffer[0].to_int64();
          }
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_test_bias);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<32> > test_bias_pc_buffer(1);
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "test_bias");
  
            // push token into output port buffer
            if (AESL_token != "") {
              test_bias_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {
            ((int*)__xlx_apatb_param_test_bias)[0] = test_bias_pc_buffer[0].to_int64();
          }
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  
    AESL_transaction_pc++;
    return ;
  }
static unsigned AESL_transaction;
static AESL_FILE_HANDLER aesl_fh;
static INTER_TCL_FILE tcl_file(INTER_TCL);
std::vector<char> __xlx_sprintf_buffer(1024);
CodeState = ENTER_WRAPC;
//in_V
aesl_fh.touch(AUTOTB_TVIN_in_V);
aesl_fh.touch(AUTOTB_TVOUT_in_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_IN_in_V);
aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_in_V);
//out_V
aesl_fh.touch(AUTOTB_TVIN_out_V);
aesl_fh.touch(AUTOTB_TVOUT_out_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_out_V);
aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_out_V);
//test_val2
aesl_fh.touch(AUTOTB_TVIN_test_val2);
aesl_fh.touch(AUTOTB_TVOUT_test_val2);
//test_bias
aesl_fh.touch(AUTOTB_TVIN_test_bias);
aesl_fh.touch(AUTOTB_TVOUT_test_bias);
CodeState = DUMP_INPUTS;
std::vector<float> __xlx_apatb_param_in_stream_buf;
{
  while (!((hls::stream<float>*)__xlx_apatb_param_in)->empty())
    __xlx_apatb_param_in_stream_buf.push_back(((hls::stream<float>*)__xlx_apatb_param_in)->read());
  for (int i = 0; i < __xlx_apatb_param_in_stream_buf.size(); ++i)
    ((hls::stream<float>*)__xlx_apatb_param_in)->write(__xlx_apatb_param_in_stream_buf[i]);
  }
long __xlx_apatb_param_in_stream_buf_size = ((hls::stream<float>*)__xlx_apatb_param_in)->size();
std::vector<float> __xlx_apatb_param_out_stream_buf;
long __xlx_apatb_param_out_stream_buf_size = ((hls::stream<float>*)__xlx_apatb_param_out)->size();
// print test_val2 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_test_val2, __xlx_sprintf_buffer.data());
  {
    sc_bv<32> __xlx_tmp_lv = *((int*)__xlx_apatb_param_test_val2);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_test_val2, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.test_val2_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_test_val2, __xlx_sprintf_buffer.data());
}
// print test_bias Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_test_bias, __xlx_sprintf_buffer.data());
  {
    sc_bv<32> __xlx_tmp_lv = *((int*)__xlx_apatb_param_test_bias);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_test_bias, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.test_bias_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_test_bias, __xlx_sprintf_buffer.data());
}
CodeState = CALL_C_DUT;
test_array_hw_stub_wrapper(__xlx_apatb_param_in, __xlx_apatb_param_out, __xlx_apatb_param_test_val2, __xlx_apatb_param_test_bias);
CodeState = DUMP_OUTPUTS;
long __xlx_apatb_param_in_stream_buf_final_size = __xlx_apatb_param_in_stream_buf_size - ((hls::stream<float>*)__xlx_apatb_param_in)->size();
// print in_V Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_in_V, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_in_stream_buf_final_size; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv_hw;
sc_bv<32> __xlx_tmp_lv;
__xlx_tmp_lv = ((int*)&__xlx_apatb_param_in_stream_buf[j])[0];
__xlx_tmp_lv_hw = __xlx_tmp_lv;

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv_hw.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_in_V, __xlx_sprintf_buffer.data()); 
  }

  tcl_file.set_num(__xlx_apatb_param_in_stream_buf_final_size, &tcl_file.in_V_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_in_V, __xlx_sprintf_buffer.data());
}

// dump stream ingress status to file
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_in_V, __xlx_sprintf_buffer.data());
  if (__xlx_apatb_param_in_stream_buf_final_size > 0) {
  long in_V_stream_ingress_size = __xlx_apatb_param_in_stream_buf_size;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", in_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_in_V, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_in_stream_buf_final_size; j != e; j++) {
    in_V_stream_ingress_size--;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", in_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_in_V, __xlx_sprintf_buffer.data());
  }
} else {
  long in_V_stream_ingress_size = 0;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", in_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_in_V, __xlx_sprintf_buffer.data());
}

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_in_V, __xlx_sprintf_buffer.data());
}{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_in_V, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_in_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_IN_in_V, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_in_V, __xlx_sprintf_buffer.data());
}long __xlx_apatb_param_out_stream_buf_final_size = ((hls::stream<float>*)__xlx_apatb_param_out)->size() - __xlx_apatb_param_out_stream_buf_size;
{
  while (!((hls::stream<float>*)__xlx_apatb_param_out)->empty())
    __xlx_apatb_param_out_stream_buf.push_back(((hls::stream<float>*)__xlx_apatb_param_out)->read());
  for (int i = 0; i < __xlx_apatb_param_out_stream_buf.size(); ++i)
    ((hls::stream<float>*)__xlx_apatb_param_out)->write(__xlx_apatb_param_out_stream_buf[i]);
  }
// print out_V Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_out_V, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_out_stream_buf_final_size; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)&__xlx_apatb_param_out_stream_buf[__xlx_apatb_param_out_stream_buf_size+j])[0];

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVOUT_out_V, __xlx_sprintf_buffer.data()); 
  }

  tcl_file.set_num(__xlx_apatb_param_out_stream_buf_final_size, &tcl_file.out_V_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_out_V, __xlx_sprintf_buffer.data());
}
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_out_V, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_out_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_OUT_out_V, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_out_V, __xlx_sprintf_buffer.data());
}// print test_val2 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_test_val2, __xlx_sprintf_buffer.data());
  {
    sc_bv<32> __xlx_tmp_lv = *((int*)__xlx_apatb_param_test_val2);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVOUT_test_val2, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.test_val2_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_test_val2, __xlx_sprintf_buffer.data());
}
// print test_bias Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_test_bias, __xlx_sprintf_buffer.data());
  {
    sc_bv<32> __xlx_tmp_lv = *((int*)__xlx_apatb_param_test_bias);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVOUT_test_bias, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.test_bias_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_test_bias, __xlx_sprintf_buffer.data());
}
CodeState = DELETE_CHAR_BUFFERS;
AESL_transaction++;
tcl_file.set_num(AESL_transaction , &tcl_file.trans_num);
}
