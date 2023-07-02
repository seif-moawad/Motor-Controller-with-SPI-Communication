/*
 * controller.c
 *
 * Created: 6/4/2022 3:43:11 AM
 *  Author: dee
 */
#include "STDtypes.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
#include "slave.h"
#include "spi.h"

char s;

void slave_main(void)
{
	//initialize slave ports
    char tdata, rdata;
    SPI_VidInt(SLAVE);

    s = 0;
    DDRC = 0xff; //all output
    OCR0 = s;
    TCCR0 = 0x64;
    MCUCR = 0x02;
    MCUCSR = 0x00;

    SETBIT(DDRD, PD7);
    SETBIT(DDRB, PB3);

    while (1)
    {
		tdata = 0;
        rdata = SPI_TransRec(tdata); //transmitting 0 from master to slave
        if (rdata == 1) //first button for speedup was pressed
        {
            s += 10;
        }
        else if (rdata == 2)// slow down was pressed
        {
            if (s != 0)
            {
                s -= 10;
            }
        }

        PORTC = 0x01;//transmit 1 in portC
        OCR0 = s; //send speed to motor controller
    }
}