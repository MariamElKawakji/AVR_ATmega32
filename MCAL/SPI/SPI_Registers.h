/*
 * SPI_Registers.h
 *
 *  Created on: Apr 12, 2024
 *      Author: Marii
 */

#ifndef MCAL_SPI_SPI_REGISTERS_H_
#define MCAL_SPI_SPI_REGISTERS_H_

#define SPDR (*(volatile unsigned char*)0x2F) /*Data Register*/

#define SPSR (*(volatile unsigned char*)0x2E)
#define SPIF 	7
#define WCOL 	6
#define SPI2X 	0

#define SPCR (*(volatile unsigned char*)0x2D)
#define SPIE 	7
#define SPE 	6
#define DORD	5
#define MSTR	4
#define CPOL	3
#define CPHA	2
#define SPR1	1
#define SPR0	0

#endif /* MCAL_SPI_SPI_REGISTERS_H_ */
