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
	/* to be completed - exercise 5 - read a data by its in port and display it */
}
