/*
 * SPI_Services.c
 *
 *  Created on: Apr 13, 2024
 *      Author: Marii
 */

#include "SPI_Services.h"


void SPI_SendReceiveString(u8 *sendStr, u8 *RcvdStr){
	u8 i = 0;
	for(i=0; sendStr[i]!=0; i++){
		RcvdStr[i] = SPI_SendReceive(sendStr[i]);
	}
}
