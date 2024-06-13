#include <systemc.h>
#include "CNN_TB.h"

void cnn_TB::cnn_testing(){
	//std::cout << "cnn_TB.cpp cnn_TB::testing_CNN()\n";

	while (true)
	{

		start.write(SC_LOGIC_0);
		wait(25, SC_NS);
		start.write(SC_LOGIC_1);
		wait(100, SC_NS);
		start.write(SC_LOGIC_0);

		wait();
	}
}

void cnn_TB::cnn_clocking(){
	//std::cout << "cnn_TB.cpp cnn_TB::cnn_clocking()\n";

	while (true)
	{
		clk.write(SC_LOGIC_0);
		wait(CLK_OFF, SC_NS);
		clk.write(SC_LOGIC_1);
		wait(CLK_ON, SC_NS);
	}
}

void cnn_TB::cnn_resetting(){
		//std::cout << "cnn_TB.cpp cnn_TB::cnn_resetting()\n";
		rst.write(SC_LOGIC_1);
		wait(RST_TIME, SC_NS);
		rst.write(SC_LOGIC_0);

}

void cnn_TB::cnn_display(){
		//std::cout << "cnn_TB.cpp cnn_TB::cnn_display()\n";
		//std::cout << "pattern= " << pattern.read();
	
}
