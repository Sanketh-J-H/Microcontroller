#include "gpio.h"
#include "rcc.h"

#define LED_PIN 5

void gpio_init(void) {
  // Enable the GPIOA clock
  RCC->AHB1ENR |= (1 << 0);

  // Configure the GPIOA pin as output
  GPIOA->MODER |= (1 << (2*LED_PIN));
}

void gpio_toggle_led(void) {
  // Toggle the LED on and off
  GPIOA->ODR ^= (1 << LED_PIN);
}
