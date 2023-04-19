#include "stm32f4xx.h"
#include <stdint.h>
#include "uart.h"


void uart2_init(void) {
	/****************Configure uart gpio pin***************/
			/*Enable clock access to gpioa */
			RCC->AHB1ENR |= GPIOAEN;

			/*Set PA2 mode to alternate function mode*/
			GPIOA->MODER  |= PA2MOD;

			/*Set PA2 alternate function type to UART_TX (AF07)*/
	        GPIOA->AFR[0] |= PA2AF;

			/****************Configure uart module ***************/
			/*Enable clock access to uart2 */
	         RCC->APB1ENR |= APB1EN;

			/*Configure baudrate*/
			uart_set_baudrate(USART2,APB1_CLK,UART_BAUDRATE);
			//USART2->BRR = ((APB1_CLK + (BaudRate/2U))/BaudRate) ;

			/*Configure the transfer direction*/
			USART2->CR1 = USART2_TX;

			/*Enable uart module*/
	        USART2->CR1 |= USART2EN;
}

void uart2_write(char ch) {
	// Loop through the string

	        // Wait until the transmit data register is empty
	        while(!(USART2->SR & SR_TXE)){}

	        // Write the current character to the transmit data register
	        USART2->DR =ch ;
}

void uart_str(char *str) {
    // Code from original uart_str() function
	for(int i =0; str[i]!='\0';i++)
		{
			uart2_write(str[i]);
		}
}

static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t BaudRate) {
    // Code from original uart_set_baudrate() function
	USARTx->BRR =  compute_uart_bd(PeriphClk,BaudRate);
}

static uint16_t compute_uart_bd(uint32_t PeriphClk, uint32_t BaudRate) {
    // Code from original compute_uart_bd() function
	return ((PeriphClk + (BaudRate/2U))/BaudRate);
}
