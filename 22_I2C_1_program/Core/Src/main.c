#include <stdint.h>
#include "I2C.h"
#include "stm32f4xx_hal.h"

void delay(int n)
{
    volatile int i;
    for(i = 0; i < n; i++);
}


int main()
{
    char data[2]={0,0}; // To store the read data
    I2C1_init(); // Initialize the I2C1 peripheral

    while(1)
    {
		//Write the address to the sensor
		I2C1_byteWrite(0x40,0xE6,&data);

		// Wait for the sensor to finish processing the measurement
		delay(1000000); // Add a delay of 15ms (maximum time required for measurement)


		// Read the temperature from the ES13505 sensor
		I2C1_burstRead(0x40, 0xE3,2, &data); // Read the temperature value from the sensor's register

		// Convert the raw data to temperature value (assuming a 12-bit resolution)
		int temp = (data[0] << 8) | data[1]; // Combine the two bytes of raw data into a 16-bit value
		float temperature = (float)temp*0.01f- 40.0f; // Convert the raw data to temperature value (each bit represents 0.0625°C)
    }


    return 0;
}
