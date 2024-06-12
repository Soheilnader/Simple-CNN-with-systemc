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

// Memory: Templated memory w/ datain, dataout, chip-select, read-write-bar
template<int ADDRESS, int WORD_LENGTH>
class Memory : public sc_module {
public:
	sc_in<sc_lv<ADDRESS>> addr;
	sc_in<sc_lv<WORD_LENGTH>> datain;
	sc_out<sc_lv<WORD_LENGTH>> dataout;
	sc_in<sc_logic> cs, rwbar;

	int addrSpace;
	sc_uint <WORD_LENGTH> *mem;

	void meminit();
	void memread();
	void memwrite();
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
	SC_METHOD(memread);
	sensitive << addr << cs << rwbar;
	SC_METHOD(memwrite);
	sensitive << addr << datain << cs << rwbar;
	SC_THREAD(memdump);
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

template<int ADDRESS, int WORD_LENGTH>
void Memory<ADDRESS, WORD_LENGTH>::memwrite() {
	sc_uint<ADDRESS> ad;
	if (cs->read() == '1') {
		if (rwbar->read() == '0') {
			ad = addr;
			mem[ad] = datain;
		}
	}
}

template<int ADDRESS, int WORD_LENGTH>
void Memory<ADDRESS, WORD_LENGTH>::memread() {
	sc_uint<ADDRESS> ad;
	if (cs->read() == '1') {
		if (rwbar->read() == '1') {
			ad = addr;
			dataout = mem[ad];
		}
	}
}

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
