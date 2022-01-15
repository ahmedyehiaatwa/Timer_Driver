/*
 * LED.c
 *
 * Created: 11/01/2021 16:38:08
 *  Author: Ahmed
 */ 

#include "LED.h"
#include "DIO.h"


void LED0_Init(void)
{
	DIO_SetPinDir(DIO_PORTB, DIO_PIN4, DIO_PIN_OUTPUT);
}

void LED0_On(void)
{
	DIO_SetPinValue(DIO_PORTB, DIO_PIN4 , DIO_PIN_HIGH);
}
void LED0_Off(void)
{
	DIO_SetPinValue(DIO_PORTB, DIO_PIN4 , DIO_PIN_LOW);
}
void LED0_Toggle(void)
{
	DIO_TogglePin(DIO_PORTB, DIO_PIN4);
}
