#include "stm32f4xx.h"
#include "gpio.h"

int main(void)
{
    gpio_init_output();  // Initialize GPIOA pin 5 as output
    gpio_init_input();   // Initialize GPIOC pin 13 as input
    while (1)
    {
        if (gpio_read_input()) {
            gpio_set_output_low();  // Turn off green LED
        }
        else {
            gpio_set_output_high(); // Turn on green LED
        }
    }
}
