/*
 * Timer0_DriverBuild.c
 *
 * Created: 3/3/2025 7:55:53 PM
 * Author : TUF
 */ 


#include "Timer1.h"
#include "HLED.h"
#include "HLCD.h"


#define F_CPU 8000000UL  // Assume 8MHz system clock
#define REQUIRED_TIME 0.5   // 1ms
#define TIMER_RESOLUTION 16  // 16-bit Timer1
#define PRESCALE 8

void Timer1_Callback(void)
{
	static HLED_enuState_t led_state = HLED_enuOFF;  // Track LED state
	led_state = (led_state == HLED_enuOFF) ? HLED_enuON : HLED_enuOFF;
	HLED_enuSetLedState(Led_start, led_state);
}

int main(void)
{
	HLED_vLED_init();
	HLCD_vLCD_init();

	// Choose the mode and calculate configuration
	if (Timer1_Config.mode == TIMER1_NORMAL_MODE)
	{
		Timer1_CalculateNormalConfig(REQUIRED_TIME, F_CPU, TIMER_RESOLUTION, PRESCALE);
	}
	else if (Timer1_Config.mode == TIMER1_CTC_MODE_OCR1A)
	{
		Timer1_CalculateCTCConfigA(REQUIRED_TIME, 199, F_CPU, PRESCALE);
	}

	// Initialize Timer1
	Timer1_Init();

	// Set callback function
	Timer1_SetCallBack_COMPA(Timer1_Callback);



	// Display the number of overflows or compare matches on LCD
	HLCD_enuLCD_WriteNumber(LCD1, Timer1_GetCompareMatchValueA());

	// If CTC mode, show the OCR1A value
	HLCD_enuLCD_WriteNumber(LCD1, Timer1_GetNumCompareMatchesA());

	while(1);

	return 0;
}
