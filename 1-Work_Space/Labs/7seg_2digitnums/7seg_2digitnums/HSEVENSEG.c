/*
 * HSEVENSEG.c
 *
 * Created: 1/5/2025 11:17:12 AM
 *  Author: yasmeen
 */ 

#include "HSEVENSEG.h"
#include "HSEVENSEG_config.h"
#include "MPORT.h"
#include "MDIO.h"
#include "STD_TYPES.h"

#define NULL ((void*)0)

extern  HSEVENSEG_strSWITCHCONFG_t HSEVENSEG_enuArrHEVENSEGCongf[Num_of_SEVENSEG];
u8 HSEVENSEG_enuCC_Patterns[10] = {
	HSEVENSEG_enuSEVENSEGCC_ZERO, HSEVENSEG_enuSEVENSEGCC_ONE,
	HSEVENSEG_enuSEVENSEGCC_TWO, HSEVENSEG_enuSEVENSEGCC_THREE,
	HSEVENSEG_enuSEVENSEGCC_FOUR, HSEVENSEG_enuSEVENSEGCC_FIVE,
	HSEVENSEG_enuSEVENSEGCC_SIX, HSEVENSEG_enuSEVENSEGCC_SEVEN,
	HSEVENSEG_enuSEVENSEGCC_EIGHT, HSEVENSEG_enuSEVENSEGCC_NINE
};


u8 HSEVENSEG_enuCA_Patterns[10] = {
	HSEVENSEG_enuSEVENSEGCA_ZERO, HSEVENSEG_enuSEVENSEGCA_ONE,
	HSEVENSEG_enuSEVENSEGCA_TWO, HSEVENSEG_enuSEVENSEGCA_THREE,
	HSEVENSEG_enuSEVENSEGCA_FOUR, HSEVENSEG_enuSEVENSEGCA_FIVE,
	HSEVENSEG_enuSEVENSEGCA_SIX, HSEVENSEG_enuSEVENSEGCA_SEVEN,
	HSEVENSEG_enuSEVENSEGCA_EIGHT, HSEVENSEG_enuSEVENSEGCA_NINE
};

#define IS_INVALID_SEVENSEG_NAME(X)			((((u8)X) > Num_of_SEVENSEG) || (((u8)X) < 0))
#define IS_INVALID_SEVENSEG_VALUE(X)			((((u8)X) > 9) || (((u8)X) < 0))


