#include "key.h"
static uint8_t hold,up;
uint8_t keyscan(void)
{
	if(hold*30 <= 2000 && up == 1)
	{
		hold = 0;
		up = 0;
		return 1;
	}
	if(hold*30 >= 2000 && up == 1)
	{
		hold = 0;
		up = 0;
		return 2;
	}
	else
		return 0;
}

uint8_t KeyGetState(void)
{
	if(HAL_GPIO_ReadPin(KEY_GPIO_Port,KEY_Pin) == GPIO_PIN_RESET)
		return 1;
	else
		return 0;
}

void KeyTick(void)
{
	static uint8_t KeyCounter;
	static uint8_t curkey,prekey;
	KeyCounter++;
	if(KeyCounter == 30)
	{
		KeyCounter = 0;
		prekey = curkey;
		curkey = KeyGetState();
		if(prekey == 1 && curkey == 0)
			up = 1;
		if(prekey == 1 && curkey == 1)
			hold++;
	}
}





