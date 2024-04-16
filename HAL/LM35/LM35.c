/*
 * LM35.c
 *
 *  Created on: Mar 16, 2024
 *      Author: Marii
 */

#include "LM35_Interface.h"


u16 LM35_GetTemp(ADC_Channel channel){
		u16 return_u16val;
		DIO_INIT_PIN(channel, INPUT);
		return_u16val = ADC_GetVolt(channel);
		/*return_u16val/=10;*/
		return return_u16val;
}
