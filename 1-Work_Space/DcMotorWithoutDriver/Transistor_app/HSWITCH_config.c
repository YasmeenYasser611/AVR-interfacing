/*
 * HSWITCH_config.c
 *
 * Created: 1/2/2025 8:45:54 PM
 *  Author: Yasmeen
 */ 

#include "STD_TYPES.h"
#include "HSWITCH_config.h"


HSWITCH_strSWITCHCONFG_t HSWITCH_enuArrSwitchCongf[Num_of_SWITCH] =
{
	[SWITCH1] = {
		.PORT = HSWITCH_enuPORTB,
		.PIN = HSWITCH_enuPIN0,
		.CONNECTION = HSWITCH_enuPullUP
	},
	[SWITCH2] = {
		.PORT = HSWITCH_enuPORTB,
		.PIN = HSWITCH_enuPIN1,
		.CONNECTION = HSWITCH_enuPullUP
	}
};