#include<DataMemory.h>
#include<testbench.h>

int sc_main(int argc,char *argv[]){
	sc_time DELAY(10,SC_NS);
	sc_time PERIOD(10,SC_NS);
	
	sc_clock clk("clock",PERIOD,0.5,DELAY,true);
	sc_signal< sc_uint<4> > dir;
	sc_signal< sc_int<32> > data;
	sc_signal< sc_int<32> > d_out;
	sc_signal< bool > enable;
	DataMemory memory("DataMemory");
	testbench test("test");

	memory.data_in(data);
	memory.write_enable_in(enable);
	memory.dir_in(dir);
	memory.data_out(d_out);
	memory.clk(clk);
	
	test.data_out(data);
	test.write_enable_out(enable);
	test.dir_out(dir);
	test.data_in(d_out);
	test.clk(clk);
	

	sc_start();
	
return 0;
}
