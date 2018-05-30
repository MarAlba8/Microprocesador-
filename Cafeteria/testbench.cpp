#include"testbench.h"

void testbench::test(){
	//std::cout<< "\n" <<endl<<"\t\tX\tY\tSEL\tR"<<endl;
	std::cout<<"\t\t_______________________________________________________"<<endl<<endl;
  std::cout << "\t\t" << "CLOCK" << "|||" << "W_EN" << "\t | " << "EN" << "\t\t || " << "PC_IN" << " \t" << "RSALIDA" << "\n";

	
	for (int i = 0; i < 20; i++)
	{
	  pc_out.write(i);
	  if (i%2 == 0)
	  {
	   // write_enable_out.write(0); //RECORDAD QUE ESTE ENABLE ES PARA ESCRIBIR EN EL ARCHIVO DE REGISTROS, y que lo controlamos
	                            //de manera "manual", porque, al no tener el pipeline completo, no tenemos el diseño logico
	                            //necesario para que esta señal se automatice
	  }
	  else
	  {
	    //write_enable_out.write(1);
	  }
	  //enable_out.write(1);//Este es el enable de los registros del PIPE, y lo envio siempre en 1, pues los registros del pipe
	                    //siempre estan almacenandose y vaciandose; sin embargo, tambien deberia ser automatico, es decir, el CPU
	                    //deberia tener la capacidad de saber cuando lo enviara en 0 y cuando en 1
	  wait();
	  print();
	}


	sc_stop();
}



void testbench::print(){
  std::cout << "\t\t" << sc_time_stamp() << /*"|||" << write_enable_out.read() << "\t | " << enable_out.read() <<*/ "\t\t || " << pc_out.read() << " \t\t " << r_in.read() << "\n";
  //RECUERDEN LA OTRA MANERA DE IMPRIMIR LOS DATOS (PARA VERLOS COMO NUMEROS BINARIOS)
	std::cout<<"\t\t_______________________________________________________"<<"\n";
}
