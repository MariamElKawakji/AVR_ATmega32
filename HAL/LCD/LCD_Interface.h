/*
 * LCD_Interface.h
 *
 *  Created on: Mar 8, 2024
 *      Author: Marii
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_

#include "Common_Files/STD_TYPES.h"
#include "MCAL/DIO/DIO_Interface.h"
#include "LCD_CFG.h"

typedef enum{
	_unsigned_=-1,      /*  0 to inf : ignores negative numbers*/
	_abs_,				/*  0 to inf : changes negative numbers to positive*/
	_signed_			/*  -inf  to inf : accepts negative and positive*/
}LCD_ABS_NUM;

void LCD_INIT(void);
void LCD_CLR(void);
void LCD_WriteString(u8* u8p_str);     /*   String   */
void LCD_WriteFloat(u32 u32_num);     /* negative and positive */
void LCD_WriteChar(u8 u8_char);       /*   Char   */
void LCD_WriteNum(s32 num, LCD_ABS_NUM abs_control);   //if u want only unsigned numbers to appear
void LCD_WriteBinary(u8 num);
void LCD_WriteHEX(u8 num);
void LCD_Write4DNum(u16 num);
void LCD_ClearDisplay(void);
void LCD_GoTo(u8 line, u8 cell);
void LCD_Create_Character(u8 *pattern, u8 location);
#endif /* HAL_LCD_LCD_INTERFACE_H_ */
