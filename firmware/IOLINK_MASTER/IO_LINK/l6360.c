/*
 * l6360.c
 *
 *  Created on: Mar 18, 2021
 *      Author: Grzegorz G
 */

#include "l6360.h"

//static I2C_HandleTypeDef hI2CPort;
I2C_HandleTypeDef pI2cHandle;


//UART_HandleTypeDef hUartPort0;
//UART_HandleTypeDef hUartPort1;
//UART_HandleTypeDef hUartPort2;
//UART_HandleTypeDef hUartPort3;

//uint8_t enableRxCallback = 0;
/** UART tx buffer */
static uint8_t uartTxBuffer[4];
/** UART rx buffer */
uint8_t uartRxBuffer[4];
uint8_t uartRxWakeup[4];
///** I2C tx buffer */
//static uint8_t i2cTxBuffer[2];
/** I2C rx buffer */
static uint8_t i2cRxBuffer[2];



void delay_us (uint16_t us)
{
	__HAL_TIM_SET_COUNTER(&htim17,0);  // set the counter value a 0
	while ((uint16_t)__HAL_TIM_GET_COUNTER(&htim17) < us);  // wait for the counter to reach the us input in the parameter
}


/*
 *
 * Sequential write mode:
 * Configuration reg
 * Control reg 1
 * Control reg 2
 * LED1 reg H
 * LED1 reg L
 * LED2 reg H
 * LED2 reg L
 * Parity
 *
 */
uint8_t L6360_PowerUp(uint8_t portId)
{

	HAL_StatusTypeDef status = HAL_OK;
//	I2C_HandleTypeDef *pI2CHandle = (void *)0;
	uint8_t dev_add = 0xC0;

	switch (portId)
	  {
	   case 0U:
		  dev_add = 0xC0;
	      break;
	    case 1U:
	      dev_add = 0xC2;
	      break;
	    case 2U:
	      dev_add = 0xC4;
	      break;
	    case 3U:
	      dev_add = 0xC6;
	      break;
	    default:
//	      status = HAL_ERROR;
	      break;
	  }
//	pI2CHandle = &hI2CPort;

	uint8_t data_init[8] = {0xE0, 0xF0, 0xA1, 0x00, 0x00, 0xFF, 0xFF, 0x50};

//	status = L6360_I2cInit();
//	HAL_Delay(100);

//	L6360_PinEnableReset(portId);
//	HAL_Delay(100);
//	L6360_PinDisableReset(portId);
//	HAL_Delay(500);

	L6360_PinEnableLPlus(portId);
<<<<<<< HEAD
	HAL_Delay(2000);
=======
	HAL_Delay(200);
>>>>>>> test1

	if(status == HAL_OK)
	{
		status = HAL_I2C_Master_Transmit(&L6360_I2C_HANDLE, dev_add, data_init, 8, 10);
	}
	if(status == HAL_OK)
	{
		status = HAL_I2C_Master_Receive(&L6360_I2C_HANDLE, dev_add, i2cRxBuffer, 1, 10);
	}
	HAL_I2C_Master_Receive(&L6360_I2C_HANDLE, 0xC2, i2cRxBuffer, 1, 10);
	HAL_I2C_Master_Receive(&L6360_I2C_HANDLE, 0xC4, i2cRxBuffer, 1, 10);
	HAL_I2C_Master_Receive(&L6360_I2C_HANDLE, 0xC6, i2cRxBuffer, 1, 10);


	return (uint8_t) status;
}


uint8_t L6360_WakeUp(uint8_t portId)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	uint8_t data_test_tx[2] = {0xA2, 0x00};

	HAL_StatusTypeDef status = HAL_OK;

	delay_us(1000);

	if(status == HAL_OK)
	{
		for(int i=0; i < 6; i++)
		{

			switch (portId)
			{
			    case 0U:
			    	GPIO_InitStruct.Pin = GPIO_PIN_9;
			    	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
			    	GPIO_InitStruct.Pull = GPIO_NOPULL;
			    	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
			    	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

			    	L6360_PinEnableCQ(portId);
			    	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, RESET);
			    	delay_us(WAKE_TIME_0);
			    	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, SET);
			    	L6360_PinDisableCQ(portId);
			    	delay_us(WAKE_TIME_1);

			    	break;
			    case 1U:
			    	GPIO_InitStruct.Pin = GPIO_PIN_2;
			    	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
			    	GPIO_InitStruct.Pull = GPIO_NOPULL;
			    	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
			    	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

			    	L6360_PinEnableCQ(portId);
			    	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, RESET);
			    	delay_us(WAKE_TIME_0);
			    	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, SET);
			    	L6360_PinDisableCQ(portId);
			    	delay_us(WAKE_TIME_1);

			    	break;
			    case 2U:
			    	GPIO_InitStruct.Pin = GPIO_PIN_4;
			    	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
			    	GPIO_InitStruct.Pull = GPIO_NOPULL;
			    	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
			    	HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

			    	L6360_PinEnableCQ(portId);
			    	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, RESET);
			    	delay_us(WAKE_TIME_0);
			    	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, SET);
			    	L6360_PinDisableCQ(portId);
			    	delay_us(WAKE_TIME_1);

			    	break;
			    case 3U:
			    	GPIO_InitStruct.Pin = GPIO_PIN_0;
			    	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
			    	GPIO_InitStruct.Pull = GPIO_NOPULL;
			    	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
			    	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

			    	L6360_PinEnableCQ(portId);
			    	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, RESET);
			    	delay_us(WAKE_TIME_0);
			    	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, SET);
			    	L6360_PinDisableCQ(portId);
			    	delay_us(WAKE_TIME_1);

			    	break;
			    default:
			    	status = HAL_ERROR;
			    	break;
			}


			if(L6360_UartPinsInit(portId) != HAL_OK)
			{
				status = HAL_ERROR;
				return (uint8_t) status;
			}


