#include <stdint.h>
#include "I2C.h"
#
#include <stdio.h>

int main()
{
    char data[2]; // To store the read data
    I2C1_init(); // Initialize the I2C1 peripheral

    //Write the address to the sensor
    I2C1_byteWrite(0x40,0xF3,data);

    // Read the temperature from the ES13505 sensor
    I2C1_byteRead(0x3A, 0x00, data); // Read the temperature value from the sensor's register

    // Convert the raw data to temperature value (assuming a 12-bit resolution)
    int temp = (data[0] << 8) | data[1]; // Combine the two bytes of raw data into a 16-bit value
    float temperature = (float)temp * 0.0625f; // Convert the raw data to temperature value (each bit represents 0.0625°C)



    return 0;
}
