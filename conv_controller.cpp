#include "CONV_CONTROLLER.h"

void conv_controller::comb_O_function(){
	read = SC_LOGIC_0;
	done_conv = SC_LOGIC_0;
	en_j = SC_LOGIC_0;
	en_9 = SC_LOGIC_0;
	en_4 = SC_LOGIC_0;
	load_data = SC_LOGIC_0;
	load_addr = SC_LOGIC_0;
	clr_data = SC_LOGIC_0;
	clr_addr = SC_LOGIC_0;
	en_dec = SC_LOGIC_0;
	sel3 = SC_LOGIC_0;
	sel4 = SC_LOGIC_0;
	sel1 = "00"; 
	sel2 = "00";

	switch (p_state){
	case IDLE:
		done_conv = SC_LOGIC_1;
		state_num = 0;
		break;
	case START:
		state_num = 1;

		break;
	case ADDR1:
		load_addr = SC_LOGIC_1;
		en_j = SC_LOGIC_1;
		state_num = 2;

		break;
	case ADDR2:
		sel1 = "10";
		load_addr = SC_LOGIC_1;
		state_num = 3;

		break;
	case ADDR3:
		sel1 = "01";
		load_addr = SC_LOGIC_1;
		state_num = 4;

		break;
	case ADDR4:
		sel1 = "10";
		sel2 = "01";
		load_addr = SC_LOGIC_1;
		state_num = 5;

		break;
	case CALCULATE1:
		read = SC_LOGIC_1;
		state_num = 6;

		break;
	case CALCULATE2:
		sel1 = "10";
		sel2 = "10";
		sel3 = SC_LOGIC_1;
		sel4 = SC_LOGIC_1;
		load_data = SC_LOGIC_1;
		clr_addr = SC_LOGIC_1;
		en_9 = SC_LOGIC_1;
		state_num = 7;

		break;
	case CALCULATE3:
		sel1 = "11";
		sel4 = SC_LOGIC_1;
		load_data = SC_LOGIC_1;
		state_num = 9;

		break;
	case WRITE1:
		en_4 = SC_LOGIC_1;
		en_dec = SC_LOGIC_1;
		clr_data = SC_LOGIC_1;
		state_num = 10;

		break;
	case WRITE2:
		state_num = 11;

		break;
	case WAIT:
		state_num = 8;

		break;
	default:
		read = SC_LOGIC_0;
		done_conv = SC_LOGIC_0;
		en_j = SC_LOGIC_0;
		en_9 = SC_LOGIC_0;
		en_4 = SC_LOGIC_0;
		load_data = SC_LOGIC_0;
		load_addr = SC_LOGIC_0;
		clr_data = SC_LOGIC_0;
		clr_addr = SC_LOGIC_0;
		en_dec = SC_LOGIC_0;
		sel3 = SC_LOGIC_0;
		sel4 = SC_LOGIC_0;
		sel1 = "00";
		sel2 = "00";
	}
	//std::cout << "conv_controller.cpp conv_controller::comb_O_function(){\n";

}

void conv_controller::comb_S_function(){
	n_state = IDLE;
	switch (p_state){
	case IDLE:
		if (start_conv == '1') n_state = START;
		else n_state = IDLE;
		break;
	case START:
		if (start_conv == '0') n_state = ADDR1;
		else n_state = START;
		break;
	case ADDR1:
		n_state = ADDR2;
		break;
	case ADDR2:
		n_state = ADDR3;
		break;
	case ADDR3:
		n_state = ADDR4;
		break;
	case ADDR4:
		n_state = CALCULATE1;
		break;
	case CALCULATE1:
		n_state = CALCULATE2;
		break;
	case CALCULATE2:
		n_state = WAIT;
		break;
	case WAIT:
		if (cmp_9 == '0') n_state = ADDR1;
		else n_state = CALCULATE3;
		break;
	case CALCULATE3:
		n_state = WRITE1;
		break;
	case WRITE1:
		n_state = WRITE2;
		break;
	case WRITE2:
		if (cmp_4 == '1') n_state = IDLE;
		else n_state = ADDR1;
		break;
	default:
		n_state = IDLE;
	}
	//std::cout << "conv_controller.cpp void conv_controller::comb_S_function(){\n";

}

void conv_controller::seq_function(){
	while (1)
	{
		if (rst == '1')
			p_state = IDLE;
		else if (clk->event() && (clk=='1'))
			p_state = n_state;
		wait();
	}
	//std::cout << "conv_controller.cpp void conv_controller::seq_function(){\n";

}