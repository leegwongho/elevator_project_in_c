
#include "ap.h"


void apInit()
{
	hwInit();
}

uint8_t state_cur = 1 ;
uint8_t txData = '1';



//
//void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
//
//	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 50 );
//	HAL_Delay(1000);
//	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 50 );
//	HAL_Delay(1000);
//	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 50 );
//	HAL_Delay(1000);
//
//}

uint8_t i = 0;
uint32_t cnt0 = 0;

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	 //B_13 = 1층센서 B_14 = 2층센서 B_15 = 3층센서  cw가 올라감 / ccw 내려감
	uint32_t break_cnt = 0;
	uint32_t break_cnt0 = 0;


	Servo_Start();
	servo_test(55);

	if(GPIO_Pin == GPIO_PIN_13 )	// 1층에 버튼 가정.
	{
		i++;
		if(i % 2 == 1)
		{
			Servo_Stop();
		break_cnt =  millis();
		HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_13);
		uint8_t uart_2 = 0;
		while(1)
		{
			if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == 0)
			{
				led_1_On();
				txData = '1';
				HAL_UART_Transmit_IT(&huart2, &txData, 1);
				state_cur = 1;
				i = 0;
				break;
			}
			else
			{

				break_cnt0 = millis();
				if((break_cnt0 - break_cnt) >= 20000)
				{
					Servo_Start();

					servo_test(100);

				//	Buzzer_Stop();
					break;
				}
				else
				{
					rotateDegrees(10, DIR_CW);
				}
				if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0)
				{
					if(uart_2 == 0)
					{
						led_2_On();
						txData = '2';
						HAL_UART_Transmit(&huart2, &txData, 1, 100);
						uart_2 =1;
					}
				}
				if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4) == 0)
				{
					txData = '3';
					HAL_UART_Transmit_IT(&huart2, &txData, 1);
					led_3_On();
				}
			}
		}
		}
		else
		{
			i = 0;
		}
	}


	if(GPIO_Pin == GPIO_PIN_12)	// 2층에서 누른 올라가는 버튼
	{
		HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_12);
		break_cnt =  millis();
		while(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4) == 1)
		{
			if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4) == 1)	//3층 led가 켜져있으면 올라가
			{
				if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0)
				{
					led_2_On();
					txData = '2';
					HAL_UART_Transmit_IT(&huart2, &txData, 1);
					state_cur = 2;
					break;
				}
				else
				{
					break_cnt0 = millis();
					if((break_cnt0 - break_cnt) >= 10000)
					{
						Servo_Start();

						servo_test(100);

					//	Buzzer_Stop();
						break;
					}
					else{
						rotateDegrees(10, DIR_CCW);
					}

					if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == 0)
					{
						led_1_On();
						txData = '2';
						HAL_UART_Transmit_IT(&huart2, &txData, 1);
					}
					if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4) == 0)
					{
						led_3_On();
						txData = '3';
						HAL_UART_Transmit_IT(&huart2, &txData, 1);
					}
				}
			}
		}
		while(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == 1)
		{
			if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == 1)	//1층 led가 켜져있으면 내려가
			{
				if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0)
				{
					led_2_On();
					txData = '2';
					HAL_UART_Transmit_IT(&huart2, &txData, 1);
					state_cur = 2;
					break;
				}
				else
				{
					break_cnt0 = millis();
					if((break_cnt0 - break_cnt) >= 10000)
						{
							Servo_Start();

							servo_test(100);

										//	Buzzer_Stop();
							break;
						}
					else{
							rotateDegrees(10, DIR_CW);
						}
					if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == 0)
					{
						led_1_On();
						txData = '1';
						HAL_UART_Transmit_IT(&huart2, &txData, 1);
					}
					if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4) == 0)
					{
						led_3_On();
						txData = '3';
						HAL_UART_Transmit_IT(&huart2, &txData, 1);
					}
				}
			}
		}
	}

	if(GPIO_Pin == GPIO_PIN_15)	// 2층에서 누른 올라가는 버튼
	{
		break_cnt =  millis();
		HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_15);
			while(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4) == 1)
			{
				if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4) == 1)	//3층 led가 켜져있으면 올라가
				{
					if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0)
					{
						led_2_On();
						txData = '2';
						HAL_UART_Transmit_IT(&huart2, &txData, 1);
						state_cur = 2;
						break;
					}
					else
					{
						break_cnt0 = millis();
						if((break_cnt0 - break_cnt) >= 10000)
						{
							Servo_Start();

							servo_test(100);

											//	Buzzer_Stop();
							break;
						}
						else{
								rotateDegrees(10, DIR_CCW);
							}
						if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == 0)
						{
							led_1_On();
							txData = '1';
							HAL_UART_Transmit_IT(&huart2, &txData, 1);
						}
						if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4) == 0)
						{
							led_3_On();
							txData = '3';
							HAL_UART_Transmit_IT(&huart2, &txData, 1);
						}
					}
				}
			}
			while(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == 1)
			{
				if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == 1)	//1층 led가 켜져있으면 내려가
				{
					if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0)
					{
						led_2_On();
						state_cur = 2;
						txData = '2';
						HAL_UART_Transmit_IT(&huart2, &txData, 1);
						break;
					}
					else
					{
						break_cnt0 = millis();
						if((break_cnt0 - break_cnt) >= 10000)
						{
							Servo_Start();

							servo_test(100);

																	//	Buzzer_Stop();
							break;
						}
						else{
							rotateDegrees(10, DIR_CW);
						}
						if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == 0)
						{
							led_1_On();
							txData = '1';
							HAL_UART_Transmit_IT(&huart2, &txData, 1);
						}
						if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4) == 0)
						{
							led_3_On();
							txData = '3';
							HAL_UART_Transmit_IT(&huart2, &txData, 1);
						}
					}
				}
			}
	}

	if(GPIO_Pin == GPIO_PIN_7)	// 3층에서 누른 버튼
	{
		break_cnt =  millis();
		HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_7);
		uint8_t uart_2 = 0;
		while(1)
		{
			if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4) == 0)
			{
				led_3_On();
				txData = '3';
				HAL_UART_Transmit_IT(&huart2, &txData, 1);
				state_cur = 3;
				break;
			}
			else
			{
				break_cnt0 = millis();
				if((break_cnt0 - break_cnt) >= 20000)
				{
					Servo_Start();

					servo_test(100);

															//	Buzzer_Stop();
					break;
				}
				else{
					rotateDegrees(10, DIR_CCW);
				}

				if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == 0)
				{
					led_1_On();
					txData = '1';
					HAL_UART_Transmit_IT(&huart2, &txData, 1);
				}
				if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0)
				{
					if(uart_2 == 0)
					{
						led_2_On();
						txData = '2';
						HAL_UART_Transmit(&huart2, &txData, 1, 100);
						uart_2 =1;
					}
				}
			}
		}
	}
}

