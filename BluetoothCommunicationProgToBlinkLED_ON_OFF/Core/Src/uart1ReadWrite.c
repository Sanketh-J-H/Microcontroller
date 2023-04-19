/*
 * uart1ReadWrite.c
 *
 *  Created on: Apr 19, 2023
 *      Author: sanketh
 */
#include "uart1ReadWrite.h"


void uart1_init(void)
{

    /**Configure uart gpio pin***/
        /*Enable clock access to gpioa */
        RCC->AHB1ENR |= GPIOAEN;

        //Set PA9 mode to alternate function mode/
        GPIOA->MODER  |= PA9MOD;

        //Set PA10 mode to alternate function mode/
        GPIOA->MODER  |= PA10MOD;

        //Set PA9 alternate function type to UART_TX (AF07)/
        GPIOA->AFR[1] |= PA9AF;

        //Set PA10 alternate function type to UART_RX (AF07)/
        GPIOA->AFR[1] |= PA10AF;

        /**Configure uart module ***/
        /*Enable clock access to uart1 */
         RCC->APB2ENR |= APB2EN;

        //Configure baudrate/
        uart_set_baudrate(USART1,APB2_CLK,UART_BAUDRATE);

        //Configure the transfer direction/
        USART1->CR1 |= USART1_TX;

        //Configure the transfer direction/
        USART1->CR1 |= USART1_RX;

        //Enable uart module/
        USART1->CR1 |= USART1EN;

}




static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk,  uint32_t BaudRate)
{
    USARTx->BRR =  compute_uart_bd(PeriphClk,BaudRate);
}

static uint16_t compute_uart_bd(uint32_t PeriphClk, uint32_t BaudRate)
{
	return ((PeriphClk + (BaudRate/2U))/BaudRate);
}




char uart1_read(void)
{
  //Make sure the transmit data register is empty/
	while(!(USART1->SR & SR_RXNE)){}

  //read to receive data register/
	return USART1->DR;
}


void uart1_write(int ch)
{
  //Make sure the transmit data register is empty/
	while(!(USART1->SR & SR_TXE)){}

  //Write to transmit data register/
	USART1->DR	=  (ch & 0xFF);
}

void uart_str(char *str)
{
	for(int i =0; str[i]!='\0';i++)
	{
		uart1_write(str[i]);
	}
}

