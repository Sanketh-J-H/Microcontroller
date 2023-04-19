
#include "exit.h"

int main(void)
{

	pc13_exit_init();
	pa5_out_init();

	while(1)
	{

		EXTI15_10_IRQHandler();

	}

}


