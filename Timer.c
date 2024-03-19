/*
 * Timer.c
 * Created: 4/13/2023 12:29:44 AM
 * Author: Antoine
 */ 
#include "Timer.h"

//Timer0 Configuration
void Timer_INIT(void)
{
    //Configuring TIMER0 in Normal Mode
    Clear_Bit(TCCR0,3);
    Clear_Bit(TCCR0,6);
    
    //Configuring TIMER0 to a Prescaler of 1024
    Clear_Bit(TCCR0,1);
    Set_Bit(TCCR0,0);
    Set_Bit(TCCR0,2);
}

//Timer0 Delay Function
void Timer_delay(int delay)    //Input Delay in Seconds
{
    unsigned long count;
    
    Timer_INIT();
    
    //Initialize TCNT0
    TCNT0 = 0;
    
    //Calculate the Number of Cycles
    unsigned long T = ( delay / 0.000064);
    count = T / 256;            //count = (delay * 1000000) / 64;
    PORTB = count;
    //Delay Logic
    while(count > 0)
    {
        if(TIFR & 1)
        {
            count--;
            Set_Bit(TIFR,0);
        }
    }
    TCCR0 = 0;    //Stop TIMER0
}