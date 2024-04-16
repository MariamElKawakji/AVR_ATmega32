/*
 * Timers.c
 *
 *  Created on: Mar 26, 2024
 *      Author: Marii
 */

#include "MCAL/Timers/Timers.h"
#include "MCAL/Interrupts/Interrupt_Registers.h"


void Timer0_Init(void){
	TCCR0 = 0;
	TCCR0 |= TIMER0_Prescaler;
	switch(TIMER0_Mode){
	case TIMER0_Normal_Mode:
		CLR_BIT(TCCR0, WGM00);
		CLR_BIT(TCCR0, WGM01);
		break;
	case TIMER0_Phase_Correct_Mode:
		SET_BIT(TCCR0, WGM00);
		CLR_BIT(TCCR0, WGM01);
		break;
	case TIMER0_CTC_Mode:
		CLR_BIT(TCCR0, WGM00);
		SET_BIT(TCCR0, WGM01);
		break;
	case TIMER0_Fast_PWM_Mode:
		SET_BIT(TCCR0, WGM00);
		SET_BIT(TCCR0, WGM01);
		break;
		}


}

void Timer0_OCMode(void){
/*Sets the mode toggle, or set, or clear*/
	switch(TIMER0_Mode){
		case TIMER0_Normal_Mode:
		case TIMER0_CTC_Mode:
			TCCR0 |= TIMER0_COMPMatch_Mode<<4;
			break;
		case TIMER0_Fast_PWM_Mode:
		case TIMER0_Phase_Correct_Mode:
			if(TIMER0_COMPMatch_Mode == TIMER0_Toggle_Mode){

			}
			else{
				TCCR0 |= TIMER0_COMPMatch_Mode<<4;
			}
			break;
			}
}

void Timer0_OV_InterruptEnable(void){
/*Timer 0 overflow interrupt enable*/
	SET_BIT(SREG, 7);
	SET_BIT(TIMSK, TOIE0);

}

void Timer0_OV_InterruptDisable(void){
/*Timer 0 overflow interrupt disable*/
	CLR_BIT(TIMSK, TOIE0);
}

void Timer0_CompMatch_InterruptEnable(void){
/*Timer 0 Compare Match interrupt enable*/
	SET_BIT(SREG, 7);
	SET_BIT(TIMSK, OCIE0);
}

void Timer0_CompMatch_InterruptDisable(void){
/*Timer 0 Compare Match interrupt disable*/
	CLR_BIT(TIMSK, OCIE0);

}
static void (*fptr_OV0) (void) = NULLPTR;
static void (*fptr_COMP0) (void) = NULLPTR;
void TIMER0_OV_SetCallBack(void(*local_fptr)(void)){
	fptr_OV0 = local_fptr;
}
void TIMER0_COMP_SetCallBack(void(*local_fptr)(void)){
	fptr_COMP0 = local_fptr;
}

ISR(TIMER0OVF){
	if(fptr_OV0!=NULLPTR)
	fptr_OV0();
}

ISR(TIMER0COMP){
	if(fptr_COMP0!=NULLPTR)
	fptr_COMP0();
}

/***************************   TIMER 1    ***********************************/


