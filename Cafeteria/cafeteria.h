#ifndef cafeteria_H_
#define cafeteria_H_

#include <systemc.h>
#include "../regs2.h"
#include "../regs4.h"
#include "../regs6.h"
#include "../regs6.h"
#include "../regs16.h"
#include "../regs32.h"
#include "../registerfile/registerfile.h"
#include "../alu/alu.h"
#include "../instruction_memory/InstrMemory.h"
#include "../data_memory/DataMemory.h"

class cafeteria : public sc_module{

public:

  sc_in_clk clk_in; 

  sc_in<sc_uint<4> > pc_in; 
  sc_out<sc_int<32> > r_out;

      SC_CTOR(cafeteria){

            SC_METHOD(split)  
            sensitive << reg6_1_sg ; 

            alu1 = new alu("alu1");
            alu2 = new alu("alu2");
            registerfile1 = new registerfile("registerfile1");
            reg2_1 = new regs2("reg2_1");
            reg2_2 = new regs2("reg2_2");
            reg6_1 = new regs6("reg6_1");
            reg32_1 = new regs32("reg32_1");
            reg32_2 = new regs32("reg32_2");
            reg32_3 = new regs32("reg32_3");
            memory = new InstrMemory("memory");
            data_memory1 = new DataMemory("data_memory1"); 

            //----------------------------------------------------------------------------------------------------------------------------
            //ETAPA FETCH
            //----------------------------------------------------------------------------------------------------------------------------    
            memory->dir_in(pc_in);
            memory->instr_out(instr_sg);
            //----------------------------------------------------------------------------------------------------------------------------      
            reg6_1 -> data_in (instr_sg);
            reg6_1 -> clk_in (clk_in);
            reg6_1 -> data_out (reg6_1_sg);	

            //----------------------------------------------------------------------------------------------------------------------------
            //ETAPA DECODE
            //---------------------------------------------------------------------------------------------------------------------------- 
            registerfile1 -> dira_in(dira);
            registerfile1 -> dirb_in(dirb);
            registerfile1 -> ra_out(da);
            registerfile1 -> rb_out(db);
            registerfile1 -> clk(clk_in);
            //----------------------------------------------------------------------------------------------------------------------------

            //Voy al 2do PIPE y almaceno los datos pertinentes en los registros adecuados para ello
            reg32_1 -> data_in (da);
            reg32_1 -> clk_in (clk_in);
            reg32_1 -> data_out (reg32_1_sg);

            reg32_2 -> data_in (db);
            reg32_2 -> clk_in (clk_in);
            reg32_2 -> data_out (reg32_2_sg);

            reg2_1 -> data_in (dirc);
            reg2_1 -> clk_in (clk_in);
            reg2_1 -> data_out (reg2_1_sg); 

            reg2_2 -> data_in (op);
            reg2_2 -> clk_in (clk_in);
            reg2_2 -> data_out (reg2_2_sg);		

            //----------------------------------------------------------------------------------------------------------------------------
            //ETAPA EXECUTE
            //----------------------------------------------------------------------------------------------------------------------------
            //Ejecuta la instruccion en la alu con los operando a y b, segun la operacion OP
            alu1 -> ra_in (reg32_1_sg);
            alu1 -> rb_in (reg32_2_sg);
            alu1 -> op_in (reg2_2_sg);
            alu1 -> r_out (r_out);

            alu2 -> ra_in (reg32_1_sg);
            alu2 -> rb_in (reg32_2_sg);
            alu2 -> op_in (reg2_2_sg);
            alu2 -> r_out (alu_sg);

            //----------------------------------------------------------------------------------------------------------------------------
            //ETAPA ACCESs MEMORY 
            //----------------------------------------------------------------------------------------------------------------------------

            reg32_3 -> data_in (alu_sg);
            reg32_3 -> clk_in (clk_in);
            reg32_3 -> data_out (r_sg);

            data_memory1 -> clk(clk_in);
            data_memory1 -> dir_in(reg2_1_sg);
            data_memory1 -> data_in(r_sg);
            data_memory1 -> data_out(gnd);       //----------------------------------------------------------------------------------------------------------------------------
      }

private:
      //Declaro los modulos que utilizare
      alu *alu1, *alu2;
      registerfile *registerfile1;
      InstrMemory *memory;
      regs2 *reg2_1, *reg2_2;
      regs6 *reg6_1;
      regs32 *reg32_1, *reg32_2, *reg32_3;
      DataMemory *data_memory1;

      //Y las señales tambien, siendo coherente con el tipo de datos que ellas transportaran
      sc_signal<sc_uint<2> > dira, dirb, dirc, op, reg2_1_sg, reg2_2_sg, rc_sg; //dira, dirb y op son las señales que almecenaran la instruccion "picada"
      sc_signal<sc_uint<6> > reg6_1_sg, instr_sg;
      sc_signal<sc_int<32> > da, db, dc, reg32_1_sg, reg32_2_sg, alu_sg, gnd, r_sg;



void split(){
      op = (reg6_1_sg.read().range(5,4));
      dira = (reg6_1_sg.read().range(3,2));
      dirb = (reg6_1_sg.read().range(1,0));

	}


};

#endif