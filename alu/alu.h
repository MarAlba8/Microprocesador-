#ifndef alu_H_
#define alu_H_

#include <systemc.h>
//Modelo en systemC de una ALU que ejecuta 4 operaciones
//pues solo posee 2 bits de OP (operacion)
#define precio0 50
#define precio1 300
#define precio2 200
#define precio3 100

class alu : public sc_module{

public:
  sc_in<sc_uint<2> > op_in; //Dos bits que me indican la operacion que realizare

 //registro a
  sc_in<sc_int<32> > ra_in;

 //registro b
  sc_in<sc_int<32> > rb_in;
  //sc_in<sc_int<16> > rc_in;
 //a y b son los operandos sobre los cuales se haran las operaciones
  
  sc_out<sc_int<32> > r_out; //Registro de salida que posee el resutado de la operacion realizada
                              //segun OP

	//Constructor
	SC_CTOR(alu){

	  SC_METHOD(operation);	//Metodo para realizar las operaciones correspondientes de la ALU
	  //Sensible a las direcciones(dir_a,dir_b) y al indicador de la operacion OP
	  sensitive << ra_in << rb_in << op_in;// rc_in << op_in;

}
private:


void operation(){
  switch(op_in.read()){//Segun el valor de OP en este caso, sumo, comparo, hago or, o and
                       //Existen muchas operaciones posibles en esta etapa
                       //Se escribe por el puerto de salida r_out el valor correspondiente a la operacion
  case 0:
  {
    if (ra_in.read() == 0)
    {
      r_out.write(rb_in.read()* precio0);

    }else if(ra_in.read() == 1){

      r_out.write(rb_in.read()* precio1);

    }else if (ra_in.read() == 2){

      r_out.write(rb_in.read()* precio2);

    }else{

      r_out.write(rb_in.read()* precio3);
    }
  }
  break;



  case 1:
  {
    if(ra_in.read() == 1)
      {
        //Precio 1$
         r_out.write(rb_in.read()-1);
      }


     if(ra_in.read() == 2)
      {
        //Precio 2$
         r_out.write(rb_in.read()-2);
      }

    if(ra_in.read() == 3)
      {
        //Precio 3$
         r_out.write(rb_in.read()-3);
      }

     if(ra_in.read() == 1)
      {
        //Precio 1$
         r_out.write(rb_in.read()-1);
      }


  }

  break;
} 
}
};

#endif
