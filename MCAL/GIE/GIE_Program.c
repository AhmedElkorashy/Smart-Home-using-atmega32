/*
 * GIE_Program.c
 *
 *  Created on: Mar 24, 2024
 *      Author: Ibrahim
 */

/**********************LIB***************************/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_Types.h"


/**********************MCAL**************************/
#include "GIE_Config.h"
#include "GIE_Interface.h"
#include "GIE_Private.h"


/**************FUNCTIONS DEFINITIONS*****************/
void GIE_voidEnable(void)
{
	SET_BIT(SREG,SREG_I_BIT);
}

void GIE_voidDisable(void)
{
	CLR_BIT(SREG,SREG_I_BIT);
}


