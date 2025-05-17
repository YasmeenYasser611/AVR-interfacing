/*
 * Timer1.c
 *
 * Created: 3/5/2025 1:11:06 PM
 *  Author: TUF
 */ 
#include "Timer1.h"
#include "Timer1_private.h"
#include "Timer1_config.h"
#include "MPORT.h"
#include "GIE.h"

/* Global Pointer to Function */
static void (*Timer1_PFUN_OVF)(void) = NULL;
static void (*Timer1_PFUN_COMPA)(void) = NULL;
static void (*Timer1_PFUN_COMPB)(void) = NULL;

/* Private Static Variables */
static u16 Timer1_Preload = 0;
static u16 Timer1_CompareMatchValueA = 0;
static u16 Timer1_CompareMatchValueB = 0;
static u16 Timer1_NumOVF = 0;
static u16 Timer1_NumCompareMatchesA = 0;
static u16 Timer1_NumCompareMatchesB = 0;
static u16 Timer1_ICR1_Value=0;


void Timer1_Init(void)
{
	/* Select Mode */
	TCCR1A &= ~WGM1A_MASK;
	TCCR1B &= ~WGM1B_MASK;
	TCCR1A |= (Timer1_Config.mode & 0x03);  // WGM10, WGM11
	TCCR1B |= (Timer1_Config.mode & 0x0C);  // WGM12, WGM13

	/* Set Compare Output Mode */
	TCCR1A &= ~((1 << COM1A0) | (1 << COM1A1) | (1 << COM1B0) | (1 << COM1B1));
	TCCR1A |= Timer1_Config.compare_output_mode_A;  // Configure OC1A
	TCCR1A |= Timer1_Config.compare_output_mode_B;  // Configure OC1B

	/* Enable Timer Interrupts */
	if (Timer1_Config.mode == TIMER1_NORMAL_MODE)
	{
		TIMSK |= TOIE1_MASK;  // Enable Overflow Interrupt
		TCNT1 = Timer1_Preload;
	}
	else if (Timer1_Config.mode == TIMER1_CTC_MODE_OCR1A || Timer1_Config.mode == TIMER1_CTC_MODE_ICR1)
	{
		TIMSK |= (OCIE1A_MASK | OCIE1B_MASK);  // Enable CTC Interrupts
		OCR1A = Timer1_CompareMatchValueA;
		OCR1B = Timer1_CompareMatchValueB;

		if (Timer1_Config.mode == TIMER1_CTC_MODE_ICR1)
		{
			ICR1 = Timer1_ICR1_Value;  // Set ICR1 value for CTC mode
		}
	}
	else if (Timer1_Config.mode == TIMER1_FAST_PWM_8BIT || Timer1_Config.mode == TIMER1_FAST_PWM_9BIT ||
	Timer1_Config.mode == TIMER1_FAST_PWM_10BIT || Timer1_Config.mode == TIMER1_FAST_PWM_OCR1A ||
	Timer1_Config.mode == TIMER1_FAST_PWM_ICR1)
	{
		MPORT_enuSetPinDirection(MPORT_enuPIN_D5, MPORT_enuPINOUTPUT); // OC1A (PWM Output)
		MPORT_enuSetPinDirection(MPORT_enuPIN_D4, MPORT_enuPINOUTPUT); // OC1B (PWM Output)
		
		if (Timer1_Config.mode == TIMER1_FAST_PWM_ICR1)
		{
			ICR1 = Timer1_ICR1_Value;  // Set ICR1 for Fast PWM
		}
		else if (Timer1_Config.mode == TIMER1_FAST_PWM_OCR1A)
		{
			OCR1A = Timer1_CompareMatchValueA;  // Set OCR1A for Fast PWM
		}
	}
	else if (Timer1_Config.mode == TIMER1_PHASE_CORRECT_PWM_8BIT || Timer1_Config.mode == TIMER1_PHASE_CORRECT_PWM_9BIT ||
	Timer1_Config.mode == TIMER1_PHASE_CORRECT_PWM_10BIT || Timer1_Config.mode == TIMER1_PHASE_CORRECT_PWM_ICR1 ||
	Timer1_Config.mode == TIMER1_PHASE_CORRECT_PWM_OCR1A)
	{
		MPORT_enuSetPinDirection(MPORT_enuPIN_D5, MPORT_enuPINOUTPUT); // OC1A (PWM Output)
		MPORT_enuSetPinDirection(MPORT_enuPIN_D4, MPORT_enuPINOUTPUT); // OC1B (PWM Output)

		if (Timer1_Config.mode == TIMER1_PHASE_CORRECT_PWM_ICR1)
		{
			ICR1 = Timer1_ICR1_Value;  // Set ICR1 for Phase Correct PWM
		}
		else if (Timer1_Config.mode == TIMER1_PHASE_CORRECT_PWM_OCR1A)
		{
			OCR1A = Timer1_CompareMatchValueA;  // Set OCR1A for Phase Correct PWM
		}
	}

	/* Configure Prescaler */
	TCCR1B &= ~CS1_MASK;
	TCCR1B |= Timer1_Config.prescaler;

	/* Enable Global Interrupts */
	GIE_VoidEnable();
}


