/*
 * ADC.c
 *
 * Created: 10/7/2022 4:57:28 PM
 *  Author: Ahmed ElAfifi
 */ 

#include "ADC.h"
#include <avr/interrupt.h>

Uint16 global_ADC =0;

void ADC_INIT(void)
{
	//global interrupt enable / disable
	SREG = (global_INT << 7) | (SREG & 0x7F);
	
	//peripherals interrupt enable / disable
	ADCSRA = (ADC_INT << 3) | (ADCSRA & 0XF7);
	
	//voltage reference an bit presentation modes
	ADMUX = (ADC_vr_MODE << 6) | (ADC_adjust_MODE << 5) | (ADMUX & 0X1F);
	
	//conversion mode & clock source & enable
	ADCSRA = (ADC_CLK_source) | (ADC_conv_MODE << 5) | (1<<7) | (ADCSRA & 0X58);
	
	//ADC auto trigger mode
	SFIOR = (ADC_auto_trigg_MODE << 5) | (SFIOR & 0X1F);
}
Uint16 ADC_read(Uint8 pin)
{
	Uint16 val=0;
	
	//ADC pin
	ADMUX = pin | (ADMUX & 0XF8);
	
	//ADC start conversion
	ADCSRA = (1 << 6) | (ADCSRA & 0XBF);
	
	while(!Get_Bit(ADCSRA , 4));
	
	//read converted value
	#if ADC_adjust_MODE == ADC_right_ADJUST
		val = ADCR;
	#elif ADC_adjust_MODE == ADC_left_ADJUST
		val = (ADCH >> 2) | (ADCL >>6);
	#endif
	
	return val;
	
}/*
ISR(ADC_vect)
{	
	#if ADC_adjust_MODE == ADC_right_ADJUST
		global_ADC = ADCR;
	#elif ADC_adjust_MODE == ADC_left_ADJUST
		global_ADC = (ADCH >> 2) | (ADCL >>6);
	#endif
	
	#if ADC_conv_MODE ==ADC_single_conv
		//ADC start conversion
		ADCSRA = (1 << 6) | (ADCSRA & 0XBF);
	#endif
	GIFR = (1 <<6) | (GIFR & 0XBF);
	global_ADC /= 11;

}*/