//			if(L6360_UartInit(portId) != HAL_OK)
//			{
//				status = HAL_ERROR;
//				return (uint8_t) status;
//			}


				//********//
				if(L6360_UartSetBaudrate(portId, 230400) != HAL_OK)
				{
					status = HAL_ERROR;
					return (uint8_t) status;
				}
				L6360_PinEnableCQ(portId);
				L6360_UartSendData(portId, data_test_tx[0]);
				L6360_UartSendData(portId, data_test_tx[1]);
				L6360_PinDisableCQ(portId);

//				__HAL_UART_FLUSH_DRREGISTER(&pUartHandle);
//				__HAL_UART_CLEAR_OREFLAG(&pUartHandle);
//				L6360_UartReceiveDataWakeup(portId);
				delay_us(WAKE_TIME_2);

				if(L6360_UartCheckReceive(portId) == HAL_OK)
				{
//					L6360_UartStopReceiveIT(portId);

					return (uint8_t) 30;
				}

//				if (__HAL_UART_GET_FLAG(&huart1, UART_FLAG_RXNE) == SET)
//				{
//					__HAL_UART_CLEAR_FLAG(&huart1, UART_FLAG_RXNE);
////					HAL_UART_AbortReceive_IT(&huart1);
////				    HAL_UART_AbortReceive_IT(&pUartHandle);
////					__HAL_UART_CLEAR_FLAG(&huart2, UART_FLAG_IDLE);
////					__HAL_UART_FLUSH_DRREGISTER(&pUartHandle);
////					__HAL_UART_CLEAR_OREFLAG(&pUartHandle);
////				    L6360_UartPinsInit(portId);
//					return (uint8_t) 30;
//				}
//				HAL_UART_AbortReceive_IT(&huart1);

				//********//
				if(L6360_UartSetBaudrate(portId, 38400) != HAL_OK)
				{
					status = HAL_ERROR;
					return (uint8_t) status;
				}

				L6360_PinEnableCQ(portId);
				L6360_UartSendData(portId, data_test_tx[0]);
				L6360_UartSendData(portId, data_test_tx[1]);
				L6360_PinDisableCQ(portId);

//				__HAL_UART_FLUSH_DRREGISTER(&pUartHandle);
//				__HAL_UART_CLEAR_OREFLAG(&pUartHandle);
//				L6360_UartReceiveDataWakeup(portId);
				delay_us(WAKE_TIME_3_1);

				if(L6360_UartCheckReceive(portId) == HAL_OK)
				{
//					L6360_UartStopReceiveIT(portId);
					return (uint8_t) 20;
				}

//				if (__HAL_UART_GET_FLAG(&huart1, UART_FLAG_RXNE) == SET)
//				{
//					__HAL_UART_CLEAR_FLAG(&huart1, UART_FLAG_RXNE);
////					HAL_UART_AbortReceive_IT(&huart1);
////				    HAL_UART_AbortReceive_IT(&pUartHandle);
////					__HAL_UART_CLEAR_FLAG(&huart2, UART_FLAG_IDLE);
////					__HAL_UART_FLUSH_DRREGISTER(&pUartHandle);
////					__HAL_UART_CLEAR_OREFLAG(&pUartHandle);
////				    L6360_UartPinsInit(portId);
//					return (uint8_t) 20;
//				}
//				HAL_UART_AbortReceive_IT(&huart1);

				//********//
				if(L6360_UartSetBaudrate(portId, 4800) != HAL_OK)
				{
					status = HAL_ERROR;
					return (uint8_t) status;
				}

				L6360_PinEnableCQ(portId);
				L6360_UartSendData(portId, data_test_tx[0]);
				L6360_UartSendData(portId, data_test_tx[1]);
				L6360_PinDisableCQ(portId);

//				  uint8_t kupa[4] = "kupa";
//				  HAL_UART_Transmit_IT(&huart1, kupa, 4);

//				__HAL_UART_FLUSH_DRREGISTER(&pUartHandle);
//				__HAL_UART_CLEAR_OREFLAG(&pUartHandle);
//				L6360_UartReceiveDataWakeup(portId);
				delay_us(WAKE_TIME_4);

				if(L6360_UartCheckReceive(portId) == HAL_OK)
				{
//					L6360_UartStopReceiveIT(portId);
					return (uint8_t) 10;
				}

//				if (__HAL_UART_GET_FLAG(&huart1, UART_FLAG_RXNE) == SET)
//				{
//				    __HAL_UART_CLEAR_FLAG(&huart1, UART_FLAG_RXNE);
////				    HAL_UART_AbortReceive_IT(&huart1);
////					HAL_UART_AbortReceive_IT(&pUartHandle);
////				    __HAL_UART_CLEAR_FLAG(&huart2, UART_FLAG_RXNE);
////				    __HAL_UART_FLUSH_DRREGISTER(&pUartHandle);
////					__HAL_UART_CLEAR_OREFLAG(&pUartHandle);
////				    L6360_UartPinsInit(portId);
//					return (uint8_t) 10;
//				}
//				HAL_UART_AbortReceive_IT(&huart1);

		}

		status = HAL_ERROR;

	}

	return (uint8_t) status;
}