uint8_t break_cnt;
uint8_t break_cnt0;

void apMain()
{
	led_1_On();
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_13);	// 1층에서 누른 버튼
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_12);	// 2층에서 누른 올라가는 버튼
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_15);	// 2층에서 누른 내려가는 버튼
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_7);	// 3층에서 누른 버튼

	while(1)
	{
		//버튼 0번은 1층으로, 버튼 1번은 2층으로, 버튼 2번은 3층으로
		if(state_cur == 1)
		{
			if(buttonGetPressed(1))	// 1층 올림 >> 2
			{
				cnt0 = 0;
				while(1){
				if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0)
				{
					led_2_On();
					txData = '2';
					HAL_UART_Transmit_IT(&huart2, &txData, 1);
					state_cur = 2;
					break;
				}
				if(cnt0 >= 100)
				{
					Servo_Start();
					servo_test(100);				//	Buzzer_Stop();
					break;
				}
				else
				{
					rotateDegrees(10, DIR_CCW);
					cnt0++;
				}
			}
		}

			if(buttonGetPressed(2))	// 1층에서 >> 3층
			{
				cnt0 = 0;
				uint8_t uart_2 = 0;
				while(1)
				{
					if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4) == 0){
						state_cur = 3;
						break;
					}

					if(cnt0 >= 190)
					{
						Servo_Start();

						servo_test(100);
						//	Buzzer_Stop();
						break;
					}
					else
					{
						rotateDegrees(10, DIR_CCW);
						cnt0++;
					}
					if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0)
					{
						led_2_On();
						if(uart_2 == 0)
						{
							led_2_On();
							txData = '2';
							HAL_UART_Transmit(&huart2, &txData, 1, 100);
							uart_2 =1;
						}
					}
					if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4) == 0)
					{
						led_3_On();
						txData = '3';
						HAL_UART_Transmit_IT(&huart2, &txData, 1);
					}
				}
			}
		}

		if(state_cur == 2)
		{

			if (buttonGetPressed(0))	// 2층 >> 1층
			{
				cnt0 = 0;
				while(1){
				if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == 0)
				{
					led_1_On();
					txData = '1';
					HAL_UART_Transmit_IT(&huart2, &txData, 1);
					state_cur = 1;
					break;
				}

				if(cnt0  >= 100)
				{
					Servo_Start();

					servo_test(100);							//	Buzzer_Stop();
					break;
				}
				else
				{
					rotateDegrees(10, DIR_CW);
					cnt0++;
				}
				}
			}

			if (buttonGetPressed(2))	// 2층 >> 3층
			{
				cnt0 = 0;
				while(1){
				if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4) == 0){
					led_3_On();
					txData = '3';
					HAL_UART_Transmit_IT(&huart2, &txData, 1);
					state_cur = 3;
					break;
				}
				if(cnt0  >= 100)
				{
					Servo_Start();

					servo_test(100);				//	Buzzer_Stop();
					break;
				}
				else
				{
					rotateDegrees(10, DIR_CCW);
					cnt0++;
				}
				}
			}
		}

		if(state_cur == 3)
		{
			if (buttonGetPressed(0))	// 3층 >> 1층
			{
				cnt0 = 0;
				uint8_t uart_2 = 0;
				while(1)
				{
					if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == 0)
					{
						led_1_On();
						txData = '1';
						HAL_UART_Transmit_IT(&huart2, &txData, 1);
						state_cur = 1;
						break;
					}

					if(cnt0 >= 190)
					{
						Servo_Start();

						servo_test(100);
							//	Buzzer_Stop();
						break;
					}
					else
					{
						rotateDegrees(10, DIR_CW);
						cnt0++;
					}
					if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == 0)
					{
						led_1_On();
						txData = '1';
						HAL_UART_Transmit_IT(&huart2, &txData, 1);
					}
					if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1)==0)
					{
						if(uart_2 == 0)
						{
							led_2_On();
							txData = '2';
							HAL_UART_Transmit(&huart2, &txData, 1, 100);
							uart_2 =1;
						}
					}
				}
			}

			if (buttonGetPressed(1))	// 3층 >> 2층
			{
				cnt0 = 0;
				while(1)
				{
					if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0)
					{
						led_2_On();
						txData = '2';
						HAL_UART_Transmit(&huart2, &txData, 1, 1);
						state_cur = 2;
						break;
					}

					if(cnt0 >= 100)
					{
						Servo_Start();
						servo_test(100);
								//	Buzzer_Stop();
						break;
					}
					else
					{
						rotateDegrees(10, DIR_CW);
						cnt0++;
					}
				}
			}
		}
	}
}
