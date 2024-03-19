/*
 * ADC.h
 *
 * Created: 10/7/2022 4:57:14 PM
 *  Author: Ahmed ElAfifi
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "ADC_CFG.h"

//voltage reference modes

#define	ADC_vr_AREF						0
#define	ADC_vr_AVCC						1
#define	ADC_vr_RESERVED					2
#define	ADC_vr_Internal_2_56			3

//left / right adjust modes

#define	ADC_right_ADJUST				0
#define	ADC_left_ADJUST					0

//ADC pins

#define	ADC_PIN0						DIO_PIN0
#define	ADC_PIN1						DIO_PIN1
#define	ADC_PIN2						DIO_PIN2
#define	ADC_PIN3						DIO_PIN3
#define	ADC_PIN4						DIO_PIN4
#define	ADC_PIN5						DIO_PIN5
#define	ADC_PIN6						DIO_PIN6
#define	ADC_PIN7						DIO_PIN7

//ADC conversion modes

#define	ADC_single_conv			0
#define	ADC_auto_trigg				1

//ADC auto trigger modes

#define ADC_Free_Running_Mode			0
#define ADC_Analog_Comp					1
#define ADC_EXT_INT0					2
#define ADC_Timer0_Comp_Match			3
#define ADC_Timer0_OVF					4
#define ADC_Timer1_Comp_Match_B			5
#define ADC_Timer1_OVF					6
#define ADC_Timer1_Cap_Mode				7

//ADC pre scaler

#define ADC_CLK_2					1
#define ADC_CLK_4					2
#define ADC_CLK_8					3
#define ADC_CLK_16					4
#define ADC_CLK_32					5
#define ADC_CLK_64					6
#define ADC_CLK_128					7


void ADC_INIT(void);
Uint16 ADC_read(Uint8 pin);





#endif /* ADC_H_ */