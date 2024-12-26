/*
 * GccApplication1.c
 *
 * Created: 12/24/2024 10:01:41 PM
 * Author : TUF
 */ 

#include "MDIO.h"
#define F_CPU 8000000UL
#include <util/delay.h>


int main(void)
{
	
	MDIO_enuErrorStatus_t status1 ,status2 , status3 , status4 , status5,status6 , status7,status8 ;
	u8 result1 , result2 , result3 ;
	MDIO_voidInit();
	
	
	while(1)
	{
		status1=MDIO_enuGetPinValue(MDIO_enuPORTC, MDIO_enuPIN0,&result1);
		status2=MDIO_enuGetPinValue(MDIO_enuPORTC, MDIO_enuPIN1,&result2);
		status3=MDIO_enuGetPinValue(MDIO_enuPORTC, MDIO_enuPIN2,&result3);
					
					if(status1==MDIO_enuOK)
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
					if(status2==MDIO_enuOK)
					{
						if(result2 ==0)
						{
							status4=MDIO_enuSetPinValue(MDIO_enuPORTA , MDIO_enuPIN1 , MDIO_enuHIGH);
						}
						else
						{
							status5=MDIO_enuSetPinValue(MDIO_enuPORTA , MDIO_enuPIN1 , MDIO_enuLOW);
						}
						
					}
					if(status3==MDIO_enuOK)
					{
						if(result3 ==0)
						{
							status4=MDIO_enuSetPinValue(MDIO_enuPORTA , MDIO_enuPIN2 , MDIO_enuHIGH);
						}
						else
						{
							status5=MDIO_enuSetPinValue(MDIO_enuPORTA , MDIO_enuPIN2 , MDIO_enuLOW);
							
						}
						
						
					}


				

		
	}
}



