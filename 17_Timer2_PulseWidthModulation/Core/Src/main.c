#include "Timer2_PulseWidthModulation.h"
#include <stdint.h>



int main()
{
	RCC->AHB1ENR |=  4;                 /* enable GPIOC clock */
	RCC->AHB1ENR |=  1;                /* enable GPIOA clock */

    GPIOA->MODER &= ~0x00000C00;        /* clear pin mode */
	GPIOA->MODER |=  0x00000400;        /* set pin to output mode */

	GPIOC->MODER &= ~0x0C000000;        /* clear pin mode to input mode */

	tim2_pa5_output_PWM();
	uint8_t Button = 0;
	while(1)
	{
				if (!(GPIOC->IDR & 0x2000)) /* if PC13 is high */
		        {
		            Button++;
		            while (!(GPIOC->IDR & 0x2000));

		        }

		        if (Button == 1)
		        {
		            TIM2->CCMR1 &= ~(1<<4); // clear bit 4
		        	TIM2->CCMR1 |= 0x60;    // set pulse width modulation mode 1
		        }
		        else
		        {
		        	TIM2->CCMR1 |= 0x70;    // set pulse width modulation mode 2
		        }

		        /* Reset Button after afterwards */
		        if (Button > 0 && Button <= 1)
		        {

		        }
		        else
		        {
		            Button = 0;
		        }

	 }


}
