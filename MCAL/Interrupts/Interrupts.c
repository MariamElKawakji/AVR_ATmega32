/*
 * Interrupts.c
 *
 *  Created on: Mar 17, 2024
 *      Author: Marii
 */

#include "Interrupt.h"
#include "Interrupt_Private.h"


void Interrupt_Enable(void){
	sei();
}

void Interrupt_Disable(void){
	cli();
}

void EXT_Interrupt_Enable(ExtInterruptSource_Type pin){
	SET_BIT(GICR,pin);
}

void EXT_Interrupt_Disable(ExtInterruptSource_Type pin){
	CLR_BIT(GICR,pin);
}


void EXT_TriggerEdge(ExtInterruptSource_Type pin, TriggerEdge_Type status){
	switch(pin){
		case INT0_PD2:
			/*SET_BIT(GICR,INT0);*/
			MCUCR&= 0xFC;
			MCUCR|= status;
			break;
		case INT1_PD3:
			/*SET_BIT(GICR,INT1);*/
			MCUCR&= 0xF3;
			MCUCR|= status<<2;
			break;
		case INT2_PB:
			/*SET_BIT(GICR,INT2);*/
			if(Falling_Edge){
				CLR_BIT(MCUCSR,ISC2);
			}
			else{
				SET_BIT(MCUCSR,ISC2);
			}
			break;
	}
}

static void (*fptr_INT0) (void) = NULLPTR;
static void (*fptr_INT1) (void) = NULLPTR;
static void (*fptr_INT2) (void) = NULLPTR;
void EXT_SetCallBack(ExtInterruptSource_Type interrupt, void(*LocalPtr)(void)){
	switch(interrupt){
	case INT0_PD2:
		fptr_INT0 = LocalPtr;
		break;
	case INT1_PD3:
		fptr_INT1 = LocalPtr;
		break;
	case INT2_PB:
		fptr_INT2 = LocalPtr;
		break;
	}

}
ISR(EXT_INT0){
	if(fptr_INT0!=NULLPTR)
	fptr_INT0();
}
ISR(EXT_INT1){
	if(fptr_INT1!=NULLPTR)
	fptr_INT1();
}
ISR(EXT_INT2){
	if(fptr_INT2!=NULLPTR)
	fptr_INT2();
}
