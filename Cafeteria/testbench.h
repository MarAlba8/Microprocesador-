#ifndef testbench_H
#define testbench_H

#include <systemc.h>
#include <iostream>


class testbench: public sc_module{

	public:
  sc_in_clk clk;
  //sc_out<bool > enable_out, write_enable_out;
  sc_out<sc_uint<4> > pc_out;
  sc_in<sc_int<32> > r_in;
  
	SC_CTOR(testbench){
		SC_THREAD(test);
			sensitive<<clk.neg();
			dont_initialize();
}
	private:
		void test();
		void print();
};

#endif
