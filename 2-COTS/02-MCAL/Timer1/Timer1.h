/*
 * Timer1.h
 *
 * Created: 3/5/2025 1:11:26 PM
 *  Author: TUF
 */ 

#ifndef TIMER1_H_
#define TIMER1_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Timer1_Private.h"

/* Timer1 Modes */
#define TIMER1_NORMAL_MODE          0x00
#define TIMER1_CTC_MODE_OCR1A       (1 << WGM12)
#define TIMER1_CTC_MODE_ICR1        ((1 << WGM12) | (1 << WGM13))
#define TIMER1_FAST_PWM_8BIT        ((1 << WGM10) | (1 << WGM12))
#define TIMER1_FAST_PWM_9BIT        ((1 << WGM11) | (1 << WGM12))
#define TIMER1_FAST_PWM_10BIT       ((1 << WGM10) | (1 << WGM11) | (1 << WGM12))
#define TIMER1_FAST_PWM_OCR1A       ((1 << WGM12) | (1 << WGM13))
#define TIMER1_FAST_PWM_ICR1        ((1 << WGM11) | (1 << WGM12) | (1 << WGM13))
#define TIMER1_PHASE_CORRECT_PWM_8BIT  (1 << WGM10)
#define TIMER1_PHASE_CORRECT_PWM_9BIT  (1 << WGM11)
#define TIMER1_PHASE_CORRECT_PWM_10BIT ((1 << WGM10) | (1 << WGM11))
#define TIMER1_PHASE_CORRECT_PWM_ICR1  ((1 << WGM11) | (1 << WGM13))
#define TIMER1_PHASE_CORRECT_PWM_OCR1A ((1 << WGM10) | (1 << WGM11) | (1 << WGM13))


/* Waveform Generation Mode Masks */
#define WGM1A_MASK ((1 << WGM10) | (1 << WGM11))
#define WGM1B_MASK ((1 << WGM12) | (1 << WGM13))

/* Timer Interrupt Masks */
#define TOIE1_MASK  (1 << TOIE1)   // Timer1 Overflow Interrupt Enable
#define OCIE1A_MASK (1 << OCIE1A)  // Timer1 Compare Match A Interrupt Enable
#define OCIE1B_MASK (1 << OCIE1B)  // Timer1 Compare Match B Interrupt Enable

/* Clock Select (Prescaler) Mask */
#define CS1_MASK ((1 << CS10) | (1 << CS11) | (1 << CS12))



/* Compare Output Modes */
#define TIMER1_DISCONNECT_OC1A_OC1B  0x00
#define TIMER1_TOGGLE_OC1A           (1 << COM1A0)
#define TIMER1_CLEAR_OC1A            (1 << COM1A1)
#define TIMER1_SET_OC1A              ((1 << COM1A0) | (1 << COM1A1))
#define TIMER1_TOGGLE_OC1B           (1 << COM1B0)
#define TIMER1_CLEAR_OC1B            (1 << COM1B1)
#define TIMER1_SET_OC1B              ((1 << COM1B0) | (1 << COM1B1))

/* Prescaler Options */
#define TIMER1_OFF       0x00
#define TIMER1_NO_PRESCALE  (1 << CS10)
#define TIMER1_PRESCALE_8   (1 << CS11)
#define TIMER1_PRESCALE_64  ((1 << CS11) | (1 << CS10))
#define TIMER1_PRESCALE_256 (1 << CS12)
#define TIMER1_PRESCALE_1024 ((1 << CS12) | (1 << CS10))

typedef enum
{
	TIMER1_OK,
	TIMER1_ERROR_NULL_PTR,
	TIMER1_ERROR_INVALID_MODE,
	TIMER1_ERROR_INVALID_DUTY,
	TIMER1_ERROR_INVALID_PRESCALER
} Timer1_ErrorStatus_t;

typedef struct
{
	u8 mode;
	u8 prescaler;
	u8 compare_output_mode_A;
	u8 compare_output_mode_B;
} Timer1_Config_t;

/* Extern Configuration */
extern Timer1_Config_t Timer1_Config;

void Timer1_Init(void);

void Timer1_SetICR1Value(u16 value);

Timer1_ErrorStatus_t Timer1_SetCallBack_OVF(void (*TIMER1_PTR)(void));
Timer1_ErrorStatus_t Timer1_SetCallBack_COMPA(void (*TIMER1_PTR)(void));
Timer1_ErrorStatus_t Timer1_SetCallBack_COMPB(void (*TIMER1_PTR)(void));


Timer1_ErrorStatus_t Pwm1_SetDutyCycleA(u8 dutyCycle);
Timer1_ErrorStatus_t Pwm1_SetDutyCycleB(u8 dutyCycle);

void Timer1_CalculateNormalConfig(f32 required_time, u32 F_CPU, u16 resolution, u16 prescaler);
void Timer1_CalculateCTCConfigA(f32 required_time_ms, u16 OCR_Val, u32 F_CPU, u16 prescaler);
void Timer1_CalculateCTCConfigB(f32 required_time_ms, u16 OCR_Val, u32 F_CPU, u16 prescaler);


u16 Timer1_GetPreload(void);
u16 Timer1_GetNumOVF(void);

u16 Timer1_GetCompareMatchValueA(void);
u16 Timer1_GetCompareMatchValueB(void);

u16 Timer1_GetNumCompareMatchesA(void);
u16 Timer1_GetNumCompareMatchesB(void);

u16 Timer1_GetICR1Value(void);


#endif /* TIMER1_H_ */
