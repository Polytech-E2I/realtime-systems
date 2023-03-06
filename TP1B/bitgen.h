#ifndef bitgen_h
#define bitgen_h

/* declare the BitGen module */

class BitGen : public sc_module
{
public: 
	SC_HAS_PROCESS(BitGen);
	BitGen(sc_module_name name);

public:
	void thProduce();

public:
	/* to be completed - exercise 2 - add the ports */

};

#endif
