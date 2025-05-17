/*
 * GIE.c
 *
 * Created: 2/10/2025 1:41:53 PM
 *  Author: TUF
 */ 


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE_private.h"
#include "GIE.h"

void GIE_VoidEnable(void)
{
	SET_BIT(SREG , I_bit);
	
}

void GIE_VoidDisable(void)
{
	CLR_BIT(SREG , I_bit);
	
}