/*
 * DIO_Interface.h
 *
 *  Created on: Mar 3, 2024
 *      Author: Marii
 */

#ifndef DIO_DIO_INTERFACE_H_
#define DIO_DIO_INTERFACE_H_

#include "DIO_Registers.h"
#include "DIO_CFG.h"
#include "Common_Files/UTILS.h"
#include "Common_Files/STD_TYPES.h"


typedef enum{
	INPUT,
	OUTPUT,
	INPUT_PULLUP,
}DIO_DIRECTION;

typedef enum{
	LOW,
	HIGH
}DIO_VOLT;

typedef enum{
	PORT_A,
	PORT_B,
	PORT_C,
	PORT_D
}DIO_PORT_TYPE;

typedef enum{
	PA0,
	PA1,
	PA2,
	PA3,
	PA4,
	PA5,
	PA6,
	PA7,
	PB0,
	PB1,
	PB2,
	PB3,
	PB4,
	PB5,
	PB6,
	PB7,
	PC0,
	PC1,
	PC2,
	PC3,
	PC4,
	PC5,
	PC6,
	PC7,
	PD0,
	PD1,
	PD2,
	PD3,
	PD4,
	PD5,
	PD6,
	PD7,
	Total_Pins
}DIO_PIN;


void DIO_INIT(void);                 //Add extern means its public function
void DIO_INIT_PIN(DIO_PIN pin, DIO_DIRECTION status);//Add static to secure the function, copy in private
void DIO_WritePin(DIO_PIN pin, DIO_VOLT value);
void DIO_WritePort(DIO_PORT_TYPE port, u8 value);
DIO_VOLT DIO_ReadPin(DIO_PIN pin);
u8 DIO_ReadPort(DIO_PORT_TYPE port);
void DIO_TogglePin(DIO_PIN pin);


#endif /* DIO_DIO_INTERFACE_H_ */
