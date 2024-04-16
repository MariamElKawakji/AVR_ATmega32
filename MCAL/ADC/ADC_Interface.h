/*
 * ADC_Interface.h
 *
 *  Created on: Mar 13, 2024
 *      Author: Marii
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_

#include "Common_Files/STD_TYPES.h"
#include "Common_Files/UTILS.h"
#include "ADC_Registers.h"
#include "ADC_LCFG.h"

typedef enum{
	CH0,
	CH1,
	CH2,
	CH3,
	CH4,
	CH5,
	CH6,
	CH7
}ADC_Channel;

typedef enum{
	ADC_AREF,
	ADC_AVCC,
	ADC_V256 = 3
}ADC_Vref_Type;

typedef enum{
	NoPrescaler,
	Prescaler_2,
	Prescaler_4,
	Prescaler_8,
	Prescaler_16,
	Prescaler_32,
	Prescaler_64,
	Prescaler_128
}ADC_Prescaler_Type;

void ADC_INIT(void);
u16 ADC_READ(ADC_Channel channel);  /*u16 because 10 bits --> data type = short*/
u16 ADC_GetVolt(ADC_Channel channel);
void ADC_Enable(void);
void ADC_Disable(void);
void ADC_StartConversion(ADC_Channel channel);
u16 ADC_GetRead(void);
u8 ADC_GetReadPeriodicCheck(u16*pdata);
u16 ADC_GetReadNoBlock(void);



#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
