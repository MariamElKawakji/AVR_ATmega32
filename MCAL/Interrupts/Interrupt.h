/*
 * Interrupt.h
 *
 *  Created on: Mar 17, 2024
 *      Author: Marii
 */

#ifndef MCAL_INTERRUPTS_INTERRUPT_H_
#define MCAL_INTERRUPTS_INTERRUPT_H_

#include "Common_Files/STD_TYPES.h"
#include "Common_Files/UTILS.h"
#include "Interrupt_Registers.h"
#include "Interrupt_LCFG.h"

typedef enum{
	INT0_PD2=6,
	INT1_PD3=7,
	INT2_PB=5
}ExtInterruptSource_Type;

typedef enum{
	Low_Level,
	Logic_Change,
	Falling_Edge,
	Rising_Edge
}TriggerEdge_Type;

void Interrupt_Enable(void);
void Interrupt_Disable(void);
void EXT_TriggerEdge(ExtInterruptSource_Type pin, TriggerEdge_Type status);
void EXT_Interrupt_Enable(ExtInterruptSource_Type pin);
void EXT_Interrupt_Disable(ExtInterruptSource_Type pin);
void EXT_SetCallBack(ExtInterruptSource_Type interrupt, void(*LocalPtr)(void));
#endif /* MCAL_INTERRUPTS_INTERRUPT_H_ */
