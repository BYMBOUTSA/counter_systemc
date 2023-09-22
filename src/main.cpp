/****************************************************************************
 * Copyright (C) 2021 by Fabrice Muller                                     *
 *                                                                          *
 * This file is useful for SystemC course.                             *
 *                                                                          *
 ****************************************************************************/

/**
 * @file main.c
 * @author Fabrice Muller
 * @date 02 Nov. 2021
 * @brief Empty main program for SystemC
 *
 * @see https://github.com/fmuller-pns/systemc-vscode-project-template.git
 */

#include <systemc.h>
#include "helper_fct.h"
#include "counter.h"
#include "user.h"

int sc_main(int argc, char* argv[]) {

	sc_signal<double> period_sig;
	sc_signal<bool> reset_sig, up_down_sig, load_sig;
	sc_signal<int> data_in_sig;
	sc_signal<int> Q_sig;
	

	/* Elaboration step */
	DISPLAY("ELABORATION");

	// Instantiations and port map
	counter counter_inst("counter_inst");
			counter_inst.period(period_sig);
			counter_inst.reset(reset_sig);
			counter_inst.up_down(up_down_sig);
			counter_inst.load(load_sig);
			counter_inst.data_in(data_in_sig);
			counter_inst.Q(Q_sig);

	user user_inst("user_inst");
		 user_inst.period(period_sig);
		 user_inst.reset(reset_sig);
		 user_inst.up_down(up_down_sig);
		 user_inst.load(load_sig);
		 user_inst.data_in(data_in_sig);



	/* Simulation step */
	DISPLAY("START SIMULATION");

	sc_start(350, SC_NS);

	/* End of Simulation */
	DISPLAY("END OF SIMULATION");
				
	return 0;
}


