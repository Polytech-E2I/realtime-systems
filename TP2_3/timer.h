
#include <systemc>

#define TIMER_PERIOD 1000

using namespace sc_core;


class Timer: public sc_module
{
public:
	Timer(CPU* cpu): m_cpu{cpu}
	{}

	CPU* m_cpu;

};
