/*
 * LCD_Private.h
 *
 *  Created on: Mar 8, 2024
 *      Author: Marii
 */

#ifndef HAL_LCD_LCD_PRIVATE_H_
#define HAL_LCD_LCD_PRIVATE_H_

static void LCD_WriteCommand(u8 command);
static void LCD_WriteData(u8 data);
static s32 str_len(u8 *arr);

#endif /* HAL_LCD_LCD_PRIVATE_H_ */
