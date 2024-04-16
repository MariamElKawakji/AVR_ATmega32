/*
 * Pot.c
 *
 *  Created on: Mar 16, 2024
 *      Author: Marii
 */

#include "Pot_Interface.h"


u16 POT_GetPercent(ADC_Channel channel){
	u16 return_u16val = 0;
	u16 return_val = 0;
	DIO_INIT_PIN(channel, INPUT);
	return_val = ADC_GetVolt(channel);
	return_u16val = (((u32)return_val*100)/5000);
	return return_u16val;
}
