/*
 * LCD_APPS.h
 *
 *  Created on: Mar 12, 2024
 *      Author: Marii
 */

#ifndef APP_LCD_APPS_H_
#define APP_LCD_APPS_H_

#define F_CPU 8000000
#include "MCAL/DIO/DIO_Interface.h"
#include "HAL/LCD/LCD_Interface.h"
#include <util/delay.h>

void LCD_Print_ASCII(u8 u8char);
void LCD_Moving_Words(u8* u8char);
#endif /* APP_LCD_APPS_H_ */
