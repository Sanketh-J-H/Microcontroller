/*
 * timer2.c
 *
 *  Created on: Apr 17, 2023
 *      Author: sanketh
 */

#include "timer2.h"


void tim2_1hz_init(void)
{
	// Enable clock access to TIM2
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

	// Set prescaler value (assuming 16 MHz system clock and desired 1 Hz timer frequency)
	TIM2->PSC = 15999;

	// Set auto-reload value (assuming 1 Hz timer frequency)
	TIM2->ARR = 999;

	// Clear counter
	TIM2->CNT = 0;

	// Enable timer
	TIM2->CR1 |= TIM_CR1_CEN;
}

void tim2_delay(void)
{

       /*Wait for UIF */
	while(!(TIM2->SR & SR_UIF)){}

	/*Clear UIF*/
	TIM2->SR &=~SR_UIF;

}
