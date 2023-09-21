#ifndef USER_H_
#define USER_H_


#include <systemc.h>
#include "helper_fct.h"

SC_MODULE(user) {

    // DECLARATIONS
    sc_out<double> period;
    sc_out<bool> reset;
    sc_out<bool> up_down;
    sc_out<bool> load;
    sc_out<int> data_in;

    // DATAS


    // CONSTRUCTOR
    SC_CTOR(user) : period("period"),
                    reset("reset"),
                    up_down("up_down"),
                    load("load"),
                    data_in("data_in")
    {
        DISPLAY("THREAD Registration");
        // REGISTRATING THE THREAD
        // Save the thread
        SC_THREAD(user_thread);
    }

    // Process
    void user_thread();

};

#endif