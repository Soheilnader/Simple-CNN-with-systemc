#include <systemc.h>
#include "MEMORY_TB.h"

void memory_TB::testing(){

	while (true)
	{
			read1.write(SC_LOGIC_0);
			read2.write(SC_LOGIC_0);
			read3.write(SC_LOGIC_0);
			write_en.write(SC_LOGIC_0);
			addr_rd1.write("0000");
			addr_rd2.write("0000");
			addr_rd3.write("0000");
			addr_wr.write("0000");
			data_wr.write("00000000");
			wait(10, SC_NS);
			addr_rd1.write("0011");
			addr_rd2.write("0000");
			addr_rd3.write("0100");
			read1.write(SC_LOGIC_1);
			read2.write(SC_LOGIC_1);
			read3.write(SC_LOGIC_1);


			wait(10, SC_NS);

		wait();
	}
}

void memory_TB::clocking(){
	while (true)
	{
		clk = SC_LOGIC_0;
		wait(CLK_OFF, SC_NS);
		clk = SC_LOGIC_1;
		wait(CLK_ON, SC_NS);
	}
}

void memory_TB::resetting(){
	while (true)
	{
		rst = SC_LOGIC_1;
		wait(RST_TIME, SC_NS);
		rst = SC_LOGIC_0;
		wait();
	}
}

