/*
 * Timer2.h
 *
 * Created: 3/5/2025 11:02:12 AM
 *  Author: TUF
 */ 


#ifndef TIMER2_H_
#define TIMER2_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Timer2_Private.h"

/* Timer Modes */
#define TIMER2_OVF_MODE   0x00
#define TIMER2_CTC_MODE   (1 << WGM21)
#define TIMER2_PHASE_CORRECT_PWM  (1 << WGM20)
#define TIMER2_FAST_PWM           ((1 << WGM20) | (1 << WGM21))

/* Compare Match Output Modes */
#define TIMER2_DISCONNECT_OC2  0x00
#define TIMER2_TOGGLE_OC2      (1 << COM20)
#define TIMER2_CLEAR_OC2       (1 << COM21)
#define TIMER2_SET_OC2         ((1 << COM20) | (1 << COM21))

/* Prescaler Options */
#define TIMER2_TIMER_OFF      0x00
#define TIMER2_NO_PRESCALE    (1 << CS20)
#define TIMER2_PRESCALE_8     (1 << CS21)
#define TIMER2_PRESCALE_32    ((1 << CS21) | (1 << CS20))
#define TIMER2_PRESCALE_64    (1 << CS22)
#define TIMER2_PRESCALE_128   ((1 << CS22) | (1 << CS20))
#define TIMER2_PRESCALE_256   ((1 << CS22) | (1 << CS21))
#define TIMER2_PRESCALE_1024  ((1 << CS22) | (1 << CS21) | (1 << CS20))

typedef enum 
{
    TIMER2_OK,                 
    TIMER2_ERROR_NULL_PTR,      
    TIMER2_ERROR_INVALID_MODE,  
    TIMER2_ERROR_INVALID_DUTY,  
    TIMER2_ERROR_INVALID_PRESCALER 
} Timer2_ErrorStatus_t;

typedef struct
{
    u8 mode;
    u8 prescaler;
    u8 compare_output_mode;
} Timer2_Config_t;

/* Extern Configuration Structure */
extern Timer2_Config_t Timer2_Config;

void Timer2_Init();
Timer2_ErrorStatus_t Timer2_SETCallBack(void (*TIMER2_PTR)(void));
Timer2_ErrorStatus_t Pwm2_SetDutyCycle(u8 dutyCycle);
void Timer2_CalculateNormalConfig(f32 required_time, u32 F_CPU, u8 resolution, u16 prescaler);
void Timer2_CalculateCTCConfig(f32 required_time, u32 F_CPU, u16 prescaler, u8 compare_match_value);


u8 Timer2_GetPreloadOrCompare(void);
u16 Timer2_GetNumOVFOrCompareMatches(void);
u16 Timer2_GetCompareMatchValue(void);

#endif /* TIMER2_H_ */
