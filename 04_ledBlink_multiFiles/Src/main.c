#include "gpio.h"
#include "rcc.h"

int main(void) {
  rcc_init();
  gpio_init();

  while (1) {
    gpio_toggle_led();
    for (int i = 0; i < 1000000; i++);
  }

  return 0;
}