uint8_t L6360_Read(uint8_t portId)
{
	uint8_t command[2] = {0xF0, 0x2D};

	L6360_PinEnableCQ(portId);
	L6360_UartSendDataIT(portId, command[0]);
	L6360_UartSendDataIT(portId, command[1]);
	L6360_PinDisableCQ(portId);
	delay_us(10000);

	command[0] = 0xE1;
	command[1] = 0x28;
	L6360_PinEnableCQ(portId);
	L6360_UartSendDataIT(portId, command[0]);
	L6360_UartSendDataIT(portId, command[1]);
	L6360_PinDisableCQ(portId);
	delay_us(10000);

	command[0] = 0xE2;
	command[1] = 0x18;
	L6360_PinEnableCQ(portId);
	L6360_UartSendDataIT(portId, command[0]);
	L6360_UartSendDataIT(portId, command[1]);
	L6360_PinDisableCQ(portId);
	delay_us(10000);

	command[0] = 0xE3;
	command[1] = 0x09;
	L6360_PinEnableCQ(portId);
	L6360_UartSendDataIT(portId, command[0]);
	L6360_UartSendDataIT(portId, command[1]);
	L6360_PinDisableCQ(portId);
	delay_us(10000);

	command[0] = 0xE4;
	command[1] = 0x2B;
	L6360_PinEnableCQ(portId);
	L6360_UartSendDataIT(portId, command[0]);
	L6360_UartSendDataIT(portId, command[1]);
	L6360_PinDisableCQ(portId);
	delay_us(10000);

	command[0] = 0xE5;
	command[1] = 0x3A;
	L6360_PinEnableCQ(portId);
	L6360_UartSendDataIT(portId, command[0]);
	L6360_UartSendDataIT(portId, command[1]);
	L6360_PinDisableCQ(portId);
	delay_us(10000);

	command[0] = 0xE6;
	command[1] = 0x0A;
	L6360_PinEnableCQ(portId);
	L6360_UartSendDataIT(portId, command[0]);
	L6360_UartSendDataIT(portId, command[1]);
	L6360_PinDisableCQ(portId);
	delay_us(10000);

	command[0] = 0xE7;
	command[1] = 0x1B;
	L6360_PinEnableCQ(portId);
	L6360_UartSendDataIT(portId, command[0]);
	L6360_UartSendDataIT(portId, command[1]);
	L6360_PinDisableCQ(portId);
	delay_us(10000);

	command[0] = 0xE8;
	command[1] = 0x1B;
	L6360_PinEnableCQ(portId);
	L6360_UartSendDataIT(portId, command[0]);
	L6360_UartSendDataIT(portId, command[1]);
	L6360_PinDisableCQ(portId);
	delay_us(10000);

	command[0] = 0xE9;
	command[1] = 0x0A;
	L6360_PinEnableCQ(portId);
	L6360_UartSendDataIT(portId, command[0]);
	L6360_UartSendDataIT(portId, command[1]);
	L6360_PinDisableCQ(portId);
	delay_us(10000);

	command[0] = 0xEA;
	command[1] = 0x3A;
	L6360_PinEnableCQ(portId);
	L6360_UartSendDataIT(portId, command[0]);
	L6360_UartSendDataIT(portId, command[1]);
	L6360_PinDisableCQ(portId);
	delay_us(10000);

	command[0] = 0xEB;
	command[1] = 0x2B;
	L6360_PinEnableCQ(portId);
	L6360_UartSendDataIT(portId, command[0]);
	L6360_UartSendDataIT(portId, command[1]);
	L6360_PinDisableCQ(portId);
	delay_us(10000);

	command[0] = 0xEC;
	command[1] = 0x09;
	L6360_PinEnableCQ(portId);
	L6360_UartSendDataIT(portId, command[0]);
	L6360_UartSendDataIT(portId, command[1]);
	L6360_PinDisableCQ(portId);
	delay_us(10000);

	command[0] = 0xED;
	command[1] = 0x18;
	L6360_PinEnableCQ(portId);
	L6360_UartSendDataIT(portId, command[0]);
	L6360_UartSendDataIT(portId, command[1]);
	L6360_PinDisableCQ(portId);
	delay_us(10000);

	command[0] = 0xEE;
	command[1] = 0x28;
	L6360_PinEnableCQ(portId);
	L6360_UartSendDataIT(portId, command[0]);
	L6360_UartSendDataIT(portId, command[1]);
	L6360_PinDisableCQ(portId);
	delay_us(10000);

	command[0] = 0xF1;
	command[1] = 0x3C;
	L6360_PinEnableCQ(portId);
	L6360_UartSendDataIT(portId, command[0]);
	L6360_UartSendDataIT(portId, command[1]);
	L6360_PinDisableCQ(portId);
	delay_us(10000);

	return HAL_OK;

}

