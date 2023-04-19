#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

typedef struct {
  volatile uint32_t MODER;
  uint32_t dummy[4];
  volatile uint32_t ODR;
} GPIO_TypeDef;

#define GPIOA ((GPIO_TypeDef*)(0x40020000UL))

void gpio_init(void);
void gpio_toggle_led(void);

#endif /* GPIO_H */
