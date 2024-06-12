#include <systemc.h>
#include "CONV_BLOCK.h"
#include "ELEMENTS.h"

#define NUM_OF_CONVS 3

SC_MODULE(cnn){
	sc_in <sc_logic> clk, rst, start;
	sc_out <sc_logic> done;
	sc_out <sc_lv<3>> pattern;
	sc_in <sc_lv<8>> data_wr;
	sc_in <sc_lv<4>> addr_write;

	sc_signal <sc_lv<8>> data_rd[NUM_OF_CONVS], val_0[NUM_OF_CONVS], val_1[NUM_OF_CONVS], val_2[NUM_OF_CONVS], val_3[NUM_OF_CONVS];
	sc_signal <sc_lv<8>> relu_0[NUM_OF_CONVS], relu_1[NUM_OF_CONVS], relu_2[NUM_OF_CONVS], relu_3[NUM_OF_CONVS], max[NUM_OF_CONVS];
	sc_signal <sc_logic> read[NUM_OF_CONVS], done_conv[NUM_OF_CONVS];
	sc_signal <sc_lv<4>> addr_rd[NUM_OF_CONVS];


	conv_block* conv_blk1;
	conv_block* conv_blk2;
	conv_block* conv_blk3;
	relu* relu1;
	relu* relu2;
	relu* relu3;
	maxpool* maxpool1;
	maxpool* maxpool2;
	maxpool* maxpool3;
	result* result_blk;
	Memory<4, 8>* MEM;

	SC_CTOR(cnn){
		sc_signal<sc_logic> BIT_0, BIT_1;
		BIT_0.write(SC_LOGIC_0);
		BIT_1.write(SC_LOGIC_1);



		conv_blk1 = new conv_block("conv_blk1");
		conv_blk1->clk(clk);
		conv_blk1->rst(rst);
		conv_blk1->read(read[0]);
		conv_blk1->done_conv(done_conv[0]);
		conv_blk1->start_conv(start);
		conv_blk1->data_rd(data_rd[0]);
		conv_blk1->addr_rd(addr_rd[0]);
		conv_blk1->val_0(val_0[0]);
		conv_blk1->val_1(val_1[0]);
		conv_blk1->val_2(val_2[0]);
		conv_blk1->val_3(val_3[0]);

		conv_blk2 = new conv_block("conv_blk2");
		conv_blk2->clk(clk);
		conv_blk2->rst(rst);
		conv_blk2->read(read[1]);
		conv_blk2->done_conv(done_conv[1]);
		conv_blk2->start_conv(start);
		conv_blk2->data_rd(data_rd[1]);
		conv_blk2->addr_rd(addr_rd[1]);
		conv_blk2->val_0(val_0[1]);
		conv_blk2->val_1(val_1[1]);
		conv_blk2->val_2(val_2[1]);
		conv_blk2->val_3(val_3[1]);

		conv_blk3 = new conv_block("conv_blk3");
		conv_blk3->clk(clk);
		conv_blk3->rst(rst);
		conv_blk3->read(read[2]);
		conv_blk3->done_conv(done_conv[2]);
		conv_blk3->start_conv(start);
		conv_blk3->data_rd(data_rd[2]);
		conv_blk3->addr_rd(addr_rd[2]);
		conv_blk3->val_0(val_0[2]);
		conv_blk3->val_1(val_1[2]);
		conv_blk3->val_2(val_2[2]);
		conv_blk3->val_3(val_3[2]);

		relu1 = new relu("relu1");
		relu1->in0(val_0[0]);
		relu1->in1(val_0[0]);
		relu1->in2(val_0[0]);
		relu1->in3(val_0[0]);
		relu1->val0(relu_0[0]);
		relu1->val1(relu_1[0]);
		relu1->val2(relu_2[0]);
		relu1->val3(relu_3[0]);

		relu2 = new relu("relu2");
		relu2->in0(val_0[1]);
		relu2->in1(val_0[1]);
		relu2->in2(val_0[1]);
		relu2->in3(val_0[1]);
		relu2->val0(relu_0[1]);
		relu2->val1(relu_1[1]);
		relu2->val2(relu_2[1]);
		relu2->val3(relu_3[1]);

		relu3 = new relu("relu3");
		relu3->in0(val_0[2]);
		relu3->in1(val_0[2]);
		relu3->in2(val_0[2]);
		relu3->in3(val_0[2]);
		relu3->val0(relu_0[2]);
		relu3->val1(relu_1[2]);
		relu3->val2(relu_2[2]);
		relu3->val3(relu_3[2]);

		maxpool1 = new maxpool("maxpool1");
		maxpool1->in0(relu_0[0]);
		maxpool1->in0(relu_1[0]);
		maxpool1->in0(relu_2[0]);
		maxpool1->in0(relu_3[0]);
		maxpool1->max(max[0]);

		maxpool2 = new maxpool("maxpool2");
		maxpool2->in0(relu_0[1]);
		maxpool2->in0(relu_1[1]);
		maxpool2->in0(relu_2[1]);
		maxpool2->in0(relu_3[1]);
		maxpool2->max(max[1]);

		maxpool3 = new maxpool("maxpool3");
		maxpool3->in0(relu_0[2]);
		maxpool3->in0(relu_1[2]);
		maxpool3->in0(relu_2[2]);
		maxpool3->in0(relu_3[2]);
		maxpool3->max(max[2]);

		result_blk = new result("result_blk");
		result_blk->in0(max[0]);
		result_blk->in1(max[1]);
		result_blk->in2(max[2]);
		result_blk->pattern(pattern);

		MEM = new Memory<4, 8>("Memory");
		MEM->clk(clk);
		MEM->write_en(BIT_0);
		MEM->read1(read[0]);
		MEM->read2(read[1]);
		MEM->read3(read[2]);
		MEM->addr_rd1(addr_rd[0]);
		MEM->addr_rd2(addr_rd[1]);
		MEM->addr_rd3(addr_rd[2]);
		MEM->data_rd1(data_rd[0]);
		MEM->data_rd2(data_rd[1]);
		MEM->data_rd3(data_rd[2]);
		MEM->data_wr(data_wr);



	}
};