uint8_t L6360_ReadState(uint8_t portId)
{
	HAL_StatusTypeDef status = HAL_ERROR;

	uint8_t data_init1[3] = {0x21, 0x03, 0x4A}; // 0010 0001  0000 0011  0100 1010
	uint8_t data_init2[3] = {0x20, 0x06, 0x99}; // 0010 0000  0000 0110  1001 1001

	L6360_PinEnableCQ(portId);
	L6360_UartSendDataIT(portId, data_init1[0]);
	L6360_UartSendDataIT(portId, data_init1[1]);
	L6360_UartSendDataIT(portId, data_init1[2]);
	L6360_PinDisableCQ(portId);
	delay_us(10000);

	L6360_PinEnableCQ(portId);
	L6360_UartSendDataIT(portId, data_init2[0]);
	L6360_UartSendDataIT(portId, data_init2[1]);
	L6360_UartSendDataIT(portId, data_init2[2]);
	L6360_PinDisableCQ(portId);
	delay_us(10000);
	status = HAL_OK;

	return (uint8_t) status;
}


uint8_t L6360_ReadName(uint8_t portId)
{
	HAL_StatusTypeDef status = HAL_ERROR;
	uint8_t command01[3] = {0x20, 0x36, 0x9A}; // 0010 0000  0011 0110  1001 1010
	uint8_t command02[2] = {0xF1, 0x3C};

	L6360_PinEnableCQ(portId);
	L6360_UartSendDataIT(portId, command01[0]);
	L6360_UartSendDataIT(portId, command01[1]);
	L6360_UartSendDataIT(portId, command01[2]);
	L6360_PinDisableCQ(portId);
	delay_us(10000);

	L6360_PinEnableCQ(portId);
	L6360_UartSendDataIT(portId, command02[0]);
	L6360_UartSendDataIT(portId, command02[1]);
	L6360_PinDisableCQ(portId);


	delay_us(10000);

	uint8_t command1[3] = {0x70, 0x09, 0x93}; // 0111 0000  0000 1001  1001 0011
	uint8_t command2[3] = {0x61, 0x14, 0x10}; // 0110 0001  0001 0100  0001 0000
	uint8_t command3[3] = {0x62, 0x28, 0x83}; // 0110 0010  0010 1000  1000 0011

	L6360_PinEnableCQ(portId);
	L6360_UartSendDataIT(portId, command1[0]);
	L6360_UartSendDataIT(portId, command1[1]);
	L6360_UartSendDataIT(portId, command1[2]);
	L6360_PinDisableCQ(portId);
	delay_us(10000);

	L6360_PinEnableCQ(portId);
	L6360_UartSendDataIT(portId, command2[0]);
	L6360_UartSendDataIT(portId, command2[1]);
	L6360_UartSendDataIT(portId, command2[2]);
	L6360_PinDisableCQ(portId);
	delay_us(10000);

	L6360_PinEnableCQ(portId);
	L6360_UartSendDataIT(portId, command3[0]);
	L6360_UartSendDataIT(portId, command3[1]);
	L6360_UartSendDataIT(portId, command3[2]);
	L6360_PinDisableCQ(portId);
//	L6360_UartReceiveDataIT(portId);
	delay_us(10000);


	status = L6360_Read(portId);

	return (uint8_t) status;
}

uint8_t L6360_ReadStart(uint8_t portId)
{
	HAL_StatusTypeDef status = HAL_ERROR;

	uint8_t command0[8] = {0xA3, 0x11, 0xA4, 0x33, 0xA5, 0x22, 0xA6, 0x12};
	uint8_t command1[3] = {0x20, 0x36, 0x95};
	uint8_t command2[16] = {0xA7, 0x03, 0xA8, 0x03, 0xA9, 0x12, 0xAA, 0x22, 0xAB, 0x33, 0xAC, 0x11, 0xAD, 0x00, 0xAE, 0x30};
	uint8_t command3[3] = {0x20, 0x36, 0x9A};

	for(int i=0; i<8; i+=2)
	{
		L6360_PinEnableCQ(portId);
		L6360_UartSendData(portId, command0[i]);
		L6360_UartSendData(portId, command0[i+1]);
		L6360_PinDisableCQ(portId);
//		L6360_UartReceiveDataIT(portId);
		delay_us(7000);
	}

	L6360_PinEnableCQ(portId);
	L6360_UartSendData(portId, command1[0]);
	L6360_UartSendData(portId, command1[1]);
	L6360_UartSendData(portId, command1[2]);
	L6360_PinDisableCQ(portId);
//	L6360_UartReceiveDataIT(portId);
	delay_us(7000);

	for(int i=0; i<16; i+=2)
	{
		L6360_PinEnableCQ(portId);
		L6360_UartSendData(portId, command2[i]);
		L6360_UartSendData(portId, command2[i+1]);
		L6360_PinDisableCQ(portId);
//		L6360_UartReceiveDataIT(portId);
		delay_us(7000);
	}

	L6360_PinEnableCQ(portId);
	L6360_UartSendData(portId, command3[0]);
	L6360_UartSendData(portId, command3[1]);
	L6360_UartSendData(portId, command3[2]);
	L6360_PinDisableCQ(portId);
//	L6360_UartReceiveDataIT(portId);
	delay_us(7000);

	status = HAL_OK;
	return (uint8_t) status;
}

