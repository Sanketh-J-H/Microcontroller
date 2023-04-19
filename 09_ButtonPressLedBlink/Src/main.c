#define PERIPH_BASE         (0x40000000UL)
#define AHB1PERIPH_OFFSET   (0x00020000UL)

#define AHB1PERIPH_BASE     (PERIPH_BASE + AHB1PERIPH_OFFSET)
#define GPIO_OFFSET         (0x0000UL)

#define GPIOA_BASE          (AHB1PERIPH_BASE + GPIO_OFFSET)
#define GPIOC_BASE          (AHB1PERIPH_BASE + GPIO_OFFSET + 0x100UL)
#define RCC_OFFSET          (0x3800UL)
#define RCC_BASE            (AHB1PERIPH_BASE + RCC_OFFSET)

#define AHB1EN_R_OFFSET     (0x30UL)
#define RCC_AHB1EN_R        (*(volatile unsigned int *)(RCC_BASE + AHB1EN_R_OFFSET))

#define MODE_R_OFFSET       (0x00UL)
#define GPIOA_MODE_R        (*(volatile unsigned int *)(GPIOA_BASE + MODE_R_OFFSET))
#define GPIOC_MODE_R        (*(volatile unsigned int *)(GPIOC_BASE + MODE_R_OFFSET))

#define OD_R_OFFSET         (0x14UL)
#define GPIOA_OD_R          (*(volatile unsigned int *)(GPIOA_BASE + OD_R_OFFSET))

#define IDR_OFFSET          (0x10UL)
#define GPIOC_IDR           (*(volatile unsigned int *)(GPIOC_BASE + IDR_OFFSET))

#define GPIOAEN             (1U<<0)
#define GPIOCEN             (1U<<2)
#define PIN5                (1U<<5)
#define LED_PIN             PIN5

int main(void)
{
    // Enable GPIOA and GPIOC clocks
    RCC_AHB1EN_R |= GPIOAEN | GPIOCEN; // Set bit 0 of RCC_AHB1EN_R to 1

    // Set PA5 as output
    GPIOA_MODE_R &= ~(1U<<11); // Clear bits 11 and 10 of GPIOA_MODE_R
    GPIOA_MODE_R |= (1U << 10); // Set bit 10 of GPIOA_MODE_R

    // Set PC13 as input
    GPIOC_MODE_R &= ~(3U << 26); // Clear bits 27 and 26 of GPIOC_MODE_R

    while (1)
    {
        if (GPIOC_IDR & (1U<<13)) // If PC13 is high
        {
            // Turn off LED
            GPIOA_OD_R &= ~LED_PIN; // Clear bit 5 of GPIOA_OD_R
        }
        else
        {
            // Turn on LED
            GPIOA_OD_R |= LED_PIN; // Set bit 5 of GPIOA_OD_R
        }
    }
}
