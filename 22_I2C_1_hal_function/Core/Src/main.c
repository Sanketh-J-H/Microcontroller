#include "stm32f4xx_hal.h"     // HAL library for STM32F4xx microcontroller
#include "stm32f4xx_hal_i2c.h" // HAL I2C library for STM32F4xx microcontroller

#define SENSOR_ADDRESS 0x40 // ES13505 sensor address on I2C bus

I2C_HandleTypeDef hi2c1; // I2C1 handle

uint16_t read_temperature(void) {
    uint8_t buf[2];
    HAL_I2C_Mem_Read(&hi2c1, SENSOR_ADDRESS, 0xE3, I2C_MEMADD_SIZE_8BIT, buf, 2, HAL_MAX_DELAY);
    return ((buf[0] << 8) | buf[1]);
}

uint16_t read_humidity(void) {
    uint8_t buf[2];
    HAL_I2C_Mem_Read(&hi2c1, SENSOR_ADDRESS, 0xE5, I2C_MEMADD_SIZE_8BIT, buf, 2, HAL_MAX_DELAY);
    return ((buf[0] << 8) | buf[1]);
}

int main(void) {
    HAL_Init();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_I2C1_CLK_ENABLE();

    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = GPIO_PIN_6 | GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF4_I2C1;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    hi2c1.Instance = I2C1;
    hi2c1.Init.ClockSpeed = 100000;
    hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
    hi2c1.Init.OwnAddress1 = 0;
    hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
    hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
    hi2c1.Init.OwnAddress2 = 0;
    hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
    hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
    if (HAL_I2C_Init(&hi2c1) != HAL_OK) {
        Error_Handler();
    }

    while (1) {
        uint16_t temperature = read_temperature();
        uint16_t humidity = read_humidity();
        float temperature_celsius = -46.85 + 175.72 * temperature / 65536.0;
        float humidity_percent = -6.0 + 125.0 * humidity / 65536.0;
        //printf("Temperature: %.2f C\r\n", temperature_celsius);
        //printf("Humidity: %.2f %%\r\n", humidity_percent);
        HAL_Delay(1000);
    }
}