void L6360_PinEnableLPlus(uint8_t portId)
{
	switch(portId)
	{
	  	case 0U:
	      HAL_GPIO_WritePin(UC_T0_ENL_GPIO_Port, UC_T0_ENL_Pin, GPIO_PIN_SET);
	      break;
	    case 1U:
	      HAL_GPIO_WritePin(UC_T1_ENL_GPIO_Port, UC_T1_ENL_Pin, GPIO_PIN_SET);
	      break;
	    case 2U:
	      HAL_GPIO_WritePin(UC_T2_ENL_GPIO_Port, UC_T2_ENL_Pin, GPIO_PIN_SET);
	      break;
	    case 3U:
	      HAL_GPIO_WritePin(UC_T3_ENL_GPIO_Port, UC_T3_ENL_Pin, GPIO_PIN_SET);
	      break;
	    default:
	      /* Ignore the request */
	      break;
	}
}
void L6360_PinDisableLPlus(uint8_t portId)
{
	switch(portId)
	{
	  	case 0U:
	      HAL_GPIO_WritePin(UC_T0_ENL_GPIO_Port, UC_T0_ENL_Pin, GPIO_PIN_RESET);
	      break;
	    case 1U:
	      HAL_GPIO_WritePin(UC_T1_ENL_GPIO_Port, UC_T1_ENL_Pin, GPIO_PIN_RESET);
	      break;
	    case 2U:
	      HAL_GPIO_WritePin(UC_T2_ENL_GPIO_Port, UC_T2_ENL_Pin, GPIO_PIN_RESET);
	      break;
	    case 3U:
	      HAL_GPIO_WritePin(UC_T3_ENL_GPIO_Port, UC_T3_ENL_Pin, GPIO_PIN_RESET);
	      break;
	    default:
	      /* Ignore the request */
	      break;
	}
}
void L6360_PinEnableCQ(uint8_t portId)
{
//	HAL_StatusTypeDef status = HAL_ERROR;
//	UART_HandleTypeDef *pUartHandle = (void *)0;
	switch(portId)
	{
	  	case 0U:
	      HAL_GPIO_WritePin(UC_T0_ENCQ_GPIO_Port, UC_T0_ENCQ_Pin, GPIO_PIN_SET);
//	      pUartHandle = &hUartPort0;
	      break;
	    case 1U:
	      HAL_GPIO_WritePin(UC_T1_ENCQ_GPIO_Port, UC_T1_ENCQ_Pin, GPIO_PIN_SET);
//	      pUartHandle = &hUartPort1;
	      break;
	    case 2U:
	      HAL_GPIO_WritePin(UC_T2_ENCQ_GPIO_Port, UC_T2_ENCQ_Pin, GPIO_PIN_SET);
//	      pUartHandle = &hUartPort2;
	      break;
	    case 3U:
	      HAL_GPIO_WritePin(UC_T3_ENCQ_GPIO_Port, UC_T3_ENCQ_Pin, GPIO_PIN_SET);
//	      pUartHandle = &hUartPort3;
	      break;
	    default:
	      /* Ignore the request */
	      break;
	}
//	// When enable must disable UART RX
//	if (pUartHandle != (void *)0)
//	{
//		status = HAL_UART_AbortReceive(pUartHandle);
//	}
//	return (uint8_t) status;
}

void L6360_PinDisableCQ(uint8_t portId)
{
//	HAL_StatusTypeDef status = HAL_ERROR;
//	UART_HandleTypeDef *pUartHandle = (void *)0;
	switch(portId)
	{
	  	case 0U:
	      HAL_GPIO_WritePin(UC_T0_ENCQ_GPIO_Port, UC_T0_ENCQ_Pin, GPIO_PIN_RESET);
//	      pUartHandle = &hUartPort0;
	      break;
	    case 1U:
	      HAL_GPIO_WritePin(UC_T1_ENCQ_GPIO_Port, UC_T1_ENCQ_Pin, GPIO_PIN_RESET);
//	      pUartHandle = &hUartPort1;
	      break;
	    case 2U:
	      HAL_GPIO_WritePin(UC_T2_ENCQ_GPIO_Port, UC_T2_ENCQ_Pin, GPIO_PIN_RESET);
//	      pUartHandle = &hUartPort2;
	      break;
	    case 3U:
	      HAL_GPIO_WritePin(UC_T3_ENCQ_GPIO_Port, UC_T3_ENCQ_Pin, GPIO_PIN_RESET);
//	      pUartHandle = &hUartPort3;
	      break;
	    default:
	      /* Ignore the request */
	      break;
	}
//	if (pUartHandle != (void *)0)
//	{
//	    __HAL_UART_FLUSH_DRREGISTER(pUartHandle);
//	    __HAL_UART_CLEAR_OREFLAG(pUartHandle);
//	    status = HAL_UART_Receive_IT(pUartHandle, &uartRxBuffer[portId], 1U);
//	}
//	return (uint8_t) status;
}

void L6360_PinEnableReset(uint8_t portId)
{
	switch(portId)
	{
	  	case 0U:
	      HAL_GPIO_WritePin(UC_T0_RST_GPIO_Port, UC_T0_RST_Pin, GPIO_PIN_SET);
	      break;
	    case 1U:
	      HAL_GPIO_WritePin(UC_T1_RST_GPIO_Port, UC_T1_RST_Pin, GPIO_PIN_SET);
	      break;
	    case 2U:
	      HAL_GPIO_WritePin(UC_T2_RST_GPIO_Port, UC_T2_RST_Pin, GPIO_PIN_SET);
	      break;
	    case 3U:
	      HAL_GPIO_WritePin(UC_T3_RST_GPIO_Port, UC_T3_RST_Pin, GPIO_PIN_SET);
	      break;
	    default:
	      /* Ignore the request */
	      break;
	}
}

