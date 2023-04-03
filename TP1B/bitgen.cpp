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
}
