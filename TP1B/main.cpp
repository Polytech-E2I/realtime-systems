#include "systemc.h"
#include "top.h"

int sc_main (int argc, char* argv[])
{
    top top1 ("top1");							// instance of the top module

    sc_trace_file *tf;							// declare a trace file
    tf = sc_create_vcd_trace_file("trace");		// create a trace file

                                                /* specify signals to be traced */
    sc_trace(tf, top1.data, "data");
    sc_trace(tf, top1.rdy, "rdy");
    sc_trace(tf, top1.ack, "ack");

    sc_start ();								// start simulation

    sc_close_vcd_trace_file(tf);				// close the trace file

    return 0;
}