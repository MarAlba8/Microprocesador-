#ifndef regs8_H
#define regs8_H

#include <systemc.h>
#include <iostream>

/*
El modulo regs8 es un modulo que simula un registro que puede
almacenar datos de hasta 8 bits de tamaño, en este caso datos del tipo
sc_unit<8>
El modulo tiene su reloj para sincronia, un enable que es el que dice si se puede o no
escribir el data_in en el registro; tiene una variable llamada "data", que correspondiente a la
data actual que se almacena en el registro. Tiene su data_in de entrada, y su data_out de salida

*/
class regs8 : public sc_module{
	public:
		sc_in < bool > clk_in;//, enable_in; //El clock, necesario para sincronizar en cual flanco (pos o neg) entran/salen los datos
		//y ademas el ENABLE que es la señal que me indica si puedo o no escribir en los registros
		sc_in < sc_uint<8> > data_in; //la data que entra al modulo, del TIPO SC_UNIT<8>, que es nos permite almacenar numeros de hasta 8 bits
		sc_out < sc_uint<8> > data_out; //la data que sale del modulo, del TIPO SC_UNIT<8>, que es nos permite almacenar numeros de hasta 8 bits

		sc_uint<8> data; //la que ESTA en el modulo actualmente, es decir, la que saldra por data_out
		                  //NO NECESARIAMENTE es lo que entra por data_in, porque si el enable es 0
		                  //lo que entre por data_in NO se almacenara en el registro
		                  // y por lo tanto el registro mantendra su data actual
		
		SC_CTOR(regs8){
			data = 0; //Incializo la data acutal en 0
		
			SC_METHOD(reading_data) //Metodo en el cual LEERE LA DATA que entra por data_in, y si el enable es 1/true
			                        //la almacenare en "data"
			sensitive << clk_in.neg() ;
		
			SC_METHOD(writing_data) //Metodo en el cual se escribe la "data" actual que haya en el registro
			                        //por el puerto de salida data_out
			sensitive << clk_in.pos();
		
		}
	private:
void reading_data(){
		//if (enable_in.read() == true)		//SOLO SI ENABLE ES 1/True, escribo lo que hay en "data" lo que entra por data_in
		                                //de lo contrario, "data" mantendra su valor actual
		//{
		  data = data_in.read();
		//}
	}
		
void writing_data(){
		  data_out.write(data);
		}
};

#endif
