/*
 * EXTI.c
 *
 * Created: 2/10/2025 1:53:38 PM
 *  Author: TUF
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_private.h"
#include "EXTI_Conf.h"
#include "EXTI.h"


static void(*GlobalPtr0)(void)=NULL;
static void(*GlobalPtr1)(void)=NULL;
static void(*GlobalPtr2)(void)=NULL;


void EXTI_VoidEnable(INT_ID Copy_enuIntNum)
{
	//peripheral interrrupt enable 
	switch(Copy_enuIntNum)
	{
		case EXTI0:
			SET_BIT(GICR , INT0);
			break;
		case EXTI1:
			SET_BIT(GICR , INT1);
			break;
		case EXTI2:
			SET_BIT(GICR , INT2);
			break;
		default:
			break;
			
	}
	
}
void EXTI_VoidDisable(INT_ID Copy_enuIntNum)
{
	//peripheral interrrupt enable
	switch(Copy_enuIntNum)
	{
		case EXTI0:
			CLR_BIT(GICR , INT0);
			break;
		case EXTI1:
			CLR_BIT(GICR , INT1);
			break;
		case EXTI2:
			CLR_BIT(GICR , INT2);
			break;
		default:
			break;
		
	}
	
}


void EXTI_VoidSetSenseControl(INT_ID Copy_enuIntNum , Sense_Ctrl Copy_enuSenseCtrl)
{
	switch(Copy_enuIntNum){
		case EXTI0:
			MCUCR&= ~(BIT_MUSK<<ISC00);  //CLEAR 2BITS
			MCUCR |=(Copy_enuSenseCtrl << ISC00 );   //set
			break;
		case EXTI1:
			MCUCR&= ~(BIT_MUSK<<ISC10);  //CLEAR 2BITS 
			MCUCR |=(Copy_enuSenseCtrl << ISC10 );   //set
			break;
		case EXTI2:
			switch(Copy_enuSenseCtrl)
			{
				case Rising_Edge:
					SET_BIT(MCUCSR , ISC2);
					break;
				case Falling_Edge:
					CLR_BIT(MCUCSR , ISC2);
					break;
				default:
					break;
			}
			break;
		default:
			break;
}
}
//just save the func address to use in isr

void EXTI_VoidSetCallBackINT0(void(*ptr)(void))
{
	GlobalPtr0=ptr;
	
}
void EXTI_VoidSetCallBackINT1(void(*ptr)(void))
{
	GlobalPtr1=ptr;
}
void EXTI_VoidSetCallBackINT2(void(*ptr)(void))
{
	GlobalPtr2=ptr;
}
// INT0 ISR
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	if (GlobalPtr0 != NULL)
	{
		GlobalPtr0();
	}
}

// INT1 ISR
void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	if (GlobalPtr1 != NULL)
	{
		GlobalPtr1();
	}
}

// INT2 ISR
void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	if (GlobalPtr2 != NULL)
	{
		GlobalPtr2();
	}
}
