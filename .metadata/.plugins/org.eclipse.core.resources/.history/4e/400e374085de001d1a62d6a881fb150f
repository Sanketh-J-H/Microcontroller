#include "Timer3_InputCapture.h"

uint32_t timestamp;

int main()
{

	tim3_pa6_input_capture();
	tim2_pa5_output_compare();
	while (1)
	    {
	        // Wait until edge is captured
	        while (!(TIM3->SR & TIM_SR_CC1IF))
	        {
	            // Do nothing
	        }

	        // Read captured value
	        timestamp = TIM3->CCR1;

	        // Clear CC1 interrupt flag
	        //TIM3->SR &= ~TIM_SR_CC1IF;

	        // Do something with the captured timestamp
	        // ...

	        // Reset the timer value to 0
	        //TIM3->CNT = 0;
	    }
}
