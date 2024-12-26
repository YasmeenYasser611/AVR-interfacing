/*
 * portdriverbuild.c
 *
 * Created: 12/26/2024 6:20:12 AM
 * Author : TUF
 */ 

#include "MPORT.h"
#include "MDIO.h"
#define F_CPU 8000000UL
#include <util/delay.h>


int main(void)
{
    MPORT_vPortInit();
    while (1) 
    {
		MDIO_enuSetPinValue(MDIO_enuPORTA , MDIO_enuPIN1 , MDIO_enuHIGH);	
		_delay_ms(100);
		MDIO_enuSetPinValue(MDIO_enuPORTA , MDIO_enuPIN1 , MDIO_enuLOW);
        _delay_ms(100);
		
		
    }
}

