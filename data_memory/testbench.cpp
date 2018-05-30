#include"testbench.h"

void testbench::test(){
	//std::cout<< "\n" <<endl<<"\t\tX\tY\tSEL\tR"<<endl;
	std::cout<<"\t\t___________________________________________________"<<endl<<endl;
	std::cout << "\t" << "CLOCK" <<  " | " << "DATA_OUT" << " || " << " | " << "dir_out" << " || " << "data_IN" << "\n\n\n";
 
  //RECUERDEN QUE CUANDO EL ENABLE ES 0, NO habra escritura en el registro, y cuando es 1 SI habra escritura
 //Envio 1 por write_enable_out, lo que quiere decir que el valor de data_out
	        

	for(int i=0; i<10; i++)
	{	                           //va a escribir en la posicion dirdata_out del archivo de registro
		data_out.write(i);
  		dir_out.write(i); //Y su vez tambien pido los valores de los registros en la direccion a y b
  	
  		wait();
		print();

  	}

	data_out.write(3);
  	dir_out.write(4); //Y su vez tambien pido los valores de los registros en la direccion a y b
  	
  		wait();
		print();

	data_out.write(3);
   //Y su vez tambien pido los valores de los registros en la direccion a y b
  	
  		wait();
		print();


	

	data_out.write(3);
  	 //Y su vez tambien pido los valores de los registros en la direccion a y b
  	
  		wait();
		print();

	sc_stop();
}



void testbench::print(){
  std::cout << "\t\t" << sc_time_stamp() << " || " << data_out.read() <<  "\t | " << dir_out.read() << "  | " << data_in.read() << "\n";
  //RECUERDEN LA OTRA MANERA DE IMPRIMIR LOS DATOS (PARA VERLOS COMO NUMEROS BINARIOS)
	std::cout<<"\t\t___________________________________________________"<<"\n";
}
