#include "systemc.h"
#include "consumer.h"

/* define the Consumer module */

/* constructor */

Consumer::Consumer(sc_module_name name)
{
    SC_THREAD(thConsume);				// thConsume is a thread
}

void Consumer::thConsume()
{
    char c = '\0';

    while(true)
    {
        in->read(c);
        printf("Caractère lu : %c\n", c);

        wait(2, SC_NS);
    }
}
