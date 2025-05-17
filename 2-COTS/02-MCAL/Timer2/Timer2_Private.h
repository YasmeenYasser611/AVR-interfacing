/*
 * Timer2_Private.h
 *
 * Created: 3/5/2025 11:02:50 AM
 *  Author: TUF
 */ 


#ifndef TIMER2_PRIVATE_H_
#define TIMER2_PRIVATE_H_

#include "STD_TYPES.h"

/* Timer/Counter2 Registers */
#define TCCR2   (*(volatile u8*)0x45)  // Timer/Counter Control Register
#define TCNT2   (*(volatile u8*)0x44)  // Timer/Counter Register
#define OCR2    (*(volatile u8*)0x43)  // Output Compare Register
#define TIMSK   (*(volatile u8*)0x59)  // Timer/Counter Interrupt Mask Register
#define TIFR    (*(volatile u8*)0x58)  // Timer/Counter Interrupt Flag Register
#define SREG    (*(volatile u8*)0x5F)  // Status Register (Global Interrupt Enable)

/* TCCR2 Register Bits */
#define CS20    0
#define CS21    1
#define CS22    2
#define WGM21   3
#define COM20   4
#define COM21   5
#define WGM20   6
#define FOC2    7

/* TIMSK Register Bits */
#define TOIE2   6
#define OCIE2   7

/* Bit Masks */
#define CS2_MASK   ((1 << CS22) | (1 << CS21) | (1 << CS20))
#define WGM2_MASK  ((1 << WGM21) | (1 << WGM20))
#define TOIE2_MASK (1 << TOIE2)
#define OCIE2_MASK (1 << OCIE2)

/* Global Pointer to Function for Callback */
extern void (*Timer2_PFUN)(void);

#endif /* TIMER2_PRIVATE_H_ */
