#include <alu.h>
#include <testbench.h>

int sc_main(int argc,char *argv[]){
	sc_time DELAY(10,SC_NS);
	sc_time PERIOD(10,SC_NS);
	
	sc_clock clk("clock",PERIOD,0.5,DELAY,true);
	sc_signal< sc_uint<2> > op;
	sc_signal< sc_int<32> > da, db, dc, r;
	sc_signal< bool > enable;
	alu alu("alu");
	testbench test("test");

	alu.op_in(op);
	alu.ra_in(da);
	alu.rb_in(db);
	//alu.rc_in(dc);
	alu.r_out(r);

	test.op_out(op);
	test.ra_out(da);
	test.rb_out(db);
	//test.rc_out(dc);
	test.r_in(r);

	test.clk(clk);
	

	sc_start();
	
return 0;
}
