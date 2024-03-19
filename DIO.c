/*
 * DIO.c
 *
 * Created: 9/10/2022 2:14:18 PM
 *  Author: AMIT
 */ 

#include "DIO.h"
/*	Set direction of the pin: input or output */
void DIO_SetPin_Dir(Uint8 port, Uint8 pin, Uint8 dir)
{
	switch (dir)
	{
		case DIO_PIN_IN:
		switch(port)
		{
			case DIO_PORTA:
			Clear_Bit(DDRA, pin);
			break;
			case DIO_PORTB:
			Clear_Bit(DDRB, pin);
			break;
			case DIO_PORTC:
			Clear_Bit(DDRC, pin);
			break;
			case DIO_PORTD:
			Clear_Bit(DDRD, pin);
			break;									
		}
		break;
		case DIO_PIN_OUT:
		switch(port)
		{
			case DIO_PORTA:
			Set_Bit(DDRA, pin);
			break;
			case DIO_PORTB:
			Set_Bit(DDRB, pin);
			break;
			case DIO_PORTC:
			Set_Bit(DDRC, pin);
			break;
			case DIO_PORTD:
			Set_Bit(DDRD, pin);
			break;
		}		
		break;
		
		default:
		break;
	}
}
/*	Set value of the pin: ON or OFF */
void DIO_SetPin_Value(Uint8 port, Uint8 pin, Uint8 value)
{
	switch (value)
	{
		case DIO_PIN_OFF:
		switch(port)
		{
			case DIO_PORTA:
			Clear_Bit(PORTA, pin);
			break;
			case DIO_PORTB:
			Clear_Bit(PORTB, pin);
			break;
			case DIO_PORTC:
			Clear_Bit(PORTC, pin);
			break;
			case DIO_PORTD:
			Clear_Bit(PORTD, pin);
			break;
		}
		break;
		case DIO_PIN_ON:
		switch(port)
		{
			case DIO_PORTA:
			Set_Bit(PORTA, pin);
			break;
			case DIO_PORTB:
			Set_Bit(PORTB, pin);
			break;
			case DIO_PORTC:
			Set_Bit(PORTC, pin);
			break;
			case DIO_PORTD:
			Set_Bit(PORTD, pin);
			break;
		}
		break;
		
		default:
		break;
	}
}
/*	Toggle the value of the pin	*/
void DIO_TogglePin(Uint8 port, Uint8 pin)
{
	switch(port)
	{
		case DIO_PORTA:
		Toggle_Bit(PORTA, pin);
		break;
		case DIO_PORTB:
		Toggle_Bit(PORTB, pin);
		break;
		case DIO_PORTC:
		Toggle_Bit(PORTC, pin);
		break;
		case DIO_PORTD:
		Toggle_Bit(PORTD, pin);
		break;						
	}
}
/*	Get the value of the pin	*/
Uint8 DIO_GetPin_Value(Uint8 port, Uint8 pin)
{
	Uint8 value = 0;
	switch(port)
	{
		case DIO_PORTA:
		value = Get_Bit(PINA, pin);
		break;
		case DIO_PORTB:
		value = Get_Bit(PINB, pin);
		break;
		case DIO_PORTC:
		value = Get_Bit(PINC, pin);
		break;
		case DIO_PORTD:
		value = Get_Bit(PIND, pin);
		break;						
	}
	return value;
}
/*	connect the internal pullup to the pin	*/
void DIO_SetPin_Pullup(Uint8 port, Uint8 pin)
{
		switch(port)
		{
			case DIO_PORTA:
			Set_Bit(PORTA, pin);
			break;
			case DIO_PORTB:
			Set_Bit(PORTB, pin);
			break;
			case DIO_PORTC:
			Set_Bit(PORTC, pin);
			break;
			case DIO_PORTD:
			Set_Bit(PORTD, pin);
			break;
		}
}
