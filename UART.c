/*
 * UART.c
 * Created: 4/29/2023 2:55:20 PM
 * Author: Antoine
 */

#define BAUD_RATE	9600
#include "UART.h"

void UART_INIT_TX()
{
	//Loading Baud Rate Values 
	UBRRH = (((BAUD_RATE_VALUE) & 0xFF00)>>8);
	UBRRL = (BAUD_RATE_VALUE) & 0x00FF;
	
	//Setting UCSRA to 0 Initially
	UCSRA = 0;
	
	//Configuring UART
	Set_Bit(UCSRB, TXEN);	//Enabling the Transmitter
	UCSRC = (1 << 7) | (3 << 1);	//Configuring Data transmission Size
}

void UART_INIT_RX()
{
	//Loading Baud Rate Values
	UBRRH = (((BAUD_RATE_VALUE) & 0xFF00)>>8);
	UBRRL = (BAUD_RATE_VALUE) & 0x00FF;
	
	//Setting UCSRA to 0 Initially
	UCSRA = 0;
	
	//Configuring UART
	Set_Bit(UCSRB, RXEN);	//Enabling the Transmitter
	UCSRC = (1 << 7) | (3 << 1);	//Configuring Data transmission Size
}



void UART_TRANS(char data)
{
	while ((UCSRA & (1<<UDRE)) == 0);	//Checking if UDR is empty
	UDR = data;		//Loading Data into UDR to be Transmitted
}

char UART_RECV()
{
	while((UCSRA & (1<<RXC)) == 0);
	return UDR;
}

int UART_RECVval()
{
	int val = 0;
	for(int i = 100; i != 0; i/=10)
	{
		char c = UART_RECV();
		val += (c-'0')*i;
	}
	return val;
}