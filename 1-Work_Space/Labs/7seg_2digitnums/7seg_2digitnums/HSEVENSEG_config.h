/*
 * HSEVENSEG_config.h
 *
 * Created: 1/5/2025 11:18:41 AM
 *  Author: yasmeen
 */ 


#ifndef HSEVENSEG_CONFIG_H_
#define HSEVENSEG_CONFIG_H_


#include "STD_TYPES.h"

typedef enum
{
	HSEVENSEG_enuOK = 0,
	HSEVENSEG_enuNOK,
	HSEVENSEG_enuINVALID_PortNum,
	HSEVENSEG_enuINVALID_PinNum ,
	HSEVENSEG_enuINVALID_Connection ,
	HSEVENSEG_enuINVALID_SEGNAME ,
	HSEVENSEG_enuINVALID_SEGVALUE , 
	HSEVENSEG_enuINVALID_SEGNUMS
	
} HSEVENSEG_enuErrorStatus_t;

 typedef enum                                  //      7  6 5 4 3 2 1 0               
{                                              // COM DOT G F E D C B A 
	HSEVENSEG_enuSEVENSEGCC_ZERO = 0x3F,       // 0    0  0 1 1 1 1 1 1
	HSEVENSEG_enuSEVENSEGCC_ONE = 0x06,        // 0    0  0 0 0 0 1 1 0
	HSEVENSEG_enuSEVENSEGCC_TWO  = 0x5B,       // 0    0  1 0 1 1 0 1 1
	HSEVENSEG_enuSEVENSEGCC_THREE = 0x4F,      // 0    0  1 0 0 1 1 1 1
	HSEVENSEG_enuSEVENSEGCC_FOUR = 0x66,       // 0    0  1 1 0 0 1 1 0
	HSEVENSEG_enuSEVENSEGCC_FIVE = 0x6D,       // 0    0  1 1 0 1 1 0 1
	HSEVENSEG_enuSEVENSEGCC_SIX = 0x7D,        // 0    0  1 1 1 1 1 0 1
	HSEVENSEG_enuSEVENSEGCC_SEVEN = 0x07,      // 0    0  0 0 0 0 1 1 1
	HSEVENSEG_enuSEVENSEGCC_EIGHT = 0x7F,      // 0    0  1 1 1 1 1 1 1
	HSEVENSEG_enuSEVENSEGCC_NINE =0x6F,        // 0    0  1 1 0 1 1 1 1
	HSEVENSEG_enuSEVENSEGCC_OFF = 0            // 0    0  0 0 0 0 0 0 0
	
	
} HSEVENSEG_enu_SEVENSEG_CC_t;




typedef enum
{                                              // COM DOT G F E D C B A 
	HSEVENSEG_enuSEVENSEGCA_ZERO =0xC0 ,       // 1    1  1 0 0 0 0 0 0
	HSEVENSEG_enuSEVENSEGCA_ONE = 0xF9,        // 1    1  1 1 1 1 0 0 1
	HSEVENSEG_enuSEVENSEGCA_TWO  =0xA4 ,       // 1    1  0 1 0 0 1 0 0
	HSEVENSEG_enuSEVENSEGCA_THREE = 0xB0,      // 1    1  0 1 1 0 0 0 0
	HSEVENSEG_enuSEVENSEGCA_FOUR =0x99 ,       // 1    1  0 0 1 1 0 0 1
	HSEVENSEG_enuSEVENSEGCA_FIVE =0x92 ,       // 1    1  0 0 1 0 0 1 0
	HSEVENSEG_enuSEVENSEGCA_SIX =0x82 ,        // 1    1  0 0 0 0 0 1 0
	HSEVENSEG_enuSEVENSEGCA_SEVEN =0xF8 ,      // 1    1  1 1 1 1 0 0 0
	HSEVENSEG_enuSEVENSEGCA_EIGHT =0x80 ,      // 1    1  0 0 0 0 0 0 0 
	HSEVENSEG_enuSEVENSEGCA_NINE =0x90,        // 1    1  0 0 1 0 0 0 0
	HSEVENSEG_enuSEVENSEGCA_OFF = 0xFF         // 1    1  1 1 1 1 1 1 1
	
} HSEVENSEG_enu_SEVENSEG_CA_t;


typedef enum
{
	HSEVENSEG_enuSEVENSEG_CC =0 ,
	HSEVENSEG_enuSEVENSEG_CA
	
}HSEVENSEG_enuSEVENSEG_ConnectionOptions_t;


typedef enum
{
	HSEVENSEG_enuPORTA = 0,
	HSEVENSEG_enuPORTB,
	HSEVENSEG_enuPORTC,
	HSEVENSEG_enuPORTD
}HSEVENSEG_enuPortNum_t;


typedef enum
{
	HSEVENSEG_enuPIN0 = 0,
	HSEVENSEG_enuPIN1,
	HSEVENSEG_enuPIN2,
	HSEVENSEG_enuPIN3,
	HSEVENSEG_enuPIN4,
	HSEVENSEG_enuPIN5,
	HSEVENSEG_enuPIN6,
	HSEVENSEG_enuPIN7
} HSEVENSEG_enuPinNum_t;



typedef struct
{
	u8 LED1_Port;
	u8 LED1_Pin;
	u8 LED2_Port;
	u8 LED2_Pin;
	u8 LED3_Port;
	u8 LED3_Pin;
	u8 LED4_Port;
	u8 LED4_Pin;
	u8 LED5_Port;
	u8 LED5_Pin;
	u8 LED6_Port;
	u8 LED6_Pin;
	u8 LED7_Port;
	u8 LED7_Pin;
	u8 DOT_Port;
	u8 DOT_Pin;
	u8 CONN_Port;
	u8 CONN_Pin;
	HSEVENSEG_enuSEVENSEG_ConnectionOptions_t CONNECTION;
} HSEVENSEG_strSWITCHCONFG_t;



#define Num_of_SEVENSEG 2


#define  SEVENSEG1 0
#define  SEVENSEG2 1



#endif /* HSEVENSEG_CONFIG_H_ */