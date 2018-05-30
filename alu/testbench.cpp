#include"testbench.h"

void testbench::test(){
	//std::cout<< "\n" <<endl<<"\t\tX\tY\tSEL\tR"<<endl;
	std::cout<<"\t__________________________________________"<<endl<<endl;
  std::cout << "\t" << "CLOCK" << "|||" << "Op" << "\t | " << "Ra" << " | " << "Rb" << " | " << "Rin" << "\n";;

  //RECUERDEN QUE CUANDO EL ENABLE ES 0, NO habra escritura en el registro, y cuando es 1 SI habra escritura
	op_out.write(0); //Asigna
	ra_out.write(1);
	rb_out.write(3);
	//


	wait();
	print();

	op_out.write(0); //Asigna
	ra_out.write(2);
	rb_out.write(3);
	//


	wait();
	print();
		

	
	sc_stop();
}



void testbench::print(){
  std::cout << "\t" << sc_time_stamp() << "|||" << op_out.read() << "\t | " << ra_out.read() << "  | " << rb_out.read() << " | " << r_in.read() << "\n";
  //RECUERDEN LA OTRA MANERA DE IMPRIMIR LOS DATOS (PARA VERLOS COMO NUMEROS BINARIOS)
	std::cout<<"\t__________________________________________"<<"\n";
}
