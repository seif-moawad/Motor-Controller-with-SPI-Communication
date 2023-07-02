/*
 * spi.c
 *
 * Created: 6/4/2022 4:32:13 PM
 *  Author: dee
 */
#include "STDtypes.h"
#include "spi.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

void SPI_VidInt(SPIMODE_t mode)
{
    if (mode == MASTER)
    {
        SETBIT(DDRB, 4);   // SS
        SETBIT(DDRB, 5);   // MOSI
        SETBIT(DDRB, 7);   // sck
        CLEARBIT(DDRB, 6); // MISO
        SETBIT(PORTB, 4);
        SETBIT(SPCR, MSTR);
    }
    else if (mode == SLAVE)
    {
        CLEARBIT(DDRB, 4); // SS
        CLEARBIT(DDRB, 5); // MOSI
        CLEARBIT(DDRB, 7); // sck
        SETBIT(DDRB, 6);   // MISO
        CLEARBIT(SPCR, MSTR);
    }

    SETBIT(SPCR, SPE);
}

char SPI_TransRec(char data)
{
    SPDR = data;
    while (!READBIT(SPSR, SPIF))
        ;
    return SPDR;
}

void SPI_vidSalveSelect()
{
    CLEARBIT(PORTB, 4);
}
void SPI_vidNSalveSelect()
{
    SETBIT(PORTB, 4);
}