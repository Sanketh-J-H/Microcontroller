#include "stm32f4xx.h"
#include "uart.h"
#include "systick.h"

int main() {
    uart2_init();
    while(1) {
        uart_str("Hello, Welcome all.\r\n");
        systickDelayMs(1000);
    }
    return 0;
}
