
#include "led.h"
#include "ap.h"

LED_TBL led_tbl[_LED_MAX_CH] =
{
		{GPIOA, GPIO_PIN_9, GPIO_PIN_SET, GPIO_PIN_RESET},	//a
		{GPIOA, GPIO_PIN_8, GPIO_PIN_SET, GPIO_PIN_RESET},	//b
		{GPIOB, GPIO_PIN_10, GPIO_PIN_SET, GPIO_PIN_RESET}, //c
		{GPIOB, GPIO_PIN_4, GPIO_PIN_SET, GPIO_PIN_RESET}, 	//d
		{GPIOB, GPIO_PIN_5, GPIO_PIN_SET, GPIO_PIN_RESET},	//e
		{GPIOB, GPIO_PIN_3, GPIO_PIN_SET, GPIO_PIN_RESET},	//f
		{GPIOA, GPIO_PIN_10, GPIO_PIN_SET, GPIO_PIN_RESET},	//g
		{GPIOC, GPIO_PIN_7, GPIO_PIN_SET, GPIO_PIN_RESET}	//.
};

bool ledInit()
{
	bool ret = true;
	return ret;
}




void led_1_On()
{
	// 1	b c = 1 / 0
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, 1);

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 0);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 0);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, 0);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, 0);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 0);

	// 2	a b g d e = 1 / 0

	// 3	a b c d g = 1 / 0
}

void led_2_On()
{
	// 1	b c = 1 / 0
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, 0);

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 1);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 1);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 1);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, 0);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, 1);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 0);

	// 2	a b g d e = 1 / 0

	// 3	a b c d g = 1 / 0
}

void led_3_On()
{
	// 1	b c = 1 / 0
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, 1);

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 1);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 1);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 0);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, 0);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, 1);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 0);

	// 2	a b g d e = 1 / 0

	// 3	a b c d g = 1 / 0
}
void led_Off()
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 0);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, 0);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 0);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 0);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, 0);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, 0);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 0);

}
