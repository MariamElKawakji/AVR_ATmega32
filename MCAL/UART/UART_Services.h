/*
 * UART_Services.h
 *
 *  Created on: Apr 6, 2024
 *      Author: Marii
 */

#ifndef MCAL_UART_UART_SERVICES_H_
#define MCAL_UART_UART_SERVICES_H_
#include "UART.h"

void UART_SendString(u8 *data);
void UART_ReceiveString(u8 *data);
void UART_ReceiveString2(u8 *data);
void UART_SendNumber(u32 num);
u32 UART_ReceiveNumber(void);
void UART_SendStringCheckSum(u8*str);
u8 UART_ReceiveStringCheckSum(u8*str);
void UART_SendStringAsynch(u8 *data);
void UART_ReceiveStringAsynch(u8 *data);
void UART_BCM_INIT(void);
void UART_BCM_Runnable(u8 *data); /*Must be in a while loop*/
#endif /* MCAL_UART_UART_SERVICES_H_ */
