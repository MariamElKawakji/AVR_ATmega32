/*
 * ADC.c
 *
 *  Created on: Mar 13, 2024
 *      Author: Marii
 */

#include "ADC_Interface.h"
#include "ADC_Private.h"

void ADC_Enable(void){
	SET_BIT(ADCSRA, ADEN);
}

void ADC_Disable(void){
	CLR_BIT(ADCSRA, ADEN);
}

void ADC_INIT(void){
	/* Clock Prescaler*/
	switch(ADC_Prescaler){
		case NoPrescaler: /*Output 2*/
			CLR_BIT(ADCSRA, ADPS2);
			CLR_BIT(ADCSRA, ADPS1);
			CLR_BIT(ADCSRA, ADPS0);
			break;
		case Prescaler_2:
			CLR_BIT(ADCSRA, ADPS2);
			CLR_BIT(ADCSRA, ADPS1);
			SET_BIT(ADCSRA, ADPS0);

			break;
		case Prescaler_4:
			CLR_BIT(ADCSRA, ADPS2);
			SET_BIT(ADCSRA, ADPS1);
			CLR_BIT(ADCSRA, ADPS0);

			break;
		case Prescaler_8:
			CLR_BIT(ADCSRA, ADPS2);
			SET_BIT(ADCSRA, ADPS1);
			SET_BIT(ADCSRA, ADPS0);
			break;
		case Prescaler_16:
			SET_BIT(ADCSRA, ADPS2);
			CLR_BIT(ADCSRA, ADPS1);
			CLR_BIT(ADCSRA, ADPS0);
			break;
		case Prescaler_32:
			SET_BIT(ADCSRA, ADPS2);
			CLR_BIT(ADCSRA, ADPS1);
			SET_BIT(ADCSRA, ADPS0);
			break;
		case Prescaler_64:
			SET_BIT(ADCSRA, ADPS2);
			SET_BIT(ADCSRA, ADPS1);
			CLR_BIT(ADCSRA, ADPS0);
			break;
		case Prescaler_128:
			SET_BIT(ADCSRA, ADPS2);
			SET_BIT(ADCSRA, ADPS1);
			SET_BIT(ADCSRA, ADPS0);
			break;
		}
	/*
	 * OR
	 * ADCSRA &= 0xF8;    1111 1000
	 * prescaler&=0x07;   0000 0111
	 * ADCSRA|=prescaler;
	 *
	 * */

	/* Voltage Reference*/
	switch(ADC_VREF){
		case ADC_AREF:
			CLR_BIT(ADMUX, REFS1);
			CLR_BIT(ADMUX, REFS0);
			break;
		case ADC_AVCC:
			CLR_BIT(ADMUX, REFS1);
			SET_BIT(ADMUX, REFS0);
			break;
		case ADC_V256:
			SET_BIT(ADMUX, REFS1);
			SET_BIT(ADMUX, REFS0);
			break;
	}
	CLR_BIT(ADMUX,ADLAR);
	ADC_Enable(); /*Enabling the peripheral must be the last thing after its initialization*/

}
u16 ADC_READ(ADC_Channel channel){
	/*u16 return_u16Reading = 0;*/
	ADMUX &= 0xE0;
	ADMUX|=channel;
	SET_BIT(ADCSRA,ADSC);
	while(READ_BIT(ADCSRA,ADSC));
	/*return_u16Reading = ADC;*/

	return ADC;
}
static u8 read_flag = 1;
void ADC_StartConversion(ADC_Channel channel){
	if(read_flag ==1)
	{
		ADMUX &= 0xE0;
		ADMUX|=channel;
		SET_BIT(ADCSRA,ADSC);
		read_flag = 0;
	}

}
u16 ADC_GetRead(void){
	u16 return_u16read = 0;
	while(READ_BIT(ADCSRA,ADSC));
	read_flag = 1;
	return return_u16read;

}

u16 ADC_GetVolt(ADC_Channel channel){
	u16 current_reading = 0;
	u16 V_reading = 0;
	current_reading = ADC_READ(channel);
	V_reading = ((u32)current_reading*5000)/1024;
	return V_reading;  /* mV */
}

u8 ADC_GetReadPeriodicCheck(u16*pdata){
	if(READ_BIT(ADCSRA,ADSC)){
		*pdata = ADC;
		read_flag = 1;
		return 1;
	}
	else{
		return 0;
	}
	/*
	 * In main()
	 * int main(){
	 * while(1){
	 * if(ADC_GetReadPeriodicCheck(u16*pdata)){
	 * LCD_WriteNum(adc);
	 * }
	 * }
	 *  }
	 */
}

u16 ADC_GetReadNoBlock(void){
	return ADC;
}
