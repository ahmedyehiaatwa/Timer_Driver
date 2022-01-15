/*
 * Timer.c
 *
 * Created: 07/01/2021 18:28:43
 *  Author: Ahmed
 */ 

#include "Timer.h"

#include <avr/interrupt.h>

uint32_t NUM_OVF = 0;
uint32_t INIT_VALUE = 0;

 void(*Ptr_0)(void);
 void(*Ptr_1)(void);

void Timer0_Init (void)
{
	CLR_BIT(TCCR0, 3); // Set normal mode including step below //
	CLR_BIT(TCCR0, 6);
	SET_BIT(SREG, 7); // Enable global interrupt//
	SET_BIT(TIMSK, 0); //Enable overflow interrupt 
}


void Timer0_SetDelay (uint32_t Delay_Ms)
{
	uint8_t Tick_Time = (1024 / 16) ;
	
	uint32_t Total_Ticks = ((Delay_Ms * 1000) / Tick_Time);
	
	NUM_OVF = Total_Ticks / 256 ;
	
	INIT_VALUE = 256 - (Total_Ticks % 256) ;
	
	TCNT0 = INIT_VALUE;
	
	if (INIT_VALUE != 0)
	{
		NUM_OVF++;
	}
}

void Timer0_Start (void)
{
	SET_BIT(TCCR0, 0); //Start timer using prescaler 1024//
	CLR_BIT(TCCR0, 1);
	SET_BIT(TCCR0, 2);
	
	
	
}

void Timer0_Stop (void)
{
	CLR_BIT(TCCR0, 0); // Stop timer //
	CLR_BIT(TCCR0, 1);
	CLR_BIT(TCCR0, 2);
	
	
}

void Set_CallBack_0(void(*p)(void))
{
	Ptr_0 = p;
}

ISR(TIMER0_OVF_vect)
{
	static uint32_t cnt = 0;
	
	cnt++;
	
	if(cnt==NUM_OVF)
	{
		cnt=0;
		(*Ptr_0)();
		TCNT0 = INIT_VALUE;
	}
}

// TIMER 1 //


void Timer1_Init (void)
{
	CLR_BIT(TCCR1A,0);  // select mode 4 CTC //
	CLR_BIT(TCCR1A,1);
	SET_BIT(TCCR1B,3);
	CLR_BIT(TCCR1B,4);
	
	SET_BIT(SREG, 7); // Set global interrupt //
	SET_BIT(TIMSK,4); // Enable Output compare match interrupt 
}

void Timer1_SetDelay (uint32_t Delay_Ms)
{
	if (Delay_Ms<4000)
	{
		uint8_t Tick_Time= 1024 / 16;
		uint8_t NUM_Ticks = (Delay_Ms*1000) / Tick_Time;
		OCR1A = NUM_Ticks - 1;
	}
}

void Timer1_Start (void)
{
		SET_BIT(TCCR1B,0);
		CLR_BIT(TCCR1B,1);
		SET_BIT(TCCR1B,2);
}

void Timer1_Stop (void)
{
	CLR_BIT(TCCR1B,0);
	CLR_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,2);
}

void Set_CallBack_1(void(*p)(void))
{
	Ptr_1 = p;
}


ISR(TIMER1_COMPA_vect)
{
	(*Ptr_1)();
}

