/*
 * UART.h
 * Created: 4/29/2023 2:55:32 PM
 * Author: Antoine
 */ 


#ifndef UART_H_
#define UART_H_

#include "MCU.h"
#include "Bit_Math.h"
#include <avr/io.h>

#define F_CPU	16000000

#define BAUD_RATE_VALUE (((F_CPU)/(BAUD_RATE*16UL))-1)

void UART_INIT_TX();
void UART_INIT_RX();
void UART_TRANS(char);
void UART_TRANSval(uint16_t);
char UART_RECV();



#endif /* UART_H_ */