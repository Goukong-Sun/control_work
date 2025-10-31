#include "led_pwm.h"
extern TIM_HandleTypeDef htim4;
static uint8_t pwmlight;

void led_pwm_tick(void)
{
	static uint8_t led_pwm_count;
	static _Bool flag ;
	led_pwm_count++;
	if(led_pwm_count == 10)
	{
		led_pwm_count = 0;
		
		if(pwmlight == 99)
			flag = 1;
		else if(pwmlight == 0)
			flag = 0;
		
		if(flag == 0)
			pwmlight++;
		else
			pwmlight--;

		
	}
}

void pwm(void)
{
		__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_1,pwmlight);
}



