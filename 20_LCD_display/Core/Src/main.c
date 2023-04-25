#include "stm32f4xx.h"

#define RS 0x20
#define RW 0x40
#define EN 0x80

void delayMs(int n);
void LCD_command(unsigned char command);
void LCD_data(char data);
void LCD_init(void);
void PORTS_init(void);

int main(void) {

LCD_init();		/* initialize LCD controller */

while(1) {
	LCD_command(0x83);
	LCD_string("Welcome",7);
	LCD_command(0xC3);	//SECOND LINE
	LCD_string("Everyone",8);
	delayMs(1000);
	LCD_command(1);
	delayMs(500);

}
}
void LCD_string(unsigned char str[200],unsigned int num){
	for(int i=0;i<num;i++){

		LCD_data(str[i]);
	}
}
/* initialize port pins then initialize LCD controller */
void LCD_init(void) {
PORTS_init();

delayMs(100);
LCD_command(0x38);
LCD_command(0x06);
LCD_command(0x01);
LCD_command(0x0F);
}
void PORTS_init(void) {
RCC->AHB1ENR |= 0x06;
GPIOB->MODER &= ~0x0000FC00;
GPIOB->MODER |=0x00005400;
GPIOB->BSRR = 0x00C00000;

GPIOC->MODER &= ~0x0000FFFF;
GPIOC->MODER |=0x00005555;
}

void LCD_command(unsigned char command) {

GPIOB->BSRR = (RS | RW) << 16;
GPIOC->ODR =command;
GPIOB->BSRR = EN;
delayMs(0);
GPIOB->BSRR = EN << 16;
if (command < 4)
delayMs(2);
else
delayMs(1);
}

void LCD_data(char data) {

GPIOB->BSRR = RS;
GPIOB->BSRR = RW << 16;
delayMs(1);
GPIOC->ODR = data;
GPIOB->BSRR = EN;
delayMs(0);
GPIOB->BSRR = EN << 16;
delayMs(1);
}
void delayMs(int n) {
	int i;
	for (; n > 0; n--)
	for (i = 0; i < 3195; i++) ;
}
