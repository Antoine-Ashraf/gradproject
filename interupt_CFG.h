/*
 * interupt_CFG.h
 *
 * Created: 10/1/2022 1:38:31 PM
 *  Author: Ahmed ElAfifi
 */ 


#ifndef INTERUPT_CFG_H_
#define INTERUPT_CFG_H_

/************* global interrupt *************/

#define global_INT				int_enable

/************* external interrupt *************/

#define ext_int0				int_disable
#define ext_int1				int_disable
#define ext_int2				int_disable

/************* ADC interrupt *************/

#define	ADC_INT					int_disable

/************* timer interrupt *************/

#define	timer_0_OVF_INT			int_enable
#define	timer_0_OCF_INT			int_enable

/*************  UART interrupt *************/

#define	UART_RX_INT				int_disable
#define	UART_TX_INT				int_disable


#endif /* INTERUPT_CFG_H_ */