void L6360_PinDisableReset(uint8_t portId)
{
	switch(portId)
	{
	  	case 0U:
	      HAL_GPIO_WritePin(UC_T0_RST_GPIO_Port, UC_T0_RST_Pin, GPIO_PIN_RESET);
	      break;
	    case 1U:
	      HAL_GPIO_WritePin(UC_T1_RST_GPIO_Port, UC_T1_RST_Pin, GPIO_PIN_RESET);
	      break;
	    case 2U:
	      HAL_GPIO_WritePin(UC_T2_RST_GPIO_Port, UC_T2_RST_Pin, GPIO_PIN_RESET);
	      break;
	    case 3U:
	      HAL_GPIO_WritePin(UC_T3_RST_GPIO_Port, UC_T3_RST_Pin, GPIO_PIN_RESET);
	      break;
	    default:
	      /* Ignore the request */
	      break;
	}
}

uint8_t L6360_UartPinsInit(uint8_t portId)
{
	HAL_StatusTypeDef status = HAL_OK;
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	switch (portId)
	  {
	    case 0U:
//		  __HAL_RCC_USART1_CLK_ENABLE(); //maybe not necessary?
//		  __HAL_RCC_GPIOA_CLK_ENABLE(); //maybe not necessary?
	      GPIO_InitStruct.Pin = GPIO_PIN_9|GPIO_PIN_10;
		  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		  GPIO_InitStruct.Pull = GPIO_NOPULL;
		  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
		  GPIO_InitStruct.Alternate = GPIO_AF1_USART1;
		  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

//		  HAL_NVIC_SetPriority(USART1_IRQn, 0, 0);
//		  HAL_NVIC_EnableIRQ(USART1_IRQn);
	      break;
	    case 1U:
//		  __HAL_RCC_USART2_CLK_ENABLE(); //maybe not necessary?
//		  __HAL_RCC_GPIOA_CLK_ENABLE(); //maybe not necessary?
	      GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_3;
		  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		  GPIO_InitStruct.Pull = GPIO_NOPULL;
		  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
		  GPIO_InitStruct.Alternate = GPIO_AF1_USART2;
		  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

//		  HAL_NVIC_SetPriority(USART2_IRQn, 0, 0);
//		  HAL_NVIC_EnableIRQ(USART2_IRQn);
	      break;
	    case 2U:
//		  __HAL_RCC_USART3_CLK_ENABLE(); //maybe not necessary?
//		  __HAL_RCC_GPIOC_CLK_ENABLE(); //maybe not necessary?
	      GPIO_InitStruct.Pin = GPIO_PIN_4|GPIO_PIN_5;
		  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		  GPIO_InitStruct.Pull = GPIO_NOPULL;
		  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
		  GPIO_InitStruct.Alternate = GPIO_AF1_USART3;
		  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

//		  HAL_NVIC_SetPriority(USART3_4_IRQn, 0, 0);
//		  HAL_NVIC_EnableIRQ(USART3_4_IRQn);
	      break;
	    case 3U:
//		  __HAL_RCC_USART4_CLK_ENABLE(); //maybe not necessary?
//		  __HAL_RCC_GPIOA_CLK_ENABLE(); //maybe not necessary?
	      GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1;
		  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		  GPIO_InitStruct.Pull = GPIO_NOPULL;
		  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
		  GPIO_InitStruct.Alternate = GPIO_AF4_USART4;
		  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

//		  HAL_NVIC_SetPriority(USART3_4_IRQn, 0, 0);
//		  HAL_NVIC_EnableIRQ(USART3_4_IRQn);
	      break;
	    default:
	      status = HAL_ERROR;
	      break;
	  }

	return (uint8_t) status;
}

