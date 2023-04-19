#include "stm32f4xx.h"
#include "led.h"
#include "systick.h"

/* turn on or off the LEDs according to the value */
void LED_blink(int value)
{
    value %= 16; /* cap the max count at 15 */
    for (; value > 0; value--)
    {
        GPIOA->BSRR = 0x00000020; /* turn on LED */
        systickDelayMs(200);
        GPIOA->BSRR = 0x00200000; /* turn off LED */
        systickDelayMs(200);
    }
    systickDelayMs(800);
}

void LED_init(void)
{
	RCC->AHB1ENR |= 1;           /* enable GPIOA clock */
	GPIOA->MODER &= ~0x00000C00; /* clear pin mode */
	GPIOA->MODER |= 0x00000400;  /* set pin to output mode */
}
