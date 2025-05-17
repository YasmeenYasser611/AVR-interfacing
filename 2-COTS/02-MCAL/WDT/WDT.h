/*
 * WDT.h
 *
 * Created: 3/11/2025 4:53:10 PM
 *  Author: TUF
 */ 

#ifndef WDT_H_
#define WDT_H_

#include "STD_TYPES.h" 

/* -------------------- WDT Timeout Configuration -------------------- */
#define WDT_TIMEOUT_16MS    (0b000)
#define WDT_TIMEOUT_32MS    (0b001)
#define WDT_TIMEOUT_65MS    (0b010)
#define WDT_TIMEOUT_130MS   (0b011)
#define WDT_TIMEOUT_260MS   (0b100)
#define WDT_TIMEOUT_520MS   (0b101)
#define WDT_TIMEOUT_1S      (0b110)
#define WDT_TIMEOUT_2S      (0b111)

/* -------------------- WDT Function Prototypes -------------------- */
void WDG_Sleep(u8 timeout);
void WDG_TurnON(void);
void WDG_TurnOff(void);

#endif  /* WDT_H_ */