uint8_t L6360_I2cInit(uint8_t freq_mode)
{

	HAL_StatusTypeDef status = HAL_OK;

	pI2cHandle = L6360_I2C_HANDLE;
//
	pI2cHandle.Instance = L6360_I2C_PORT;
	if(freq_mode == 1) //400kHz
	{
		pI2cHandle.Init.Timing = 0x0000020B;
	}
	else //100kHz
	{
		pI2cHandle.Init.Timing = 0x20000215;
	}
	pI2cHandle.Init.OwnAddress1 = 0;
	pI2cHandle.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	pI2cHandle.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	pI2cHandle.Init.OwnAddress2 = 0;
	pI2cHandle.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
	pI2cHandle.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	pI2cHandle.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
	if (HAL_I2C_Init(&pI2cHandle) != HAL_OK)
	{
		status = HAL_ERROR;
		return (uint8_t) status;
	}
	  /** Configure Analogue filter */
	if (HAL_I2CEx_ConfigAnalogFilter(&pI2cHandle, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
	{
		status = HAL_ERROR;
	}
	  /** Configure Digital filter */
	if (HAL_I2CEx_ConfigDigitalFilter(&pI2cHandle, 0) != HAL_OK)
	{
		status = HAL_ERROR;
	}

	return (uint8_t) status;

}

uint8_t L6360_UartInit(uint8_t portId)
{
	HAL_StatusTypeDef status = HAL_OK;
	UART_HandleTypeDef *pUartHandle = (void *)0;


	switch (portId)
	  {
	    case 0U:
//	      pUartHandle = &hUartPort0;
	      pUartHandle->Instance  = L6360_UART_PORT_0;
	      break;
	    case 1U:
//		  __HAL_RCC_USART2_CLK_ENABLE(); //maybe not necessary?
//		  __HAL_RCC_GPIOA_CLK_ENABLE(); //maybe not necessary?
//		  pUartHandle = &hUartPort1;
		  pUartHandle->Instance  = L6360_UART_PORT_1;
	      break;
	    case 2U:
//		  __HAL_RCC_USART3_CLK_ENABLE(); //maybe not necessary?
//		  __HAL_RCC_GPIOC_CLK_ENABLE(); //maybe not necessary?
//		  pUartHandle = &hUartPort2;
		  pUartHandle->Instance  = L6360_UART_PORT_2;
	      break;
	    case 3U:
//		  __HAL_RCC_USART4_CLK_ENABLE(); //maybe not necessary?
//		  __HAL_RCC_GPIOA_CLK_ENABLE(); //maybe not necessary?
//		  pUartHandle = &hUartPort3;
		  pUartHandle->Instance  = L6360_UART_PORT_3;
	      break;
	    default:
	      status = HAL_ERROR;
	      break;
	  }

	if(status == HAL_OK)
	{
	    pUartHandle->Init.BaudRate = 230400;
	    pUartHandle->Init.WordLength = UART_WORDLENGTH_9B; //8B
	    pUartHandle->Init.StopBits = UART_STOPBITS_1;
	    pUartHandle->Init.Parity = UART_PARITY_EVEN; //none
	    pUartHandle->Init.Mode = UART_MODE_TX_RX;
	    pUartHandle->Init.HwFlowCtl = UART_HWCONTROL_NONE;
	    pUartHandle->Init.OverSampling = UART_OVERSAMPLING_16;
	    pUartHandle->Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
	    pUartHandle->AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;

	    status = HAL_UART_Init(pUartHandle);
	    if( status == HAL_OK)
	    {
//	        __HAL_UART_FLUSH_DRREGISTER(&pUartHandle);
//	        __HAL_UART_CLEAR_OREFLAG(&pUartHandle);
//	        status = HAL_UART_Receive_IT(&pUartHandle, &uartRxWakeup[portId], 1U);
	    }

	}

	return (uint8_t) status;


}

uint8_t L6360_UartSetBaudrate(uint8_t portId, uint32_t baudrate)
{
	HAL_StatusTypeDef status = HAL_OK;
	UART_HandleTypeDef *pUartHandle;

	switch (portId)
	  {
    	case 0U:
    		pUartHandle = &L6360_UART_HANDLE_0;
    		pUartHandle->Instance  = L6360_UART_PORT_0;
    		break;
    	case 1U:
    		pUartHandle = &L6360_UART_HANDLE_1;
    		pUartHandle->Instance  = L6360_UART_PORT_1;
    		break;
    	case 2U:
    		pUartHandle = &L6360_UART_HANDLE_2;
    		pUartHandle->Instance  = L6360_UART_PORT_2;
    		break;
    	case 3U:
    		pUartHandle = &L6360_UART_HANDLE_3;
    		pUartHandle->Instance  = L6360_UART_PORT_3;
    		break;
	    default:
	      status = HAL_ERROR;
	      break;
	  }

	if(status == HAL_OK)
	{

//		status = HAL_UART_AbortReceive(&pUartHandle);
//		if(status == HAL_OK)
//		{
		    pUartHandle->Init.BaudRate = baudrate;
		    status = HAL_UART_Init(pUartHandle);
//		}
	}


	return (uint8_t) status;
}

uint8_t L6360_UartSendData(uint8_t portId, uint8_t data)
{
	HAL_StatusTypeDef status = HAL_OK;
	UART_HandleTypeDef *pUartHandle;

	switch (portId)
	  {
    	case 0U:
    		pUartHandle = &L6360_UART_HANDLE_0;
    		break;
    	case 1U:
    		pUartHandle = &L6360_UART_HANDLE_1;
    		break;
    	case 2U:
    		pUartHandle = &L6360_UART_HANDLE_2;
    		break;
    	case 3U:
    		pUartHandle = &L6360_UART_HANDLE_3;
    		break;
	    default:
	      status = HAL_ERROR;
	      break;
	  }
	if(status == HAL_OK)
	{
		uartTxBuffer[portId]  = data;
		status = HAL_UART_Transmit(pUartHandle, &uartTxBuffer[portId], 1U, 1);
	}

	return (uint8_t) status;

}

uint8_t L6360_UartSendDataIT(uint8_t portId, uint8_t data)
{
	HAL_StatusTypeDef status = HAL_OK;
	UART_HandleTypeDef *pUartHandle;

	switch (portId)
	  {
    	case 0U:
    		pUartHandle = &L6360_UART_HANDLE_0;
    		break;
    	case 1U:
    		pUartHandle = &L6360_UART_HANDLE_1;
    		break;
    	case 2U:
    		pUartHandle = &L6360_UART_HANDLE_2;
    		break;
    	case 3U:
    		pUartHandle = &L6360_UART_HANDLE_3;
    		break;
	    default:
	      status = HAL_ERROR;
	      break;
	  }
	if(status == HAL_OK)
	{
		uartTxBuffer[portId]  = data;
		status = HAL_UART_Transmit_IT(pUartHandle, &uartTxBuffer[portId], 1U);
	}

	return (uint8_t) status;

}

uint8_t L6360_UartReceiveData(uint8_t portId)
{
	HAL_StatusTypeDef status = HAL_OK;
	UART_HandleTypeDef *pUartHandle;

	switch (portId)
	  {
    	case 0U:
    		pUartHandle = &L6360_UART_HANDLE_0;
    		break;
    	case 1U:
    		pUartHandle = &L6360_UART_HANDLE_1;
    		break;
    	case 2U:
    		pUartHandle = &L6360_UART_HANDLE_2;
    		break;
    	case 3U:
    		pUartHandle = &L6360_UART_HANDLE_3;
    		break;
	    default:
	      status = HAL_ERROR;
	      break;
	  }
	if(status == HAL_OK)
	{
		status = HAL_UART_Receive(pUartHandle, &uartRxBuffer[portId], 1U, 10);
	}

	return (uint8_t) status;

}

uint8_t L6360_UartReceiveDataIT(uint8_t portId)
{
	HAL_StatusTypeDef status = HAL_OK;
	UART_HandleTypeDef *pUartHandle;

	switch (portId)
	  {
    	case 0U:
    		pUartHandle = &L6360_UART_HANDLE_0;
    		break;
    	case 1U:
    		pUartHandle = &L6360_UART_HANDLE_1;
    		break;
    	case 2U:
    		pUartHandle = &L6360_UART_HANDLE_2;
    		break;
    	case 3U:
    		pUartHandle = &L6360_UART_HANDLE_3;
    		break;
	    default:
	      status = HAL_ERROR;
	      break;
	  }
	if(status == HAL_OK)
	{
		status = HAL_UART_Receive_IT(pUartHandle, &uartRxBuffer[portId], 1U);
	}

	return (uint8_t) status;

}

uint8_t L6360_UartStopReceiveIT(uint8_t portId)
{
	HAL_StatusTypeDef status = HAL_OK;
	UART_HandleTypeDef *pUartHandle;

	switch (portId)
	  {
    	case 0U:
    		pUartHandle = &L6360_UART_HANDLE_0;
    		break;
    	case 1U:
    		pUartHandle = &L6360_UART_HANDLE_1;
    		break;
    	case 2U:
    		pUartHandle = &L6360_UART_HANDLE_2;
    		break;
    	case 3U:
    		pUartHandle = &L6360_UART_HANDLE_3;
    		break;
	    default:
	      status = HAL_ERROR;
	      break;
	  }
	if(status == HAL_OK)
	{
		status = HAL_UART_Abort_IT(pUartHandle);
	}

	return (uint8_t) status;

}

uint8_t L6360_UartReceiveDataWakeup(uint8_t portId)
{
	HAL_StatusTypeDef status = HAL_OK;
	UART_HandleTypeDef *pUartHandle;

	switch (portId)
	  {
    	case 0U:
    		pUartHandle = &L6360_UART_HANDLE_0;
    		break;
    	case 1U:
    		pUartHandle = &L6360_UART_HANDLE_1;
    		break;
    	case 2U:
    		pUartHandle = &L6360_UART_HANDLE_2;
    		break;
    	case 3U:
    		pUartHandle = &L6360_UART_HANDLE_3;
    		break;
	    default:
	      status = HAL_ERROR;
	      break;
	  }
	if(status == HAL_OK)
	{
		status = HAL_UART_Receive_IT(pUartHandle, &uartRxWakeup[portId], 1U);
	}

	return (uint8_t) status;

}

uint8_t L6360_SioInit(uint8_t portId)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	HAL_StatusTypeDef status = HAL_OK;
	switch (portId)
	{
		case 0U:
			GPIO_InitStruct.Pin = GPIO_PIN_10;
			GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
			GPIO_InitStruct.Pull = GPIO_NOPULL;
			GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
			HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
			break;
		case 1U:
			GPIO_InitStruct.Pin = GPIO_PIN_3;
			GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
			GPIO_InitStruct.Pull = GPIO_NOPULL;
			GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
			HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
			break;
		case 2U:
			GPIO_InitStruct.Pin = GPIO_PIN_5;
			GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
			GPIO_InitStruct.Pull = GPIO_NOPULL;
			GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
			HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
			break;
		case 3U:
			GPIO_InitStruct.Pin = GPIO_PIN_1;
			GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
			GPIO_InitStruct.Pull = GPIO_NOPULL;
			GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
			HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
			break;
		default:
			status = HAL_ERROR;
			break;
	}

	return (uint8_t) status;


}
uint8_t L6360_SioRead(uint8_t portId)
{
	switch (portId)
	{
		case 0U:
			return HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10);
		case 1U:
			return HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_3);
		case 2U:
			return HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5);
		case 3U:
			return HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1);
		default:
			return 3;
	}
}

uint8_t L6360_UartCheckReceive(uint8_t portId)
{

	HAL_StatusTypeDef status = HAL_OK;
	UART_HandleTypeDef *pUartHandle;

	switch (portId)
	  {
    	case 0U:
    		pUartHandle = &L6360_UART_HANDLE_0;
    		break;
    	case 1U:
    		pUartHandle = &L6360_UART_HANDLE_1;
    		break;
    	case 2U:
    		pUartHandle = &L6360_UART_HANDLE_2;
    		break;
    	case 3U:
    		pUartHandle = &L6360_UART_HANDLE_3;
    		break;
	    default:
	      status = HAL_ERROR;
	      break;
	  }
	if(status == HAL_OK)
	{
		if (__HAL_UART_GET_FLAG(pUartHandle, UART_FLAG_RXNE) == SET)
		{
			__HAL_UART_CLEAR_FLAG(pUartHandle, UART_FLAG_RXNE);
			status  = HAL_OK;
		}
		else
		{
			status = HAL_ERROR;
		}
	}


	return (uint8_t) status;


}


