#include "stm32f4xx.h"
#include "gpio.h"

void gpio_init_output(void)
{
    RCC->AHB1ENR |= 1;          // Enable GPIOA clock
    GPIOA->MODER &= ~0x00000C00; // Clear pin mode
    GPIOA->MODER |= 0x00000400;  // Set pin to output mode
}

void gpio_set_output_high(void)
{
    GPIOA->BSRR = 0x00000020;   // Turn on green LED
}

void gpio_set_output_low(void)
{
    GPIOA->BSRR = 0x00200000;  // Turn off green LED
}

void gpio_init_input(void)
{
    RCC->AHB1ENR |= 1<<2;          // Enable GPIOC clock
    GPIOC->MODER &= ~0x0C000000; // Clear pin mode
}

int gpio_read_input(void)
{
    return (GPIOC->IDR & 0x2000); // Return the state of PC13
}
