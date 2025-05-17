/*
 * KPD_confg.c
 *
 * Created: 2/4/2025 10:24:53 AM
 *  Author: TUF
 */ 
#include "KPD.h"
#include "KPD_confg.h"



HKPD_strKPDElement_t HKPD_enuArrKPDCongf[Num_of_KPD] =
{
	[KPD1] = {
		.Rows = {
			{.KPD_PORT=HKPD_enuPORTA, .KPD_PIN=HKPD_enuPIN0},
			{.KPD_PORT=HKPD_enuPORTA, .KPD_PIN= HKPD_enuPIN1},
			{.KPD_PORT=HKPD_enuPORTA, .KPD_PIN =HKPD_enuPIN2},
			{.KPD_PORT=HKPD_enuPORTA, .KPD_PIN =HKPD_enuPIN3}
		},
		.Cols = {
			{.KPD_PORT=HKPD_enuPORTA, .KPD_PIN =HKPD_enuPIN4},
			{.KPD_PORT=HKPD_enuPORTA, .KPD_PIN =HKPD_enuPIN5},
			{.KPD_PORT=HKPD_enuPORTA, .KPD_PIN  = HKPD_enuPIN6},
			{.KPD_PORT=HKPD_enuPORTA, .KPD_PIN = HKPD_enuPIN7}
		},
		.Symboles = {
			{'1', '2', '3', 'A'},
			{'4', '5', '6', 'B'},
			{'7', '8', '9', 'C'},
			{'*', '0', '#', 'D'}
		}
	}
};