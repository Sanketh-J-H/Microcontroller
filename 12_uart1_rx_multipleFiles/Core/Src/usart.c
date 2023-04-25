#include "stm32f4xx.h"
#include "usart.h"

/* Read a character from USART2*/
char USART2_read(void)
{
    while (!(USART2->SR & 0x0020))
    {
    } // wait until char arrives
    return USART2->DR;
}

/*------------------------------------------------------------------
---------Initialize UART pins, Baudrate
*-------------------------------------------------------------------
---------*/

void USART2_init(void)
{
    RCC->AHB1ENR |= 1;       /* Enable GPIOA clock */
    RCC->APB1ENR |= 0x20000; /* Enable USART2 clock */
    USART2->BRR = 0x682;    /* 115200 baud @ 16 MHz */
    USART2->CR1 = 0x0004;    /* enable Rx, 8-bit data */
    USART2->CR2 = 0x0000;    /* 1 stop  bit */
    USART2->CR3 = 0x0000;    /* no flow control */
    USART2->CR1 |= 0x2000;   /* enable USART2 */
    /* Configure PA3 for USART2 RX */
    GPIOA->AFR[0] &= ~0xF000;
    GPIOA->AFR[0] |= 0x7000; /* alt7 for USART2 */
    GPIOA->MODER &= ~0x00C0;
    GPIOA->MODER |= 0x0080; /* enable alternate function for PA3 */
}

