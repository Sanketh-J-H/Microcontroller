/*
 * timer1.c
 *
 *  Created on: Apr 17, 2023
 *      Author: sanketh
 */
#include "timer1.h"
void tim1_init(void)
{
    // Divide AHB prescaler by 2
    RCC->CFGR |= RCC_CFGR_HPRE_DIV2;

    // Enable clock access to TIM1
    RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;

    // Set prescaler value (assuming 8 MHz system clock after dividing by 2 and desired 1 Hz timer frequency)
    TIM1->PSC = 7999;

    // Set auto-reload value (assuming a desired maximum count of 1000)
    TIM1->ARR = 999;

    // Clear counter
    TIM1->CNT = 0;

    // Set direction to down-counting
    TIM1->CR1 |= TIM_CR1_DIR;

    // Enable timer
    TIM1->CR1 |= TIM_CR1_CEN;
}

void tim1_delay(void)
{

       /*Wait for UIF */
	while(!(TIM1->SR & SR_UIF)){}

	/*Clear UIF*/
	TIM1->SR &=~SR_UIF;

}
