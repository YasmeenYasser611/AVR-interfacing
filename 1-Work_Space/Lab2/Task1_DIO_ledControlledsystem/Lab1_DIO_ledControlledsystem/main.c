/*
 * Lab1_DIO_ledControlledsystem.c
 *
 * Created: 12/17/2024 1:27:04 PM
 * Author : TUF
 */ 


#include "MDIO.h"
#define F_CPU 8000000UL
#include <util/delay.h>


int main(void)
{
   
	MDIO_enuErrorStatus_t status1 ,status2 , status3 , status4 , status5,status6 , status7,status8 ;
	u8 result1 , result2 ;
	status1=MDIO_enuSetPinConfigration(MDIO_enuPORTA , MDIO_enuPIN0 , MDIO_enuOUTPUT);
	status2=MDIO_enuSetPinConfigration(MDIO_enuPORTA, MDIO_enuPIN7 , MDIO_enuINPUT_PULLUP);
	status6=MDIO_enuSetPinConfigration(MDIO_enuPORTC , MDIO_enuPIN0 , MDIO_enuOUTPUT);
	status7=MDIO_enuSetPinConfigration(MDIO_enuPORTC, MDIO_enuPIN7 , MDIO_enuINPUT_PULLUP);
	while(1)
	{
		if((status1==MDIO_enuOK)&&(status2==MDIO_enuOK)&&(status6==MDIO_enuOK)&&(status7==MDIO_enuOK))
		{
			status3=MDIO_enuGetPinValue(MDIO_enuPORTA, MDIO_enuPIN7,&result1);
			status8=MDIO_enuGetPinValue(MDIO_enuPORTC, MDIO_enuPIN7,&result2);
			if(status3==MDIO_enuOK)
			{
				if(result1 ==0)
				{
					status4=MDIO_enuSetPinValue(MDIO_enuPORTA , MDIO_enuPIN0 , MDIO_enuHIGH);
				}
				else
				{
					status5=MDIO_enuSetPinValue(MDIO_enuPORTA , MDIO_enuPIN0 , MDIO_enuLOW);
				}
				
			}
		   if(status8==MDIO_enuOK)
			{
				if(result2 ==0)
				{
					status4=MDIO_enuSetPinValue(MDIO_enuPORTC , MDIO_enuPIN0 , MDIO_enuHIGH);
				}
				else
				{
					status5=MDIO_enuSetPinValue(MDIO_enuPORTC , MDIO_enuPIN0 , MDIO_enuLOW);
				}
				
			}
		}
		
	}
}

