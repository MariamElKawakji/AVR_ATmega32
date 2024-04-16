/*
 * SPI.c
 *
 *  Created on: Apr 12, 2024
 *      Author: Marii
 */


#include "SPI_Interface.h"
#include "MCAL/Interrupts/Interrupt_Registers.h"


void SPI_INIT(void){
	if(Master_Slave_Type == MASTER){
		SET_BIT(SPCR, MSTR);
	}
	else if(Master_Slave_Type == SLAVE){
		CLR_BIT(SPCR, MSTR);
	}
	/*Enable*/
	SET_BIT(SPCR, SPE);
}

u8 SPI_SendReceive(u8 data){
	SPDR = data;
	while(!READ_BIT(SPSR,SPIF));
	return SPDR;
}

void SPI_Send(u8 data){
	SPDR = data;
}

u8 SPI_ReceivePeriodic(u8*pdata){
	if(READ_BIT(SPSR,SPIF)){
		*pdata = SPDR;
		return 1;
	}
	else return 0;
}

u8 SPI_Receive(void){
	return SPDR;
}

void SPI_InterruptEnable(void){
	SET_BIT(SREG, GIE);
	SET_BIT(SPCR, SPIE);
}
void SPI_InterruptDisable(void){
	CLR_BIT(SPCR, SPIE);
}

static void (*fptr_SPI)(void) = NULLPTR;
void SPI_InterruptSetCallback(void (*local_fptr)(void)){
	fptr_SPI = local_fptr;
}

ISR(SPI_STC){
	if(fptr_SPI!=NULLPTR)
	fptr_SPI();
}

