/*
 * gpioa5.c
 *
 *  Created on: Apr 17, 2023
 *      Author: sanketh
 */
#include "gpioa5.h"

void gpioa5_init(void)
{
    RCC->AHB1ENR |= 1;          // Enable GPIOA clock
    GPIOA->MODER &= ~0x00000C00; // Clear pin mode
    GPIOA->MODER |= 0x00000400;  // Set pin to output mode
}
