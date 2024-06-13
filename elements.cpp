#include "ELEMENTS.h"

void nBitAdder::adding()
{
	//std::cout << "adding\n";
	result->write(in1->read().to_int() + in2->read().to_int());
}

void nBitMultiplier::multiplying()
{
	//std::cout << "multiplying\n";
	result->write(in1->read().to_int() * in2->read().to_int());
}

void nBitComparator::comparing()
{
	//std::cout << "comparing\n";
	if (in1->read().to_int() == in2->read().to_int())
		result->write(SC_LOGIC_1);
	else
		result->write(SC_LOGIC_0);
}

void mux2To1::muxing2()
{
	//std::cout << "muxing2\n";
	if (sel->read() == '1')	result->write(in1->read());
	else result->write(in0->read());
}

void mux4To1::muxing4() {
	//std::cout << "muxing4\n";
	if (sel->read() == "01") result->write(in1->read());
	else if (sel->read() == "10") result->write(in2->read());
	else if (sel->read() == "11") result->write(in3->read());
	else result->write(in0->read());
}

void mux9To1::muxing9() {
	//std::cout << "muxing9\n";
	if (sel->read() == "0001") result->write(in1->read());
	else if (sel->read() == "0010") result->write(in2->read());
	else if (sel->read() == "0011") result->write(in3->read());
	else if (sel->read() == "0100") result->write(in4->read());
	else if (sel->read() == "0101") result->write(in5->read());
	else if (sel->read() == "0110") result->write(in6->read());
	else if (sel->read() == "0111") result->write(in7->read());
	else if (sel->read() == "1000") result->write(in8->read());
	else result->write(in0->read());
}

void dec2To4::decoding() {
	//std::cout << "decoding\n";

	if (en->read() == '0')  result->write("0000");
	else{
		if (sel->read() == "00") result->write("0001");
		else if (sel->read() == "01") result->write("0010");
		else if (sel->read() == "10") result->write("0100");
		else if (sel->read() == "11") result->write("1000");
	}
}

void relu::reluing() {
	//std::cout << "reluing\n";
	val0->write((in0->read().to_int() < 0) == '1' ? "00000000" : in0->read());
	val1->write((in1->read().to_int() < 0) == '1' ? "00000000" : in1->read());
	val2->write((in2->read().to_int() < 0) == '1' ? "00000000" : in2->read());
	val3->write((in3->read().to_int() < 0) == '1' ? "00000000" : in3->read());
}

void maxpool::maxpooling() {
	//std::cout << "maxpooling\n";

	if ((in0->read().to_uint() >= in1->read().to_uint()) &&
		(in0->read().to_uint() >= in2->read().to_uint()) &&
		(in0->read().to_uint() >= in3->read().to_uint()))
		max->write(in0->read());
	else if ((in1->read().to_uint() >= in0->read().to_uint()) &&
		(in1->read().to_uint() >= in2->read().to_uint()) &&
		(in1->read().to_uint() >= in3->read().to_uint()))
		max->write(in1->read());
	else if ((in2->read().to_uint() >= in0->read().to_uint()) &&
		(in2->read().to_uint() >= in1->read().to_uint()) &&
		(in2->read().to_uint() >= in3->read().to_uint()))
		max->write(in2->read());
	else if ((in3->read().to_uint() >= in0->read().to_uint()) &&
		(in3->read().to_uint() >= in2->read().to_uint()) &&
		(in3->read().to_uint() >= in1->read().to_uint()))
		max->write(in3->read());
}

void result::resulting(){
	//std::cout << "resulting\n";

	if ((in0->read().to_uint() >= in1->read().to_uint()) &&
		(in0->read().to_uint() >= in2->read().to_uint())) 
		pattern->write("001");
	else if ((in1->read().to_uint() >= in0->read().to_uint()) &&
		(in1->read().to_uint() >= in2->read().to_uint()))
		pattern->write("010");
	else if ((in2->read().to_uint() >= in0->read().to_uint()) &&
		(in2->read().to_uint() >= in1->read().to_uint()))
		pattern->write("100");
}

void nBitRegister::registering(){
	//std::cout << "registering\n";

	if (rst->read() == '1')
	{
		q->write("00000000");
	}
	else if (clk->event() && (clk->read() == '1'))
	{
		if (clr->read() == '1') q->write("00000000");

		else if (load->read() == '1') { 
				q->write(d->read());
		}
	}
}

void nBitCounter::counting(){
	//std::cout << "counting\n";

	if (rst->read() == '1')
	{
		q->write("00000000");
	}
	else if (clk->event() && (clk->read() == '1'))
	{
		if (clr->read() == '1') q->write("00000000");

		else if (en->read() == '1') {
			q->write(q->read().to_uint() + 1);
		}
	}
}