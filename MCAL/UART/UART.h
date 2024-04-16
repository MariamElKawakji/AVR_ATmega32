/*
 * UART.h
 *
 *  Created on: Apr 5, 2024
 *      Author: Marii
 */

#ifndef MCAL_UART_UART_H_
#define MCAL_UART_UART_H_

#include "Common_Files/STD_TYPES.h"
#include "Common_Files/UTILS.h"
#include "UART_Registers.h"

void UART_INIT(void);
void UART_Send(u8 data);

u8 UART_Receive(void);
u8 UART_ReceivePeriodic(u8 *pdata);


void UART_RX_EnableInterrupt(void);
void UART_RX_DisableInterrupt(void);
void UART_RX_SetCallback(void (*fptr_local) (void));
void UART_TX_EnableInterrupt(void);
void UART_TX_DisableInterrupt(void);
void UART_TX_SetCallback(void (*fptr_local) (void));
void UART_SendNoBlock(u8 data); /*for interrupt*/
u8 UART_ReceiveNoBlock(void);	/*for interrupt*/

#endif /* MCAL_UART_UART_H_ */
