/*
 * LCD_CFG.h
 *
 *  Created on: Mar 8, 2024
 *      Author: Marii
 */

#ifndef HAL_LCD_LCD_CFG_H_
#define HAL_LCD_LCD_CFG_H_


#define _4_BIT  1
#define _8_BIT  2

/******************* PIN Config *****************/

#define LCD_Mode	_4_BIT

#define   RS     PA1
#define   EN     PA2

#define		LCD_PORT	PORT_A
/****   DB   ****/
#define		D0		PC0
#define		D1		PC1
#define		D2		PC2
#define		D3		PC3
#define		D4		PA3
#define		D5		PA4
#define		D6		PA5
#define		D7		PA6

#endif /* HAL_LCD_LCD_CFG_H_ */
