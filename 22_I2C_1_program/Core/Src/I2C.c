/*
 * I2C.c
 *
 *  Created on: Apr 26, 2023
 *      Author: sanketh
 */
#include "I2C.h"

/*Pin
  PB8----SCL
  PB9-----SDA
   */
void I2C1_init(void)
{
	/*Configure GPIO port*/
	//Enable clock access to GPIOB
	RCC->AHB1ENR |= GPIOBEN;

	//Set PB8 and PB9 to alternate function mode
	GPIOB->MODER &= ~(1U<<16);
	GPIOB->MODER |= (1U<<17);

	GPIOB->MODER &= ~(1U<<18);
	GPIOB->MODER |= (1U<<19);

	//Set PB8 and PB9  Output type to open drain mode
	GPIOB->OTYPER |= (1U<<8);
	GPIOB->OTYPER |= (1U<<9);

	//Enable PullUp for PB8 and PB9
	GPIOB->PUPDR |= (1U<<16);
	GPIOB->PUPDR &= ~(1U<<17);

	GPIOB->PUPDR |= (1U<<18);
	GPIOB->PUPDR &= ~(1U<<19);

	/*Configure I2C 1 peripheral*/
	//Enable clock access to I2C_1
	RCC->APB1ENR |= I2CEN;

	//Enter reset mode
	I2C1->CR1 |=(1U<<15);

	//Come out of reset mode
	I2C1->CR1 &=~(1U<<15);

	//Set peripheral clock frequency
	I2C1->CR2 = (1U<<4);  //16Mhz

	// Set I2C to standard mode , 100 khz clk
	I2C1->CCR = I2C_100KHZ;

	//Set rise time
	I2C1->TRISE = SD_MODE_MAX_RISE_TIME;

	//Enable I2C1 module
	I2C1->CR1 |= CR1_PE;
}

void I2C1_byteRead(char saddr, char maddr, char* data)
{
	volatile int temp;

	//Wait until not busy
	while(I2C1->SR2 & (SR2_BUSY)){}

	//Generate start
	I2C1->CR1 |= CR1_START;

	//wait until start flag is set
	while (!(I2C1->SR1 & (SR1_SB))){}

	//Transmit slave address + Write
	I2C1->DR =saddr<<1;

	//Wait until addr flag is set
	while(!(I2C1->SR1 &(SR1_ADDR))){}

	//Clear the addr flag by reading it
	temp = I2C1->SR2;

	//Send memory address
	I2C1->DR = maddr;

	//Wait until transmitter is empty
	while(!(I2C1->SR1 & SR1_TXE)){}

	//Generate restart
	I2C1->CR1 |= CR1_START;

	//Wait until start flag is set
	while(!(I2C1->SR1 & SR1_SB)){}

	//Transmit slave address + read
	I2C1->DR = saddr << 1 | 1 ;

	//Wait until addr flag is set
	while(!(I2C1->SR1 &(SR1_ADDR))){}

	//Disable Acknowledge
	I2C1->CR1 &= ~CR1_ACK;

	//Clear the addr flag by reading it
	temp = I2C1->SR2;

	//Generate stop after the data is received
	I2C1->CR1 |= CR1_STOP;

	//Wait until RXNE flag is set
	while(!(I2C1->SR1 & SR1_RXNE)){}

	//Read data from DR
	*data++ = I2C1->DR;
}

void I2C1_byteWrite(char saddr, char maddr, char* data)
{
    volatile int temp;

    // Wait until not busy
    //while (I2C1->SR2 & SR2_BUSY) {}

    // Generate start
    I2C1->CR1 |= CR1_START;

    // Wait until start flag is set
    while (!(I2C1->SR1 & SR1_SB)) {}

    // Transmit slave address + Write
    I2C1->DR = saddr << 1;

    // Wait until addr flag is set
    while (!(I2C1->SR1 & SR1_ADDR)) {}

    // Clear the addr flag by reading it
    temp = I2C1->SR2;

    // Send memory address
    I2C1->DR = maddr;

    // Wait until transmitter is empty
    while (!(I2C1->SR1 & SR1_TXE)) {}

    // Send data
    I2C1->DR = data;

    // Wait until transmitter is empty and transfer is complete
    while (!(I2C1->SR1 & SR1_TXE) || !(I2C1->SR1 & SR1_BTF)) {}

    // Generate stop
    I2C1->CR1 |= CR1_STOP;
}



