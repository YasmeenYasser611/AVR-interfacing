/*
 * Timer0_Private.h
 *
 * Created: 3/3/2025 8:08:23 PM
 *  Author: TUF
 */ 
#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

#include "STD_TYPES.h"

/* Timer/Counter0 Registers */
#define TCCR0   (*(volatile u8*)0x53)  // Timer/Counter Control Register
#define TCNT0   (*(volatile u8*)0x52)  // Timer/Counter Register
#define OCR0    (*(volatile u8*)0x5C)  // Output Compare Register
#define TIMSK   (*(volatile u8*)0x59)  // Timer/Counter Interrupt Mask Register
#define TIFR    (*(volatile u8*)0x58)  // Timer/Counter Interrupt Flag Register
#define SREG    (*(volatile u8*)0x5F)  // Status Register (Global Interrupt Enable)

/* TCCR0 Register Bits */
#define CS00    0  // Clock Select Bit 0
#define CS01    1  // Clock Select Bit 1
#define CS02    2  // Clock Select Bit 2
#define WGM01   3  // Waveform Generation Mode Bit 1
#define COM00   4  // Compare Match Output Mode Bit 0
#define COM01   5  // Compare Match Output Mode Bit 1
#define WGM00   6  // Waveform Generation Mode Bit 0
#define FOC0    7  // Force Output Compare

/* TIMSK Register Bits */
#define TOIE0   0  // Timer/Counter0 Overflow Interrupt Enable
#define OCIE0   1  // Timer/Counter0 Output Compare Match Interrupt Enable

/* Bit Masks */
#define CS_MASK   ((1 << CS02) | (1 << CS01) | (1 << CS00))  // Mask for Clock Select Bits
#define WGM_MASK  ((1 << WGM01) | (1 << WGM00))  // Mask for Waveform Generation Mode
#define TOIE_MASK (1 << TOIE0)  // Overflow Interrupt Enable Mask
#define OCIE_MASK (1 << OCIE0)  // Compare Match Interrupt Enable Mask

/* Global Pointer to Function for Callback */
extern void (*Timer_PFUN)(void);

#endif /* TIMER0_PRIVATE_H_ */

