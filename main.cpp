//#include "ELEMENTS_TB.h"
#include "MEMORY_TB.h"
#include "CNN_TB.h"

int sc_main(int argc, char *argv[])
{
	/*
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
	
	sc_trace(VCDFile, TOP->din, "din");
	sc_trace(VCDFile, TOP->dout, "dout");
	sc_trace(VCDFile, TOP->clr, "clr");
	sc_trace(VCDFile, TOP->load, "load");

	*/
	/*
	memory_TB* TOP = new memory_TB("TB");
	sc_trace_file* VCDFile;
	VCDFile = sc_create_vcd_trace_file("Waveform");

	sc_trace(VCDFile, TOP->clk, "clk");
	sc_trace(VCDFile, TOP->rst, "rst");
	sc_trace(VCDFile, TOP->read1, "read1");
	sc_trace(VCDFile, TOP->read2, "read2");
	sc_trace(VCDFile, TOP->read3, "read3");
	sc_trace(VCDFile, TOP->addr_rd1, "addr_rd1");
	sc_trace(VCDFile, TOP->addr_rd2, "addr_rd2");
	sc_trace(VCDFile, TOP->addr_rd3, "addr_rd3");
	sc_trace(VCDFile, TOP->addr_wr, "addr_wr");
	sc_trace(VCDFile, TOP->data_rd1, "data_rd1");
	sc_trace(VCDFile, TOP->data_rd2, "data_rd2");
	sc_trace(VCDFile, TOP->data_rd3, "data_rd3");
	*/

	cnn_TB* TOP = new cnn_TB("TB");
	sc_trace_file* VCDFile;
	VCDFile = sc_create_vcd_trace_file("Waveform");

	sc_trace(VCDFile, TOP->clk, "clk");
	sc_trace(VCDFile, TOP->rst, "rst");
	sc_trace(VCDFile, TOP->start, "start");
	sc_trace(VCDFile, TOP->pattern, "pattern");
	sc_trace(VCDFile, TOP->cnn_blk->conv_blk1->conv_cntrl->load_data, "load_data"); 
	sc_trace(VCDFile, TOP->cnn_blk->conv_blk1->conv_dp->s_dec, "s_dec"); 
	//sc_trace(VCDFile, TOP->cnn_blk->conv_blk1->conv_dp->k0, "K00");
	//sc_trace(VCDFile, TOP->cnn_blk->conv_blk1->conv_dp->k1, "K01");
	//sc_trace(VCDFile, TOP->cnn_blk->conv_blk1->conv_dp->k2, "K02");
	//sc_trace(VCDFile, TOP->cnn_blk->conv_blk1->conv_dp->k3, "K03");
	//sc_trace(VCDFile, TOP->cnn_blk->conv_blk1->conv_dp->bias, "bias");
	sc_trace(VCDFile, TOP->cnn_blk->conv_blk1->conv_dp->s_cnt_4, "s_cnt_4");
	sc_trace(VCDFile, TOP->cnn_blk->conv_blk1->conv_dp->s_cnt_4_LOWER, "s_cnt_4_LOWER");
	sc_trace(VCDFile, TOP->cnn_blk->conv_blk1->conv_dp->s_dec_0, "s_dec_0");
	sc_trace(VCDFile, TOP->cnn_blk->conv_blk1->conv_dp->s_dec_1, "s_dec_1");
	sc_trace(VCDFile, TOP->cnn_blk->conv_blk1->conv_dp->s_dec_2, "s_dec_2");
	sc_trace(VCDFile, TOP->cnn_blk->conv_blk1->conv_dp->s_dec_3, "s_dec_3");
	sc_trace(VCDFile, TOP->cnn_blk->conv_blk1->conv_dp->val0, "val0");
	sc_trace(VCDFile, TOP->cnn_blk->conv_blk1->conv_dp->s_data, "s_data");
	sc_trace(VCDFile, TOP->cnn_blk->conv_blk1->conv_dp->s_add_out, "s_add_out");
	sc_trace(VCDFile, TOP->cnn_blk->conv_blk1->conv_dp->s_add1, "s_add1");
	sc_trace(VCDFile, TOP->cnn_blk->conv_blk1->conv_dp->s_add2, "s_add2");
	sc_trace(VCDFile, TOP->cnn_blk->conv_blk1->conv_dp->sel4, "sel4");
	sc_trace(VCDFile, TOP->cnn_blk->conv_blk1->conv_cntrl->state_num, "state_num");
	sc_trace(VCDFile, TOP->cnn_blk->conv_blk1->conv_dp->s_cnt_9, "s_cnt_9");
	sc_trace(VCDFile, TOP->cnn_blk->conv_blk1->conv_dp->s_cnt_9_LOWER, "s_cnt_9_LOWER");
	sc_trace(VCDFile, TOP->cnn_blk->conv_blk1->conv_dp->s_mux9to1, "s_mux9to1");


	sc_trace(VCDFile, TOP->done, "done");

	std::cout << "Sim Start!\n";
	sc_start(6000, SC_NS);
	std::cout << "Sim Done!\n";
	return 0;
}