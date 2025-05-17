/*
 * Timer0.h
 *
 * Created: 3/3/2025 7:57:20 PM
 *  Author: TUF
 */ 
#ifndef TIMER0_H_
#define TIMER0_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Timer0_Private.h"

/* Timer Modes */
#define TIMER0_OVF_MODE   0x00
#define TIMER0_CTC_MODE   (1 << WGM01)
#define TIMER0_PHASE_CORRECT_PWM  (1 << WGM00)
#define TIMER0_FAST_PWM           ((1 << WGM00) | (1 << WGM01))


/* Compare Match Output Modes */
#define TIMER0_DISCONNECT_OC0  0x00
#define TIMER0_TOGGLE_OC0      (1 << COM00)
#define TIMER0_CLEAR_OC0       (1 << COM01)
#define TIMER0_SET_OC0         ((1 << COM00) | (1 << COM01))

/* Prescaler Options */
#define TIMER0_TIMER_OFF      0x00
#define TIMER0_NO_PRESCALE    (1 << CS00)
#define TIMER0_PRESCALE_8     (1 << CS01)
#define TIMER0_PRESCALE_64    ((1 << CS00) | (1 << CS01))
#define TIMER0_PRESCALE_256   (1 << CS02)
#define TIMER0_PRESCALE_1024  ((1 << CS00) | (1 << CS02))

typedef enum 
{
	TIMER0_OK,                  // No error
	TIMER0_ERROR_NULL_PTR,      // Null pointer passed
	TIMER0_ERROR_INVALID_MODE,  // Invalid timer mode
	TIMER0_ERROR_INVALID_DUTY,  // Invalid duty cycle value
	TIMER0_ERROR_INVALID_PRESCALER // Invalid prescaler value
} Timer0_ErrorStatus_t;


typedef struct
{
	u8 mode;
	u8 prescaler;
	u8 compare_output_mode;  // COM00 & COM01 settings
} Timer0_Config_t;

/* Extern Configuration Structure */
extern Timer0_Config_t Timer0_Config;

void Timer0_Init();
Timer0_ErrorStatus_t  Timer0_SETCallBack(void (*TIMER0_PTR)(void));
Timer0_ErrorStatus_t  Pwm_SetDutyCycle(u8 dutyCycle);
void Timer0_CalculateNormalConfig(f32 required_time, u32 F_CPU, u8 resolution, u16 prescaler);
void Timer0_CalculateCTCConfig(f32 required_time,u8 OCR_Val ,  u32 F_CPU, u16 prescaler);

/* Debugging Functions */
u8 Timer0_GetPreloadOrCompare(void);
u16 Timer0_GetNumOVFOrCompareMatches(void);
u16 Timer0_GetCompareMatcheValue(void);

#endif /* TIMER0_H_ */
