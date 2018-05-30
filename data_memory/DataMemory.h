#ifndef DATAMEMORY_H
#define DATAMEMORY_H
#include <systemc.h>
#include <fstream>

using namespace std;
#define data_length 32 

class DataMemory: public sc_module{

	public:
		 sc_in_clk clk; 
		 sc_in< sc_int<data_length> > data_in; 
		 //sc_in<bool> write_enable_in;
		 sc_in< sc_uint<2> > dir_in;
		 sc_out< sc_int<data_length> > data_out;                                    

		SC_CTOR(DataMemory){

			SC_METHOD(write); 
				sensitive << clk.pos();
		
			SC_METHOD(read); 
				sensitive << clk.neg();

			memoryFile.open("../DataFile.txt", std::fstream::in | std::fstream::out | std::fstream::app);// ios::in | ios::out);

		}

		~DataMemory()
		{
			memoryFile.close();
		}

	private:

	    fstream memoryFile; 

	    void write()
	    {
			unsigned int dir;	
			sc_uint<data_length> data;
			data = data_in.read();
			dir = dir_in.read();
 
			memoryFile.seekp(dir*(data_length+1), ios::beg);	

			for(int i=0; i < data_length;i++)
	     	{
		        if (data[data_length-1-i] == 1)
		        {
		          memoryFile <<  '1';
		        } 
		        else
		        {
		          memoryFile <<  '0';
		        }
	     	}
		      	
		    memoryFile << '\n';
	    }

	    void read()
	    {

	      char dataTmp[data_length];
 		  sc_int<data_length> data;
 		  unsigned int dir;
 		  dir = dir_in.read();
 
		  memoryFile.seekg(dir*(data_length+1), ios::beg);

		  memoryFile.getline(dataTmp, data_length+1); 

			for(int i=0; i < data_length;i++)
	     	{
		        if (dataTmp[i] == '1')
		        {
		          data[data_length-1-i] = 1;
		        } 
		        else
		        {
		          data[data_length-1-i] = 0;
		        }
	     	}
     	
		data_out.write(data);
	    }
};
#endif