void Timer1_SetICR1Value(u16 value)
{
	Timer1_ICR1_Value = value;
}


Timer1_ErrorStatus_t Timer1_SetCallBack_OVF(void (*TIMER1_PTR)(void))
{
	Timer1_ErrorStatus_t status = TIMER1_OK;
	if (TIMER1_PTR == NULL)
	{
		status = TIMER1_ERROR_NULL_PTR;
	}
	else
	{
		Timer1_PFUN_OVF = TIMER1_PTR;
	}
	return status;
}

Timer1_ErrorStatus_t Timer1_SetCallBack_COMPA(void (*TIMER1_PTR)(void))
{
	Timer1_ErrorStatus_t status = TIMER1_OK;
	if (TIMER1_PTR == NULL)
	{
		status = TIMER1_ERROR_NULL_PTR;
	}
	else
	{
		Timer1_PFUN_COMPA = TIMER1_PTR;
	}
	return status;
}

Timer1_ErrorStatus_t Timer1_SetCallBack_COMPB(void (*TIMER1_PTR)(void))
{
	Timer1_ErrorStatus_t status = TIMER1_OK;
	if (TIMER1_PTR == NULL)
	{
		status = TIMER1_ERROR_NULL_PTR;
	}
	else
	{
		Timer1_PFUN_COMPB = TIMER1_PTR;
	}
	return status;
}

Timer1_ErrorStatus_t Pwm1_SetDutyCycleA(u8 dutyCycle)
{
	Timer1_ErrorStatus_t status = TIMER1_OK;
	if (dutyCycle > 100)
	{
		status = TIMER1_ERROR_INVALID_DUTY;
	}
	else
	{
		OCR1A = (u16)((dutyCycle * 65535) / 100);
	}
	return status;
}

Timer1_ErrorStatus_t Pwm1_SetDutyCycleB(u8 dutyCycle)
{
	Timer1_ErrorStatus_t status = TIMER1_OK;
	if (dutyCycle > 100)
	{
		status = TIMER1_ERROR_INVALID_DUTY;
	}
	else
	{
		OCR1B = (u16)((dutyCycle * 65535) / 100);
	}
	return status;
}
/* Calculate Normal Mode Configuration for Timer1 */
void Timer1_CalculateNormalConfig(f32 required_time_ms, u32 F_CPU, u16 resolution, u16 prescaler)
{
	// Convert required time from ms to seconds
	f32 required_time = required_time_ms / 1000.0;

	f32 tick_time = (f32)prescaler / F_CPU;   // Time per tick
	u32 max_count = (1 << resolution);        // 65536 for 16-bit Timer1
	f32 overflow_time = max_count * tick_time; // Time for one full overflow

	// Calculate full overflows
	Timer1_NumOVF = (u16)(required_time / overflow_time);
	f32 remaining_time = required_time - (Timer1_NumOVF * overflow_time);

	if (remaining_time > 0)
	{
		// Convert remaining time to timer ticks
		f32 required_float_ticks = (remaining_time * max_count) / overflow_time;

		// Correct Preload Calculation
		Timer1_Preload = max_count - (u16)required_float_ticks;

		// Since we use a preload, we need an extra overflow
		Timer1_NumOVF += 1;
	}
	else
	{
		Timer1_Preload = 0;  // No need for preload
	}
}

