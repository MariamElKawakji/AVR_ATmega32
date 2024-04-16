/*
 * MyFuns.c
 *
 *  Created on: Mar 12, 2024
 *      Author: Marii
 */

#include "LCD_APPS.h"


void LCD_Print_ASCII(u8 u8char){
			/*static u8 count = 65;*/
			DIO_INIT();
			LCD_INIT();

			LCD_GoTo(0,0);
			LCD_WriteString((unsigned char *)"ASCII:");
			LCD_GoTo(0,8);
			LCD_WriteNum(u8char, _unsigned_);
			LCD_GoTo(1,0);
			LCD_WriteString((unsigned char *)"Char: ");
			LCD_GoTo(1,8);
			LCD_WriteChar(u8char);
			/*count++;*/
			/*_delay_ms(1000);*/
}

void LCD_Moving_Words(u8* u8char){
	u8 row = 0;
	u8 col = 0;
	DIO_INIT();
	LCD_INIT();
	for(row=0,col=0; col<32; col++){
	LCD_ClearDisplay();
	LCD_GoTo(row,col%16);
	LCD_WriteString(u8char);
	if(col==15){
		row++;
	}
	_delay_ms(300);
	}
}
