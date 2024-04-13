/*
 * LM35_Prog.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#include "LM35_Interface.h"



void H_LM35_Void_LM35Init(void)
{
	M_ADC_Void_ADCInit();
}
void H_LM35_Void_LM35Read(u16*Copy_U16_Ptr)
{
	u16 Local_U16_ADCReading = 0;
	Local_U16_ADCReading     = M_ADC_U16_ADCRead(LM35_CHANNEL);
	*Copy_U16_Ptr            = ((u32)Local_U16_ADCReading * 500 ) / 1023;
}
