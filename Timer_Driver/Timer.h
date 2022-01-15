/*
 * Timer.h
 *
 * Created: 07/01/2021 18:28:56
 *  Author: Ahmed
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "MCU.h"
#include "STD.h"
#include "BIT_Math.h"



void Timer0_Init (void);

void Timer0_SetDelay (uint32_t Delay_Ms);

void Timer0_Start (void);

void Timer0_Stop (void);

void Set_CallBack_0 (void(*p)(void));

// TIMER 1 //

void Timer1_Init (void);

void Timer1_SetDelay (uint32_t Delay_Ms);

void Timer1_Start (void);

void Timer1_Stop (void);

void Set_CallBack_1 (void(*p)(void));




#endif /* TIMER_H_ */