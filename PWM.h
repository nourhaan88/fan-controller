/*
 * PWM.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Nourhan Ehab
 */

#ifndef PWM_H_
#define PWM_H_
#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define MAX_DUTY_CYCLE  256

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description:
 * Generate a PWM signal with frequency 500Hz
 * Timer0 will be used with pre-scaler F_CPU/8
 * F_PWM=(F_CPU)/(256*N) = (10^6)/(256*8) = 500Hz
 * Duty Cycle can be changed be update the value in
 * The Compare Register
 */
void Timer0_PWM_start(uint8 duty_cycle);


#endif /* PWM_H_ */
