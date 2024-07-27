

#ifndef HW_HW_H_
#define HW_HW_H_

void hwInit();
#include "hw_def.h"
#include "led.h"
#include "button.h"
#include "stepper.h"
#include "uart.h"
#include "buzz.h"

void delay(uint32_t time_ms);
uint32_t millis(void);

#endif /* HW_HW_H_ */
