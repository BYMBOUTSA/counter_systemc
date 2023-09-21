#include "helper_fct.h"
#include "user.h"


void user::user_thread() {

    // SCENARIOS

    // Initialisation
    DISPLAY("RUNNING TEST...");
    period->write(10);
    reset->write(false);
    up_down->write(false);
    load->write(false);
    data_in->write(0);
    wait(1, SC_NS);

    // RESET
    DISPLAY("RESET");
    reset->write(true);
    wait(15, SC_NS);

    // COUNT_DOWN
    DISPLAY("COUNT_DOWN");
    reset->write(false);
    wait(100, SC_NS);

    // LOAD
    DISPLAY("LOAD");
    load->write(3);
    wait(20, SC_NS);
    load->write(false);

    // COUNT_DOWN
    DISPLAY("COUNT_DOWN");
    wait(100, SC_NS);

    // COUNT_UP
    DISPLAY("COUNT_UP");
    reset->write(true);
    wait(140, SC_NS);

    // CHANGE_PERIOD
    DISPLAY("CHANGE_PERIOD");
    period->write(30);

}