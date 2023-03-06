#include "systemc.h"
#include "fifo.h"

/* define the FIFO channel */

/* constructor */

FIFO::FIFO(sc_module_name name) : sc_channel(name), num_elements(0), first(0)
{
}

/* read_if implementation: definitions */

void FIFO::read(char &c)
{
	/* to be completed - exercise 4 */
}

int FIFO::num_available()
{
	return num_elements; 
}

/* write_if implementation: definitions */

void FIFO::write(char c)
{
	if (num_elements == max)					// if FIFO is full
	{
		printf("[%lu] FIFO is full. Writer waiting...\n", (unsigned long)sc_simulation_time());
		wait(read_event);						// wait for a reading event (which frees a position in the FIFO)
		printf("[%lu] FIFO is no longer full.\n", (unsigned long)sc_simulation_time());
	}
	
	data[(first + num_elements) % max] = c;		// write to the next position (in a circular manner) the new element		
	num_elements ++;							// updates the number of elements in the FIFO
	write_event.notify();						// notifies the write_event
}

void FIFO::reset()
{
	num_elements = first = 0;
}
