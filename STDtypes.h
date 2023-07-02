/*
 * STDtypes.h
 *
 * Created: 6/4/2022 2:05:02 AM
 *  Author: dee
 */ 


#ifndef STDTYPES_H_
#define STDTYPES_H_
#define F_CPU 8000000UL // freq of cpu
#define SETBIT(reg, bit) reg |= (1 << bit) //makes bit 1
#define CLEARBIT(reg, bit) reg &= ~(1 << bit) //makes bit 0
#define READBIT(reg, bit) ((reg >> bit) & 1) //checks if bit is 0 or 1

#endif /* STDTYPES_H_ */