void TIMER1_INIT(void){
	TCCR1A = 0;
	TCCR1B = 0;
	TCCR1B|=TIMER1_Prescaler;
	switch(TIMER1_Mode){
		case TIMER1_Normal_Mode:
			CLR_BIT(TCCR1A,WGM10);
			CLR_BIT(TCCR1A,WGM11);
			CLR_BIT(TCCR1B,WGM12);
			CLR_BIT(TCCR1B,WGM13);
			break;
		case TIMER1_PhaseCorrect_8bit_TOP_Mode:
			SET_BIT(TCCR1A,WGM10);
			CLR_BIT(TCCR1A,WGM11);
			CLR_BIT(TCCR1B,WGM12);
			CLR_BIT(TCCR1B,WGM13);
			break;
		case TIMER1_PhaseCorrect_9bit_TOP_Mode:
			CLR_BIT(TCCR1A,WGM10);
			SET_BIT(TCCR1A,WGM11);
			CLR_BIT(TCCR1B,WGM12);
			CLR_BIT(TCCR1B,WGM13);
			break;
		case TIMER1_PhaseCorrect_10bit_TOP_Mode:
			SET_BIT(TCCR1A,WGM10);
			SET_BIT(TCCR1A,WGM11);
			CLR_BIT(TCCR1B,WGM12);
			CLR_BIT(TCCR1B,WGM13);
			break;
		case TIMER1_CTC_OCRA_TOP_Mode:
			CLR_BIT(TCCR1A,WGM10);
			CLR_BIT(TCCR1A,WGM11);
			SET_BIT(TCCR1B,WGM12);
			CLR_BIT(TCCR1B,WGM13);
			break;
		case TIMER1_FastPWM_8bit_TOP_Mode:
			SET_BIT(TCCR1A,WGM10);
			CLR_BIT(TCCR1A,WGM11);
			SET_BIT(TCCR1B,WGM12);
			CLR_BIT(TCCR1B,WGM13);
			break;
		case TIMER1_FastPWM_9bit_TOP_Mode:
			CLR_BIT(TCCR1A,WGM10);
			SET_BIT(TCCR1A,WGM11);
			SET_BIT(TCCR1B,WGM12);
			CLR_BIT(TCCR1B,WGM13);
			break;
		case TIMER1_FastPWM_10bit_TOP_Mode:
			SET_BIT(TCCR1A,WGM10);
			SET_BIT(TCCR1A,WGM11);
			SET_BIT(TCCR1B,WGM12);
			CLR_BIT(TCCR1B,WGM13);
			break;
		case TIMER1_PhaseCorrect_ICR_BOT_Mode:
			CLR_BIT(TCCR1A,WGM10);
			CLR_BIT(TCCR1A,WGM11);
			CLR_BIT(TCCR1B,WGM12);
			SET_BIT(TCCR1B,WGM13);
			break;
		case TIMER1_PhaseCorrect_OCRA_BOT_Mode:
			SET_BIT(TCCR1A,WGM10);
			CLR_BIT(TCCR1A,WGM11);
			CLR_BIT(TCCR1B,WGM12);
			SET_BIT(TCCR1B,WGM13);
			break;
		case TIMER1_PhaseCorrect_ICR_TOP_Mode:
			CLR_BIT(TCCR1A,WGM10);
			SET_BIT(TCCR1A,WGM11);
			CLR_BIT(TCCR1B,WGM12);
			SET_BIT(TCCR1B,WGM13);
			break;
		case TIMER1_PhaseCorrect_OCRA_TOP_Mode:
			SET_BIT(TCCR1A,WGM10);
			SET_BIT(TCCR1A,WGM11);
			CLR_BIT(TCCR1B,WGM12);
			SET_BIT(TCCR1B,WGM13);
			break;
		case TIMER1_CTC_ICR_TOP_Mode:
			CLR_BIT(TCCR1A,WGM10);
			CLR_BIT(TCCR1A,WGM11);
			SET_BIT(TCCR1B,WGM12);
			SET_BIT(TCCR1B,WGM13);
			break;
		case TIMER1_FastPWM_ICR_TOP_Mode:
			CLR_BIT(TCCR1A,WGM10);
			SET_BIT(TCCR1A,WGM11);
			SET_BIT(TCCR1B,WGM12);
			SET_BIT(TCCR1B,WGM13);
			break;
		case TIMER1_FastPWM_OCRA_TOP_Mode:
			SET_BIT(TCCR1A,WGM10);
			SET_BIT(TCCR1A,WGM11);
			SET_BIT(TCCR1B,WGM12);
			SET_BIT(TCCR1B,WGM13);
			break;
			}

}
void TIMER1_OCRA1Mode(void){
	TCCR1A &= 0x3F;
	TCCR1A |= TIMER1_COMPMatchA_Mode<<6;
}
void TIMER1_OCRB1Mode(void){
	TCCR1A &= 0xCF;
	TCCR1A |= TIMER1_COMPMatchB_Mode<<4;
}

void Timer1_InputCaptureEdge(ICU_Edge_type edge)
{
	if(edge==RISING)
		SET_BIT(TCCR1B,ICES1);

	else if(edge==FALLING)
		CLR_BIT(TCCR1B,ICES1);

}


void Timer1_OV_InterruptEnable(void){
	SET_BIT(SREG, GIE);
	SET_BIT(TIMSK, TOIE1);
}

void Timer1_OV_InterruptDisable(void){
	CLR_BIT(TIMSK, TOIE1);
}

void Timer1_CompMatchA_InterruptEnable(void){
	SET_BIT(SREG, GIE);
	SET_BIT(TIMSK, OCIE1A);
}
void Timer1_CompMatchA_InterruptDisable(void){
	CLR_BIT(TIMSK, OCIE1A);
}
void Timer1_CompMatchB_InterruptEnable(void){
	SET_BIT(SREG, GIE);
	SET_BIT(TIMSK, OCIE1B);
}
void Timer1_CompMatchB_InterruptDisable(void){
	CLR_BIT(TIMSK, OCIE1B);
}
void Timer1_CAPT_InterruptEnable(void){
	SET_BIT(SREG, GIE);
	SET_BIT(TIMSK, TICIE1);
}
void Timer1_CAPT_InterruptDisable(void){
	CLR_BIT(TIMSK, TICIE1);
}

