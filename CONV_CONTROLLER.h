#include <systemc.h>

SC_MODULE(conv_controller){
	sc_in <sc_logic> clk, rst, cmp_4, cmp_9, start_conv;
	sc_out <sc_logic> read, done, load_data, load_addr, clr_data, clr_addr, en_dec, sel3, sel4, en_j, en_9, en_4;
	sc_out <sc_lv<2>> sel1, sel2;

	enum states
	{
		IDLE, START, ADDR1, ADDR2, ADDR3, ADDR4, CALCULATE1, CALCULATE2, CALCULATE3, WRITE1, WRITE2, WAIT
	};

	sc_signal <states> p_state, n_state;

	SC_CTOR(conv_controller)
	{
		SC_METHOD(comb_S_function);
		sensitive << cmp_4 << cmp_9 << start_conv << p_state;
		SC_METHOD(comb_O_function);
		sensitive << p_state;
		SC_METHOD(seq_function);
		sensitive << clk << rst;
	}
	void comb_S_function();
	void comb_O_function();
	void seq_function();
};