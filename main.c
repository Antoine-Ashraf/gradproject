/*
 * Receiver.c
 * Created: 5/23/2023 5:53:40 PM
 * Author : Antoine
 */ 

#define F_CPU 16000000

#include "DIO.h"
#include "Timer.h"
#include "UART.h"
#include "Valves.h"
#include "std.h"

#define ZONE1	0
#define ZONE2	1
#define ZONE3	2
#define ZONE4	3

extern Uint8 i;
Uint16 sensor_value;
volatile Uint8 zone;


int main(void)
{
	zone = ZONE4;	//Calibrating Zone Counter to 0 for Program Start
	Timer_INIT();	//Initializing TIMER0
	
	//Valves Control
    VALVE_INIT();		//Initializing Valves Pins as Output Pins
	VALVE_SYS_OFF();
	SYSTEM_TEST();		//Performing Valves System Test Before Operation
	VALVE_SYS_OFF();	//Configuring Valves as Initially OFF
	
	//UART Control 
	UART_INIT_RX();	//Initializing UART as Receiver
    while (1) 
    {
		//sensor_value = UART_RECV();	//Storing the Sensor Value from the Receiver in a Variable
		sensor_value = UART_RECVval();	//Storing the Sensor Value from the Receiver in a Variable
		//zone ++;
		zone = (zone + 1) % 4;
		if (sensor_value < 350)		//If Moisture Value Less than Standards
		{
			switch (zone)
			{
				case ZONE1:
					VALVE_1_ON();
					Timer_delay(2);
					VALVE_1_OFF();
					break;
				case ZONE2:
					VALVE_2_ON();
					Timer_delay(2);
					VALVE_2_OFF();	
					break;
				case ZONE3:
					VALVE_3_ON();
					Timer_delay(2);
					VALVE_3_OFF();
					break;
				case ZONE4:
					VALVE_4_ON();
					Timer_delay(2);
					VALVE_4_OFF();
					break;
			}
		}
		else if (sensor_value > 350)	//If Moisture Value More than Standards
		{
			VALVE_SYS_OFF();
		}
		sensor_value = 0;
    }
}