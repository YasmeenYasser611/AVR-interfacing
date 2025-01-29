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
	[Led_start] = {
		.PORT = HLED_enuPORTA,
		.PIN = HLED_enuPIN0,
		.CONNECTION = HLED_enuForward
	},
	[Led_1] = {
		.PORT = HLED_enuPORTA,
		.PIN = HLED_enuPIN1,
		.CONNECTION = HLED_enuForward
	},
	[Led_2] = {
		.PORT = HLED_enuPORTA,
		.PIN = HLED_enuPIN2,
		.CONNECTION = HLED_enuForward
	},
	[Led_3] = {
		.PORT = HLED_enuPORTA,
		.PIN = HLED_enuPIN3,
		.CONNECTION = HLED_enuForward
	}, 
	[Led_4] = {
		.PORT = HLED_enuPORTA,
		.PIN = HLED_enuPIN4,
		.CONNECTION = HLED_enuForward
	},
	[Led_5] = {
		.PORT = HLED_enuPORTA,
		.PIN = HLED_enuPIN5,
		.CONNECTION = HLED_enuForward
	},
	[Led_6] = {
		.PORT = HLED_enuPORTA,
		.PIN = HLED_enuPIN6,
		.CONNECTION = HLED_enuForward
	},
	[Led_7] = {
		.PORT = HLED_enuPORTA,
		.PIN = HLED_enuPIN7,
		.CONNECTION = HLED_enuForward
	}
};
