/*
 * INT_DRIVER_Build.c
 *
 * Created: 2/10/2025 12:41:24 PM
 * Author : TUF
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI.h"
#include "MDIO.h"
#include "MPORT.h"
#include "GIE.h"


void func0(void)
{
	
	static u8 i=0;
	if(i==0)
	{
		MDIO_enuSetPinValue(MDIO_enuPORTC , MDIO_enuPIN0 , MDIO_enuHIGH);
		i=1;
	}
	else
	{
		MDIO_enuSetPinValue(MDIO_enuPORTC , MDIO_enuPIN0 , MDIO_enuLOW);
		i=0;
		
	}
}


void func1(void)
{
	
	static u8 i=0;
	if(i==0)
	{
		MDIO_enuSetPinValue(MDIO_enuPORTC , MDIO_enuPIN1 , MDIO_enuHIGH);
		i=1;
	}
	else
	{
		MDIO_enuSetPinValue(MDIO_enuPORTC , MDIO_enuPIN1 , MDIO_enuLOW);
		i=0;
		
	}
}


void func2(void)
{
	
	static u8 i=0;
	if(i==0)
	{
		MDIO_enuSetPinValue(MDIO_enuPORTC , MDIO_enuPIN2 , MDIO_enuHIGH);
		i=1;
	}
	else
	{
		MDIO_enuSetPinValue(MDIO_enuPORTC , MDIO_enuPIN2 , MDIO_enuLOW);
		i=0;
		
	}
}

int main(void)
{
	MPORT_vPortInit();
	
	GIE_VoidEnable();
	
	EXTI_VoidSetSenseControl(EXTI0 , On_Change);
	EXTI_VoidSetSenseControl(EXTI1 , Falling_Edge);
	EXTI_VoidSetSenseControl(EXTI2 , Rising_Edge);
	
	EXTI_VoidSetCallBackINT0(func0);
	EXTI_VoidSetCallBackINT1(func1);
	EXTI_VoidSetCallBackINT2(func2);
	
	EXTI_VoidEnable(EXTI0);
	EXTI_VoidEnable(EXTI1);
	EXTI_VoidEnable(EXTI2);
	
   
    while (1) 
    {
    }
}

