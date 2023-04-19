#ifndef UART_H_
#define UART_H_

#include <stm32f4xx.h>
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

void uart2_init(void);
void uart_str(char *str);

static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk,  uint32_t BaudRate);
static uint16_t compute_uart_bd(uint32_t PeriphClk, uint32_t BaudRate);


#endif /* UART_H_ */
