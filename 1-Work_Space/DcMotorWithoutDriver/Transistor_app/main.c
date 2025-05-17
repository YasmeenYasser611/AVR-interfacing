/*
 * Transistor_app.c
 *
 * Created: 2/10/2025 4:56:17 PM
 * Author : TUF
 */ 

#include "MDIO.h"
#include "MPORT.h"
#include "HSWITCH.h"


int main(void)
{
    MPORT_vPortInit(); 
	HSWITCH_vSWITCH_init();
	
	u8 state1 ,state2 ;
	
    while (1) 
    {
		HSWITCH_enuGetSwitchState(SWITCH1 ,&state1);
		HSWITCH_enuGetSwitchState(SWITCH2 ,&state2);
		if(state1 == 0)
		{
			MDIO_enuSetPinValue(MDIO_enuPORTA , MDIO_enuPIN0 , MDIO_enuHIGH);
			MDIO_enuSetPinValue(MDIO_enuPORTA , MDIO_enuPIN1 , MDIO_enuLOW);
			
			
		}
		if(state2==0)
		{
			MDIO_enuSetPinValue(MDIO_enuPORTA , MDIO_enuPIN1 , MDIO_enuHIGH);
			MDIO_enuSetPinValue(MDIO_enuPORTA , MDIO_enuPIN0 , MDIO_enuLOW);
		
			
		}
    }
}

