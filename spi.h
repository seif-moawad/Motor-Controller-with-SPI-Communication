/*
 * spi.h
 *
 * Created: 6/4/2022 4:27:19 PM
 *  Author: dee
 */

#ifndef SPI_H_
#define SPI_H_

typedef enum
{
    MASTER = 0,
    SLAVE
} SPIMODE_t;

extern void SPI_VidInt(SPIMODE_t mode);
extern char SPI_TransRec(char data);
extern void SPI_vidSalveSelect();
extern void SPI_vidNSalveSelect();

#endif /* SPI_H_ */