static void (*fptr_OV1) (void) = NULLPTR;
static void (*fptr_COMP1A) (void) = NULLPTR;
static void (*fptr_COMP1B) (void) = NULLPTR;
static void (*fptr_CAPT1) (void) = NULLPTR;
void TIMER1_OV_SetCallBack(void(*local_fptr)(void)){
	fptr_OV1 = local_fptr;
}
void TIMER1_COMPA_SetCallBack(void(*local_fptr)(void)){
	fptr_COMP1A = local_fptr;
}
void TIMER1_COMPB_SetCallBack(void(*local_fptr)(void)){
	fptr_COMP1B = local_fptr;
}
void TIMER1_CAPT_SetCallBack(void(*local_fptr)(void)){
	fptr_CAPT1 = local_fptr;
}

ISR(TIMER1OVF){
	if(fptr_OV1!=NULLPTR)
		fptr_OV1();
}

ISR(TIMER1COMPA){
	if(fptr_COMP1A!=NULLPTR)
		fptr_COMP1A();
}
ISR(TIMER1COMPB){
	if(fptr_COMP1B!=NULLPTR)
		fptr_COMP1B();
}

ISR(TIMER1CAPT){
	if(fptr_CAPT1!=NULLPTR)
		fptr_CAPT1();
}



/********************** TIMER 2 ******************************/


void Timer2_Init(void){
	TCCR2 = 0;
	TCCR2 |= TIMER0_Prescaler;
	switch(TIMER2_Mode){
	case TIMER2_Normal_Mode:
		CLR_BIT(TCCR2, WGM20);
		CLR_BIT(TCCR2, WGM21);
		break;
	case TIMER2_Phase_Correct_Mode:
		SET_BIT(TCCR2, WGM20);
		CLR_BIT(TCCR2, WGM21);
		break;
	case TIMER2_CTC_Mode:
		CLR_BIT(TCCR2, WGM20);
		SET_BIT(TCCR2, WGM21);
		break;
	case TIMER2_Fast_PWM_Mode:
		SET_BIT(TCCR2, WGM20);
		SET_BIT(TCCR2, WGM21);
		break;
		}


}

void Timer2_OCMode(void){
/*Sets the mode toggle, or set, or clear*/
	switch(TIMER2_Mode){
		case TIMER2_Normal_Mode:
		case TIMER2_CTC_Mode:
			TCCR2 |= TIMER2_COMPMatch_Mode<<4;
			break;
		case TIMER2_Fast_PWM_Mode:
		case TIMER2_Phase_Correct_Mode:
			if(TIMER2_COMPMatch_Mode == TIMER2_Toggle_Mode){

			}
			else{
				TCCR2 |= TIMER2_COMPMatch_Mode<<4;
			}
			break;
			}
}

void Timer2_OV_InterruptEnable(void){
/*Timer 0 overflow interrupt enable*/
	SET_BIT(SREG, GIE);
	SET_BIT(TIMSK, TOIE2);

}

void Timer2_OV_InterruptDisable(void){
/*Timer 0 overflow interrupt disable*/
	CLR_BIT(TIMSK, TOIE2);
}

void Timer2_CompMatch_InterruptEnable(void){
/*Timer 0 Compare Match interrupt enable*/
	SET_BIT(SREG, GIE);
	SET_BIT(TIMSK, OCIE2);
}

void Timer2_CompMatch_InterruptDisable(void){
/*Timer 0 Compare Match interrupt disable*/
	CLR_BIT(TIMSK, OCIE2);

}
static void (*fptr_OV2) (void) = NULLPTR;
static void (*fptr_COMP2) (void) = NULLPTR;

void TIMER2_OV_SetCallBack(void(*local_fptr)(void)){
	fptr_OV2 = local_fptr;
}
void TIMER2_COMP_SetCallBack(void(*local_fptr)(void)){
	fptr_COMP2 = local_fptr;
}

ISR(TIMER2OVF){
	if(fptr_OV2!=NULLPTR)
	fptr_OV2();
}

ISR(TIMER2COMP){
	if(fptr_COMP2!=NULLPTR)
	fptr_COMP2();
}



