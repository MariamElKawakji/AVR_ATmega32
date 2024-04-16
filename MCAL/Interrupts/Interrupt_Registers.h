/*
 * Interrupt_Registers.h
 *
 *  Created on: Mar 17, 2024
 *      Author: Marii
 */

#ifndef MCAL_INTERRUPTS_INTERRUPT_REGISTERS_H_
#define MCAL_INTERRUPTS_INTERRUPT_REGISTERS_H_

#define SREG	(*(volatile u8*)0x5F)
#define GIE		7	/*Global Interrupt Enable*/

#define MCUCR	(*(volatile u8*)0x5B)
#define ISC11	3
#define ISC10	2
#define ISC01	1
#define ISC00	0
/*
 * 		ISC11/ISC01		ISC10/ISC00		Description (INT1/INT0)
 * 			0				0			Low Level
 * 			0				1			Any Logical Change
 * 			1				0			Falling Edge
 * 			1				1			Rising Edge
 */


#define MCUCSR	(*(volatile u8*)0x5A)
#define ISC2	6

#define GICR	(*(volatile u8*)0x5B)
#define INT1	7	/*External Interrupt Enable 1*/
#define INT0	6	/*External Interrupt Enable 0*/
#define INT2	5	/*External Interrupt Enable 2*/

#define GIFR	(*(volatile u8*)0x5A)
#define INTF1	7	/*External Interrupt Flag 1*/
#define INTF0	6	/*External Interrupt Flag 0*/
#define INTF2	5	/*External Interrupt Flag 2*/


#define sei()	__asm__ __volatile__("sei"::)
#define cli()	__asm__ __volatile__("cli"::)
#define reti()	__asm__ __volatile__("reti"::)
#define ret()	__asm__ __volatile__("ret"::)

#define ISR_NOBLOCK	__attribute__((interrupt))
#define ISR_NAKED	__attribute__((naked))

#define ISR(vector,...)		\
	void vector(void) __attribute__ ((signal)) __VA_ARGS__;\
	void vector(void)

#define RESET		__vector_0 /*External Pin,Power-on Reset,Brown-out Reset,Watchdog Reset,JTAG Reset*/
#define EXT_INT0	__vector_1		/*External Interrupt Request 0*/
#define EXT_INT1	__vector_2		/*External Interrupt Request 1*/
#define EXT_INT2	__vector_3		/*External Interrupt Request 2*/
#define TIMER2COMP	__vector_4		/*Timer/Counter2 Compare Match*/
#define TIMER2OVF	__vector_5		/*Timer/Counter2 Overflow*/
#define TIMER1CAPT	__vector_6		/*Timer/Counter1 Capture Event*/
#define TIMER1COMPA	__vector_7		/*Timer/Counter1 Compare Match A*/
#define TIMER1COMPB	__vector_8		/*Timer/Counter1 Compare Match B*/
#define TIMER1OVF	__vector_9		/*Timer/Counter1 Overflow*/
#define TIMER0COMP	__vector_10		/*Timer/Counter0 Compare Match*/
#define TIMER0OVF	__vector_11		/*Timer/Counter0 Overflow*/
#define SPI_STC		__vector_12		/*Serial Transfer Complete*/
#define USART_RXC	__vector_13		/*USART, Rx Complete*/
#define USART_UDRE	__vector_14		/*USART, Data Register Empty*/
#define USART_TXC	__vector_15		/*USART, Tx Complete*/
#define ADC_CONV	__vector_16		/*ADC Conversion Complete*/
#define EE_RDY		__vector_17		/*EEPROM Ready*/
#define ANA_COMP	__vector_18		/*Analog Comparator*/
#define TWI			__vector_19		/*Two-Wire Serial Interface*/
#define SPM_RDY		__vector_20		/*Store Program Memory Ready*/
#define BAD_vect	__vector_default
#endif /* MCAL_INTERRUPTS_INTERRUPT_REGISTERS_H_ */
