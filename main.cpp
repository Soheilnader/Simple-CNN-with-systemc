#include "ELEMENTS_TB.h"

int sc_main(int argc, char *argv[])
{
	elements_TB* TOP = new elements_TB("TB");

	sc_trace_file* VCDFile;
	VCDFile = sc_create_vcd_trace_file("Waveform");

	sc_trace(VCDFile, TOP->clk, "clk");
	sc_trace(VCDFile, TOP->rst, "rst");
	/*			//mux2To1 Testing
	sc_trace(VCDFile, TOP->sel, "sel");
	sc_trace(VCDFile, TOP->result, "result");
	sc_trace(VCDFile, TOP->in0, "in0");
	sc_trace(VCDFile, TOP->in1, "in1");
	*/
	/*			//nBitMultiplier Testing
	sc_trace(VCDFile, TOP->result, "result");
	sc_trace(VCDFile, TOP->in1, "in1");
	sc_trace(VCDFile, TOP->in2, "in2");
	*/
	sc_trace(VCDFile, TOP->din, "din");
	sc_trace(VCDFile, TOP->dout, "dout");
	sc_trace(VCDFile, TOP->clr, "clr");
	sc_trace(VCDFile, TOP->load, "load");

	std::cout << "Done!\n";
	sc_start(2000, SC_NS);
	std::cout << "Done!\n";
	return 0;
}