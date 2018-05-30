#include <cafeteria.h>
#include <testbench.h>

int sc_main(int argc,char *argv[]){
	sc_time DELAY(10,SC_NS);
	sc_time PERIOD(10,SC_NS);
	
	sc_clock clk("clock",PERIOD,0.5,DELAY,true);
	sc_signal< sc_uint<4> > i1;
	sc_signal< sc_int<32> > r;
	sc_signal< bool > enable, e2;
	cafeteria cafeteria("cafeteria");
	testbench test("test");

	//cafeteria.write_enable_in(enable);
	cafeteria.pc_in(i1);
	//cafeteria.enable_in(e2);
	cafeteria.r_out(r);
	cafeteria.clk_in(clk);
	
	
	//test.write_enable_out(enable);
	test.pc_out(i1);
	//test.enable_out(e2);
	test.r_in(r);
	test.clk(clk);
	

	sc_start();
	
return 0;
}
