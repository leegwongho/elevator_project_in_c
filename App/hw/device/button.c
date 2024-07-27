
#include "button.h"

typedef struct
{
	GPIO_TypeDef	*port;
	uint16_t		PinNumber;
	GPIO_PinState	onState;
}BUTTON_TBL;

BUTTON_TBL button_tbl[_BUTTON_MAX_CH] =
{
		{GPIOC, GPIO_PIN_0, 0},
		{GPIOC, GPIO_PIN_1, 0},
		{GPIOC, GPIO_PIN_2, 0},
		{GPIOC, GPIO_PIN_13, 0}
};

bool buttonInit()
{
	bool ret = true;

	return ret;
}

bool buttonGetPressed(uint8_t ch)
{
	bool ret = false;

	if(ch >= _BUTTON_MAX_CH)
	{
		return ret;
	}

	if(HAL_GPIO_ReadPin(button_tbl[ch].port, button_tbl[ch].PinNumber) == button_tbl[ch].onState)
	{
		delay(20);
		if(HAL_GPIO_ReadPin(button_tbl[ch].port, button_tbl[ch].PinNumber) == button_tbl[ch].onState)
		{
			ret = true;
		}
	}
	return ret;
}
