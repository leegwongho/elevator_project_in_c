
#include "hw.h"

void hwInit()
{
	ledInit();
	buttonInit();
}


//할 딜레이 함수 대체
void delay(uint32_t time_ms)
{
	HAL_Delay(time_ms);
}

// 전원 입력후에 카운트 값을 변환하는 함수
// 시스템 틱을 이용
uint32_t millis()
{
	uint32_t tick = HAL_GetTick();
	return tick;
}



