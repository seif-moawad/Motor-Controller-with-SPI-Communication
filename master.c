/*
 * remote.c
 *
 * Created: 6/4/2022 4:11:07 PM
 *  Author: dee
 */
#include "STDtypes.h"
#include "master.h"
#include "spi.h"

#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

void master_main(void)
{//initialize master
    char tdata, rdata;
	SPI_VidInt(MASTER);
	DDRD = 0;//all input

    while (1)
    {
        SPI_vidSalveSelect();

		tdata = 0;
		
        if (READBIT(PIND, PD6) == 1) //if button is pressed speedup
        {
            tdata = 1;
        }
        
		if (READBIT(PIND, PD7) == 1)//speed down
        {
            tdata = 2;
        }
		
		rdata = SPI_TransRec(tdata);//transmit info to slave

        _delay_ms(700);
    }
}