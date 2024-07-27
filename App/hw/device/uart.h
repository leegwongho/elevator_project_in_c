/*
 * uart_rx.h
 *
 *  Created on: Jul 22, 2024
 *      Author: USER
 */

#ifndef HW_DEVICE_UART_H_
#define HW_DEVICE_UART_H_

#include "hw.h"



void uart_rx_Init();

void uart_rx_receive_IT();

void uart_rx_receive_DMA();

void uart_tx_Init();


void uart_tx_Transmit_IT();


void uart_tx_Transmit_DMA();

extern UART_HandleTypeDef huart2;
extern DMA_HandleTypeDef hdma_usart2_rx;
extern DMA_HandleTypeDef hdma_usart2_tx;



#endif /* HW_DEVICE_UART_H_ */
