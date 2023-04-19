/*
 * exit.c
 *
 *  Created on: Apr 13, 2023
 *      Author: sanketh
 */
#include "exit.h"

#define 	LINE13 		(1U<<13)
#define 	GPIOCEN 	(1U<<2)
#define 	SYSCFGEN	(1U<<14)

#define 	PIN5	(1U<<5)
#define 	LED		PIN5

void pc13_exit_init(void)
{
	//disable global interrupts
	__disable_irq();

	//enable clock access for GPIOC
	RCC->AHB1ENR |= GPIOCEN;

	//Set PC13 as input
	GPIOC->MODER &= ~(3U<<(2*13)); // Clear bits 27:26 (13*2)
	GPIOC->PUPDR &= ~(3U<<(2*13)); // Clear bits 27:26 (13*2)


	//Enable clock access to SYSCFG
	RCC->APB2ENR |= SYSCFGEN;

	//Select PORTC for EXTI13
	SYSCFG->EXTICR[3] &= ~(15U<<4); // Clear bits 7:4
	SYSCFG->EXTICR[3] |= 2U<<4;    // Set bits 7:4 to 0b0010


	//Unmask EXTI13
	EXTI->IMR |= LINE13;


	//Select falling edge trigger
	EXTI->FTSR |= LINE13;
	EXTI->RTSR &= ~LINE13;

	//Enable EXTI13 line in NVIC
	NVIC_EnableIRQ(EXTI15_10_IRQn);

	//Enable global interrupts
	__enable_irq();
}

void pa5_out_init(void)
{
	/*1.Enable clock access to GPIOA*/
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

	/*2.Set PA5 as output pin*/
	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &=~(1U<<11);
}

void EXTI15_10_IRQHandler(void)
{
	if((EXTI->PR & LINE13) != 0)
	{
		//clear PR flag
		EXTI->PR |= LINE13;

		//Do something
		exti_callback();
	}
}

static void exti_callback(void)
{

	GPIOA->ODR ^=LED;
}


