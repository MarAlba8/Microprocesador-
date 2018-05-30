#ifndef registerfile_H_
#define registerfile_H_
//Lo siguiente un modelo de archivo de registro de lectura y escritura modelado en systemC
#include <systemc.h>
#define TAM_REG 4

class registerfile : public sc_module{ //El nombre de la clase, archivo de registro

public:

  sc_in_clk clk;

  //sc_in<bool> write_enable_in; 
 // sc_in<sc_uint<2> > dirdata_in; //Es la direccion del registro en el cual quiero escribir

  sc_in<sc_uint<2> > dira_in; 
  sc_in<sc_uint<2> > dirb_in;
 //ss sc_in<sc_int<32> > data_in;

  sc_out<sc_int<32> > ra_out;
  sc_out<sc_int<32> > rb_out;
  //sc_out<sc_uint<2> > r

	//Constructor
	SC_CTOR(registerfile)
	{

	  SC_METHOD(read);
      sensitive << clk.neg();

    for (int i=1;i<TAM_REG;i++)
    {
	    registers[i]=i; 
    }

  }
    
    
private:
  sc_int<32> registers[TAM_REG]; /*Esta es la parte del archivo de registro donde van los registros;
  por lo tanto, es un vector de TAM_REG, donde cada posicion almacena 16 bits en este caso.*/

void read()
  {
   //if(write_enable_in == false)
     // {
	    ra_out.write(registers[ dira_in.read() ] );

	    rb_out.write(registers[ dirb_in.read() ] );
	  //}

    //rc_out.write(dirdata_in);
  } 


/*
void write(){
  En escritura SIEMPRE estaran presentandose datos a las entradas de alguna direccion
  del archivo de registro, sin embargo, ese dato SOLO pasara cuando el write_enable_in es 1.
  Cuando es eso? Cuando la logica del programa lo requiera, o cuando segun los resultados de una operacion
  se requiere escribir en el archivo de registro de envia en 1 el write_enable_in por un periodo del clock
  para escribir el dato, y luego se vuelve a colocar en cero (esto deberia hacerloy decidirlo automaticamente el CPU)
  if(write_enable_in == true)
  {
	  registers[dirdata_in.read()] = data_in.read(); //Escribo en la direccion correspondiente a "dirdata_in"
	                                                 //en el registro el dato que llega por "data_in"
	}
	//registers[0]=0; //Esta linea no es necesaria, pero a veces como el 0 es un valor muy utilizado
	//se mantiene la direccion 0 del registro con el valor 0
}*/

}; //Esto es un punto y coma seguido de una llave xD

#endif
