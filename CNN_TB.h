#include <systemc.h>
#include "CNN.h"

#define CLK_ON 5
#define CLK_OFF 5
#define RST_TIME 2

SC_MODULE(cnn_TB)
{
	sc_signal<sc_logic>	rst, clk, write, done, start;
	sc_signal<sc_lv<8>>	data_wr;
	sc_signal<sc_lv<4>>	addr_wr;
	sc_signal<sc_lv<3>>	pattern;
	cnn* cnn_blk;
	SC_CTOR(cnn_TB)
	{

		cnn_blk = new cnn("cnn");
		cnn_blk->clk(clk);
		cnn_blk->rst(rst);
		cnn_blk->done(done);
		cnn_blk->start(start);
		cnn_blk->pattern(pattern);
		cnn_blk->addr_write(addr_wr);
		cnn_blk->data_wr(data_wr);


		SC_THREAD(clocking);
		SC_THREAD(resetting);
		SC_THREAD(testing_CNN);
		SC_THREAD(display);
		//sensitive << clk;


	}
	void clocking();
	void resetting();
	void testing_CNN();
	void display();


};