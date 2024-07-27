/*
 * uart_rx.c
 *
 *  Created on: Jul 22, 2024
 *      Author: USER
 */

#include "uart.h"




void uart_rx_Init(){


}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{





}


void uart_tx_Init(){

}



void uart_tx_Transmit_IT(uint8_t txData[]){
	HAL_UART_Transmit_IT(&huart2, txData, 10);
}


void uart_tx_Transmit_DMA(uint8_t txData[]){
	HAL_UART_Transmit_DMA(&huart2, txData, 10);
}
