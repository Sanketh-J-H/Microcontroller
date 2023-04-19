#include "timer1.h"
#include "gpioa5.h"

int main()
{
	tim1_init();
	gpioa5_init();
	while(1)
	{
		tim1_delay();
		GPIOA->ODR ^= (1U<<5);

	}
}
