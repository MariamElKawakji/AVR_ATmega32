/*
 * Timers.h
 *
 *  Created on: Mar 26, 2024
 *      Author: Marii
 */

#ifndef MCAL_TIMERS_TIMERS_H_
#define MCAL_TIMERS_TIMERS_H_

#include "Common_Files/UTILS.h"
#include "Common_Files/STD_TYPES.h"
#include "MCAL/Timers/Timers_Registers.h"
#include "MCAL/Timers/Timers_CFG.h"

/**********************************************/
#define Timer0_Set_TCNT(value)	TCNT0 = value
#define Timer0_Set_OCR(value)	OCR0 = value
/**********************************************/
/**********************************************/
#define Timer2_Set_TCNT(value)	TCNT2 = value
#define Timer2_Set_OCR(value)	OCR2 = value
/**********************************************/

/**********************************************/
typedef enum{
	TIMER0_No_Clock_Source,
	TIMER0_No_Prescaler,
	TIMER0_Prescaler_8,
	TIMER0_Prescaler_64,
	TIMER0_Prescaler_256,
	TIMER0_Prescaler_1024,
	TIMER0_FallingEdge_ExternalClock,
	TIMER0_RisingEdge_ExternalClock
}Timer0Prescaler_Type;

typedef enum{
	TIMER0_Normal_Mode,
	TIMER0_Phase_Correct_Mode,
	TIMER0_CTC_Mode,
	TIMER0_Fast_PWM_Mode
}Timer0Mode_Type;

typedef enum{
	TIMER0_NormalDCD_Mode,
	TIMER0_Toggle_Mode,
	TIMER0_Clear_Mode,
	TIMER0_Set_Mode
}Timer0CMPMatch_Mode;

/**********************************************/
/**********************************************/

typedef enum{
	TIMER1_No_Clock_Source,
	TIMER1_No_Prescaler,
	TIMER1_Prescaler_8,
	TIMER1_Prescaler_64,
	TIMER1_Prescaler_256,
	TIMER1_Prescaler_1024,
	TIMER1_FallingEdge_ExternalClock,
	TIMER1_RisingEdge_ExternalClock
}Timer1Prescaler_Type;

typedef enum{
	TIMER1_Normal_Mode, /*0 to 65,535*/
	TIMER1_PhaseCorrect_8bit_TOP_Mode,  /*up to 255*/
	TIMER1_PhaseCorrect_9bit_TOP_Mode, /*up to 511*/
	TIMER1_PhaseCorrect_10bit_TOP_Mode, /*up to 1023*/
	TIMER1_CTC_OCRA_TOP_Mode,
	TIMER1_FastPWM_8bit_TOP_Mode,   /*up to 255*/
	TIMER1_FastPWM_9bit_TOP_Mode,  /*up to 511*/
	TIMER1_FastPWM_10bit_TOP_Mode,  /*up to 1023*/
	TIMER1_PhaseCorrect_ICR_BOT_Mode,
	TIMER1_PhaseCorrect_OCRA_BOT_Mode,
	TIMER1_PhaseCorrect_ICR_TOP_Mode,
	TIMER1_PhaseCorrect_OCRA_TOP_Mode,
	TIMER1_CTC_ICR_TOP_Mode,
	TIMER1_FastPWM_ICR_TOP_Mode,
	TIMER1_FastPWM_OCRA_TOP_Mode
}Timer1Mode_Type;

typedef enum{
	OCR1A_NormalDCD_Mode,
	OCR1A_Toggle_Mode, /*cannot be applied in Normal*/
	OCR1A_Non_Inverting_Mode, /*cannot be applied in CTC*/
	OCR1A_Inverting_Mode
}Timer1CMPMatchA_Mode;

typedef enum{
	OCR1B_NormalDCD_Mode,
	OCR1B_Toggle_Mode,
	OCR1B_Non_Inverting_Mode,
	OCR1B_Inverting_Mode
}Timer1CMPMatchB_Mode;

typedef enum{
	RISING,
	FALLING
}ICU_Edge_type;

/**********************************************/
/**********************************************/
typedef enum{
	TIMER2_No_Clock_Source,
	TIMER2_No_Prescaler,
	TIMER2_Prescaler_8,
	TIMER2_Prescaler_32,
	TIMER2_Prescaler_64,
	TIMER2_Prescaler_128,
	TIMER2_Prescaler_256,
	TIMER2_Prescaler_1024
}Timer2Prescaler_Type;

typedef enum{
	TIMER2_Normal_Mode,
	TIMER2_Phase_Correct_Mode,
	TIMER2_CTC_Mode,
	TIMER2_Fast_PWM_Mode
}Timer2Mode_Type;

typedef enum{
	TIMER2_NormalDCD_Mode,
	TIMER2_Toggle_Mode,
	TIMER2_Clear_Mode,
	TIMER2_Set_Mode
}Timer2CMPMatch_Mode;

/*****************************************************************/
/**************************** TIMER 0 ****************************/

void Timer0_Init(void);
/*mode, prescaler*/
void Timer0_OCMode(void);
/*Sets the mode toggle, or set, or clear*/
void Timer0_OV_InterruptEnable(void);
/*Timer 0 overflow interrupt enable*/
void Timer0_OV_InterruptDisable(void);
/*Timer 0 overflow interrupt disable*/
void Timer0_CompMatch_InterruptEnable(void);
/*Timer 0 Compare Match interrupt enable*/
void Timer0_CompMatch_InterruptDisable(void);
/*Timer 0 Compare Match interrupt disable*/
void TIMER0_OV_SetCallBack(void (*local_fptr) (void));
void TIMER0_COMP_SetCallBack(void (*local_fptr) (void));
/*
u8 Timer0_Read(void);
*/

/**************************** TIMER 1 ****************************/

void TIMER1_INIT(void);
void TIMER1_OCRA1Mode(void);
void TIMER1_OCRB1Mode(void);
void Timer1_InputCaptureEdge(ICU_Edge_type edge);
void Timer1_OV_InterruptEnable(void);
void Timer1_OV_InterruptDisable(void);
void TIMER1_OV_SetCallBack(void(*local_fptr)(void));
void Timer1_CompMatchA_InterruptEnable(void);
void Timer1_CompMatchA_InterruptDisable(void);
void TIMER1_COMPA_SetCallBack(void(*local_fptr)(void));
void Timer1_CompMatchB_InterruptEnable(void);
void Timer1_CompMatchB_InterruptDisable(void);
void TIMER1_COMPB_SetCallBack(void(*local_fptr)(void));
void Timer1_CAPT_InterruptEnable(void);
void Timer1_CAPT_InterruptDisable(void);
void TIMER1_CAPT_SetCallBack(void(*local_fptr)(void));


/**************************** TIMER 2 ****************************/

void Timer2_Init(void);
void Timer2_OCMode(void);
void Timer2_OV_InterruptEnable(void);
void Timer2_OV_InterruptDisable(void);
void TIMER2_OV_SetCallBack(void(*local_fptr)(void));
void Timer2_CompMatch_InterruptEnable(void);
void Timer2_CompMatch_InterruptDisable(void);
void TIMER2_COMP_SetCallBack(void(*local_fptr)(void));



#endif /* MCAL_TIMERS_TIMERS_H_ */
