#ifndef GPIO_H
#define GPIO_H

void gpio_init_output(void);
void gpio_set_output_high(void);
void gpio_set_output_low(void);
void gpio_init_input(void);
int gpio_read_input(void);

#endif
