/*
 * KPD.h
 *
 * Created: 2/4/2025 10:25:10 AM
 *  Author: TUF
 */ 
#include "STD_TYPES.h"
#include "KPD_confg.h"


#ifndef KPD_H_
#define KPD_H_



typedef enum
{
	HKPD_enuPORTA = 0,
	HKPD_enuPORTB,
	HKPD_enuPORTC,
	HKPD_enuPORTD
} HKPD_enuPortNum_t;

typedef enum
{
	HKPD_enuPIN0 = 0,
	HKPD_enuPIN1,
	HKPD_enuPIN2,
	HKPD_enuPIN3,
	HKPD_enuPIN4,
	HKPD_enuPIN5,
	HKPD_enuPIN6,
	HKPD_enuPIN7
} HKPD_enuPinNum_t;


typedef struct
{
	u8 KPD_PORT;
	u8 KPD_PIN;
} HKPD_strKPDElementPinConnection_t;



typedef struct
{
	HKPD_strKPDElementPinConnection_t Rows[KPD_ROWS];
	HKPD_strKPDElementPinConnection_t Cols[KPD_COLS];
	u8 Symboles[KPD_ROWS][KPD_COLS];
} HKPD_strKPDElement_t;


typedef enum
{
	HKPD_enuOK = 0,
	HKPD_enuNullPointer

} HKPD_enuErrorStatus_t;


void HKPD_vKPD_init(void);

HKPD_enuErrorStatus_t HKPD_enuKPD_GetKey(u8 Copy_enuKPDNum , u8* Copy_enuKPDKey);



#endif /* KPD_H_ */