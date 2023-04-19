#include "stm32f4xx.h"
#include <stdint.h>

#define    GPIOAEN     (1U<<0)
#define    PA2MOD      (2U<<4)
#define    PA2AF       (7U<<8)
#define    APB1EN      (1U<<17)
#define    USART2_TX   (1U<<3)
#define    USART2EN    (1U<<13)
#define    SR_TXE      (1U<<7)


#define SYS_FREQ		16000000
#define APB1_CLK		SYS_FREQ

#define UART_BAUDRATE	115200

#define SYSTICK_LOAD_VAL			16000
#define	CTRL_ENABLE					(1U<<0)
#define CTRL_CLKSRC					(1U<<2)
#define CTRL_COUNTFLAG				(1U<<16)

void systickDelayMs(int delay)
{
	/*Reload with number of clocks per millisecond*/
	SysTick->LOAD	= SYSTICK_LOAD_VAL;

	/*Clear systick current value register */
	SysTick->VAL = 0;

	/*Enable systick and select internal clk src*/
	SysTick->CTRL = CTRL_ENABLE | CTRL_CLKSRC;

	for(int i=0; i<delay ; i++)
	{
		/*Wait until the COUNTFLAG is set*/
		while((SysTick->CTRL &  CTRL_COUNTFLAG) == 0){}
	}

	SysTick->CTRL = 0;

}

void uart2_init(void);
void uart2_write(char ch);
void uart_str(char *str);

static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk,  uint32_t BaudRate);
static uint16_t compute_uart_bd(uint32_t PeriphClk, uint32_t BaudRate);

int main()
{

	uart2_init();
	while(1)
	{
		//char* message = "Hello, Welcome all.\r\n";
		uart_str("Hello, Welcome all.\r\n");
		systickDelayMs(1000);

	}
	return 0;
}


void uart2_init(void)
{

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






static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk,  uint32_t BaudRate)
{
	USARTx->BRR =  compute_uart_bd(PeriphClk,BaudRate);
}

static uint16_t compute_uart_bd(uint32_t PeriphClk, uint32_t BaudRate)
{
	return ((PeriphClk + (BaudRate/2U))/BaudRate);
}






void uart2_write(char ch)
{
    // Loop through the string

        // Wait until the transmit data register is empty
        while(!(USART2->SR & SR_TXE)){}

        // Write the current character to the transmit data register
        USART2->DR =ch ;

}

void uart_str(char *str)
{
	for(int i =0; str[i]!='\0';i++)
	{
		uart2_write(str[i]);
	}
}

