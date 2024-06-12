/*
#include <systemc.h>
#include "elements.h"

// Testbench
int sc_main(int argc, char* argv[]) {
	// Signals
	sc_signal<sc_lv<8>> in0;
	sc_signal<sc_lv<8>> in1;
	sc_signal<sc_logic> sel;
	sc_signal<sc_lv<8>> data_out;

	// Instantiate the module
	mux2To1 mux("Mux2to1");
	mux.in0(in0);
	mux.in1(in1);
	mux.sel(sel);
	mux.result(data_out);

	// Initialize signals
	in0.write("00000001");
	in1.write("00000010");
	sel.write(SC_LOGIC_1);

	// Start simulation
	sc_start(1, SC_NS);
	std::cout << "data_out: " << data_out.read() << std::endl;

	sel.write(SC_LOGIC_0);
	sc_start(1, SC_NS);
	std::cout << "data_out: " << data_out.read() << std::endl;

	return 0;
}
*/