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
static u16 Timer0_NumCompareMatches = 0; // Number of compare matches for CTC mode

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
	    OCR0 = (u8)((dutyCycle * 255) / 100);
    }

    return status;}


/* Calculate Normal Mode Configuration */
void Timer0_CalculateNormalConfig(f32 required_time, u32 F_CPU, u8 resolution, u16 prescaler)
{
	f32 tick_time = (f32)prescaler / F_CPU;
	u16 max_count = (1 << resolution);
	f32 overflow_time = max_count * tick_time;

	if (required_time == overflow_time)
	{
		Timer0_NumOVF = 1;
		Timer0_Preload = 0;
	}
	else
	{
		Timer0_NumOVF = (u16)(required_time / overflow_time);
		f32 fraction = (required_time / overflow_time) - Timer0_NumOVF;
		f32 required_float_time = fraction * max_count;
		Timer0_Preload = max_count - (u8)required_float_time;
	}
}

/* Calculate CTC Mode Configuration */
void Timer0_CalculateCTCConfig(f32 required_time, u32 F_CPU, u16 prescaler)
{
	f32 tick_time = (f32)prescaler / F_CPU;
	f32 compare_match_time = (Timer0_CompareMatchValue + 1) * tick_time;
	Timer0_NumCompareMatches = (u16)(required_time / compare_match_time);

	if ((u32)required_time % (u32)compare_match_time != 0)
	{
		Timer0_NumCompareMatches++;
	}
}

/* Timer0 Overflow ISR */
void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	static u16 Local_Counter = 0;
	Local_Counter++;
	if (Local_Counter == Timer0_NumOVF)
	{
		Local_Counter = 0;
		TCNT0 = Timer0_Preload;
		if (Timer_PFUN) Timer_PFUN();
	}
}

/* Timer0 Compare Match ISR */
void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	static u16 Local_Counter = 0;
	Local_Counter++;
	if (Local_Counter == Timer0_NumCompareMatches)
	{
		Local_Counter = 0;
		if (Timer_PFUN) Timer_PFUN();
	}
}
