#include"testbench.h"

void testbench::test(){
	//std::cout<< "\n" <<endl<<"\t\tX\tY\tSEL\tR"<<endl;
	std::cout<<"\t\t___________________________________________________"<<endl<<endl;
	std::cout << "\t" << "CLOCK" << " || " << "dir_out" << " | " << "instr_in" << endl;;
	
	for (int i = 0; i < 20; i++)
	{
	  dir_out.write(i);

	  wait();
	  print();
	}

	
	sc_stop();
}



void testbench::print(){
  std::cout << "\t" << sc_time_stamp() << " || " << dir_out.read() << " \t | " << instr_in.read().to_string(SC_BIN).substr(3) << endl;
  //RECUERDEN LA OTRA MANERA DE IMPRIMIR LOS DATOS (PARA VERLOS COMO NUMEROS BINARIOS)
	std::cout<<"\t\t___________________________________________________"<<"\n";
}
