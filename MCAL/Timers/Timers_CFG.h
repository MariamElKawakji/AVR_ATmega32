/*
 * Timers_CFG.h
 *
 *  Created on: Mar 26, 2024
 *      Author: Marii
 */

#ifndef MCAL_TIMERS_TIMERS_CFG_H_
#define MCAL_TIMERS_TIMERS_CFG_H_

/*******************  TMR0 CFG  ***********************/
#define TIMER0_Prescaler		TIMER0_Prescaler_64

#define TIMER0_Mode				TIMER0_Normal_Mode

#define TIMER0_COMPMatch_Mode	TIMER0_Toggle_Mode

/*******************  TMR1 CFG  ***********************/

#define TIMER1_Prescaler		TIMER1_Prescaler_64

#define TIMER1_Mode				TIMER1_Normal_Mode

#define TIMER1_COMPMatchA_Mode	OCR1A_Toggle_Mode

#define TIMER1_COMPMatchB_Mode	OCR1B_Toggle_Mode


/*******************  TMR2 CFG  ***********************/
#define TIMER2_Prescaler		TIMER2_Prescaler_64

#define TIMER2_Mode				TIMER2_Normal_Mode

#define TIMER2_COMPMatch_Mode	TIMER2_Toggle_Mode


#endif /* MCAL_TIMERS_TIMERS_CFG_H_ */
