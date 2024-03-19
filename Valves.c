/*
 * Valves.c
 * Created: 5/23/2023 5:57:01 PM
 * Author: Antoine
 */ 

#include "Valves.h"
#include "Timer.h"
#include "DIO.h"

void VALVE_INIT()
{
	DIO_SetPin_Dir(DIO_PORTD, DIO_PIN2, DIO_PIN_OUT);	
	DIO_SetPin_Dir(DIO_PORTD, DIO_PIN3, DIO_PIN_OUT);
	DIO_SetPin_Dir(DIO_PORTD, DIO_PIN4, DIO_PIN_OUT);
	DIO_SetPin_Dir(DIO_PORTD, DIO_PIN5, DIO_PIN_OUT);
	DIO_SetPin_Dir(DIO_PORTD, DIO_PIN6, DIO_PIN_OUT);	//Enable PIN OUT
	DIO_SetPin_Value(DIO_PORTD, DIO_PIN6, DIO_PIN_ON);	//Enable PIN ON
	DIO_SetPin_Dir(DIO_PORTA, DIO_PIN3, DIO_PIN_OUT);	//BUZZER
}


//////////////////// VALVES ON FUNCTIONS ////////////////////
void VALVE_1_ON()
{
	DIO_SetPin_Value(DIO_PORTD, DIO_PIN2, DIO_PIN_ON);		//VALVE 1 ON
	DIO_SetPin_Value(DIO_PORTA, DIO_PIN3, DIO_PIN_ON);		//BUZZER ON
}

void VALVE_2_ON()
{
	DIO_SetPin_Value(DIO_PORTD, DIO_PIN3, DIO_PIN_ON);		//VALVE 2 ON
	DIO_SetPin_Value(DIO_PORTA, DIO_PIN3, DIO_PIN_ON);		//BUZZER ON
}

void VALVE_3_ON()
{
	DIO_SetPin_Value(DIO_PORTD, DIO_PIN4, DIO_PIN_ON);		//VALVE 3 ON
	DIO_SetPin_Value(DIO_PORTA, DIO_PIN3, DIO_PIN_ON);		//BUZZER ON
}

void VALVE_4_ON()
{
	DIO_SetPin_Value(DIO_PORTD, DIO_PIN5, DIO_PIN_ON);		//VALVE 4 ON
	DIO_SetPin_Value(DIO_PORTA, DIO_PIN3, DIO_PIN_ON);		//BUZZER ON
}

void VALVE_SYS_ON()	//All Valves Network ON
{
	DIO_SetPin_Value(DIO_PORTD, DIO_PIN2, DIO_PIN_ON);
	DIO_SetPin_Value(DIO_PORTD, DIO_PIN3, DIO_PIN_ON);
	DIO_SetPin_Value(DIO_PORTD, DIO_PIN4, DIO_PIN_ON);
	DIO_SetPin_Value(DIO_PORTD, DIO_PIN5, DIO_PIN_ON);
}


//////////////////// VALVES OFF FUNCTIONS ////////////////////
void VALVE_1_OFF()
{
	DIO_SetPin_Value(DIO_PORTD, DIO_PIN2, DIO_PIN_OFF);		//VALVE 1 OFF
	DIO_SetPin_Value(DIO_PORTA, DIO_PIN3, DIO_PIN_OFF);		//BUZZER OFF
}

void VALVE_2_OFF()
{
	DIO_SetPin_Value(DIO_PORTD, DIO_PIN3, DIO_PIN_OFF);		//VALVE 2 OFF
	DIO_SetPin_Value(DIO_PORTA, DIO_PIN3, DIO_PIN_OFF);		//BUZZER OFF
}

void VALVE_3_OFF()
{
	DIO_SetPin_Value(DIO_PORTD, DIO_PIN4, DIO_PIN_OFF);		//VALVE 3 OFF
	DIO_SetPin_Value(DIO_PORTA, DIO_PIN3, DIO_PIN_OFF);		//BUZZER OFF
}

void VALVE_4_OFF()
{
	DIO_SetPin_Value(DIO_PORTD, DIO_PIN5, DIO_PIN_OFF);		//VALVE 4 OFF
	DIO_SetPin_Value(DIO_PORTA, DIO_PIN3, DIO_PIN_OFF);		//BUZZER OFF
}

void VALVE_SYS_OFF()	//All Valves Network OFF
{
	DIO_SetPin_Value(DIO_PORTD, DIO_PIN2, DIO_PIN_OFF);
	DIO_SetPin_Value(DIO_PORTD, DIO_PIN3, DIO_PIN_OFF);
	DIO_SetPin_Value(DIO_PORTD, DIO_PIN4, DIO_PIN_OFF);
	DIO_SetPin_Value(DIO_PORTD, DIO_PIN5, DIO_PIN_OFF);
	DIO_SetPin_Value(DIO_PORTA, DIO_PIN3, DIO_PIN_OFF);		//BUZZER OFF
}


//////////////////// SYSTEM TEST ////////////////////
void SYSTEM_TEST()
{
	VALVE_SYS_ON();
	DIO_SetPin_Value(DIO_PORTA, DIO_PIN3, DIO_PIN_ON);		//BUZZER ON
	Timer_delay(5);
	VALVE_SYS_OFF();
	DIO_SetPin_Value(DIO_PORTA, DIO_PIN3, DIO_PIN_OFF);		//BUZZER OFF
	Timer_delay(3);
	for (Uint8 i = 1; i <= 5; i++)
	{
		VALVE_SYS_ON();
		DIO_SetPin_Value(DIO_PORTA, DIO_PIN3, DIO_PIN_ON);		//BUZZER ON
		Timer_delay(1);
		VALVE_SYS_OFF();
		DIO_SetPin_Value(DIO_PORTA, DIO_PIN3, DIO_PIN_OFF);		//BUZZER OFF
		Timer_delay(1);
	}
}