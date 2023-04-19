#include "rcc.h"

void rcc_init(void) {
  // Enable the GPIOA clock
  RCC->AHB1ENR |= (1 << 0);
}
