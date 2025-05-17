/*
 * Timer0_DriverBuild.c
 *
 * Created: 3/3/2025 7:55:53 PM
 * Author : TUF
 */ 

#include "Timer2.h"
#include "HLED.h"
#include "HLCD.h"

#define F_CPU 8000000UL  // Assume 8MHz system clock
#define REQUIRED_TIME 1   // 1ms
#define TIMER_RESOLUTION 8  // 8-bit Timer2
#define PRESCALER 8

void Timer2_Callback(void)
{
	static HLED_enuState_t led_state = HLED_enuOFF;  // Track LED state
	led_state = (led_state == HLED_enuOFF) ? HLED_enuON : HLED_enuOFF;
	HLED_enuSetLedState(Led_start, led_state);
}

int main(void)
{
	HLED_vLED_init();
	HLCD_vLCD_init();

	if (Timer2_Config.mode == TIMER2_OVF_MODE)
	{
		Timer2_CalculateNormalConfig(REQUIRED_TIME, F_CPU, TIMER_RESOLUTION, PRESCALER);
	}
	else if (Timer2_Config.mode == TIMER2_CTC_MODE)
	{
		Timer2_CalculateCTCConfig(REQUIRED_TIME, F_CPU, PRESCALER, 199);
	}

	Timer2_Init();
	Timer2_SETCallBack(Timer2_Callback);

	// Display calculated values on LCD
	HLCD_enuLCD_WriteNumber(LCD1, Timer2_GetPreloadOrCompare());
	HLCD_enuLCD_WriteNumber(LCD1, Timer2_GetNumOVFOrCompareMatches());
	HLCD_enuLCD_WriteNumber(LCD1, Timer2_GetCompareMatchValue());

	while (1);
}
