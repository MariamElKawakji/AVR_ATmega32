/*
 * LDR.c
 *
 *  Created on: Mar 15, 2024
 *      Author: Marii
 */

#include "HAL/LDR/LDR_Interface.h"

void LDR_INIT(void){
	DIO_INIT();
	ADC_INIT();
}

u16 LDR_READ(ADC_Channel channel)
{
	u16 return_u16val = 0;
	DIO_INIT_PIN(channel, INPUT);
	return_u16val = ADC_READ(channel);
	return return_u16val;
}
