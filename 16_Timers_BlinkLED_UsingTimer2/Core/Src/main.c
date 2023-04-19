#include "timer2.h"
#include "gpioa5.h"

int main()
{
	tim2_1hz_init();
	gpioa5_init();
	while(1)
	{
		tim2_delay();
		GPIOA->ODR ^= (1U<<5);

	}
}
