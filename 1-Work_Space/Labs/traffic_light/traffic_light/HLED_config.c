/*
 * HLED_config.c
 *
 * Created: 1/2/2025 3:07:35 PM
 *  Author: TUF
 */ 

#include "STD_TYPES.h"
#include "HLED_config.h"


HLED_strLedCONFG_t HLED_enuArrLedCongf[Num_of_Led] =
{
	[Led_1] = {
		.PORT = HLED_enuPORTD,
		.PIN = HLED_enuPIN0,
		.CONNECTION = HLED_enuForward
	},
	[Led_2] = {
		.PORT = HLED_enuPORTD,
		.PIN = HLED_enuPIN1,
		.CONNECTION = HLED_enuForward
	},
	[Led_3] = {
		.PORT = HLED_enuPORTD,
		.PIN = HLED_enuPIN2,
		.CONNECTION = HLED_enuForward
	}
};
