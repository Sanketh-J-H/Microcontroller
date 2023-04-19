#ifndef RCC_H
#define RCC_H

#include <stdint.h>

typedef struct {
  uint32_t dummy[12];
  volatile uint32_t AHB1ENR;
} RCC_TypeDef;

#define RCC ((RCC_TypeDef*)(0x40023800UL))

void rcc_init(void);

#endif /* RCC_H */
