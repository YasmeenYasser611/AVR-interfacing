/*
 * HLED.c
 *
 * Created: 1/2/2025 3:07:00 PM
 *  Author: Yasmeen
 */ 
#include "MPORT.h"
#include "MDIO.h"
#include "HLED_config.h"
#include "STD_TYPES.h"

#define IS_INVALID_LED_NAME(X)			((((u8)X) > Num_of_Led) || (((u8)X) < 0))
#define IS_INVALID_LED_VALUE(X)			((((HLED_enuState_t)X) > HLED_enuOFF) || (((HLED_enuState_t)X) < HLED_enuON))

extern HLED_strLedCONFG_t HLED_enuArrLedCongf[Num_of_Led];


void HLED_vLED_init(void)
{
	u8 Local_u8_currentPinPort=0;
	u8 Local_u8_i=0;
	for(Local_u8_i =0 ; Local_u8_i < Num_of_Led ; Local_u8_i++)
	{
		Local_u8_currentPinPort = ((HLED_enuArrLedCongf[Local_u8_i].PORT<<4) + HLED_enuArrLedCongf[Local_u8_i].PIN);
		MPORT_enuSetPinDirection(Local_u8_currentPinPort , MPORT_enuPINOUTPUT);
		
	}
}


HLED_enuErrorStatus_t HLED_enuSetLedState( u8 Copy_u8LedName, HLED_enuState_t Copy_enuState)
{
	MDIO_enuErrorStatus_t Ret_enuError = HLED_enuNOK;
	
	// Validate input parameters
	if (IS_INVALID_LED_NAME(Copy_u8LedName))
	{
		Ret_enuError =HLED_enuINVALID_LEDName ;
		
	}
	else if (IS_INVALID_LED_VALUE(Copy_enuState))
	{
		Ret_enuError = HLED_enuINVALID_LEDValue;
	}
	else
	{
		Ret_enuError = HLED_enuOK;
		if(HLED_enuArrLedCongf[Copy_u8LedName].CONNECTION == HLED_enuForward)
		{
			if(Copy_enuState == HLED_enuON)
			{
				 Ret_enuError = MDIO_enuSetPinValue(HLED_enuArrLedCongf[Copy_u8LedName].PORT ,HLED_enuArrLedCongf[Copy_u8LedName].PIN , MDIO_enuHIGH);
			}
			else
			{
				Ret_enuError = MDIO_enuSetPinValue(HLED_enuArrLedCongf[Copy_u8LedName].PORT ,HLED_enuArrLedCongf[Copy_u8LedName].PIN , MDIO_enuLOW);
			}
		}
		else if(HLED_enuArrLedCongf[Copy_u8LedName].CONNECTION == HLED_enuReverse)
		{
			if(Copy_enuState == HLED_enuON)
			{
				Ret_enuError = MDIO_enuSetPinValue(HLED_enuArrLedCongf[Copy_u8LedName].PORT ,HLED_enuArrLedCongf[Copy_u8LedName].PIN , MDIO_enuLOW);
			}
			else
			{
				Ret_enuError = MDIO_enuSetPinValue(HLED_enuArrLedCongf[Copy_u8LedName].PORT ,HLED_enuArrLedCongf[Copy_u8LedName].PIN , MDIO_enuHIGH);
			}
		}
		else
		{
			Ret_enuError = HLED_enuINVALID_LEDConnection;
		}
		
	   

	}
	return Ret_enuError;
}