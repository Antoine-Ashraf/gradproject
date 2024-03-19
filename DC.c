/*
 * DC.c
 * Created: 5/16/2023 1:09:16 PM
 * Author: Antoine
 */ 

#include "DC.h"

void DC_INIT()
{
	//Configuring DIO Pins Required for DC Motors Operation as Output Pins
	DIO_SetPin_Dir(DIO_PORTD, DIO_PIN2, DIO_PIN_OUT);	//Enable Pin for Left Traction
	DIO_SetPin_Dir(DIO_PORTD, DIO_PIN3, DIO_PIN_OUT);	//Direction Pin for Left Traction
	DIO_SetPin_Dir(DIO_PORTD, DIO_PIN4, DIO_PIN_OUT);	//Direction Pin for Left Traction
	DIO_SetPin_Dir(DIO_PORTD, DIO_PIN5, DIO_PIN_OUT);	//Enable Pin for Right Traction
	DIO_SetPin_Dir(DIO_PORTD, DIO_PIN6, DIO_PIN_OUT);	//Direction Pin	for Right Traction
	DIO_SetPin_Dir(DIO_PORTD, DIO_PIN7, DIO_PIN_OUT);	//Direction Pin for Right Traction
}

void DC_FWD()
{
	//Motors Left & Right Lines Power ON
	DIO_SetPin_Value(DIO_PORTD, DIO_PIN2, DIO_PIN_ON);	//Left Line Power ON
	DIO_SetPin_Value(DIO_PORTD, DIO_PIN5, DIO_PIN_ON);	//Right Line Power ON
	
	//Configuring Forward Direction Control
	DIO_SetPin_Value(DIO_PORTD, DIO_PIN3, DIO_PIN_ON);	//PIN2 ON
	DIO_SetPin_Value(DIO_PORTD, DIO_PIN4, DIO_PIN_OFF);	//PIN3 OFF
	DIO_SetPin_Value(DIO_PORTD, DIO_PIN6, DIO_PIN_ON);	//PIN5 ON
	DIO_SetPin_Value(DIO_PORTD, DIO_PIN7, DIO_PIN_OFF);	//PIN6 OFF
}

void DC_RIGHT()
{
	//Motors Left & Right Lines Power ON
	DIO_SetPin_Value(DIO_PORTD, DIO_PIN2, DIO_PIN_ON);	//Left Line Power ON
	DIO_SetPin_Value(DIO_PORTD, DIO_PIN5, DIO_PIN_ON);	//Right Line Power ON
		
	//Configuring Right Direction Control
	DIO_SetPin_Value(DIO_PORTD, DIO_PIN3, DIO_PIN_ON);	//PIN2 ON
	DIO_SetPin_Value(DIO_PORTD, DIO_PIN4, DIO_PIN_OFF);	//PIN3 OFF
	DIO_SetPin_Value(DIO_PORTD, DIO_PIN6, DIO_PIN_OFF);	//PIN5 OFF
	DIO_SetPin_Value(DIO_PORTD, DIO_PIN7, DIO_PIN_ON);	//PIN6 ON
}

void DC_LEFT()
{
	//Motors Left & Right Lines Power ON
	DIO_SetPin_Value(DIO_PORTD, DIO_PIN2, DIO_PIN_ON);	//Left Line Power ON
	DIO_SetPin_Value(DIO_PORTD, DIO_PIN5, DIO_PIN_ON);	//Right Line Power ON
	
	//Configuring Forward Direction Control
	DIO_SetPin_Value(DIO_PORTD, DIO_PIN3, DIO_PIN_OFF);	//PIN2 OFF
	DIO_SetPin_Value(DIO_PORTD, DIO_PIN4, DIO_PIN_ON);	//PIN3 ON
	DIO_SetPin_Value(DIO_PORTD, DIO_PIN6, DIO_PIN_ON);	//PIN5 ON
	DIO_SetPin_Value(DIO_PORTD, DIO_PIN7, DIO_PIN_OFF);	//PIN6 OFF
}

void DC_STOP()
{
	//Motors Left & Right Lines Power OFF
	DIO_SetPin_Value(DIO_PORTD, DIO_PIN2, DIO_PIN_OFF);	//Left Line Power OFF
	DIO_SetPin_Value(DIO_PORTD, DIO_PIN5, DIO_PIN_OFF);	//Right Line Power OFF
}