#include<registerfile.h>
#include<testbench.h>

int sc_main(int argc,char *argv[]){
	sc_time DELAY(10,SC_NS);
	sc_time PERIOD(10,SC_NS);
	
	sc_clock clk("clock",PERIOD,0.5,DELAY,true);
	sc_signal< sc_uint<2> > dird, dira, dirb, dirc;
	sc_signal< sc_int<32> > da, db, dc, din;
	//sc_signal< bool > enable;
	registerfile registerfile("registerfile");
	testbench test("test");

	//registerfile.write_enable_in(enable);
	//registerfile.dirdata_in(dird);
	registerfile.dira_in(dira);
	registerfile.dirb_in(dirb);
	//registerfile.dirc_in(dirc);
	//registerfile.data_in(din);
	registerfile.ra_out(da);
	registerfile.rb_out(db);
	//registerfile.rc_out(dc);
	registerfile.clk(clk);
	
	
	//test.write_enable_out(enable);
	//test.dirdata_out(dird);
	test.dira_out(dira);
	test.dirb_out(dirb);
	//test.dirc_out(dirc);
	//test.data_out(din);
	test.ra_in(da);
	test.rb_in(db);
	//test.rc_in(dc);
	test.clk(clk);
	

	sc_start();
	
return 0;
}
