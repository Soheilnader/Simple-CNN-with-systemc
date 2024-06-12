#include <systemc.h>

SC_MODULE(nBitAdder)
{
public:
	sc_port<sc_signal_in_if<sc_lv<8>>, 1> in1, in2;
	sc_port<sc_signal_out_if<sc_lv<8>>, 1> result;

	SC_CTOR(nBitAdder)
	{
		SC_METHOD(adding);
		sensitive << in1 << in2;
	}
	void adding();
};

SC_MODULE(nBitMultiplier)
{
public:
	sc_port<sc_signal_in_if<sc_lv<8>>, 1> in1, in2;
	sc_port<sc_signal_out_if<sc_lv<8>>, 1> result;

	SC_CTOR(nBitMultiplier)
	{
		SC_METHOD(multiplying);
		sensitive << in1 << in2;
	}
	void multiplying();
};

SC_MODULE(nBitComparator)
{
public:
	sc_port<sc_signal_in_if<sc_lv<8>>, 1> in1, in2;
	sc_port<sc_signal_out_if<sc_lv<8>>, 1> result;

	SC_CTOR(nBitComparator)
	{
		SC_METHOD(comparing);
		sensitive << in1 << in2;
	}
	void comparing();
};

SC_MODULE(mux2To1)
{
public:
	sc_port<sc_signal_in_if<sc_lv<8>>, 1> in0, in1;
	sc_port<sc_signal_in_if<sc_logic>, 1> sel;
	sc_port<sc_signal_out_if<sc_lv<8>>, 1> result;

	SC_CTOR(mux2To1)
	{
		SC_METHOD(muxing2);
		sensitive << sel << in0 << in1;
	}
	void muxing2();
};

SC_MODULE(mux4To1)
{
public:
	sc_port<sc_signal_in_if<sc_lv<8>>, 1> in0, in1, in2, in3;
	sc_port<sc_signal_in_if<sc_lv<2>>, 1> sel;
	sc_port<sc_signal_out_if<sc_lv<8>>, 1> result;

	SC_CTOR(mux4To1)
	{
		SC_METHOD(muxing4);
		sensitive << sel << in0 << in1 << in2 << in3;
	}
	void muxing4();
};

SC_MODULE(mux9To1)
{
public:
	sc_port<sc_signal_in_if<sc_lv<8>>, 1> in0, in1, in2, in3, in4, in5, in6, in7, in8;
	sc_port<sc_signal_in_if<sc_lv<4>>, 1> sel;
	sc_port<sc_signal_out_if<sc_lv<8>>, 1> result;

	SC_CTOR(mux9To1)
	{
		SC_METHOD(muxing9);
		sensitive << sel << in0 << in1 << in2 << in3 << in4 << in5 << in6 << in7 << in8;
	}
	void muxing9();
};

SC_MODULE(dec2To4)
{
public:
	sc_port<sc_signal_in_if<sc_lv<2>>, 1> sel;
	sc_port<sc_signal_in_if<sc_logic>, 1> en;
	sc_port<sc_signal_out_if<sc_lv<4>>, 1> result;

	SC_CTOR(dec2To4)
	{
		SC_METHOD(decoding);
		sensitive << sel << en;
	}
	void decoding();
};

SC_MODULE(relu)
{
public:
	sc_port<sc_signal_in_if<sc_lv<4>>, 1> in0, in1, in2, in3;
	sc_port<sc_signal_out_if<sc_lv<4>>, 1> val0, val1, val2, val3;

	SC_CTOR(relu)
	{
		SC_METHOD(reluing);
		sensitive << in0 << in1 << in2 << in3;
	}
	void reluing();
};

SC_MODULE(maxpool)
{
public:
	sc_port<sc_signal_in_if<sc_lv<4>>, 1> in0, in1, in2, in3;
	sc_port<sc_signal_out_if<sc_lv<4>>, 1> max;

	SC_CTOR(maxpool)
	{
		SC_METHOD(maxpooling);
		sensitive << in0 << in1 << in2 << in3;
	}
	void maxpooling();
};

SC_MODULE(result)
{
public:
	sc_port<sc_signal_in_if<sc_lv<4>>, 1> in0, in1, in2, in3;
	sc_port<sc_signal_out_if<sc_lv<4>>, 1> pattern;

	SC_CTOR(result)
	{
		SC_METHOD(resulting);
		sensitive << in0 << in1 << in2 << in3;
	}
	void resulting();
};

SC_MODULE(nBitRegister)
{
public:
	sc_port<sc_signal_in_if<sc_logic>, 1> clk, rst, load, clr;
	sc_port<sc_signal_in_if<sc_lv<8>>, 1> d;
	sc_port<sc_signal_out_if<sc_lv<8>>, 1> q;

	SC_CTOR(nBitRegister)
	{
		SC_METHOD(registering);
		sensitive << clk << rst;
	}
	void registering();
};

SC_MODULE(nBitCounter)
{
public:
	sc_port<sc_signal_in_if<sc_logic>, 1> clk, rst, en, clr;
	sc_port<sc_signal_out_if<sc_lv<4>>, 1> q;

	SC_CTOR(nBitCounter)
	{
		SC_METHOD(counting);
		sensitive << clk << rst;
	}
	void counting();
};