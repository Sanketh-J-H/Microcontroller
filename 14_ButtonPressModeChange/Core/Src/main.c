#include "exit.h"
#include "uart.h"
#include "systick.h"

int main()
{
    uart2_init();
    pc13_exit_init();
    pa5_out_init();
    while(1)
    {
    	EXTI15_10_IRQHandler();
    }
    return 0;
}
