#include "systemc.h"
#include "bitgen.h"

/* define the BitGen module */

/* constructor */

BitGen::BitGen (sc_module_name name) : sc_module (name)
{
    SC_THREAD (thProduce);
}

/* definition of the thread thProduce */
void BitGen::thProduce()
{
    /* to be completed - exercise 3 */

    std::ifstream source{ "a.txt "};

    if(!source)
    {
        std::cerr << "Unable to open file" << std::endl;
        exit(EXIT_FAILURE);
    }

    while(true)
    {
        data_out = 1;
        rdy = 1;

        if( ack == false )
        {
            wait( ack.posedge_event() );
        }

        rdy = 0;

        if( ack == true )
        {
            wait( ack.negedge_event() );
        }
    }
}
