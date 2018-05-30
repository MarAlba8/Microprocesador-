#ifndef INSTRMEMORY_H
#define INSTRMEMORY_H
#include <systemc.h>
#include <fstream>

/*
En este modulo vamos a modelar una memoria de instrucciones, utlizando archivos .txt
El archivo se llama memoryFile.txt , y contiene las instrucciones que ejecutara nuestro procesador
El formato de instrucciones escogido es de 6 bits, por lo tanto esa sera la longitud de las lineas
del archivo
*/
using namespace std;
#define instruction_length 6 //Aca definimos como CONSTANTE la longitud de nuestro formato de instruccion
                             //Notar que si quiero cambiar la longitud del formato de instruccion, solo debo cambiar
                             //el numero en esta constante, y por supuesto hacer los arreglos pertinentes en el
                             //archivo .txt

class InstrMemory: public sc_module{

	public:
		sc_in< sc_uint<4> > dir_in; //Esta entrada dir_in representa la direccion que viene del PC,
		                            //es decir, la direccion de la SIGUIENTE instruccion a leer
		                            //En este caso es de 4 bits, lo que quiere decir que podemos tener
		                            //hasta 16 intruciones en nuestra memoria de instrucciones (contando de 0 a 15)
		                            //El .txt tiene 20 lineas, sin embargo, solo podremos leer las primeras 16 lineas del mismo
		                            //dado que dir_in es de 4 bits
		sc_out< sc_uint<instruction_length> >instr_out; //La salida de nuestro modulo es la instruccion escogida por el PC (dir_in),
		                                                //desde nuestra memoria de instrucciones (archivo .txt)
		
		SC_CTOR(InstrMemory){

			SC_METHOD(search); //Este metodo es para buscar la instruccion en la memoria de instrucciones segun la direccion indicada por dir_in
			sensitive << dir_in;
		
			memoryFile.open("../InstructionMemory.txt"); 
			//Aca se abre el archivo que contiene las instrucciones, y se coloca la direccion correspondiente a la ubicacion del mismo
}
		~InstrMemory()
		{
			memoryFile.close();
		}

	private:
    ifstream memoryFile; //Declaro el archivo correspondiente a nuestra memoria de instrucciones

    void search()
    {
      unsigned int dir;	//Entero para la direccion que llega por dir_in
      sc_uint<instruction_length> instr; //Instruccion leida y "convertida" (leer mas adelante)
      char instrTmp[instruction_length]; //Instruccion temporal para leer desde el archivo

      dir = dir_in.read(); //en la variable dir almaceno la direccion que llega por dir_in

      memoryFile.seekg(dir*(instruction_length+1), ios::beg);//Segun la direccion que me llego por dir_in, que se almaceno en dir,
                                                             //me posiciono en el archivo para leer la instruccion que corresponde
                                                             
      memoryFile.getline(instrTmp,instruction_length+1);//Aca leo la instruccion, notese que se lee como CARACTERES
      
      for(int i=0; i < instruction_length;i++)
      /*
      Debido a que leimos la instruccion como caracteres en instrTmp, necesitamos este for para transformar esos
      caracteres a valores que podamos manejar, en este caso a sc_uint; y lo que hacemos es una comparacion simple:
      si el caracter es 1, entonces almacena un 1 del tipo sc_uint en la posicion correspondiente, contrario, se almacena
      un 0 en esa posicion.
      */
      {
        if (instrTmp[i] == '1')
        {
          instr[instruction_length-1-i] = 1;
        } 
        else
        {
          instr[instruction_length-1-i] = 0;
        }
      }
      //Al terminar el for, ya tenemos nuestro vector de sc_uint que corresponde a la instruccion
      //leida desde el archivo, asi que simplemente por el puerto de salida instr_out escribimos
      //esa direccion que es "instr".
      instr_out.write(instr);
    }

};
#endif
