/*
 * Timers_Registers.h
 *
 *  Created on: Mar 26, 2024
 *      Author: Marii
 */

#ifndef MCAL_TIMERS_TIMERS_REGISTERS_H_
#define MCAL_TIMERS_TIMERS_REGISTERS_H_


#define SREG	(*(volatile u8*)0x5F)


/******************TIMER 0************************/

#define OCR0 (*(volatile unsigned char*)0x5C)

#define TCCR0 (*(volatile unsigned char*)0x53)
#define FOC0	7
#define WGM00	6
#define COM01	5
#define	COM00	4
#define WGM01	3
#define CS02	2
#define CS01	1
#define CS00	0

#define TCNT0 (*(volatile unsigned char*)0x52)


/*************************************************/

#define TIMSK (*(volatile unsigned char*)0x59)
#define TOIE0 	0
#define OCIE0 	1
#define TOIE1 	2
#define OCIE1B 	3
#define OCIE1A 	4
#define TICIE1 	5
#define TOIE2 	6
#define OCIE2	7

#define TIFR (*(volatile unsigned char*)0x58)
#define TOV0	0
#define OCF0	1
#define TOV1	2
#define OCF1B	3
#define OCF1A	4
#define ICF1	5
#define TOV2	6
#define OCF2	7


/*******************TIMER 1***********************/

#define TCCR1A (*(volatile unsigned char*)0x4F)
#define COM1A1	7
#define COM1A0	6
#define COM1B1	5
#define COM1B0	4
#define FOC1A	3
#define FOC1B	2
#define WGM11	1
#define WGM10	0

#define TCCR1B (*(volatile unsigned char*)0x4E)
#define ICNC1	7
#define ICES1	6
#define WGM13	4
#define WGM12	3
#define CS12	2
#define CS11	1
#define CS10	0

#define TCNT1H (*(volatile unsigned char*)0x4D)
#define TCNT1L (*(volatile unsigned char*)0x4C)
#define TCNT1	(*(volatile unsigned short*) 0x4C)

#define OCR1AH (*(volatile unsigned char*)0x4B)
#define OCR1AL (*(volatile unsigned char*)0x4A)
#define OCR1A	(*(volatile unsigned short*) 0x4A)

#define OCR1BH (*(volatile unsigned char*)0x49)
#define OCR1BL (*(volatile unsigned char*)0x48)
#define OCR1B	(*(volatile unsigned short*) 0x48)

/*******************ICU*********************/
#define ICR1H (*(volatile unsigned char*)0x47)
#define ICR1L (*(volatile unsigned char*)0x46)
#define ICR1	(*(volatile unsigned short*) 0x46)



/******************TIMER 2**********************/

#define TCCR2 (*(volatile unsigned char*)0x45)
#define FOC2	7
#define WGM20	6
#define COM21	5
#define COM20	4
#define WGM21	3
#define CS22	2
#define CS21	1
#define CS20	0

#define TCNT2 (*(volatile unsigned char*)0x44)

#define OCR2 (*(volatile unsigned char*)0x43)

#define ASSR (*(volatile unsigned char*)0x42)
#define AS2		3
#define TCN2UB	2
#define OCR2UB	1
#define TCR2UB	0

#define WDTCR (*(volatile unsigned char*)0x41)

#define SFIOR (*(volatile unsigned char*)0x50)
#define PSR2	1

#endif /* MCAL_TIMERS_TIMERS_REGISTERS_H_ */
