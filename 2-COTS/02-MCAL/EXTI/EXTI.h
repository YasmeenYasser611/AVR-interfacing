/*
 * EXTI.h
 *
 * Created: 2/10/2025 1:53:53 PM
 *  Author: TUF
 */ 


#ifndef EXTI_H_
#define EXTI_H_

typedef enum
{
	EXTI0=0 ,
	EXTI1 ,
	EXTI2
	
}INT_ID;

typedef enum
{
	Low_Level=0 ,
	On_Change ,
	Falling_Edge,
	Rising_Edge
	
	
}Sense_Ctrl;


void EXTI_VoidSetSenseControl(INT_ID Copy_enuIntNum , Sense_Ctrl Copy_enuSenseCtrl);

void EXTI_VoidEnable(INT_ID Copy_enuIntNum);
void EXTI_VoidDisable(INT_ID Copy_enuIntNum);

void EXTI_VoidSetCallBackINT0(void(*ptr)(void));
void EXTI_VoidSetCallBackINT1(void(*ptr)(void));
void EXTI_VoidSetCallBackINT2(void(*ptr)(void));

#endif /* EXTI_H_ */