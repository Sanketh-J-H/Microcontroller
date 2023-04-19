#include "stm32f4xx.h"

#define SYSTICK_LOAD_VAL			16000
#define	CTRL_ENABLE					(1U<<0)
#define CTRL_CLKSRC					(1U<<2)
#define CTRL_COUNTFLAG				(1U<<16)

void systickDelayMs(int delay)
{
	/*Reload with number of clocks per millisecond*/
	SysTick->LOAD	= SYSTICK_LOAD_VAL;

	/*Clear systick current value register */
	SysTick->VAL = 0;

	/*Enable systick and select internal clk src*/
	SysTick->CTRL = CTRL_ENABLE | CTRL_CLKSRC;

	for(int i=0; i<delay ; i++)
	{
		/*Wait until the COUNTFLAG is set*/
		while((SysTick->CTRL &  CTRL_COUNTFLAG) == 0){}
	}

	SysTick->CTRL = 0;

}

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
            counter++; // increment counter

            while(GPIOC->IDR & GPIO_IDR_ID13); // wait for button release
            systickDelayMs(200); // debounce delay
        }

        // blink LED based on counter value
        for (uint32_t i = 0; i < counter; i++)
        {
            GPIOA->BSRR = GPIO_BSRR_BS5; // turn on LED
            systickDelayMs(500); // delay of 0.5 second
            GPIOA->BSRR = GPIO_BSRR_BR5; // turn off LED
            systickDelayMs(500); // delay of 0.5 second
        }

    }

}
