#include "stm32f4xx.h"
#include <stdint.h>

#define    GPIOAEN      (1U<<0)
#define    PA3MOD       (2U<<6)
#define    PA3AF        (7U<<12)
#define    PA2MOD       (2U<<4)
#define    PA2AF        (7U<<8)
#define    APB1EN       (1U<<17)
#define    USART2_RX    (1U<<2)
#define    USART2EN     (1U<<13)
#define    USART2_TX    (1U<<3)
#define    SR_RXNE      (1U<<5)
#define    SR_TXE       (1U<<7)


#define SYS_FREQ		16000000
#define APB1_CLK		SYS_FREQ

#define UART_BAUDRATE	9600


void uart2_init(void);
char uart2_read(void);
void uart2_write(int);

static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk,  uint32_t BaudRate);
static uint16_t compute_uart_bd(uint32_t PeriphClk, uint32_t BaudRate);

int main()
{
	char c;

	uart2_init();
	while(1)
	{
		c = uart2_read();
		  uart2_write(c);
	}
	return 0;
}


void uart2_init(void)
{

	/**Configure uart gpio pin***/
		/*Enable clock access to gpioa */
		RCC->AHB1ENR |= GPIOAEN;

    	//Set PA2 mode to alternate function mode/
    	GPIOA->MODER  |= PA2MOD;

		//Set PA2 mode to alternate function mode/
		GPIOA->MODER  |= PA3MOD;

    	//Set PA2 alternate function type to UART_TX (AF07)/
        GPIOA->AFR[0] |= PA2AF;

		//Set PA3 alternate function type to UART_RX (AF07)/
        GPIOA->AFR[0] |= PA3AF;

		/**Configure uart module ***/
		/*Enable clock access to uart2 */
         RCC->APB1ENR |= APB1EN;

		//Configure baudrate/
		uart_set_baudrate(USART2,APB1_CLK,UART_BAUDRATE);
		//USART2->BRR = ((APB1_CLK + (BaudRate/2U))/BaudRate) ;

		//Configure the transfer direction/
		USART2->CR1 |= USART2_TX;

        //Configure the transfer direction/
    	USART2->CR1 |= USART2_RX;

		//Enable uart module/
        USART2->CR1 |= USART2EN;

}




static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk,  uint32_t BaudRate)
{
	USARTx->BRR =  compute_uart_bd(PeriphClk,BaudRate);
}

static uint16_t compute_uart_bd(uint32_t PeriphClk, uint32_t BaudRate)
{
	return ((PeriphClk + (BaudRate/2U))/BaudRate);
}




char uart2_read(void)
{
  //Make sure the transmit data register is empty/
	while(!(USART2->SR & SR_RXNE)){}

  //Write to transmit data register/
	return USART2->DR;
}


void uart2_write(int ch)
{
  //Make sure the transmit data register is empty/
	while(!(USART2->SR & SR_TXE)){}

  //Write to transmit data register/
	USART2->DR	=  (ch & 0xFF);
}
