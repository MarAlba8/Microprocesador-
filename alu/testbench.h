#ifndef testbench_H
#define testbench_H

#include <systemc.h>
#include <iostream>


class testbench: public sc_module{

	public:
	sc_in_clk clk;
	 
  sc_out<sc_uint<2> > op_out;


  sc_out<sc_int<32> > ra_out;
  sc_out<sc_int<32> > rb_out;
  //sc_out<sc_uint<32> > rc_out;
  
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
