/*
 * a_traffic_lights.c
 *
 * this is the main application skeleton for the student exercises in task 3
 *
 */

// include the hal drivers
#include "stm32f7xx_hal.h"

// include the shu bsp libraries for the stm32f7 discovery board
#include "pinmappings.h"
#include "clock.h"
#include "gpio.h"

// map the led to GPIO PA8
gpio_pin_t led = {PI_1, GPIOI, GPIO_PIN_1};
gpio_pin_t led2 = {PB_14, GPIOB, GPIO_PIN_14};
gpio_pin_t led3 = {PB_15, GPIOB, GPIO_PIN_15};

// this is the main method
int main()
{
		HAL_Init();
		init_sysclk_216MHz();
	
	  init_gpio(led, OUTPUT);
		init_gpio(led2, OUTPUT);
		init_gpio(led3, OUTPUT);
		
		while(1)
		{
		
			HAL_GPIO_WritePin (GPIOI, GPIO_PIN_1, GPIO_PIN_SET);
			HAL_Delay(5000);	
			
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_14, GPIO_PIN_SET);
			HAL_GPIO_WritePin (GPIOI, GPIO_PIN_1, GPIO_PIN_RESET);
			HAL_Delay(2000);	
			
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_15, GPIO_PIN_SET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);
			HAL_Delay(1000);
			
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_15, GPIO_PIN_SET);
			HAL_Delay(5000);

			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_14, GPIO_PIN_SET);
			HAL_Delay(1000);
			
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);
			HAL_Delay(1000);
				

		}
}
