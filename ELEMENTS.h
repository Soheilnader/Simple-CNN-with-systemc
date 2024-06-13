#ifndef ELEMENTS_H
#define ELEMENTS_H
#include <systemc.h>

SC_MODULE(nBitAdder)
{
	sc_in<sc_lv<8>> in1, in2;
	sc_out<sc_lv<8>> result;

	SC_CTOR(nBitAdder)
	{
		SC_METHOD(adding);
		sensitive << in1 << in2;
	}
	void adding();
};

SC_MODULE(nBitMultiplier)
{
	sc_in<sc_lv<8>> in1, in2;
	sc_out<sc_lv<8>> result;

	SC_CTOR(nBitMultiplier)
	{
		SC_METHOD(multiplying);
		sensitive << in1 << in2;
	}
	void multiplying();
};

SC_MODULE(nBitComparator)
{
	sc_in<sc_lv<8>> in1, in2;
	sc_out<sc_logic> result;

	SC_CTOR(nBitComparator)
	{
		SC_METHOD(comparing);
		sensitive << in1 << in2;
	}
	void comparing();
};

SC_MODULE(mux2To1)
{
	sc_in<sc_lv<8>> in0, in1;
	sc_in<sc_logic> sel;
	sc_out<sc_lv<8>> result;

	SC_CTOR(mux2To1)
	{
		SC_METHOD(muxing2);
		sensitive << sel << in0 << in1;
	}
	void muxing2();
};

SC_MODULE(mux4To1)
{
	sc_in<sc_lv<8>> in0, in1, in2, in3;
	sc_in<sc_lv<2>> sel;
	sc_out<sc_lv<8>> result;

	SC_CTOR(mux4To1)
	{
		SC_METHOD(muxing4);
		sensitive << sel << in0 << in1 << in2 << in3;
	}
	void muxing4();
};

SC_MODULE(mux9To1)
{
	sc_in<sc_lv<8>> in0, in1, in2, in3, in4, in5, in6, in7, in8;
	sc_in<sc_lv<4>> sel;
	sc_out<sc_lv<8>> result;

	SC_CTOR(mux9To1)
	{
		SC_METHOD(muxing9);
		sensitive << sel << in0 << in1 << in2 << in3 << in4 << in5 << in6 << in7 << in8;
	}
	void muxing9();
};

SC_MODULE(dec2To4)
{
	sc_in<sc_lv<2>> sel;
	sc_in<sc_logic> en;
	sc_out<sc_lv<4>> result;

	SC_CTOR(dec2To4)
	{
		SC_METHOD(decoding);
		sensitive << sel << en;
	}
	void decoding();
};

SC_MODULE(relu)
{
	sc_in<sc_lv<8>> in0, in1, in2, in3;
	sc_out<sc_lv<8>> val0, val1, val2, val3;

	SC_CTOR(relu)
	{
		SC_METHOD(reluing);
		sensitive << in0 << in1 << in2 << in3;
	}
	void reluing();
};

SC_MODULE(maxpool)
{
	sc_in<sc_lv<8>> in0, in1, in2, in3;
	sc_out<sc_lv<8>> max;

	SC_CTOR(maxpool)
	{
		SC_METHOD(maxpooling);
		sensitive << in0 << in1 << in2 << in3;
	}
	void maxpooling();
};

SC_MODULE(result)
{
	sc_in<sc_lv<8>> in0, in1, in2;
	sc_out<sc_lv<3>> pattern;

	SC_CTOR(result)
	{
		SC_METHOD(resulting);
		sensitive << in0 << in1 << in2;
	}
	void resulting();
};

SC_MODULE(nBitRegister)
{
	sc_in<sc_logic> clk, rst, load, clr;
	sc_in<sc_lv<8>> d;
	sc_out<sc_lv<8>> q;

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
	sc_in<sc_logic> clk, rst, en, clr;
	sc_out<sc_lv<8>> q;

	SC_CTOR(nBitCounter)
	{
		SC_METHOD(counting);
		sensitive << clk << rst;
	}
	void counting();
};

// Memory: Templated memory w/ datain, dataout, chip-select, read-write-bar
template<int ADDRESS, int WORD_LENGTH>
class Memory : public sc_module {
public:
	sc_in<sc_lv<ADDRESS>> addr_rd1, addr_rd2, addr_rd3;
	sc_in<sc_lv<WORD_LENGTH>> data_wr;
	sc_out<sc_lv<WORD_LENGTH>> data_rd1, data_rd2, data_rd3;
	sc_in<sc_logic> clk, write_en, read1, read2, read3;

	int addrSpace;
	sc_uint <WORD_LENGTH> *mem;

	void meminit();
	void memread1();
	void memread2();
	void memread3();
	//void memwrite();
	void memdump();

	SC_HAS_PROCESS(Memory);
	Memory(sc_module_name);
};

template<int ADDRESS, int WORD_LENGTH>
Memory<ADDRESS, WORD_LENGTH>::Memory(sc_module_name)
{
	addrSpace = int(pow(2.0, ADDRESS));
	mem = new sc_uint<WORD_LENGTH>[addrSpace];

	SC_THREAD(meminit);
	SC_METHOD(memread1);
	sensitive << clk;
	SC_METHOD(memread2);
	sensitive << clk;
	SC_METHOD(memread3);
	sensitive << clk;
	//SC_METHOD(memwrite);
	//sensitive << clk;
	//SC_THREAD(memdump);
}

template<int ADDRESS, int WORD_LENGTH>
void Memory<ADDRESS, WORD_LENGTH>::meminit() {

	ifstream in("memin.txt");
	int i;
	sc_lv<WORD_LENGTH> data;

	for (i = 0; i<addrSpace; i++) {
		in >> data;
		mem[i] = data;
		cout << "Init at: " << i << " writes: " << data << '\n';
	}
}
/*
template<int ADDRESS, int WORD_LENGTH>
void Memory<ADDRESS, WORD_LENGTH>::memwrite() {
	sc_uint<ADDRESS> ad_w;
	if (clk->event() && clk->read() == '1') {
		if (write_en->read() == '1') {
			ad_w = addr_wr;
			mem[ad_w] = data_wr;
		}
	}
}
*/
template<int ADDRESS, int WORD_LENGTH>
void Memory<ADDRESS, WORD_LENGTH>::memread1() {
	sc_uint<ADDRESS> ad1;
	if (clk->event() && clk->read() == '1') {
		if (read1->read() == '1') {
			ad1 = addr_rd1;
			data_rd1 = mem[ad1];
		}
	}
}

template<int ADDRESS, int WORD_LENGTH>
void Memory<ADDRESS, WORD_LENGTH>::memread2() {
	sc_uint<ADDRESS> ad2;
	if (clk->event() && clk->read() == '1') {
		if (read2->read() == '1') {
			ad2 = addr_rd2;
			data_rd2 = mem[ad2];
		}
	}
}

template<int ADDRESS, int WORD_LENGTH>
void Memory<ADDRESS, WORD_LENGTH>::memread3() {
	sc_uint<ADDRESS> ad3;
	if (clk->event() && clk->read() == '1') {
		if (read3->read() == '1') {
			ad3 = addr_rd3;
			data_rd3 = mem[ad3];
		}
	}
}
/*
template<int ADDRESS, int WORD_LENGTH>
void Memory<ADDRESS, WORD_LENGTH>::memdump() {
	int i;
	sc_lv<WORD_LENGTH> data;
	ofstream out("memout.txt");
	wait(2000, SC_NS);
	for (i = 0; i<addrSpace; i++) {
		data = mem[i];
		out << i << ":\t" << data << "\n";
	}
}
*/
#endif