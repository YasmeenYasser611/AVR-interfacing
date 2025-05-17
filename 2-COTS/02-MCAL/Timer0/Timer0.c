/*
 * Timer0.c
 *
 * Created: 3/3/2025 7:57:40 PM
 *  Author: TUF
 */ 
#include "Timer0.h"
#include "Timer0_private.h"
#include "Timer0_config.h"
#include "MPORT.h"
#include "GIE.h"

/* Global Pointer to Function */
void (*Timer_PFUN)(void) = NULL;

/* Private Static Variables */
static u8 Timer0_Preload = 0;  // For overflow mode
static u8 Timer0_CompareMatchValue = 0;  // For CTC mode
static u16 Timer0_NumOVF = 0; // Number of overflows for normal mode
static u32 Timer0_NumCompareMatches = 0; // Number of compare matches for CTC mode

void Timer0_Init(void)
{
	/* Select Mode */
	TCCR0 &= ~WGM_MASK;
	TCCR0 |= Timer0_Config.mode;

	/* Set Compare Output Mode */
	TCCR0 &= ~((1 << COM00) | (1 << COM01));
	TCCR0 |= Timer0_Config.compare_output_mode;



	/* Enable Timer Interrupts */
	if (Timer0_Config.mode == TIMER0_OVF_MODE)
	{
		TIMSK |= TOIE_MASK;  // Enable Overflow Interrupt
		TCNT0 = Timer0_Preload;  // Set Preload Value
		/* Enable Global Interrupts */
	    GIE_VoidEnable();
	}
	else if(Timer0_Config.mode == TIMER0_CTC_MODE)
	{
		TIMSK |= OCIE_MASK;  // Enable Compare Match Interrupt
		OCR0 = Timer0_CompareMatchValue; // Set Compare Match Value
		/* Enable Global Interrupts */
		GIE_VoidEnable();
	}
	else if(Timer0_Config.mode == TIMER0_PHASE_CORRECT_PWM ||Timer0_Config.mode == TIMER0_FAST_PWM )
	{
		/* Configure OC0 (PB3) as Output */
		MPORT_enuSetPinDirection(MPORT_enuPIN_B3 , MPORT_enuPINOUTPUT);

	}

	/* Configure Prescaler */
	TCCR0 &= ~CS_MASK;
	TCCR0 |= Timer0_Config.prescaler;
}

/* Callback Function Setter */
Timer0_ErrorStatus_t  Timer0_SETCallBack(void (*TIMER0_PTR)(void))
{
	Timer0_ErrorStatus_t status = TIMER0_OK;

    if (TIMER0_PTR == NULL)
    {
        status = TIMER0_ERROR_NULL_PTR;
    }
    else
    {
        Timer_PFUN = TIMER0_PTR;
    }

    return status;
	
}

Timer0_ErrorStatus_t  Pwm_SetDutyCycle(u8 dutyCycle)
{
    Timer0_ErrorStatus_t status = TIMER0_OK;

    if (dutyCycle > 100)
    {
	    status = TIMER0_ERROR_INVALID_DUTY;
    }
    else
    {
	    OCR0 = (u8)(((f32)dutyCycle * 255.0f) / 100.0f);
    }

    return status;}


/* Calculate Normal Mode Configuration */
void Timer0_CalculateNormalConfig(f32 required_time_ms, u32 F_CPU, u8 resolution, u16 prescaler)
{
	// Convert required time from ms to seconds
	f32 required_time = required_time_ms / 1000.0;

	f32 tick_time = (f32)prescaler / F_CPU;   // Time per tick
	u16 max_count = (1 << resolution);        // 256 for 8-bit Timer0
	f32 overflow_time = max_count * tick_time; // Time for one full overflow

	// Calculate full overflows
	Timer0_NumOVF = (u16)(required_time / overflow_time);
	f32 remaining_time = required_time - (Timer0_NumOVF * overflow_time);

	if (remaining_time > 0)
	{
		// Convert remaining time to timer ticks
		f32 required_float_ticks = (remaining_time * max_count) / overflow_time;

		// Correct Preload Calculation
		Timer0_Preload = max_count - (u8)required_float_ticks;

		// Since we use a preload, we need an extra overflow
		Timer0_NumOVF += 1;
	}
	else
	{
		Timer0_Preload = 0;  // No need for preload
	}
}





void Timer0_CalculateCTCConfig(f32 required_time,u8 OCR_Val ,  u32 F_CPU, u16 prescaler)
{
	f32 required_time_ms = required_time / 1000.0;
	f32 tick_time = (f32)prescaler / F_CPU;  // Time per tick
	f32 required_ticks = required_time_ms / tick_time;  // Total ticks needed

	// Choose OCR0 (keep within 8-bit range)
	if (required_ticks > 255)
	{
		Timer0_CompareMatchValue = OCR_Val;  
	}
	else
	{
		Timer0_CompareMatchValue = (u8)required_ticks; 
	}
	// Compute compare match time
	f32 compare_match_time = (Timer0_CompareMatchValue + 1) * tick_time;

	// Compute number of compare matches
	Timer0_NumCompareMatches = (u32)(required_time_ms / compare_match_time);

	if ((u32)required_time_ms % (u32)compare_match_time != 0)
	{
		Timer0_NumCompareMatches++;
	}

}





/* Timer0 Overflow ISR */
void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	static u16 Local_Counter = 0;

	if (Local_Counter == 0)  // First execution, apply preload
	{
		TCNT0 = Timer0_Preload;
	}

	Local_Counter++;

	if (Local_Counter >= Timer0_NumOVF) // Use '>=' for safety
	{
		Local_Counter = 0; // Reset counter
		if (Timer_PFUN) Timer_PFUN(); // Call the callback function
	}
}


/* Timer0 Compare Match ISR */
void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	static u16 Local_Counter = 0;
	Local_Counter++;
	if (Local_Counter >= Timer0_NumCompareMatches)
	{
		Local_Counter = 0;
		if (Timer_PFUN) Timer_PFUN();
	}
}


/* Function to Get Preload or Compare Match Value */
u8 Timer0_GetPreloadOrCompare(void)
{
	if (Timer0_Config.mode == TIMER0_OVF_MODE)
	{
		return Timer0_Preload;  // Return preload for overflow mode
	}
	else if (Timer0_Config.mode == TIMER0_CTC_MODE)
	{
		return 0;  // 
	}
	return 0;  // Default return in case of invalid mode
}

/* Function to Get Number of Overflows or Compare Matches */
u16 Timer0_GetNumOVFOrCompareMatches(void)
{
	if (Timer0_Config.mode == TIMER0_OVF_MODE)
	{
		return Timer0_NumOVF;  // Return number of overflows for normal mode
	}
	else if (Timer0_Config.mode == TIMER0_CTC_MODE)
	{
		return Timer0_NumCompareMatches;  // Return number of compare matches for CTC mode
	}
	return 0;  // Default return in case of invalid mode
}

u16 Timer0_GetCompareMatcheValue(void)
{
	return Timer0_CompareMatchValue;
}