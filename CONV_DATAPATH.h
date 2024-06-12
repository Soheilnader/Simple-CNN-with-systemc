#include <systemc.h>
#include "ELEMENTS.h"

SC_MODULE(conv_datapath){
	sc_in <sc_logic> clk, rst;
	sc_out <sc_logic> cmp_4, cmp_9;
	sc_in <sc_logic> load_data, load_addr, clr_data, clr_addr, en_dec, sel3, sel4, en_j, en_9, en_4;
	sc_in <sc_lv<2>> sel1, sel2;
	sc_in <sc_lv<8>> data_rd;
	sc_out <sc_lv<4>> addr_rd;
	sc_out <sc_lv<8>> val0, val1, val2, val3;

	sc_signal <sc_lv<8>> s_cnt_j, s_cnt_i, s_cnt_y, s_cnt_x, s_cnt_9, s_cnt_4;
	sc_signal <sc_logic> s_cmp_j, s_cmp_i, s_cmp_y, s_cmp_x, s_cmp_9, s_cmp_4;
	sc_signal <sc_lv<8>> s_mul1, s_mul2, s_mul_out;
	sc_signal <sc_lv<8>> s_add1, s_add2, s_add_out;
	sc_signal <sc_lv<8>> s_mux9to1;
	sc_signal <sc_lv<8>> s_data, s_addr;
	sc_signal <sc_lv<4>> s_dec;

	nBitCounter* cnt_j;
	nBitComparator* cmp_j;

	nBitCounter* cnt_i;
	nBitComparator* cmp_i;

	nBitCounter* cnt_y;
	nBitComparator* cmp_y;

	nBitCounter* cnt_x;
	nBitComparator* cmp_x;

	mux4To1* mux1; mux4To1* mux2;
	mux2To1* mux3; mux2To1* mux4;

	nBitAdder* add1;
	nBitMultiplier* mul1;

	nBitRegister* addr; nBitRegister* data;

	mux9To1* mux5;
	nBitCounter* cnt_9;
	nBitComparator* cmp9;

	dec2To4* dec;
	nBitCounter* cnt_4;
	nBitComparator* cmp4;

	nBitRegister* V_0;
	nBitRegister* V_1;
	nBitRegister* V_2;
	nBitRegister* V_3;

	SC_CTOR(conv_datapath){
		sc_lv<8> s_cnt_9_SLICE;
		sc_signal<sc_lv<8>> var_z;
		var_z = "00000000";
		s_cnt_9_SLICE = s_cnt_9;

		cnt_j = new nBitCounter("cnt_j");
			cnt_j->clk(clk);
			cnt_j->rst(rst);
			cnt_j->en(en_j);
			cnt_j->clr(s_cmp_j);
			cnt_j->q(s_cnt_j);
		cmp_j = new nBitComparator("cmp_j");
			cmp_j->in1(s_cnt_j);
			cmp_j->in2("00000011");
			cmp_j->result(s_cmp_j);

		cnt_i = new nBitCounter("cnt_i");
			cnt_i->clk(clk);
			cnt_i->rst(rst);
			cnt_i->en(s_cmp_j);
			cnt_i->clr(s_cmp_i);
			cnt_i->q(s_cnt_i);
		cmp_i = new nBitComparator("cmp_i");
			cmp_j->in1(s_cnt_i);
			cmp_j->in2("00000011");
			cmp_j->result(s_cmp_i);

		cnt_y = new nBitCounter("cnt_y");
			cnt_y->clk(clk);
			cnt_y->rst(rst);
			cnt_y->en(s_cmp_i);
			cnt_y->clr(s_cmp_y);
			cnt_y->q(s_cnt_y);
		cmp_y = new nBitComparator("cmp_y");
			cmp_y->in1(s_cnt_y);
			cmp_y->in2("00000010");
			cmp_y->result(s_cmp_y);

		cnt_x = new nBitCounter("cnt_x");
			cnt_x->clk(clk);
			cnt_x->rst(rst);
			cnt_x->en(s_cmp_y);
			cnt_x->clr(s_cmp_x);
			cnt_x->q(s_cnt_x);
		cmp_x = new nBitComparator("cmp_x");
			cmp_x->in1(s_cnt_x);
			cmp_x->in2("00000010");
			cmp_x->result(s_cmp_x);

		mux1 = new mux4To1("mux1");
			mux1->sel(sel1);
			mux1->in0(s_cnt_j);
			mux1->in1(s_cnt_y);
			mux1->in2(s_mul_out);
			mux1->in3(BIAS);
			mux1->result(s_add1);
		mux2 = new mux4To1("mux2");
			mux2->sel(sel2);
			mux2->in0(s_cnt_i);
			mux2->in1(s_cnt_x);
			mux2->in2(data_rd);
			mux2->in3(var_z);
			mux2->result(s_mul1);
		mux3 = new mux2To1("mux3");
			mux3->sel(sel3);
			mux3->in0("00000100");
			mux3->in1(s_mux9to1);
			mux3->result(s_mul2);
		mux4 = new mux2To1("mux4");
			mux4->sel(sel4);
			mux4->in0(s_addr);
			mux4->in1(s_data);
			mux4->result(s_add2);

		add1 = new nBitAdder("add1");
			add1->in1(s_add1);
			add1->in2(s_add2);
			add1->result(s_add_out);
		mul1 = new nBitMultiplier("mul1");
			mul1->in1(s_mul1);
			mul1->in2(s_mul2);
			mul1->result(s_mul_out);

		addr = new nBitRegister("addr");
			addr->clk(clk);
			addr->rst(rst);
			addr->load(load_addr);
			addr->clr(clr_addr);
			addr->d(s_add_out);
			addr->q(s_addr);
		data = new nBitRegister("data");
			data->clk(clk);
			data->rst(rst);
			data->load(load_data);
			data->clr(clr_data);
			data->d(s_add_out);
			data->q(s_data);

		mux5 = new mux9To1("mux5");
			mux5->sel(s_cnt_9);	//3 downto 0
			mux5->in0(k0);
			mux5->in1(k1);
			mux5->in2(k2);
			mux5->in3(k3);
			mux5->in4(k4);
			mux5->in5(k5);
			mux5->in6(k6);
			mux5->in7(k7);
			mux5->in8(k8);
			mux5->result(s_mux9to1);
		cnt_9 = new nBitCounter("cnt_9");
			cnt_9->clk(clk);
			cnt_9->rst(rst);
			cnt_9->en(en_9);
			cnt_9->clr(s_cmp_9);
			cnt_9->q(s_cnt_9);
		cmp9 = new nBitComparator("cmp9");
			cmp9->in1(s_cnt_9);
			cmp9->in2("00001001");
			cmp9->result(s_cmp_9);

		dec = new dec2To4("dec");
			dec->sel(s_cnt_4);	// 1 downto 0
			dec->en(en_dec);
			dec->result(s_dec);
		cnt_4 = new nBitCounter("cnt_4");
			cnt_4->clk(clk);
			cnt_4->rst(rst);
			cnt_4->en(en_4);
			cnt_4->clr(s_cmp_4);
			cnt_4->q(s_cnt_4);
		cmp4 = new nBitComparator("cmp4");
			cmp4->in1(s_cnt_4);
			cmp4->in2("00000100");
			cmp4->result(s_cmp_4);

		V_0 = new nBitRegister("V_0");
			V_0->clk(clk);
			V_0->rst(rst);
			V_0->load(s_dec[0]);
			V_0->clr('0');
			V_0->d(s_data);
			V_0->q(val0);
		V_1 = new nBitRegister("V_1");
			V_1->clk(clk);
			V_1->rst(rst);
			V_1->load(s_dec[1]);
			V_1->clr('0');
			V_1->d(s_data);
			V_1->q(val1);
		V_2 = new nBitRegister("V_2");
			V_2->clk(clk);
			V_2->rst(rst);
			V_2->load(s_dec[2]);
			V_2->clr('0');
			V_2->d(s_data);
			V_2->q(val2);
		V_3 = new nBitRegister("V_3");
			V_3->clk(clk);
			V_3->rst(rst);
			V_3->load(s_dec[3]);
			V_3->clr('0');
			V_3->d(s_data);
			V_3->q(val3);
	}
};