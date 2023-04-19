#include "uart1ReadWrite.h"


int main()
{

	char c;
    uart1_init();
    gpio_init();

    while(1)
    {
    	c = uart1_read();
    	if(c == 'N')
    		gpio_set();
    	else if(c == 'F')
    		gpio_reset();
    	else
    	{

    	}
    	uart1_write(c);
    }
    return 0;
}
