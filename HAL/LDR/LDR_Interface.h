/*
 * LDR_Interface.h
 *
 *  Created on: Mar 15, 2024
 *      Author: Marii
 */

#ifndef HAL_LDR_LDR_INTERFACE_H_
#define HAL_LDR_LDR_INTERFACE_H_

#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/ADC/ADC_Interface.h"

void LDR_INIT(void);
u16 LDR_READ(ADC_Channel channel);

#endif /* HAL_LDR_LDR_INTERFACE_H_ */
