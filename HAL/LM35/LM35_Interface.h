/*
 * LM35_Interface.h
 *
 *  Created on: Mar 16, 2024
 *      Author: Marii
 */

#ifndef HAL_LM35_LM35_INTERFACE_H_
#define HAL_LM35_LM35_INTERFACE_H_

#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/ADC/ADC_Interface.h"

u16 LM35_GetTemp(ADC_Channel channel);



#endif /* HAL_LM35_LM35_INTERFACE_H_ */
