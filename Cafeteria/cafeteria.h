#ifndef cafeteria_H_
#define cafeteria_H_

#include <systemc.h>
#include "../regs2.h"
#include "../regs4.h"
#include "../regs6.h"
#include "../regs8.h"
#include "../regs32.h"
#include "../registerfile/registerfile.h"
#include "../alu/alu.h"
#include "../instruction_memory/InstrMemory.h"

class cafeteria : public sc_module{

public:

  sc_in_clk clk_in; 

  sc_in<sc_uint<4> > pc_in; 
  sc_out<sc_int<32> > r_out;

      SC_CTOR(cafeteria){

        SC_METHOD(split)  
        sensitive << reg6_1_sg ; 

        alu1 = new alu("alu1");
        registerfile1 = new registerfile("registerfile1");
        reg2_1 = new regs2("reg2_1");
        reg6_1 = new regs6("reg6_1");
        reg32_1 = new regs32("reg32_1");
        reg32_2 = new regs32("reg32_2");
        reg32_3 = new regs32("reg32_3");
        memory = new InstrMemory("memory");

        //----------------------------------------------------------------------------------------------------------------------------
        //ETAPA FETCH
        //----------------------------------------------------------------------------------------------------------------------------    
        memory->dir_in(pc_in);
        memory->instr_out(instr_sg);

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

        reg32_1 -> data_in (da);
        reg32_1 -> clk_in (clk_in);
        reg32_1 -> data_out (reg32_1_sg);

        reg32_2 -> data_in (db);
        reg32_2 -> clk_in (clk_in);
        reg32_2 -> data_out (reg32_2_sg);

        reg2_1 -> data_in (op);
        reg2_1 -> clk_in (clk_in);
        reg2_1 -> data_out (reg2_1_sg);		

        //----------------------------------------------------------------------------------------------------------------------------
        //ETAPA EXECUTE
        //----------------------------------------------------------------------------------------------------------------------------

        alu1 -> ra_in (reg32_1_sg);
        alu1 -> rb_in (reg32_2_sg);
        alu1 -> op_in (reg2_1_sg);
        alu1 -> r_out (alu1_sg);

        reg32_3 -> data_in (alu1_sg);
        reg32_3 -> clk_in (clk_in);
        reg32_3 -> data_out (r_out);   
      }

private:
      alu *alu1;
      registerfile *registerfile1;
      InstrMemory *memory;
      regs2 *reg2_1;
      regs6 *reg6_1;
      regs32 *reg32_1, *reg32_2, *reg32_3;

      sc_signal<sc_uint<2> > dira, dirb, op, reg2_1_sg; //dira, dirb y op son las señales que almecenaran la instruccion "picada"
      sc_signal<sc_uint<6> > reg6_1_sg, instr_sg;
      sc_signal<sc_int<32> > da, db, reg32_1_sg, reg32_2_sg, alu1_sg;



void split(){
      op = (reg6_1_sg.read().range(5,4));
      dira = (reg6_1_sg.read().range(3,2));
      dirb = (reg6_1_sg.read().range(1,0));

	}


};

#endif
