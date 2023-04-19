/*
 * exit.h
 *
 *  Created on: Apr 13, 2023
 *      Author: sanketh
 */

#ifndef INC_EXIT_H_
#define INC_EXIT_H_

#include "stm32f4xx.h"
#include "uart.h"
#include "systick.h"
#include <stdint.h>

void pc13_exit_init(void);
void EXTI15_10_IRQHandler(void);
void pa5_out_init(void);
static void exti_callback(void);

#endif /* INC_EXIT_H_ */
