#include "ELEMENTS.h"

void nBitAdder::adding()
{
	result->write(in1->read().to_int() + in2->read().to_int());
}

void nBitMultiplier::multiplying()
{
	result->write(in1->read().to_int() * in2->read().to_int());
}

void nBitComparator::comparing()
{
	if (in1->read().to_uint() == in2->read().to_uint())
		result->write('1');
	else
		result->write('0');
}

void mux2To1::muxing2()
{
	if (sel->read() == '1')	result->write(in1->read());
	else result->write(in0->read());
}

void mux4To1::muxing4() {
	if (sel->read() == "01") result->write(in1->read());
	else if (sel->read() == "10") result->write(in2->read());
	else if (sel->read() == "11") result->write(in3->read());
	else result->write(in0->read());
}

void mux9To1::muxing9() {
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
	if (en->read() == '0')  result->write("0000");
	else{
		if (sel->read() == "00") result->write("0001");
		else if (sel->read() == "01") result->write("0010");
		else if (sel->read() == "10") result->write("0100");
		else if (sel->read() == "11") result->write("1000");
	}
}

void relu::reluing() {
	val0->write(in0[7]->read() == '1' ? "00000000" : in0->read());
	val1->write(in1[7]->read() == '1' ? "00000000" : in1->read());
	val2->write(in2[7]->read() == '1' ? "00000000" : in2->read());
	val3->write(in3[7]->read() == '1' ? "00000000" : in3->read());
}

void maxpool::maxpooling() {
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
	if ((in0->read().to_uint() >= in1->read().to_uint()) &&
		(in0->read().to_uint() >= in2->read().to_uint())) 
		pattern->write(in0->read());
	else if ((in1->read().to_uint() >= in0->read().to_uint()) &&
		(in1->read().to_uint() >= in2->read().to_uint()))
		pattern->write(in1->read());
	else if ((in2->read().to_uint() >= in0->read().to_uint()) &&
		(in2->read().to_uint() >= in1->read().to_uint()))
		pattern->write(in2->read());
}

void nBitRegister::registering(){
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