/*
 * motor.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Nourhan Ehab
 */

#include<avr/io.h>
#include "motor.h"
#include "std_types.h"
#include "gpio.h"
#include "PWM.h"


void DCmotor_init(void){
	/*Setup the motor pins as output pins*/
	GPIO_setupPinDirection(PORTB_ID,PIN0_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID,PIN1_ID,PIN_OUTPUT);
/*	GPIO_setupPinDirection(PORTB_ID,PIN2_ID,PIN_OUTPUT);
	GPIO_writePin(PORTB_ID,PIN2_ID,1);
	/*stop the DC motor at the beginning*/
	PORTB = PORTB & 0XFC;

}

void DCmotor_Rotate(DC_MOTOR_STATE state, uint8 speed){
	/*rotating the motor CW or A_CW or stop it based on the state input*/
	PORTB = (PORTB & 0XFC) | (state);
	/*send the duty cycle value to the PWM driver based on the required speed value*/
	Timer0_PWM_start(speed);
}
