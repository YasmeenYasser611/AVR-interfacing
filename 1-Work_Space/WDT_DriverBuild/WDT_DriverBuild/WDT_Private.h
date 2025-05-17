/*
 * WDT_Private.h
 *
 * Created: 3/11/2025 4:53:30 PM
 *  Author: TUF
 */ 

#ifndef WDT_PRIVATE_H_
#define WDT_PRIVATE_H_

#define WDTCR  *((volatile u8 *)(0x41))  // Watchdog Timer Control Register

#define WDTOE  4  // Watchdog Turn-Off Enable
#define WDE    3  // Watchdog Enable
#define WDP2   2  // Watchdog Prescaler Bit 2
#define WDP1   1  // Watchdog Prescaler Bit 1
#define WDP0   0  // Watchdog Prescaler Bit 0

#define WDT_MASK  0xF8  // Mask to clear WDP2:WDP0 bits (11111000)

#endif /* WDT_PRIVATE_H_ */
