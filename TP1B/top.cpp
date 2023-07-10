#include "systemc.h"
#include "top.h"

/* define the top module, containing all other submodules */

/* constructor of the top module, calling also the constructors of its submodules */

top::top (sc_module_name name) : sc_module (name),
    fifo1 ("fifo1"), bitGen1 ("bitGen1"), bit2Byte1 ("bit2Byte1"), consumer1 ("consumer1")
{
    bitGen1.data_out (data);
    bitGen1.rdy (rdy);
    bitGen1.ack (ack);

    bit2Byte1.data_in (data);
    bit2Byte1.rdy (rdy);
    bit2Byte1.ack (ack);
    bit2Byte1.out (fifo1);

    consumer1.in (fifo1);
}
