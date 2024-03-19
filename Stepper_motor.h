/*
 * Stepper_motor.h
 * Created: 6/13/2023 11:59:09 AM
 * Author: Ahmed ElAfifi
 */ 


#ifndef STEPPER_MOTOR_H_
#define STEPPER_MOTOR_H_

#include "DIO.h"
#define F_CPU		16000000
#include <util/delay.h>

//Stepper motor control functions
void STP_INIT(void);
void STP_UP(void);
void STP_DOWN(void);
void STP_DIR_CLK(void);





#endif /* STEPPER_MOTOR_H_ */