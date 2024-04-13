/*
 * GIE_Prog.c
 *
 *  Created on: Sep 24, 2022
 *      Author: Abdelrahman
 */


#include "GIE_Interface.h"
#include "GIE_Private.h"

void M_GIE_Void_GlobalIntEnable(void)
{
	SET_BIT(SREG_REG,I_BIT);
}
void M_GIE_Void_GlobalIntDisable(void)
{
	CLR_BIT(SREG_REG,I_BIT);
}
