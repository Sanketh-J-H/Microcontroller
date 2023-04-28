#include "adc.h"
#include "stm32f4xx.h"

uint16_t adc_value=0;
// Constants for ADC and temperature conversion
const float ADC_REFERENCE_VOLTAGE = 5.0;  // ADC reference voltage in volts
const float ADC_MAX_VALUE = 4095.0;  // Maximum ADC value
const float TEMPERATURE_SLOPE = 0.1;  // Temperature sensor slope in degrees C per mV
const float TEMPERATURE_OFFSET = 0.0;  // Temperature sensor offset in degrees C
float temperature =0;
float voltage = 0;

int main()
{
	pa1_adc_init();
	start_converstion();

	while(1)
	{

		adc_value=adc_read();
		// Convert the ADC value to voltage
		voltage = adc_value * ADC_REFERENCE_VOLTAGE / ADC_MAX_VALUE;

		// Convert the voltage to temperature in Celsius
		temperature = voltage / TEMPERATURE_SLOPE - TEMPERATURE_OFFSET;

	}

	return 0;
}



