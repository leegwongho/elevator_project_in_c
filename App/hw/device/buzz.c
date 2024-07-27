#include "buzz.h"
extern TIM_HandleTypeDef htim3; // 타이머 핸들러를 사용해 PWM 제어

void Servo_Init(void) {
    // 타이머 초기화 코드 (htim2)와 PWM 채널 설정 필요
    // 예를 들어, TIM2의 PWM 채널 1을 사용한다고 가정
}

void Servo_SetAngle(uint8_t angle) {
    // 서보 모터의 각도를 설정합니다 (0~180도)
    // 1ms ~ 2ms의 펄스 폭을 0도 ~ 180도로 매핑합니다.
    // 1ms = 0도, 2ms = 180도

    // PWM 주기는 20ms로 설정 (50Hz)
    uint32_t period = __HAL_TIM_GET_AUTORELOAD(&htim3) + 1;

    // 1ms에서 2ms 사이의 펄스 폭을 계산합니다.
    uint32_t pulse_width = (uint32_t)((angle / 180) * (2 - 1) + 1) * period / 20;

    // PWM 채널의 듀티 사이클을 설정합니다.
    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, pulse_width);
}


void servo_test(uint32_t ang){

	TIM3->CCR1 = ang;

}





void Servo_Start(void) {
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
}

void Servo_Stop(void) {
    HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1);
}
