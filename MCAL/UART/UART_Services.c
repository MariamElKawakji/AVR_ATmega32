/*
 * UART_Services.c
 *
 *  Created on: Apr 6, 2024
 *      Author: Marii
 */

#include "UART_Services.h"


void UART_SendString(u8 *data){
	for(u8 i=0; data[i]!='\0'; i++){
		UART_Send(data[i]);
		}
}

void UART_ReceiveString(u8 *data){
	u8 i =0;
	data[i] = UART_Receive();
	for(i=0; data[i]!='#';){
		i++;
		data[i] = UART_Receive();
	}
	data[i] = 0;
}
void UART_ReceiveString2(u8 *data){
	u8 i =0;
	data[i] = UART_Receive();
	for(i=0; data[i]!=13;){  /*Enter*/
		i++;
		data[i] = UART_Receive();
	}
	data[i] = 0;
}

void UART_SendNumber(u32 num)
{
	UART_Send((u8)num);
	UART_Send((u8)(num>>8));
	UART_Send((u8)(num>>16));
	UART_Send((u8)(num>>24));

	/*
	 * Another method
	 * using pointers
	 * u8 *p = &num;
	 * UART_Send(p[0]);
	 * UART_Send(p[1]);
	 * UART_Send(p[2]);
	 * UART_Send(p[3]);
	 */

}
u32 UART_ReceiveNumber(void){
	u32 num = 0;
	u8 byte0 = UART_Receive();
	u8 byte1 = UART_Receive();
	u8 byte2 = UART_Receive();
	u8 byte3 = UART_Receive();
	num = (u32)(byte3<<24)|(u32)(byte2<<16)|(u32)(byte1<<8)|(u32)(byte0);
	return num;
	/*
	 * Using pointers
	 * u32 num = 0;
	 * u8 *p = &num;
	 * p[0] = UART_Receive();
	 * p[1] = UART_Receive();
	 * p[2] = UART_Receive();
	 * p[3] = UART_Receive();
	 */
}

void UART_SendStringCheckSum(u8*str){
	u8 i,len = 0;
	u16 sum = 0;
	for(len = 0; str[len];len++);
	UART_Send(len);
	for(i = 0; i<len;i++){
		UART_Send(str[i]);
		sum+= str[i];
	}
	UART_Send((u8)sum);
	UART_Send((u8)(sum>>8));
}

u8 UART_ReceiveStringCheckSum(u8*str){
	u8 i,len,sum_Byte0,sum_Byte1 = 0;
	u16 sum_calc = 0;
	u16 sum_recv = 0;
	len = UART_Receive();
	for(i = 0; i<len;i++){
		str[i] = UART_Receive();
		sum_calc+= str[i];
	}
	sum_Byte0 = UART_Receive();
	sum_Byte1 = UART_Receive();
	sum_recv = (u16)(sum_Byte1<<8) | (u16)sum_Byte0;
	str[i] = 0;
	if(sum_recv == sum_calc){
		return 1;
	}
	else{
		return 0;
	}
}



/*
 * Asynchronous func is working
 * in the background
 */
static u8*Tx_str[20];
static void FUNC_TX(void);
void UART_SendStringAsynch(u8 *data){
	static u8 tx_cnt = 0;
	Tx_str[tx_cnt] = data;
	UART_TX_SetCallback(FUNC_TX);
	UART_TX_EnableInterrupt();
	tx_cnt++;
	if(tx_cnt == 20) tx_cnt = 0;

}

static void FUNC_TX(void){
	static u8 i =0, k=0;
	if(Tx_str[k][i]!=0){
		UART_Send(Tx_str[k][i]);
		i++;
	}
	else{
		i = 0;
		k++;
		if(k == 20) k = 0;
	}
}
static u8*Rx_str;
static void FUNC_RX(void);
void UART_ReceiveStringAsynch(u8 *data){
	UART_RX_SetCallback(FUNC_RX);
	UART_RX_EnableInterrupt();
	Rx_str = data;

}

static void FUNC_RX(void){
	static u8 i =0;
	Rx_str[i] = UART_ReceiveNoBlock();
	i++;
	if(Rx_str[i]=='#'){
		i=0;
	}
}
static u8 TX_Interrupt_Flag = 0;
static void FUNC_TX2(void);
void UART_BCM_INIT(void){
	UART_TX_SetCallback(FUNC_TX2);
	UART_TX_EnableInterrupt();
}
void UART_BCM_Runnable(u8 *data){
	static u8 i =0;
	if(TX_Interrupt_Flag ==1){
		if(data[i]!=0){
			UART_SendNoBlock(data[i]);
			i++;
			TX_Interrupt_Flag = 0;
		}
	}
}

static void FUNC_TX2(void){
	TX_Interrupt_Flag = 1;
}
