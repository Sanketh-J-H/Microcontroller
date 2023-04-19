/*
 * Timer3_InputCapture.h
 *
 *  Created on: Apr 19, 2023
 *      Author: sanketh
 */

#ifndef INC_TIMER3_INPUTCAPTURE_H_
#define INC_TIMER3_INPUTCAPTURE_H_

#include "stm32f4xx.h"
#include <stdint.h>

#define TIM2EN		(1U<<0)
#define TIM3EN		(1U<<1)

#define CR1_CEN		(1U<<0)
#define OC_TOGGLE	((1U<<4) | (1U<<5))
#define CCER_CC1E	(1U<<0)
#define CCER_CC1P   (1U<<1)


#define GPIOAEN		(1U<<0)
#define AFR5_TIM	(1U<<20)
#define AFR6_TIM	(1U<<25)
#define CCER_CC1S   (1U<<0)

void tim3_pa6_input_capture(void);
void tim2_pa5_output_compare(void);


#endif /* INC_TIMER3_INPUTCAPTURE_H_ */
