/*
 * Timer2_OutputCompare.c
 *
 *  Created on: Apr 18, 2023
 *      Author: sanketh
 */
#include "Timer2_OutputCompare.h"

void tim2_pa5_output_compare(void)
{

	/*Enable clock access to GPIOA*/
	RCC->AHB1ENR |=GPIOAEN;

	/*Set PA5 mode to alternate function*/
	GPIOA->MODER &=~(1U<<10);
	GPIOA->MODER |=(1U<<11);

	/*Set PA5 alternate function type to TIM2_CH1 (AF01)*/
	GPIOA->AFR[0] |=AFR5_TIM;

	/*Enable clock access to tim2*/
	RCC->APB1ENR |=TIM2EN;

	/*Set prescaler value*/
	TIM2->PSC =  1600 - 1 ;  //  16 000 000 / 1 600 = 10 000

	/*Set auto-reload value*/
	TIM2->ARR =  10000 - 1;  // 10 000 / 10 000 = 1

	/* Set output compare toggle mode */
	TIM2->CCMR1 |= OC_TOGGLE;

	/* Set compare value for TIM2 Channel 1 */
	TIM2->CCR1 = 5000 - 1; // Toggle output at 50% of period

	/* Enable tim2 ch1 in compare mode */
	TIM2->CCER |= CCER_CC1E;


	/*Clear counter*/
	TIM2->CNT = 0;
	/*Enable timer*/
	TIM2->CR1 = CR1_CEN;
}
