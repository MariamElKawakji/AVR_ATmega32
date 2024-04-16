/*
 * SPI_Services.h
 *
 *  Created on: Apr 13, 2024
 *      Author: Marii
 */

#ifndef MCAL_SPI_SPI_SERVICES_H_
#define MCAL_SPI_SPI_SERVICES_H_

#include "SPI_Interface.h"

void SPI_SendReceiveString(u8 *sendStr, u8 *RcvdStr);

#endif /* MCAL_SPI_SPI_SERVICES_H_ */
