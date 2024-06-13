#include <systemc.h>
#include "CNN.h"

#define CLK_ON 10
#define CLK_OFF 10
#define RST_TIME 15

SC_MODULE(cnn_TB)
{
	sc_signal<sc_logic>	rst, clk, write, done, start;
	sc_signal<sc_lv<8>>	data_wr;
	sc_signal<sc_lv<4>>	addr_wr;
	sc_signal<sc_lv<3>>	pattern;
	cnn* cnn_blk;

	SC_CTOR(cnn_TB)
	{
		//std::cout << "CNN_TB.h SC_CTOR(cnn_TB)\n";

		
		cnn_blk = new cnn("cnn");
		cnn_blk->clk(clk);
		cnn_blk->rst(rst);
		cnn_blk->done(done);
		cnn_blk->start(start);
		cnn_blk->pattern(pattern);
		cnn_blk->addr_write(addr_wr);
		cnn_blk->data_wr(data_wr);
		//std::cout << "CNN_TB.h cnn_blk = new cnn\n";

		
		SC_THREAD(cnn_clocking);
		//std::cout << "SC_THREAD(clocking);\n";
		SC_THREAD(cnn_resetting);
		//std::cout << "SC_THREAD(resetting);\n";
		SC_THREAD(cnn_testing);
		//std::cout << "SC_THREAD(testing_CNN);\n";
		SC_THREAD(cnn_display);
		//std::cout << "SC_THREAD(display);\n";
		//sensitive << clk;


	}
	void cnn_clocking();
	void cnn_resetting();
	void cnn_testing();
	void cnn_display();


};