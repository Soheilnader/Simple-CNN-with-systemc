#include <systemc.h>
#include "CNN_TB.h"

void cnn_TB::testing_CNN(){

	while (true)
	{

		start.write(SC_LOGIC_0);
		wait(50, SC_NS);
		start.write(SC_LOGIC_1);
		wait(20, SC_NS);
		start.write(SC_LOGIC_0);

		wait();
	}
}

void cnn_TB::clocking(){
	while (true)
	{
		clk.write(SC_LOGIC_0);
		wait(CLK_OFF, SC_NS);
		clk.write(SC_LOGIC_1);
		wait(CLK_ON, SC_NS);
	}
}

void cnn_TB::resetting(){

		rst.write(SC_LOGIC_1);
		wait(RST_TIME, SC_NS);
		rst.write(SC_LOGIC_0);

}

void cnn_TB::display(){
		std::cout << "pattern= " << pattern.read();
	
}
