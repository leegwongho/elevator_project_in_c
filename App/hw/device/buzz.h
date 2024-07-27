
#ifndef HW_DEVICE_BUZZ_H_
#define HW_DEVICE_BUZZ_H_


#include "hw.h"


void Servo_Init(void);

void Servo_SetAngle(uint8_t angle);

void Servo_Start(void);

void Servo_Stop(void);

void servo_test(uint32_t ang);

//void Buzzer_Init(TIM_HandleTypeDef *htim);
//void Buzzer_SetFrequency(uint32_t frequency);
//void Buzzer_Start(void);
//void Buzzer_Stop(void);
//void Play_Buzzer_Sound(uint8_t currentfloor);
//void Buzzer_Update(void);

#endif /* HW_DEVICE_BUZZ_H_ */
