/*
 * DIO.h
 *
 * Created: 9/10/2022 2:14:32 PM
 *  Author: AMIT
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "std.h"
#include "Bit_Math.h"
#include "MCU.h"

/*------------------> DIO PORTS <--------------------*/
#define DIO_PORTA			0
#define DIO_PORTB			1
#define DIO_PORTC			2
#define DIO_PORTD			3

/*------------------> DIO PINS <--------------------*/
#define DIO_PIN0			0
#define DIO_PIN1			1
#define DIO_PIN2			2
#define DIO_PIN3			3
#define DIO_PIN4			4
#define DIO_PIN5			5
#define DIO_PIN6			6
#define DIO_PIN7			7

/*------------------> DIO PIN Directions <--------------------*/
#define DIO_PIN_IN			0
#define DIO_PIN_OUT			1

/*------------------> DIO PIN Values <--------------------*/
#define DIO_PIN_OFF			0
#define DIO_PIN_ON			1

void DIO_SetPin_Dir(Uint8 port, Uint8 pin, Uint8 dir);
void DIO_SetPin_Value(Uint8 port, Uint8 pin, Uint8 value);
void DIO_TogglePin(Uint8 port, Uint8 pin);
Uint8 DIO_GetPin_Value(Uint8 port, Uint8 pin);
void DIO_SetPin_Pullup(Uint8 port, Uint8 pin);



#endif /* DIO_H_ */