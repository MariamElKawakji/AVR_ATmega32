/*
 * DIO.c
 *
 *  Created on: Mar 3, 2024
 *      Author: Marii
 */

#include "DIO_Interface.h"
#include "DIO_Private.h"


void DIO_INIT_PIN(DIO_PIN pin, DIO_DIRECTION status){
	DIO_PORT_TYPE port = pin/8;
	pin%=8;
	switch(status){
		case INPUT:
			switch(port){
				case PORT_A:
					CLR_BIT(DDRA, pin);
					CLR_BIT(PORTA, pin);
					break;
				case PORT_B:
					CLR_BIT(DDRB, pin);
					CLR_BIT(PORTB, pin);
					break;
				case PORT_C:
					CLR_BIT(DDRC, pin);
					CLR_BIT(PORTC, pin);
					break;
				case PORT_D:
					CLR_BIT(DDRD, pin);
					CLR_BIT(PORTD, pin);
					break;
			}
			break;

		case OUTPUT:
			switch(port){
				case PORT_A:
					SET_BIT(DDRA, pin);
					CLR_BIT(PORTA, pin);
					break;
				case PORT_B:
					SET_BIT(DDRB, pin);
					CLR_BIT(PORTB, pin);
					break;
				case PORT_C:
					SET_BIT(DDRC, pin);
					CLR_BIT(PORTC, pin);
					break;
				case PORT_D:
					SET_BIT(DDRD, pin);
					CLR_BIT(PORTD, pin);
					break;}
			break;
		case INPUT_PULLUP:
				switch(port){
				case PORT_A:
					CLR_BIT(DDRA, pin);
					SET_BIT(PORTA, pin);
					break;
				case PORT_B:
					CLR_BIT(DDRB, pin);
					SET_BIT(PORTB, pin);
					break;
				case PORT_C:
					CLR_BIT(DDRC, pin);
					SET_BIT(PORTC, pin);
					break;
				case PORT_D:
					CLR_BIT(DDRD, pin);
					SET_BIT(PORTD, pin);
					break;}
			break;
	}



}

void DIO_INIT(void){
	for(DIO_PIN i = PA0; i<Total_Pins; i++ ){
		DIO_INIT_PIN(i, Pin_StatusArray[i]);
	}
}

void DIO_WritePin(DIO_PIN pin, DIO_VOLT value){
	DIO_PORT_TYPE port = pin/8;
	u8 pin_num = pin%8;
	switch(port){
				case PORT_A:
					WRITE_BIT(PORTA, pin_num, value);
					break;
				case PORT_B:
					WRITE_BIT(PORTB, pin_num, value);
					break;
				case PORT_C:
					WRITE_BIT(PORTC, pin_num, value);
					break;
				case PORT_D:
					WRITE_BIT(PORTD, pin_num, value);
					break;
				}

}
void DIO_WritePort(DIO_PORT_TYPE port, u8 value){
	switch(port){
		case PORT_A:
			WRITE_PORT(PORTA, value);
			break;
		case PORT_B:
			WRITE_PORT(PORTB, value);
			break;
		case PORT_C:
			WRITE_PORT(PORTC, value);
			break;
		case PORT_D:
			WRITE_PORT(PORTD, value);
			break;
		}
}
DIO_VOLT DIO_ReadPin(DIO_PIN pin){
	DIO_VOLT bool_ReturnVal = LOW;
	DIO_PORT_TYPE port = pin/8;
	pin%=8;
	switch(port){
		case PORT_A:
			bool_ReturnVal = READ_BIT(PORTA, pin);
		 	break;
		case PORT_B:
			bool_ReturnVal = READ_BIT(PORTB, pin);
			break;
		case PORT_C:
			bool_ReturnVal = READ_BIT(PORTC, pin);
			break;
		case PORT_D:
			bool_ReturnVal = READ_BIT(PORTD, pin);
			break;
			}
	return bool_ReturnVal;
}
u8 DIO_ReadPort(DIO_PORT_TYPE port){
	u8 u8_ReturnVal = 0;
	switch(port){
				case PORT_A:
					u8_ReturnVal = READ_PORT(PORTA);
					break;
				case PORT_B:
					u8_ReturnVal = READ_PORT(PORTB);
					break;
				case PORT_C:
					u8_ReturnVal = READ_PORT(PORTC);
					break;
				case PORT_D:
					u8_ReturnVal = READ_PORT(PORTD);
					break;
				}
	return u8_ReturnVal;

}

void DIO_TogglePin(DIO_PIN pin){
	DIO_PORT_TYPE port = pin/8;
	pin%=8;
	switch(port){
		case PORT_A:
			TOGGLE_BIT(PORTA, pin);
			break;
		case PORT_B:
			TOGGLE_BIT(PORTB, pin);
			break;
		case PORT_C:
			TOGGLE_BIT(PORTC, pin);
			break;
		case PORT_D:
			TOGGLE_BIT(PORTD, pin);
			break;
					}

}
