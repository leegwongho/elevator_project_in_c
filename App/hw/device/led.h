
#ifndef HW_DEVICE_LED_H_
#define HW_DEVICE_LED_H_

#include "hw_def.h"

typedef struct
{
	GPIO_TypeDef	*port;
	uint16_t		pinNumber;
	GPIO_PinState	onState;
	GPIO_PinState	offState;
}LED_TBL;

bool ledInit(void);
void led_1_On();
void led_2_On();
void led_3_On();
void led_Off();


#endif /* HW_DEVICE_LED_H_ */
