#ifndef testbench_H
#define testbench_H

#include <systemc.h>
#include <iostream>


class testbench: public sc_module{

	public:
    sc_in_clk clk;

   // sc_out<bool> write_enable_out;
    //sc_out<sc_uint<2> > dirdata_out;

    sc_out<sc_uint<2> > dira_out;
    sc_out<sc_uint<2> > dirb_out;
  //  sc_out<sc_uint<2> > dirc_out;

    //sc_out<sc_int<32> > data_out;

    sc_in<sc_int<32> > ra_in;
    sc_in<sc_int<32> > rb_in;
  //  sc_in<sc_int<32> > rc_in;
	
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
