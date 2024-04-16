/*
 * ADC_Registers.h
 *
 *  Created on: Mar 13, 2024
 *      Author: Marii
 */

#ifndef MCAL_ADC_ADC_REGISTERS_H_
#define MCAL_ADC_ADC_REGISTERS_H_


#define ADMUX	(*(volatile u8*) 0x27)
/*
 *	REFS1 = 0   REFS0 = 0	AREF
 *	REFS1 = 1   REFS0 = 0	AVCC 5v
 *	REFS1 = 1   REFS0 = 1	Internal Voltage 2.56v
 */
#define		REFS1		7
#define		REFS0		6
#define		ADLAR		5
#define		MUX4		4
#define		MUX3		3
#define		MUX2		2
#define		MUX1		1
#define		MUX0		0

#define 	ADCSRA		(*(volatile u8*) 0x26)

#define 	ADEN		7 	/* ADC Enable */
#define		ADSC		6 	/* ADC Start Conversion */
#define		ADATE		5	/* ADC Auto Trigger Enable */
#define		ADIF		4	/* ADC Interrupt Flag */
#define		ADIE		3	/* ADC Interrupt Enable */
/*
 *  ADC Prescaler Select bits 2:0
 *	ADSP2		ADSP1		ADSP0
 *	  0           0           0            2
 *	  0           0           1            2
 *	  0           1           0			   4
 *	  0           1           1            8
 *	  1			  0           0            16
 *	  1           0           1            32
 *	  1           1           0            64
 *	  1           1           1            128
 *
 * */
#define 	ADPS2		2
#define 	ADPS1		1
#define 	ADPS0		0

#define 	ADCH		(*(volatile u8*) 0x25)
#define 	ADCL		(*(volatile u8*) 0x24)
/*since the two addresses are consecutive*/
/*we can read them with short*/
#define 	ADC			(*(volatile u16*) 0x24)
#endif /* MCAL_ADC_ADC_REGISTERS_H_ */
