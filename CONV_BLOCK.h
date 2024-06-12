#include <systemc.h>
#include "CONV_DATAPATH.h"
#include "CONV_CONTROLLER.h"

SC_MODULE(conv_block){
	sc_in <sc_logic> clk, rst, start_conv;
	sc_out <sc_logic> done_conv, read;
	sc_out <sc_lv<4>> addr_rd;
	sc_in <sc_lv<8>> data_rd;
	sc_out <sc_lv<8>> val_0, val_1, val_2, val_3;

	sc_signal <sc_lv<2>> sel1, sel2;
	sc_signal <sc_logic> en_j, en_9, en_4;
	sc_signal <sc_logic> clr_9, clr_4;
	sc_signal <sc_logic> load_data, load_addr;
	sc_signal <sc_logic> clr_data, clr_addr, en_dec;
	sc_signal <sc_logic> sel3, sel4;
	sc_signal <sc_logic> cmp_4, cmp_9;


	conv_datapath* conv_dp;
	conv_controller* conv_cntrl;



	SC_CTOR(conv_block){


		conv_dp = new conv_datapath("conv_dp");
		conv_dp->clk(clk);
		conv_dp->rst(rst);
		conv_dp->data_rd(data_rd);
		conv_dp->addr_rd(addr_rd);
		conv_dp->val0(val_0);
		conv_dp->val1(val_1);
		conv_dp->val2(val_2);
		conv_dp->val3(val_3);
		conv_dp->en_j(en_j);
		conv_dp->en_9(en_9);
		conv_dp->en_4(en_4);
		conv_dp->load_data(load_data);
		conv_dp->load_addr(load_addr);
		conv_dp->clr_data(clr_data);
		conv_dp->clr_addr(clr_addr);
		conv_dp->en_dec(en_dec);
		conv_dp->sel1(sel1);
		conv_dp->sel2(sel2);
		conv_dp->sel3(sel3);
		conv_dp->sel4(sel4);
		conv_dp->cmp_4(cmp_4);
		conv_dp->cmp_9(cmp_9);

		conv_cntrl = new conv_controller("conv_cntrl");
		conv_cntrl->clk(clk);
		conv_cntrl->rst(rst);
		conv_cntrl->read(read);
		conv_cntrl->done_conv(done_conv);
		conv_cntrl->en_j(en_j);
		conv_cntrl->en_9(en_9);
		conv_cntrl->en_4(en_4);
		conv_cntrl->load_data(load_data);
		conv_cntrl->load_addr(load_addr);
		conv_cntrl->clr_data(clr_data);
		conv_cntrl->clr_addr(clr_addr);
		conv_cntrl->en_dec(en_dec);
		conv_cntrl->sel1(sel1);
		conv_cntrl->sel2(sel2);
		conv_cntrl->sel3(sel3);
		conv_cntrl->sel4(sel4);
		conv_cntrl->cmp_4(cmp_4);
		conv_cntrl->cmp_9(cmp_9);
		conv_cntrl->start_conv(start_conv);



	}
};