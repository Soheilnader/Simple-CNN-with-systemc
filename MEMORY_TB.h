#include <systemc.h>
#include "ELEMENTS.h"

#define CLK_ON 5
#define CLK_OFF 5
#define RST_TIME 2

SC_MODULE(memory_TB)
{
	sc_signal<sc_logic>	rst, clk, write_en, read1, read2, read3;
	sc_signal<sc_lv<8>>	data_rd1, data_rd2, data_rd3, data_wr;
	sc_signal<sc_lv<4>>	addr_rd1, addr_rd2, addr_rd3, addr_wr;


	SC_CTOR(memory_TB)
	{
	
		Memory<4, 8>* MEM = new Memory<4, 8>("Memory");
		MEM->clk(clk);
		MEM->write_en(write_en);
		MEM->read1(read1);
		MEM->read2(read2);
		MEM->read3(read3);
		MEM->addr_rd1(addr_rd1);
		MEM->addr_rd2(addr_rd2);
		MEM->addr_rd3(addr_rd3);
		//MEM->addr_wr(addr_wr);
		MEM->data_rd1(data_rd1);
		MEM->data_rd2(data_rd2);
		MEM->data_rd3(data_rd3);
		MEM->data_wr(data_wr);






		SC_THREAD(clocking);
		SC_THREAD(resetting);
		SC_THREAD(testing);

	}
	void clocking();
	void resetting();
	void testing();


};