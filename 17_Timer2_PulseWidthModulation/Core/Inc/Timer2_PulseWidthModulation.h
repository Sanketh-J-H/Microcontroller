/*
 * Timer2_PulseWidthModulation.h
 *
 *  Created on: Apr 18, 2023
 *      Author: sanketh
 */

#ifndef INC_TIMER2_PULSEWIDTHMODULATION_H_
#define INC_TIMER2_PULSEWIDTHMODULATION_H_

#include "stm32f4xx.h"



#define TIM2EN		(1U<<0)
#define CR1_CEN	(1U<<0)

#define GPIOAEN	(1U<<0)
#define AFR5_TIM	(1U<<20)

void tim2_pa5_output_PWM(void);

#endif /* INC_TIMER2_PULSEWIDTHMODULATION_H_ */
