/*
 * WDT.c
 *
 * Created: 3/11/2025 4:57:48 PM
 *  Author: TUF
 */ 



#include "WDT.h"
#include "WDT_Private.h"


/* Enable Watchdog Timer (without modifying timeout) */
void WDG_TurnON(void)
{
	WDTCR |= (1 << WDE); 
}

/* Disable Watchdog Timer */
void WDG_TurnOff(void)
{
	WDTCR |= (1 << WDTOE) | (1 << WDE);  // Step 1: Set WDTOE & WDE
	WDTCR = 0x00;  // Step 2: Clear WDE within 4 clock cycles
}

/* Set Watchdog Timer timeout (does NOT enable the WDT) */
void WDG_Sleep(u8 timeout)
{
	WDTCR = (WDTCR & WDT_MASK) | (timeout & 0x07);  // Clear WDP bits & Set new timeout
}