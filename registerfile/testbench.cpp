#include"testbench.h"

void testbench::test(){
	//std::cout<< "\n" <<endl<<"\t\tX\tY\tSEL\tR"<<endl;
	std::cout<<"\t\t___________________________________________________"<<endl<<endl;
	std::cout << "\t" << "CLOCK" << " || " << "W_EN (Write enable)" << " | " << "DIR_D (Direccion para escribir)" << " || " << "DOUT (Dato a escribir)" << " | " << "DA (Direccion A a leer)" << " | " << "DB (Direccion B a leer) |" << "RA (Valor leido en direccion A)|" << "RB (Valor leido en direccion B)|" "\n\n\n";
  std::cout << "\t\t" << "CLOCK" << " || " << "W_EN" << "\t | " << "DIR_D" << " || " << "DOUT" << " | " << "DA" << " | " << "DB |" << "RA |" << "RB |" "\n";
	
	
  //RECUERDEN QUE CUANDO EL ENABLE ES 0, NO habra escritura en el registro, y cuando es 1 SI habra escritura
	//write_enable_out.write(0); //Envio 1 por write_enable_out, lo que quiere decir que el valor de data_out
	//                           //va a escribir en la posicion dirdata_out del archivo de registro
	//dirdata_out.write(3);
	//data_out.write(20);
  dira_out.write(0); //Y su vez tambien pido los valores de los registros en la direccion a y b
  dirb_out.write(1);

	wait();
	print();
	
	//write_enable_out.write(1);
	//dirdata_out.write(1);
	//data_out.write(20);
  dira_out.write(0);
  dirb_out.write(1);

	wait();
	print();
	
	//write_enable_out.write(0);
	//dirdata_out.write(3);
	//data_out.write(10);
  dira_out.write(2);
  dirb_out.write(3);

	wait();
	print();

	//write_enable_out.write(0);
	//dirdata_out.write(3);
	//data_out.write(10);
  dira_out.write(2);
  dirb_out.write(3);

	wait();
	print();

	//write_enable_out.write(0); //Envio 1 por write_enable_out, lo que quiere decir que el valor de data_out
	//                           //va a escribir en la posicion dirdata_out del archivo de registro
	//dirdata_out.write(3);
	//data_out.write(20);
  dira_out.write(0); //Y su vez tambien pido los valores de los registros en la direccion a y b
  dirb_out.write(1);

  	wait();
	print();

	//write_enable_out.write(0);
	//dirdata_out.write(3);
	//data_out.write(10);
  dira_out.write(2);
  dirb_out.write(3);

	wait();
	print();
	
	sc_stop();
}



void testbench::print(){
  std::cout << "\t\t" << sc_time_stamp() << " || "  << dira_out.read() << "  | " << dirb_out.read() << "  | " << ra_in.read() << " | " << rb_in.read() << "\n";
  //RECUERDEN LA OTRA MANERA DE IMPRIMIR LOS DATOS (PARA VERLOS COMO NUMEROS BINARIOS)
	std::cout<<"\t\t___________________________________________________"<<"\n";
}
