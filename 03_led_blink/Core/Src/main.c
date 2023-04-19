/**
 * @brief General Purpose I/O
 */
#define __IO volatile
#include <stdint.h>

typedef struct
{
	__IO uint32_t MODER; /*!< GPIO port mode register,            Address offset: 0x00      */
	uint32_t dummy[4];
	__IO uint32_t ODR; /*!< GPIO port output data register,        Address offset: 0x14      */
} GPIO_TypeDef;

/**
 * @brief Reset and Clock Control
 */

typedef struct
{
	uint32_t dummy[12];
	__IO uint32_t AHB1ENR; /*!< RCC AHB1 peripheral clock register,      Address offset: 0x30 */

} RCC_TypeDef;

#define PERIPH_BASE 0x40000000UL /*!< Peripheral base address in the alias region     */

/*!< Peripheral memory map */
#define AHB1PERIPH_BASE (PERIPH_BASE + 0x00020000UL)

#define GPIOA_BASE (AHB1PERIPH_BASE + 0x0000UL)

#define RCC_BASE (AHB1PERIPH_BASE + 0x3800UL)

#define GPIOA ((GPIO_TypeDef *)(GPIOA_BASE))

#define RCC ((RCC_TypeDef *)(RCC_BASE))

#define LED_PIN 5 // Assume the LED is connected to GPIOA Pin 5

int main()
{
	// Enable the GPIOA clock
	RCC->AHB1ENR |= (1 << 0); // Set the bit 0 of AHB1ENR to enable GPIOA clock

	// Configure the GPIOA pin as output
	GPIOA->MODER |= (1 << (2 * LED_PIN)); // Set the mode of the pin to Output

	while (1) // Infinite loop
	{
		// Toggle the LED on and off
		GPIOA->ODR ^= (1 << LED_PIN); // Toggle the state of the LED pin
		for (int i = 0; i < 1000000; i++)
			; // Delay for a short period
	}
}
