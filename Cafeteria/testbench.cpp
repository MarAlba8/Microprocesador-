#include"testbench.h"

void testbench::test(){
	//std::cout<< "\n" <<endl<<"\t\tX\tY\tSEL\tR"<<endl;
	std::cout<<"\t\t_______________________________________________________"<<endl<<endl;
 	std::cout << "\t\t" << "\tClock" << "\t|| " << "\tNúmero pedido" << "\t || " << "Monto a pagar" << "\n";

	for (int i = 0; i < 20; i++)
	{
	  pc_out.write(i);

	  wait();

	  //if(i>3)
	  	print();
	}

	sc_stop();
}



void testbench::print(){
	std::cout << "\t\t" << sc_time_stamp() << "\t\t|| \t" << (pc_out.read()) << "\t\t || " << r_in.read() << "\n";

 // std::cout << "\t\t" << sc_time_stamp() <<"\t\t || " << pc_out.read() 
	//<< " \t\t " << r_in.read() << "\n";

	std::cout<<"\t\t_______________________________________________________"<<"\n";
}
