/*
 * UART.c
 *
 *  Created on: Apr 5, 2024
 *      Author: Marii
 */

#include "UART.h"
#include "MCAL/Interrupts/Interrupt_Registers.h"

void UART_INIT(void){
	/*Baud rate 9600, 8Mhz, Normal speed*/
	UBRRL = 51;
	/*Normal Speed*/
	CLR_BIT(UCSRA,U2X);
	/*Frame -> parity, data bits, stop bits*/

	/*Enable Tx*/
	SET_BIT(UCSRB, TXEN);
	/*Enable Rx*/
	SET_BIT(UCSRB, RXEN);


}
void UART_Send(u8 data){
	while(!READ_BIT(UCSRA, UDRE));
	UDR = data;
}


u8 UART_Receive(void){
	while(!READ_BIT(UCSRA,RXC));
	return UDR;
}

u8 UART_ReceivePeriodic(u8 *pdata){
	if(READ_BIT(UCSRA, RXC)){
		*pdata = UDR;
		return 1;
	}
	return 0;
}

void UART_RX_EnableInterrupt(void){
	SET_BIT(SREG, 7);
	/*Set bit of uart reg*/
}
void UART_RX_DisableInterrupt(void){
	/*clr bit of uart reg*/
}
static void (*fptr_UART_RX) (void) = NULLPTR;
void UART_RX_SetCallback(void (*fptr_local) (void)){
	fptr_UART_RX = fptr_local;
}
void UART_TX_EnableInterrupt(void){
	SET_BIT(SREG, 7);
	/*Set bit of uart reg*/
}
void UART_TX_DisableInterrupt(void){
	/*clr bit of uart reg*/
}
static void (*fptr_UART_TX) (void) = NULLPTR;
void UART_TX_SetCallback(void (*fptr_local) (void)){
	fptr_UART_TX = fptr_local;
}

void UART_SendNoBlock(u8 data) /*for interrupt func*/
{
	UDR = data;
}
u8 UART_ReceiveNoBlock(void){
	return UDR;
}


ISR(USART_RXC){
	if(fptr_UART_RX != NULLPTR)
		fptr_UART_RX();
}

ISR(USART_TXC){
	if(fptr_UART_TX != NULLPTR)
		fptr_UART_TX();
}

