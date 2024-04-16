/*
 * LCD.c
 *
 *  Created on: Mar 8, 2024
 *      Author: Marii
 */

#define F_CPU 8000000
#include "util/delay.h"
#include"LCD_Interface.h"
#include"LCD_Private.h"

#if LCD_Mode == _4_BIT
static void LCD_WriteCommand(u8 command){
	DIO_WritePin(RS, LOW);
	DIO_WritePin(D7, READ_BIT(command,7));
	DIO_WritePin(D6, READ_BIT(command,6));
	DIO_WritePin(D5, READ_BIT(command,5));
	DIO_WritePin(D4, READ_BIT(command,4));
	DIO_WritePin(EN, HIGH);
	_delay_ms(1);
	DIO_WritePin(EN, LOW);
	_delay_ms(1);
	DIO_WritePin(D7, READ_BIT(command,3));
	DIO_WritePin(D6, READ_BIT(command,2));
	DIO_WritePin(D5, READ_BIT(command,1));
	DIO_WritePin(D4, READ_BIT(command,0));
	DIO_WritePin(EN, HIGH);
	_delay_ms(1);
	DIO_WritePin(EN, LOW);
	_delay_ms(1);
}

static void LCD_WriteData(u8 data){
	DIO_WritePin(RS, HIGH);
	DIO_WritePin(D7, READ_BIT(data,7));
	DIO_WritePin(D6, READ_BIT(data,6));
	DIO_WritePin(D5, READ_BIT(data,5));
	DIO_WritePin(D4, READ_BIT(data,4));
	DIO_WritePin(EN, HIGH);
	_delay_ms(1);
	DIO_WritePin(EN, LOW);
	_delay_ms(1);
	DIO_WritePin(D7, READ_BIT(data,3));
	DIO_WritePin(D6, READ_BIT(data,2));
	DIO_WritePin(D5, READ_BIT(data,1));
	DIO_WritePin(D4, READ_BIT(data,0));
	DIO_WritePin(EN, HIGH);
	_delay_ms(1);
	DIO_WritePin(EN, LOW);
	_delay_ms(1);
}

void LCD_INIT(void){
	_delay_ms(50);
	LCD_WriteCommand(0x02);   // To enable 4 bit config
	LCD_WriteCommand(0x28);  // Function Set: 4-bit, 2-line, 5*8
	LCD_WriteCommand(0x0C);	 // Display On/Off: Display On
	LCD_WriteCommand(0x01);  // Clear LCD: Clear Screen Enabled
 	_delay_ms(1);
	LCD_WriteCommand(0x06);  // Increase DDRAM Address, no shift
}

#elif LCD_Mode == _8_BIT
static void LCD_WriteCommand(u8 command){
	DIO_WritePin(RS, LOW);
	DIO_WritePort(LCD_PORT, command);
	DIO_WritePin(EN, HIGH);
	_delay_ms(1);
	DIO_WritePin(EN, LOW);
	_delay_ms(1);
}

static void LCD_WriteData(u8 data){
	DIO_WritePin(RS, HIGH);
	DIO_WritePort(LCD_PORT, data);
	DIO_WritePin(EN, HIGH);
	_delay_ms(1);
	DIO_WritePin(EN, LOW);
	_delay_ms(1);
}

void LCD_INIT(void){
	_delay_ms(50);
	LCD_WriteCommand(0x38);  // Function Set: 8-bit, 2-line, 5*8
	LCD_WriteCommand(0x0C);	 // Display On/Off: Display On
	LCD_WriteCommand(0x01);  // Clear LCD: Clear Screen Enabled
	_delay_ms(1);
	LCD_WriteCommand(0x06);  // Increase DDRAM Address, no shift
}


#endif



/************************************************************************/

void LCD_WriteChar(u8 u8_char){

	LCD_WriteData(u8_char);

}

void LCD_WriteString(u8* u8p_str){

	for(u8 i=0; u8p_str[i]!='\0'; i++){
		LCD_WriteChar(u8p_str[i]);
	}

}

static s32 str_len(u8 *arr){
	    u8 count;
	    for(count = 0; arr[count]!='\0';count++);
	    return count;
	}
