/*
 * HSWITCH.c
 *
 * Created: 1/2/2025 8:45:27 PM
 *  Author: Yasmeen
 */ 

#include "MPORT.h"
#include "MDIO.h"
#include "HSWITCH_config.h"
#include "HSWITCH.h"
#include "STD_TYPES.h"

#define NULL ((void*)0)

#define IS_INVALID_PTR(X)				((X) == NULL)
#define IS_INVALID_SWITCH_NAME(X)			((((u8)X) > Num_of_SWITCH) || (((u8)X) < 0))

extern HSWITCH_strSWITCHCONFG_t HSWITCH_enuArrSwitchCongf[Num_of_SWITCH];


void HSWITCH_vSWITCH_init(void)
{
	HSWITCH_enuErrorStatus_t Ret_enuError = HSWITCH_enuNOK;
	u8 Local_u8_currentPinPort=0;
	u8 Local_u8_i=0;
	for(Local_u8_i =0 ; Local_u8_i < Num_of_SWITCH ; Local_u8_i++)
	{
		Local_u8_currentPinPort = ((HSWITCH_enuArrSwitchCongf[Local_u8_i].PORT<<4) + HSWITCH_enuArrSwitchCongf[Local_u8_i].PIN);
		MPORT_enuSetPinDirection(Local_u8_currentPinPort , MPORT_enuPININPUT);
		if(HSWITCH_enuArrSwitchCongf[Local_u8_i].CONNECTION == HSWITCH_enuPullUP)
		{
			 Ret_enuError = MPORT_enuSetPinMode(Local_u8_currentPinPort ,MPORT_enuINPUT_PULL_UP);
		}
		else if(HSWITCH_enuArrSwitchCongf[Local_u8_i].CONNECTION == HSWITCH_enuPullDown)
		{
			 Ret_enuError = MPORT_enuSetPinMode(Local_u8_currentPinPort ,MPORT_enuINPUT_PULL_DOWN);
		}
		else
		{
			Ret_enuError = HSWITCH_enuINVALID_SWITCHConnection;
		}
		
		
	}
}


HSWITCH_enuErrorStatus_t HSWITCH_enuGetSwitchState(u8 Copy_u8SwitchName, u8* Add_pu8State)
{
	HSWITCH_enuErrorStatus_t Ret_enuError = HSWITCH_enuNOK;
	
	// Validate input parameters
	if (IS_INVALID_SWITCH_NAME(Copy_u8SwitchName))
	{
		Ret_enuError = HSWITCH_enuINVALID_SwitchName;
		
	}
	else if (IS_INVALID_PTR(Add_pu8State))
	{
		Ret_enuError = HSWITCH_enuNULL_PTR;
	}
	else
	{
		Ret_enuError = HSWITCH_enuOK;
		Ret_enuError =MDIO_enuGetPinValue(HSWITCH_enuArrSwitchCongf[Copy_u8SwitchName].PORT,HSWITCH_enuArrSwitchCongf[Copy_u8SwitchName].PIN,Add_pu8State);

	}
	return Ret_enuError;
	
}