void HSEVENSEG_vInit(void)
{
	
	u8 Local_u8_LED1PinPort=0 ,Local_u8_LED2PinPort=0 ,Local_u8_LED3PinPort=0 ,Local_u8_LED4PinPort=0 ,Local_u8_LED5PinPort=0 ,Local_u8_LED6PinPort=0 ,Local_u8_LED7PinPort=0 ,Local_u8_DOTPinPort=0 ,Local_u8_CONPinPort=0  ;
	u8 Local_u8_i=0;
	for(Local_u8_i =0 ; Local_u8_i < Num_of_SEVENSEG ; Local_u8_i++)
	{
		Local_u8_LED1PinPort = ((HSEVENSEG_enuArrHEVENSEGCongf[Local_u8_i].LED1_Port<<4) + HSEVENSEG_enuArrHEVENSEGCongf[Local_u8_i].LED1_Pin);
		MPORT_enuSetPinDirection(Local_u8_LED1PinPort , MPORT_enuPINOUTPUT);
		Local_u8_LED2PinPort = ((HSEVENSEG_enuArrHEVENSEGCongf[Local_u8_i].LED2_Port<<4) + HSEVENSEG_enuArrHEVENSEGCongf[Local_u8_i].LED2_Pin);
		MPORT_enuSetPinDirection(Local_u8_LED2PinPort , MPORT_enuPINOUTPUT);
		Local_u8_LED3PinPort = ((HSEVENSEG_enuArrHEVENSEGCongf[Local_u8_i].LED3_Port<<4) + HSEVENSEG_enuArrHEVENSEGCongf[Local_u8_i].LED3_Pin);
		MPORT_enuSetPinDirection(Local_u8_LED3PinPort , MPORT_enuPINOUTPUT);
		Local_u8_LED4PinPort = ((HSEVENSEG_enuArrHEVENSEGCongf[Local_u8_i].LED4_Port<<4) + HSEVENSEG_enuArrHEVENSEGCongf[Local_u8_i].LED4_Pin);
		MPORT_enuSetPinDirection(Local_u8_LED4PinPort , MPORT_enuPINOUTPUT);
		Local_u8_LED5PinPort = ((HSEVENSEG_enuArrHEVENSEGCongf[Local_u8_i].LED5_Port<<4) + HSEVENSEG_enuArrHEVENSEGCongf[Local_u8_i].LED5_Pin);
		MPORT_enuSetPinDirection(Local_u8_LED5PinPort , MPORT_enuPINOUTPUT);
		Local_u8_LED6PinPort = ((HSEVENSEG_enuArrHEVENSEGCongf[Local_u8_i].LED6_Port<<4) + HSEVENSEG_enuArrHEVENSEGCongf[Local_u8_i].LED6_Pin);
		MPORT_enuSetPinDirection(Local_u8_LED6PinPort , MPORT_enuPINOUTPUT);
		Local_u8_LED7PinPort = ((HSEVENSEG_enuArrHEVENSEGCongf[Local_u8_i].LED7_Port<<4) + HSEVENSEG_enuArrHEVENSEGCongf[Local_u8_i].LED7_Pin);
		MPORT_enuSetPinDirection(Local_u8_LED7PinPort , MPORT_enuPINOUTPUT);
		Local_u8_DOTPinPort = ((HSEVENSEG_enuArrHEVENSEGCongf[Local_u8_i].DOT_Port<<4) + HSEVENSEG_enuArrHEVENSEGCongf[Local_u8_i].DOT_Pin);
		MPORT_enuSetPinDirection(Local_u8_DOTPinPort , MPORT_enuPINOUTPUT);
		Local_u8_CONPinPort = ((HSEVENSEG_enuArrHEVENSEGCongf[Local_u8_i].CONN_Port<<4) + HSEVENSEG_enuArrHEVENSEGCongf[Local_u8_i].CONN_Pin);
		MPORT_enuSetPinDirection(Local_u8_CONPinPort , MPORT_enuPINOUTPUT);

	}

	
}


