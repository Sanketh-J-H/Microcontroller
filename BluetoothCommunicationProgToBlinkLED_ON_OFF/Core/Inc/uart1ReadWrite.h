/*
 * uart1ReadWrite.h
 *
 *  Created on: Apr 19, 2023
 *      Author: sanketh
 */

#ifndef INC_UART1READWRITE_H_
#define INC_UART1READWRITE_H_

#include "stm32f4xx.h"
#include <stdint.h>

#define    GPIOAEN     (1U<<0)
#define    PA9MOD      (2U<<18)
#define    PA9AF       (7U<<4)
#define    PA10MOD     (2U<<20)
#define    PA10AF      (7U<<8)
#define    APB2EN      (1U<<4)
#define    USART1_RX   (1U<<2)
#define    USART1EN    (1U<<13)
#define    USART1_TX   (1U<<3)

#define    SR_RXNE     (1U<<5)
#define    SR_TXE      (1U<<7)

#define SYS_FREQ        16000000
#define APB2_CLK        SYS_FREQ

#define UART_BAUDRATE   9600


void uart1_init(void);
char uart1_read(void);
void uart1_write(int);
void uart_str(char *str);

static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk,  uint32_t BaudRate);
static uint16_t compute_uart_bd(uint32_t PeriphClk, uint32_t BaudRate);

#endif /* INC_UART1READWRITE_H_ */
