#include "led.h"

#define PERIPH_BASE         (0x40000000UL)
#define AHB1PERIPH_OFFSET   (0x00020000UL)

#define AHB1PERIPH_BASE     (PERIPH_BASE + AHB1PERIPH_OFFSET)
#define GPIO_OFFSET         (0x0000UL)

#define GPIOA_BASE          (AHB1PERIPH_BASE + GPIO_OFFSET)
#define RCC_OFFSET          (0x3800UL)
#define RCC_BASE            (AHB1PERIPH_BASE + RCC_OFFSET)

#define AHB1EN_R_OFFSET     (0x30UL)
#define RCC_AHB1EN_R        (*(volatile unsigned int *)(RCC_BASE + AHB1EN_R_OFFSET))

#define MODE_R_OFFSET       (0x00UL)
#define GPIOA_MODE_R        (*(volatile unsigned int *)(GPIOA_BASE + MODE_R_OFFSET))

#define OD_R_OFFSET         (0x14UL)
#define GPIOA_OD_R          (*(volatile unsigned int *)(GPIOA_BASE + OD_R_OFFSET))

#define GPIOAEN     (1U<<0)

#define PIN5             (1U<<5)
#define LED_PIN              PIN5

void LED_Init(void)
{
    // Enable GPIOA clock
    RCC_AHB1EN_R |= GPIOAEN; // Set bit 0 of RCC_AHB1EN_R to 1

    // Set PA5 as output
    GPIOA_MODE_R &= ~(1U<<11); // Clear bits 11 and 10 of GPIOA_MODE_R
    GPIOA_MODE_R |= (1U << 10); // Set bit 10 of GPIOA_MODE_R
}

void LED_Toggle(void)
{
    // Toggle PA5
    GPIOA_OD_R ^= LED_PIN; // Toggle bit 5 of GPIOA_OD_R
}

void LED_Delay(void)
{
    // Delay for some time
    for (volatile int i = 0; i < 1000000; i++);
}
