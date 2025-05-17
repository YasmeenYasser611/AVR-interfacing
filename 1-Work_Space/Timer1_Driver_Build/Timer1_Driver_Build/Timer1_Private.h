/*
 * Timer1_Private.h
 *
 * Created: 3/5/2025 1:12:06 PM
 *  Author: TUF
 */ 


#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_

#include "STD_TYPES.h"

/* Timer1 Registers */
#define TCCR1A (*(volatile u8*)0x4F)
#define TCCR1B (*(volatile u8*)0x4E)
#define TCNT1  (*(volatile u16*)0x4C)
#define OCR1A  (*(volatile u16*)0x4A)
#define OCR1B  (*(volatile u16*)0x48)
#define ICR1   (*(volatile u16*)0x46)
#define TIMSK  (*(volatile u8*)0x59)
#define TIFR   (*(volatile u8*)0x58)

/* Bit Positions */
#define WGM10   0
#define WGM11   1
#define COM1B0  4
#define COM1B1  5
#define COM1A0  6
#define COM1A1  7
#define WGM12   3
#define WGM13   4
#define CS10    0
#define CS11    1
#define CS12    2

/* Interrupt Masks */
#define TOIE1 2
#define OCIE1A 4
#define OCIE1B 3

#endif /* TIMER1_PRIVATE_H_ */
