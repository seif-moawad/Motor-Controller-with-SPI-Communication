#define F_CPU 8000000UL

#include "STDtypes.h"

#include <avr/interrupt.h>
#include <avr/io.h>
#include "slave.h"
#include "master.h"
#include "spi.h"


int main(void)
{
	//slave_main();
	master_main();
	return 0;
}