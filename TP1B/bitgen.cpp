#include "systemc.h"
#include "bitgen.h"
#include <bitset>

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

    std::ifstream source{ "a.txt"};

    if(!source)
    {
        std::cerr << "Unable to open file" << std::endl;
        exit(EXIT_FAILURE);
    }

    char current_byte = '\0';

    while(source)
    {
        source.read(&current_byte, 1);

        // std::bitset<8> x(current_byte);
        // std::cout << "Read byte " << current_byte << " (" << x << ") from file" << std::endl;

        for(int i = 0 ; i < 8 ; ++i)
        {
            data_out = ( current_byte >> i ) & 0x1;

            // std::cout << data_out;

            rdy = 1;

            if( ack == false )
            {
                wait( ack.posedge_event() );
            }

            rdy = 0;

            wait(2, SC_NS);

            if( ack == true )
            {
                wait( ack.negedge_event() );
            }
            wait(2, SC_NS);
        }

        // std::cout << std::endl;
    }
}
