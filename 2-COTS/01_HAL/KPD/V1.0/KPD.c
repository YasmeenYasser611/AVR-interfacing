/*
 * KPD.c
 *
 * Created: 2/4/2025 10:24:21 AM
 *  Author: TUF
 */ 

#include "MPORT.h"
#include "MDIO.h"
#include "KPD_confg.h"
#include "KPD.h"
#include "STD_TYPES.h"


extern HKPD_strKPDElement_t HKPD_enuArrKPDCongf[Num_of_KPD];


void HKPD_vKPD_init(void)
{
	u8 Local_u8_currentPinPort = 0;
	u8 Local_u8_i = 0, Local_u8_rows = 0, Local_u8_cols = 0;

	for (Local_u8_i = 0; Local_u8_i < Num_of_KPD; Local_u8_i++) 
	{

		for (Local_u8_rows = 0; Local_u8_rows < KPD_ROWS; Local_u8_rows++) {
			Local_u8_currentPinPort = ((HKPD_enuArrKPDCongf[Local_u8_i].Rows[Local_u8_rows].KPD_PORT << 4) +HKPD_enuArrKPDCongf[Local_u8_i].Rows[Local_u8_rows].KPD_PIN);
			MPORT_enuSetPinDirection(Local_u8_currentPinPort, MPORT_enuPININPUT);
			MPORT_enuSetPinMode(Local_u8_currentPinPort, MPORT_enuINPUT_PULL_UP);
		}
		// Initialize columns as output and set to HIGH
		for (Local_u8_cols = 0; Local_u8_cols < KPD_COLS; Local_u8_cols++) 
		{
			Local_u8_currentPinPort = ((HKPD_enuArrKPDCongf[Local_u8_i].Cols[Local_u8_cols].KPD_PORT << 4) +HKPD_enuArrKPDCongf[Local_u8_i].Cols[Local_u8_cols].KPD_PIN);
			MPORT_enuSetPinDirection(Local_u8_currentPinPort, MPORT_enuPINOUTPUT);
			MDIO_enuSetPinValue(HKPD_enuArrKPDCongf[Local_u8_i].Cols[Local_u8_cols].KPD_PORT,HKPD_enuArrKPDCongf[Local_u8_i].Cols[Local_u8_cols].KPD_PIN, MDIO_enuHIGH);
		}
	}
}

HKPD_enuErrorStatus_t HKPD_enuKPD_GetKey(u8 Copy_enuKPDNum, u8* Copy_enuKPDKey)
{
	HKPD_enuErrorStatus_t Ret_enuError = HKPD_enuOK;

	if (Copy_enuKPDKey == NULL)
	{
		Ret_enuError = HKPD_enuNullPointer;
	}
	else
	{
		u8 Local_u8_rows = 0, Local_u8_cols = 0, Local_u8_value = 100, Local_u8_Key = 100, Local_u8_flag = 0;

		// Iterate through the columns
		for (Local_u8_cols = 0; Local_u8_cols < KPD_COLS; Local_u8_cols++)
		{
			// Set the current column to LOW (active)
			MDIO_enuSetPinValue(HKPD_enuArrKPDCongf[Copy_enuKPDNum].Cols[Local_u8_cols].KPD_PORT,HKPD_enuArrKPDCongf[Copy_enuKPDNum].Cols[Local_u8_cols].KPD_PIN, MDIO_enuLOW);

			// Iterate through the rows
			for (Local_u8_rows = 0; Local_u8_rows < KPD_ROWS; Local_u8_rows++)
			{
				// Read the row pin value
				MDIO_enuGetPinValue(HKPD_enuArrKPDCongf[Copy_enuKPDNum].Rows[Local_u8_rows].KPD_PORT,HKPD_enuArrKPDCongf[Copy_enuKPDNum].Rows[Local_u8_rows].KPD_PIN, &Local_u8_value);

				if (Local_u8_value == 0)  // Key is pressed
				{
					Local_u8_Key = HKPD_enuArrKPDCongf[Copy_enuKPDNum].Symboles[Local_u8_rows][Local_u8_cols];
					*Copy_enuKPDKey = Local_u8_Key;  // Store the pressed key
					
		        	// Debounce: Wait for key release (ensure key is not held)
		        	while (Local_u8_value == 0)
		        	{
			        	MDIO_enuGetPinValue(HKPD_enuArrKPDCongf[Copy_enuKPDNum].Rows[Local_u8_rows].KPD_PORT,HKPD_enuArrKPDCongf[Copy_enuKPDNum].Rows[Local_u8_rows].KPD_PIN, &Local_u8_value);
		        	}
				    Local_u8_flag = 1;
					break;  // Exit the loop once the key is detected
				}
			}
			// Set the column back to HIGH (inactive)
			MDIO_enuSetPinValue(HKPD_enuArrKPDCongf[Copy_enuKPDNum].Cols[Local_u8_cols].KPD_PORT,HKPD_enuArrKPDCongf[Copy_enuKPDNum].Cols[Local_u8_cols].KPD_PIN, MDIO_enuHIGH);
			if (Local_u8_flag == 1)
			{
				break;
			}

		}
	}
	return Ret_enuError;
}
