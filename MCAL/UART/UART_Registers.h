/*
 * UART_Registers.h
 *
 *  Created on: Apr 5, 2024
 *      Author: Marii
 */

#ifndef MCAL_UART_UART_REGISTERS_H_
#define MCAL_UART_UART_REGISTERS_H_

#define UCSRC (*(volatile unsigned char*)0x40)
#define	URSEL 	7
#define	UMSEL 	6
#define	UPM1 	5
#define	UPM0 	4
#define	USBS 	3
#define	UCSZ1 	2
#define	UCSZ0 	1
#define	UCPOL 	0

#define UDR (*(volatile unsigned char*)0x2C)

#define UCSRA (*(volatile unsigned char*)0x2B)
#define	U2X 	1
#define	UDRE 	5
#define	TXC 	6
#define	RXC		7

#define UCSRB (*(volatile unsigned char*)0x2A)
#define	TXEN 	3
#define RXEN 	4
#define UBRRL (*(volatile unsigned char*)0x29)

#endif /* MCAL_UART_UART_REGISTERS_H_ */
