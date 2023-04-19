/*
 * timer2.h
 *
 *  Created on: Apr 17, 2023
 *      Author: sanketh
 */

#ifndef INC_TIMER1_H_
#define INC_TIMER1_H_

#include "stm32f4xx.h"

//#define TIM2EN		(1U<<0)
//#define CR1_CEN		(1U<<0)
#define SR_UIF      (1U<<0)

void tim1_init(void);
void tim1_delay(void);

#endif /* INC_TIMER1_H_ */
