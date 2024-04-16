/*
 * UTILS.h
 *
 *  Created on: Mar 4, 2024
 *      Author: Marii
 */

#ifndef UTILS_H_
#define UTILS_H_

#define SET_BIT(reg, bit)			(reg|=(1<<bit))

#define CLR_BIT(reg, bit)			(reg&=~(1<<bit))

#define TOGGLE_BIT(reg, bit)		(reg^=(1<<bit))

#define READ_BIT(reg, bit)			((reg>>bit)&1)

#define READ_PORT(reg)				(reg&0xFF)

#define WRITE_BIT(reg, bit, val)	(reg=((reg&~(1<<bit))|(value<<bit)))

#define WRITE_PORT(reg, val)		(reg = val)

#endif /* UTILS_H_ */
