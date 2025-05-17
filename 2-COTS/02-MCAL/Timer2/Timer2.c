/*
 * Timer2.c
 *
 * Created: 3/5/2025 11:01:54 AM
 *  Author: TUF
 */ 
#include "Timer2.h"
#include "Timer2_private.h"
#include "Timer2_config.h"
#include "MPORT.h"
#include "GIE.h"

/* Global Pointer to Function */
void (*Timer2_PFUN)(void) = NULL;

/* Private Static Variables */
static u8 Timer2_Preload = 0;
static u8 Timer2_CompareMatchValue = 0;
static u16 Timer2_NumOVF = 0;
static u16 Timer2_NumCompareMatches = 0;

void Timer2_Init(void)
{
	/* Select Mode */
	TCCR2 &= ~WGM2_MASK;
	TCCR2 |= Timer2_Config.mode;

	/* Set Compare Output Mode */
	TCCR2 &= ~((1 << COM20) | (1 << COM21));
	TCCR2 |= Timer2_Config.compare_output_mode;

	/* Enable Timer Interrupts */
	if (Timer2_Config.mode == TIMER2_OVF_MODE)
	{
		TIMSK |= TOIE2_MASK;
		TCNT2 = Timer2_Preload;
		GIE_VoidEnable();
	}
	else if (Timer2_Config.mode == TIMER2_CTC_MODE)
	{
		TIMSK |= OCIE2_MASK;
		OCR2 = Timer2_CompareMatchValue;
		GIE_VoidEnable();
	}
	else if (Timer2_Config.mode == TIMER2_PHASE_CORRECT_PWM || Timer2_Config.mode == TIMER2_FAST_PWM)
	{
		MPORT_enuSetPinDirection(MPORT_enuPIN_D7, MPORT_enuPINOUTPUT);
	}

	/* Configure Prescaler */
	TCCR2 &= ~CS2_MASK;
	TCCR2 |= Timer2_Config.prescaler;
}

Timer2_ErrorStatus_t Timer2_SETCallBack(void (*TIMER2_PTR)(void))
{
	Timer2_ErrorStatus_t status = TIMER2_OK;
	if (TIMER2_PTR == NULL)
	{
		status = TIMER2_ERROR_NULL_PTR;
	}
	else
	{
		Timer2_PFUN = TIMER2_PTR;
	}
	return status;
}

Timer2_ErrorStatus_t Pwm2_SetDutyCycle(u8 dutyCycle)
{
	Timer2_ErrorStatus_t status = TIMER2_OK;
	if (dutyCycle > 100)
	{
		status = TIMER2_ERROR_INVALID_DUTY;
	}
	else
	{
		OCR2 = (u8)((dutyCycle * 255) / 100);
	}
	return status;
}
void Timer2_CalculateNormalConfig(f32 required_time_ms, u32 F_CPU, u8 resolution, u16 prescaler)
{
	// Convert required time from ms to seconds
	f32 required_time = required_time_ms / 1000.0;

	f32 tick_time = (f32)prescaler / F_CPU;
	u16 max_count = (1 << resolution); // 256 for 8-bit Timer2
	f32 overflow_time = max_count * tick_time;

	// Calculate full overflows
	Timer2_NumOVF = (u16)(required_time / overflow_time);
	f32 remaining_time = required_time - (Timer2_NumOVF * overflow_time);

	if (remaining_time > 0)
	{
		// Convert remaining time to timer ticks
		f32 required_float_ticks = (remaining_time * max_count) / overflow_time;

		// Correct Preload Calculation
		Timer2_Preload = max_count - (u8)required_float_ticks;

		// Since we use a preload, we need an extra overflow
		Timer2_NumOVF += 1;
	}
	else
	{
		Timer2_Preload = 0;  // No need for preload
	}
}


void Timer2_CalculateCTCConfig(f32 required_time_ms, u32 F_CPU, u16 prescaler, u8 OCR_Val)
{
	// Convert required time from ms to seconds
	f32 required_time = required_time_ms / 1000.0;

	f32 tick_time = (f32)prescaler / F_CPU; // Time per tick
	f32 required_ticks = required_time / tick_time; // Total ticks needed

	// Choose OCR2 (keep within 8-bit range)
	if (required_ticks > 255)
	{
		Timer2_CompareMatchValue = OCR_Val;
	}
	else
	{
		Timer2_CompareMatchValue = (u8)required_ticks;
	}

	// Compute compare match time
	f32 compare_match_time = (Timer2_CompareMatchValue + 1) * tick_time;

	// Compute number of compare matches
	Timer2_NumCompareMatches = (u32)(required_time / compare_match_time);

	if ((u32)required_time % (u32)compare_match_time != 0)
	{
		Timer2_NumCompareMatches++;
	}
}



void __vector_5(void) __attribute__((signal));
void __vector_5(void)
{
	static u16 Local_Counter = 0;
	Local_Counter++;
	if (Local_Counter == Timer2_NumOVF)
	{
		Local_Counter = 0;
		TCNT2 = Timer2_Preload;
		if (Timer2_PFUN) Timer2_PFUN();
	}
}

void __vector_4(void) __attribute__((signal));
void __vector_4(void)
{
	static u16 Local_Counter = 0;
	Local_Counter++;
	if (Local_Counter == Timer2_NumCompareMatches)
	{
		Local_Counter = 0;
		if (Timer2_PFUN) Timer2_PFUN();
	}
}


/* Function to Get Preload or Compare Match Value */
u8 Timer2_GetPreloadOrCompare(void)
{
	if (Timer2_Config.mode == TIMER2_OVF_MODE)
	{
		return Timer2_Preload;  // Return preload for overflow mode
	}
	else if (Timer2_Config.mode == TIMER2_CTC_MODE)
	{
		return 0;  // No preload needed in CTC mode
	}
	return 0;  // Default return in case of invalid mode
}

/* Function to Get Number of Overflows or Compare Matches */
u16 Timer2_GetNumOVFOrCompareMatches(void)
{
	if (Timer2_Config.mode == TIMER2_OVF_MODE)
	{
		return Timer2_NumOVF;  // Return number of overflows for normal mode
	}
	else if (Timer2_Config.mode == TIMER2_CTC_MODE)
	{
		return Timer2_NumCompareMatches;  // Return number of compare matches for CTC mode
	}
	return 0;  // Default return in case of invalid mode
}

/* Function to Get Compare Match Value */
u16 Timer2_GetCompareMatchValue(void)
{
	return Timer2_CompareMatchValue;
}
