/*
 * Stepper_motor.c
 * Created: 6/13/2023 11:58:50 AM
 * Author: Ahmed ElAfifi
 */ 

#include "Stepper_motor.h"

void STP_INIT(void)
{
	//Setting the control pins to output
	DIO_SetPin_Dir(DIO_PORTC,DIO_PIN0,DIO_PIN_OUT);
	DIO_SetPin_Dir(DIO_PORTC,DIO_PIN1,DIO_PIN_OUT);
	DIO_SetPin_Dir(DIO_PORTC,DIO_PIN2,DIO_PIN_OUT);

	//Determining enable is OFF
	DIO_SetPin_Value(DIO_PORTC,DIO_PIN0,DIO_PIN_ON);
}

void STP_UP(void)
{
	//Determining enable is ON
	DIO_SetPin_Value(DIO_PORTC,DIO_PIN0,DIO_PIN_OFF);
	
	//Setting the direction
	DIO_SetPin_Value(DIO_PORTC,DIO_PIN1,DIO_PIN_ON);
	
	//rack assembly control 270 degree , step = 1.8 degree
	 for(int step = 0 ; step < 150 ; step ++)
	 {
		 DIO_SetPin_Value(DIO_PORTC,DIO_PIN2,DIO_PIN_ON);
		 _delay_ms(10);
		 DIO_SetPin_Value(DIO_PORTC,DIO_PIN2,DIO_PIN_OFF);
		 _delay_ms(10);
	 }
	 //Determining enable is OFF
	 DIO_SetPin_Value(DIO_PORTC,DIO_PIN0,DIO_PIN_ON);
}

void STP_DOWN(void)
{
	//Determining enable is ON
	DIO_SetPin_Value(DIO_PORTC,DIO_PIN0,DIO_PIN_OFF);
	
	//Setting the direction
	DIO_SetPin_Value(DIO_PORTC,DIO_PIN1,DIO_PIN_OFF);
	
	//rack assembly control 270 degree , step = 1.8 degree
	for(int step = 0 ; step < 150 ; step ++)
	{
		DIO_SetPin_Value(DIO_PORTC,DIO_PIN2,DIO_PIN_ON);
		_delay_ms(10);
		DIO_SetPin_Value(DIO_PORTC,DIO_PIN2,DIO_PIN_OFF);
		_delay_ms(10);
	}
	
	//Determining enable is OFF
	DIO_SetPin_Value(DIO_PORTC,DIO_PIN0,DIO_PIN_ON);
}
