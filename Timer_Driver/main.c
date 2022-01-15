/*
 * Timer_Driver.c
 *
 * Created: 29/05/2021 18:19:19
 * Author : Ahmed
 */ 

#include "Timer.h"
#include "LED.h"


extern uint32_t NUM_OVF;
extern uint32_t INIT_VALUE;


int main(void)
{
	LED0_Init();
	Timer0_Init();


    while (1) 
    {
		LED0_Off();
		Timer0_SetDelay(500);
		LED0_On();
		Timer0_SetDelay(500);
    }
}

