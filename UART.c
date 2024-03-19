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

void UART_TRANSval(uint16_t val)
{
	int hun,ten,unit;
	
	unit = val % 10;
	ten = (val/10) % 10;
	hun = (val/100);
	
	UART_TRANS(hun + '0');
	UART_TRANS(ten + '0');
	UART_TRANS(unit + '0');
}

char UART_RECV()
{
	while((UCSRA & (1<<RXC)) == 0);
	return UDR;
}