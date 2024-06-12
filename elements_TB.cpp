#include <systemc.h>
#include "ELEMENTS_TB.h"

void elements_TB::testing(){

	while (true)
	{
		nBitRegister_testing();
		wait();
	}
}

void elements_TB::clocking(){
	while (true)
	{
		clk = SC_LOGIC_0;
		wait(CLK_OFF, SC_NS);
		clk = SC_LOGIC_1;
		wait(CLK_ON, SC_NS);
	}
}

void elements_TB::resetting(){
	while (true)
	{
		rst = SC_LOGIC_1;
		wait(RST_TIME, SC_NS);
		rst = SC_LOGIC_0;
		wait();
	}
}
/*			//mux2To1 Testing
void elements_TB::mux2To1_testing(){
	in0.write("00000001");
	in1.write("00000111");
	sel.write(SC_LOGIC_0);
	wait(10, SC_NS);
	std::cout << result.read() << "\n";
	in0.write("00000001");
	in1.write("00000111");
	sel.write(SC_LOGIC_1);
	wait(10, SC_NS);
	std::cout << result.read() << "\n";
}
*/			
/*		//nBitMultiplier Testing
void elements_TB::nBitMultiplier_testing(){
	in1.write("00000011");
	in2.write("00000111");
	wait(10, SC_NS);
	std::cout << result.read() << "\n";
	in1.write("11111111");
	in2.write("00000111");
	wait(10, SC_NS);
	std::cout << result.read() << "\n";
}
*/

		//nBitRegister_testing
void elements_TB::nBitRegister_testing(){
	din.write("10000011");
	load.write(SC_LOGIC_0);
	clr.write(SC_LOGIC_0);

	wait(10, SC_NS);
	load.write(SC_LOGIC_1);
	wait(13, SC_NS);
	load.write(SC_LOGIC_0);
	clr.write(SC_LOGIC_1);
	wait(13, SC_NS);
	clr.write(SC_LOGIC_0);
	load.write(SC_LOGIC_1);

	wait(10, SC_NS);
}