#include "stm32f4xx.h"

int main(void) {
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; // enable GPIOA clock
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN; // enable GPIOC clock

    // set pin A5 as output
    GPIOA->MODER &= ~GPIO_MODER_MODE5;
    GPIOA->MODER |= GPIO_MODER_MODE5_0;

    // set pin C13 as input with pull-up
    GPIOC->MODER &= ~GPIO_MODER_MODE13;
    GPIOC->PUPDR &= ~GPIO_PUPDR_PUPD13;  // clear bits
    GPIOC->PUPDR |= GPIO_PUPDR_PUPD13_0; // set pull-up

    uint32_t counter = 0; // initialize counter variable

    while(1)
    {
        if(GPIOC->IDR & GPIO_IDR_ID13) // if button is pressed
        {
        	counter++;
            while(GPIOC->IDR & GPIO_IDR_ID13); // wait for button release
        }
        // blink LED based on counter value
			for (uint32_t i = 0; i < counter; i++)
			{
				for (volatile uint32_t j = 0; j < 1000000; j++); // delay
				GPIOA->BSRR = GPIO_BSRR_BS5; // turn on LED
				for (volatile uint32_t j = 0; j < 1000000; j++); // delay
				GPIOA->BSRR = GPIO_BSRR_BR5; // turn off LED

			}

    }
}





