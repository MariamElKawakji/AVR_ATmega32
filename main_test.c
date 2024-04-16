/*
 * main_test.c
 *
 *  Created on: Mar 7, 2024
 *      Author: Marii
 */


#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/ADC/ADC_Interface.h"
#include "MCAL/Timers/Timers.h"
#include "MCAL/Interrupts/Interrupt.h"
#include "HAL/LCD/LCD_Interface.h"
#include "HAL/LDR/LDR_Interface.h"
#include "HAL/Potentiometer/Pot_Interface.h"
#include "HAL/LM35/LM35_Interface.h"
#include "HAL/Keypad/Keypad_Interface.h"
#include <util/delay.h>
#include "APP/LCD_APPS.h"
#include "MCAL/UART/UART.h"
#include "MCAL/UART/UART_Services.h"
#include "MCAL/SPI/SPI_Interface.h"
#include "MCAL/SPI/SPI_Services.h"

int main(){
		DIO_INIT();
		LCD_INIT();
		UART_INIT();
		while(1){

		}

	return 0;
}
