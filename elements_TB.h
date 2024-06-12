#include <systemc.h>
#include "ELEMENTS.h"

#define CLK_ON 5
#define CLK_OFF 5
#define RST_TIME 2

SC_MODULE(elements_TB)
{
	sc_signal<sc_logic>	rst, clk;

	/*
	sc_signal<sc_logic>	sel;
	sc_signal<sc_lv<8>>	in0, in1, result;
	*/
	/*
	sc_signal<sc_lv<8>>	in1, in2, result;
	*/
	sc_signal<sc_logic>	load, clr;
	sc_signal<sc_lv<8>>	din, dout;


	SC_CTOR(elements_TB)
	{
		/*
		mux2To1* mux = new mux2To1("Mux2to1");
		mux->in0(in0);
		mux->in1(in1);
		mux->sel(sel);
		mux->result(result);
		*/
		/*
		nBitMultiplier* mul = new nBitMultiplier("nBitMultiplier");
		mul->in1(in1);
		mul->in2(in2);
		mul->result(result);
		*/

		nBitRegister* reg = new nBitRegister("nBitRegister");
		reg->load(load);
		reg->d(din);
		reg->q(dout);
		reg->rst(rst);
		reg->clk(clk);
		reg->clr(clr);


		SC_THREAD(clocking);
		SC_THREAD(resetting);
		SC_THREAD(testing);

	}
	void clocking();
	void resetting();
	void testing();


	void mux2To1_testing();
	void nBitMultiplier_testing();
	void nBitRegister_testing();

};