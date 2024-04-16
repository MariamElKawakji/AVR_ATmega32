/*
 * SPI_Interface.h
 *
 *  Created on: Apr 12, 2024
 *      Author: Marii
 */

#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_

#include "Common_Files/STD_TYPES.h"
#include "Common_Files/UTILS.h"
#include "SPI_Registers.h"
#include "SPI_CFG.h"

typedef enum{
	MASTER,
	SLAVE
}MasterSlave_Type;

void SPI_INIT(void);
u8 SPI_SendReceive(u8 data);
void SPI_Send(u8 data);
u8 SPI_ReceivePeriodic(u8*pdata);
u8 SPI_Receive(void);
void SPI_InterruptEnable(void);
void SPI_InterruptDisable(void);
void SPI_InterruptSetCallback(void (*local_fptr)(void));


#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