/* Calculate CTC Mode Configuration for Timer1 */
void Timer1_CalculateCTCConfigA(f32 required_time_ms, u16 OCR_Val, u32 F_CPU, u16 prescaler)
{
	// Convert required time from ms to seconds
	f32 required_time = required_time_ms / 1000.0;

	f32 tick_time = (f32)prescaler / F_CPU;  // Time per tick
	f32 required_ticks = required_time / tick_time;  // Total ticks needed

	// Choose OCR1A (keep within 16-bit range)
	if (required_ticks > 65535)
	{
		Timer1_CompareMatchValueA = OCR_Val;
	}
	else
	{
		Timer1_CompareMatchValueA = (u16)required_ticks;
	}
	
	// Compute compare match time
	f32 compare_match_time = (Timer1_CompareMatchValueA + 1) * tick_time;

	// Compute number of compare matches
	Timer1_NumCompareMatchesA = (u32)(required_time / compare_match_time);

	if (fmod(required_time, compare_match_time) != 0)
	{
		Timer1_NumCompareMatchesA++;
	}
}


/* Calculate CTC Mode Configuration for Timer1 - Compare Match B */
void Timer1_CalculateCTCConfigB(f32 required_time_ms, u16 OCR_Val, u32 F_CPU, u16 prescaler)
{
	// Convert required time from ms to seconds
	f32 required_time = required_time_ms / 1000.0;

	f32 tick_time = (f32)prescaler / F_CPU;  // Time per tick
	f32 required_ticks = required_time / tick_time;  // Total ticks needed

	// Choose OCR1B (keep within 16-bit range)
	if (required_ticks > 65535)
	{
		Timer1_CompareMatchValueB = OCR_Val;
	}
	else
	{
		Timer1_CompareMatchValueB = (u16)required_ticks;
	}
	
	// Compute compare match time
	f32 compare_match_time = (Timer1_CompareMatchValueB + 1) * tick_time;

	// Compute number of compare matches
	Timer1_NumCompareMatchesB = (u32)(required_time / compare_match_time);

	if (fmod(required_time, compare_match_time) != 0)
	{
		Timer1_NumCompareMatchesB++;
	}
}


/* Overflow ISR */
void __vector_9(void) __attribute__((signal));
void __vector_9(void)
{
	static u16 Local_Counter = 0;
	Local_Counter++;
	if (Local_Counter == Timer1_NumOVF)
	{
		Local_Counter = 0;
		TCNT1 = Timer1_Preload;
		if (Timer1_PFUN_OVF) Timer1_PFUN_OVF();
	}
}


/* Compare Match A ISR */
void __vector_7(void) __attribute__((signal));
void __vector_7(void)
{
	static u16 Local_Counter_A = 0;
	Local_Counter_A++;
	if (Local_Counter_A == Timer1_NumCompareMatchesA)
	{
		Local_Counter_A = 0;
		if (Timer1_PFUN_COMPA)
		{
			Timer1_PFUN_COMPA();
		}
	}
}

/* Compare Match B ISR */
void __vector_8(void) __attribute__((signal));
void __vector_8(void)
{
	static u16 Local_Counter_B = 0;
	Local_Counter_B++;
	if (Local_Counter_B == Timer1_NumCompareMatchesB)
	{
		Local_Counter_B = 0;
		if (Timer1_PFUN_COMPB)
		{
			Timer1_PFUN_COMPB();
		}
	}
}


u16 Timer1_GetPreload(void)
{
	return Timer1_Preload;
}

u16 Timer1_GetCompareMatchValueA(void)
{
	return Timer1_CompareMatchValueA;
}

u16 Timer1_GetCompareMatchValueB(void)
{
	return Timer1_CompareMatchValueB;
}

u16 Timer1_GetNumOVF(void)
{
	return Timer1_NumOVF;
}

u16 Timer1_GetNumCompareMatchesA(void)
{
	return Timer1_NumCompareMatchesA;
}

u16 Timer1_GetNumCompareMatchesB(void)
{
	return Timer1_NumCompareMatchesB;
}

u16 Timer1_GetICR1Value(void)
{
	return Timer1_ICR1_Value;
}
