#include "counter.h"
#include "helper_fct.h"

void counter::counter_thread() {
    DISPLAY("Running Counter Thread");

    for(;;) {
        
        wait(period->read(), SC_NS, reset->posedge_event());

        if(reset->read() == true) {
            Q.write(0);
        } else if (load->read() == true) {
            Q.write(data_in->read());
        } else {
            // On regarde si on compte
            if(up_down->read() == true) {
                Q.write((Q->read() + 1) % 10);
            } else {
                Q->write(Q->read() == 0 ? 9 : Q->read() - 1);
            }
        }
        // DISPLAY DATAS
        DISPLAY(load);
        cout << "Count = " << Q << endl;
    }
}