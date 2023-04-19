#include "led.h"

int main(void)
{
    LED_Init();
    while (1)
    {
        LED_Toggle();
        LED_Delay();
    }
}