HSEVENSEG_enuErrorStatus_t HSEVENSEG_vSetValue(u8 Copy_enuSevenSegNum , u8 Copy_u8Value)
{
	HSEVENSEG_enuErrorStatus_t Ret_enuError = HSEVENSEG_enuNOK;
	if(IS_INVALID_SEVENSEG_NAME(Copy_enuSevenSegNum) )
	{
		Ret_enuError = HSEVENSEG_enuINVALID_SEGNAME;

		
	}
	else if(IS_INVALID_SEVENSEG_VALUE(Copy_u8Value))
	{
		Ret_enuError = HSEVENSEG_enuINVALID_SEGVALUE ;
	}
	else
	{
		Ret_enuError = HSEVENSEG_enuOK ;
		u8 Local_u8_segmentPattern =0 ;
		if(HSEVENSEG_enuArrHEVENSEGCongf[Copy_enuSevenSegNum].CONNECTION == HSEVENSEG_enuSEVENSEG_CA)
		{
			MDIO_enuSetPinValue(HSEVENSEG_enuArrHEVENSEGCongf[Copy_enuSevenSegNum].CONN_Port , HSEVENSEG_enuArrHEVENSEGCongf[Copy_enuSevenSegNum].CONN_Pin, MDIO_enuHIGH);
			Local_u8_segmentPattern = HSEVENSEG_enuCA_Patterns[Copy_u8Value] ;
			
		}
		else if(HSEVENSEG_enuArrHEVENSEGCongf[Copy_enuSevenSegNum].CONNECTION == HSEVENSEG_enuSEVENSEG_CC)
		{
			
			MDIO_enuSetPinValue(HSEVENSEG_enuArrHEVENSEGCongf[Copy_enuSevenSegNum].CONN_Port , HSEVENSEG_enuArrHEVENSEGCongf[Copy_enuSevenSegNum].CONN_Pin, MDIO_enuLOW);
			Local_u8_segmentPattern = HSEVENSEG_enuCC_Patterns[Copy_u8Value] ;
		}
		else
		{
			Ret_enuError =HSEVENSEG_enuINVALID_Connection ;
		}
		
		MDIO_enuSetPinValue(HSEVENSEG_enuArrHEVENSEGCongf[Copy_enuSevenSegNum].LED1_Port , HSEVENSEG_enuArrHEVENSEGCongf[Copy_enuSevenSegNum].LED1_Pin,(Local_u8_segmentPattern >> 0) & 0x01 );
		MDIO_enuSetPinValue(HSEVENSEG_enuArrHEVENSEGCongf[Copy_enuSevenSegNum].LED2_Port , HSEVENSEG_enuArrHEVENSEGCongf[Copy_enuSevenSegNum].LED2_Pin,(Local_u8_segmentPattern >> 1) & 0x01 );
		MDIO_enuSetPinValue(HSEVENSEG_enuArrHEVENSEGCongf[Copy_enuSevenSegNum].LED3_Port , HSEVENSEG_enuArrHEVENSEGCongf[Copy_enuSevenSegNum].LED3_Pin,(Local_u8_segmentPattern >> 2) & 0x01 );
		MDIO_enuSetPinValue(HSEVENSEG_enuArrHEVENSEGCongf[Copy_enuSevenSegNum].LED4_Port , HSEVENSEG_enuArrHEVENSEGCongf[Copy_enuSevenSegNum].LED4_Pin,(Local_u8_segmentPattern >> 3) & 0x01 );
		MDIO_enuSetPinValue(HSEVENSEG_enuArrHEVENSEGCongf[Copy_enuSevenSegNum].LED5_Port , HSEVENSEG_enuArrHEVENSEGCongf[Copy_enuSevenSegNum].LED5_Pin,(Local_u8_segmentPattern >> 4) & 0x01 );
		MDIO_enuSetPinValue(HSEVENSEG_enuArrHEVENSEGCongf[Copy_enuSevenSegNum].LED6_Port , HSEVENSEG_enuArrHEVENSEGCongf[Copy_enuSevenSegNum].LED6_Pin,(Local_u8_segmentPattern >> 5) & 0x01 );
		MDIO_enuSetPinValue(HSEVENSEG_enuArrHEVENSEGCongf[Copy_enuSevenSegNum].LED7_Port , HSEVENSEG_enuArrHEVENSEGCongf[Copy_enuSevenSegNum].LED7_Pin,(Local_u8_segmentPattern >> 6) & 0x01 );
		MDIO_enuSetPinValue(HSEVENSEG_enuArrHEVENSEGCongf[Copy_enuSevenSegNum].DOT_Port , HSEVENSEG_enuArrHEVENSEGCongf[Copy_enuSevenSegNum].DOT_Pin,(Local_u8_segmentPattern >> 7) & 0x01 );
		
		
	}
	
	return Ret_enuError;

}


HSEVENSEG_enuErrorStatus_t HSEVENSEG_enuSetMultiDigitValue(u16 Copy_u16Value)
{
	u8 Local_u8_count = 0;
	HSEVENSEG_enuErrorStatus_t Ret_enuError = HSEVENSEG_enuNOK;
	u16 Local_u16_value = Copy_u16Value;  // Store the original value for later use

	// Count the digits
	while (Local_u16_value > 0) 
	{
		Local_u8_count++;
		Local_u16_value /= 10;
	}

	if (IS_INVALID_SEVENSEG_NAME(Local_u8_count)) 
	{
		Ret_enuError = HSEVENSEG_enuINVALID_SEGNUMS;
	} 
	else 
	{
		Ret_enuError = HSEVENSEG_enuOK;

		u8 Local_u8_digits[Local_u8_count];  

		// Reuse the original value to extract digits and store them in reverse order
		for (u8 Local_u8_i = 0; Local_u8_i < Local_u8_count; Local_u8_i++) 
		{
			Local_u8_digits[Local_u8_i] = Copy_u16Value % 10;
			Copy_u16Value /= 10;
		}

		// Now display digits in reverse order (most significant to least significant)
		for (u8 Local_u8_i = 0; Local_u8_i < Local_u8_count; Local_u8_i++) 
		{
			HSEVENSEG_vSetValue(Local_u8_i, Local_u8_digits[Local_u8_count - 1 - Local_u8_i]);
		}
	}

	return Ret_enuError;
}


