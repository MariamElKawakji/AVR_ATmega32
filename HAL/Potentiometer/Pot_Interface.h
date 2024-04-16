/*
 * Pot_Interface.h
 *
 *  Created on: Mar 16, 2024
 *      Author: Marii
 */

#ifndef HAL_POTENTIOMETER_POT_INTERFACE_H_
#define HAL_POTENTIOMETER_POT_INTERFACE_H_

#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/ADC/ADC_Interface.h"

u16 POT_GetPercent(ADC_Channel channel);

#endif /* HAL_POTENTIOMETER_POT_INTERFACE_H_ */
