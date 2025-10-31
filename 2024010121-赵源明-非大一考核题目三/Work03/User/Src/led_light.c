#include "led_light.h"

static uint8_t troggle_flag;
extern uint8_t n;

void troggle_led(uint8_t times)
{
	if(troggle_flag == 1 && n <= 2*times)
	{
		troggle_flag = 0;
		n++;
		HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port,LED_GREEN_Pin);
	}
	
	
}

void led_light_tick(void)
{
	static uint8_t light_count;
	light_count++;
	if(light_count == 200)
	{
		light_count = 0;
		troggle_flag = 1;
		
	}
}