void LCD_WriteNum(s32 num, LCD_ABS_NUM abs_control){
	/*
	 * Another way to write function
	 *
	 * u8 str[20];
	 * u8 rem, i=0;
	 * while(num>0){
	 * rem = num%10;
	 * str[i] = rem + '0';
	 * num = num/10;
	 * i++;
	 * }
	 *	for( s8 j=i-1; j>=0; j--){
	 * 	LCD_WriteChar(str[j]);
	 * 	}
	 *
	 */
	    u8 flag =0;
	    u8 unsigned_arr[10] = {48,49,50,51,52,53,54,55,56,57};
	    u8 arr[10];
	    if(num<0 && abs_control == _signed_) {
	        flag=1;
	        num *=-1;
	    }
	    else if(num<0 && abs_control == _abs_) {
	    	        flag=0;
	    	        num *=-1;
	    }
	    else if(num<0 && abs_control == _unsigned_) {
	    	    	        flag= 0;
	    	    	        num = 0;
	    	    	        arr[0] = '0';
	    	    }
	    else if(num<=0||num<=1) {
	    	    	    	        flag= 0;
	    	    	    	        num = 0;
	    	    	    	        arr[0] = '0';
	    	    	    }
	    u8 rem = 0;
	    s32 mul_num = num;
	    for(s32 i=10, j=0; mul_num!=0; i*=10, j++){
	        rem = mul_num%10;
	        mul_num = num/i;
	        arr[j] = unsigned_arr[rem];
	        if(mul_num==0){
	            if(flag==1) arr[++j] = '-';
	            arr[++j] = '\0';
	        }
	    }

	    for(u8 k=0; k<str_len(arr)/2; k++){
	        u8 size = str_len(arr);
	        u8 temp;
	        temp = arr[k];
	        arr[k] = arr[size-1-k];
	        arr[size-1-k] = temp;
	    }
	    LCD_WriteString(arr);
}

void LCD_WriteFloat(u32 u32_num){
	LCD_WriteNum((u32_num)/10,_unsigned_);
	LCD_WriteChar('.');
	LCD_WriteNum(u32_num%10,_unsigned_);
}

void LCD_WriteBinary(u8 num){
	u8 arr[11];
	u8 i;
	for(i=0; i<8;i++){
		arr[i] = ((num & (1<<i))>>i) + '0';
	}
	arr[i] = 'b';
	arr[i+1] = '0';
	arr[i+2] = '\0';
	for(u8 k=0; k<str_len(arr)/2; k++){
		        u8 size = str_len(arr);
		        u8 temp;
		        temp = arr[k];
		        arr[k] = arr[size-1-k];
		        arr[size-1-k] = temp;
		    }
		LCD_WriteString(arr);


}


void LCD_WriteHEX(u8 num){
	u8 Hnibble = num>>4;
	u8 Lnibble = num&0x0f;
	/* u8 HexArray[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
		 *
		 * LCD_WriteChar(HexArray[Lnibble]);
		 * LCD_WriteChar(HexArray[Hnibble]);
		 *
		 * */
	if(Hnibble<=9){
		LCD_WriteChar(Hnibble + '0');
	}
	else{
		LCD_WriteChar(Hnibble - 10 + 'A');
	}
	if(Lnibble<=9){
			LCD_WriteChar(Lnibble + '0');
		}
		else{
			LCD_WriteChar(Lnibble - 10 + 'A');
		}

}

void LCD_GoTo(u8 line, u8 cell){
	if(line ==0){
		LCD_WriteCommand(0x80|cell);
	}
	else if(line ==1){
		LCD_WriteCommand(0x80|0x40|cell);
	}
}

void LCD_Write4DNum(u16 num){

	LCD_WriteChar(((num%10000)/1000)+'0');
	LCD_WriteChar(((num%1000)/100)+'0');
	LCD_WriteChar(((num%100)/10)+'0');
	LCD_WriteChar(((num%10)/1)+'0');
	/*if(num>9999 || num==0){
		LCD_WriteString("0000");
	}
	else if(num>999){
		LCD_WriteNum(num, _unsigned_);}
	else if(num>99){
	LCD_WriteChar('0');
	LCD_WriteNum(num, _unsigned_);}
	else if(num>99){
		LCD_WriteChar('0');
		LCD_WriteNum(num, _unsigned_);}
	else if(num>9){
		LCD_WriteString("00");
		LCD_WriteNum(num, _unsigned_);}
	else if(num>0){
		LCD_WriteString("000");
		LCD_WriteNum(num, _unsigned_);}*/
}

void LCD_ClearDisplay(void){
	LCD_WriteCommand(0x01);
	_delay_ms(1);
}

void LCD_Create_Character(u8 *pattern, u8 location){

	LCD_WriteCommand(0x40+(location*8)); //Send CGRAM Address
	for(u8 i=0; i<8;i++){
		LCD_WriteData(pattern[i]);}
	LCD_WriteCommand(0x80);

}

