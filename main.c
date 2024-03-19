/*
 * Transmitter.c
 * Created: 5/16/2023 1:49:32 PM
 * Author: Antoine
 * This is the Transmitter Microcontroller
 */ 

#define F_CPU 16000000

#include "Timer.h"
#include "ADC.h"
#include "DIO.h"
#include "UART.h"
#include "DC.h"
#include "interupt.h"
#include "Stepper_motor.h"

int main(void)
{
	Uint16 sensor_value = 0;
	
	//Initializing required peripherals
	Timer_INIT();	//Initializing TIMER0
	DC_INIT();	//Initializing DC Motors
	STP_INIT();	//Initializing Stepper Motor
	UART_INIT_TX();	//Initializing UART as a Sender
	ADC_INIT(); //Initializing ADC for reading the sensor value
	
	while (1)
	{
		///// ZONE 1 /////
		DC_FWD();
		Timer_delay(5);
		DC_STOP();
		STP_DOWN();
		Timer_delay(3);
		sensor_value = ADC_read(0);
		//UART_TRANS(sensor_value);
		UART_TRANSval(sensor_value);
		STP_UP();
		Timer_delay(5);
		
		
		///// ZONE 2 /////
		DC_FWD();
		Timer_delay(5);
		DC_STOP();
		STP_DOWN();
		Timer_delay(3);
		sensor_value = ADC_read(0);
		//UART_TRANS(sensor_value);
		UART_TRANSval(sensor_value);
		STP_UP();
		Timer_delay(5);
		
		
		///// ZONE 3 /////
		DC_RIGHT();
		Timer_delay(1);
		DC_FWD();
		Timer_delay(5);
		DC_STOP();
		STP_DOWN();
		Timer_delay(3);
		sensor_value = ADC_read(0);
		//UART_TRANS(sensor_value);
		UART_TRANSval(sensor_value);
		STP_UP();
		Timer_delay(5);
		DC_RIGHT();
		Timer_delay(1);
		
		
		///// ZONE 4 /////
		DC_FWD();
		Timer_delay(5);
		DC_STOP();
		STP_DOWN();
		Timer_delay(3);
		sensor_value = ADC_read(0);
		//UART_TRANS(sensor_value);
		UART_TRANSval(sensor_value);
		STP_UP();
		Timer_delay(10);
	}
	return 0;
}

