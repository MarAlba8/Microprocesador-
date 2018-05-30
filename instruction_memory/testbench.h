#ifndef testbench_H
#define testbench_H

#include <systemc.h>
#include <iostream>


class testbench: public sc_module{

	public:
    sc_in_clk clk;
		sc_in< sc_uint<8> >instr_in;

		sc_out< sc_uint<4> > dir_out;

	
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
