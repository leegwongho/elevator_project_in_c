
#ifndef INC_DELAY_H_
#define INC_DELAY_H_

#include "hw.h"
extern TIM_HandleTypeDef htim10;
extern TIM_HandleTypeDef htim11;
extern TIM_HandleTypeDef htim3;

void delay_us(uint16_t us);

#endif /* INC_DELAY_H_ */
