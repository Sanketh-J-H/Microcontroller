#include "stm32f4xx.h"

int main(void)
{
    RCC->AHB1ENR |= 1;          // Enable GPIOA clock
    GPIOA->MODER &= ~0x00000C00; // Clear pin mode
    GPIOA->MODER |= 0x00000400;  // Set pin to output mode

    while (1)
    {
        GPIOA->BSRR = 0x00000020;   // Turn on LED
        for (volatile int i = 0; i < 1000000; i++);  // Delay
        GPIOA->BSRR = 0x00200000;   // Turn off LED
        for (volatile int i = 0; i < 1000000; i++);  // Delay
    }
}
