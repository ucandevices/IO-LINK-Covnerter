/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "i2c.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "usb_device.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "usbd_cdc_if.h"
#include "io_link.h"
#include "l6360.h"
#include "io_link.h"

#include "wizchip_conf.h"
#include "socket.h"
#include "wiz_ster.h"


/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

#define TIMEOUT_RECEIVE 3


/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

//uint8_t TIMEOUT_RECEIVE = 2;

uint8_t USB_txBuffer[64];
uint8_t USB_txLength = 0;
uint8_t USB_rxBuffer[64];
uint8_t USB_rxLength = 0;
uint8_t USB_rxFlag = 0;

uint8_t periodically_uart[4] = {0};
uint8_t periodically_i2c = 0;
uint8_t periodically_sio = 0;

uint8_t com_baud[4] = {0};

uint16_t cnt = 1;

uint32_t timeout_rec0 = 0;
uint32_t timeout_rec1 = 0;
uint32_t timeout_rec2 = 0;
uint32_t timeout_rec3 = 0;
uint8_t buf_rec0[64];
uint8_t buf_rec0_l = 0;
uint8_t buf_rec1[64] = {0,};
uint8_t buf_rec1_l = 0;
uint8_t buf_rec2[64] = {0,};
uint8_t buf_rec2_l = 0;
uint8_t buf_rec3[64] = {0,};
uint8_t buf_rec3_l = 0;



//extern UART_HandleTypeDef pUartHandle;
extern uint8_t uartRxBuffer[4];
//extern IO_LINK_SPE_HEADER;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void L6360_Reset(uint8_t com);
void IO_LINK_Init(uint8_t dev);
void SIO_Init(uint8_t dev);

void DisplayNetConf(void);

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

struct IO_LINK_SPE_HEADER HEADER_RS = {
		.HeaderVersion = 0x00,
		.HeaderSize = 0x00,
		.IO_LINK_ProtocolVersion = 0x00,
		.TransferDirection = 0x00,
		.IO_LINK_FrameType = 0x00,
		.IO_LINK_FrameSize0 = 0x00,
		.IO_LINK_FrameSize1 = 0x00,
		.PortNumber = 0x00
		};

wiz_NetInfo gWIZNETINFO = { .mac = {0x00, 0x08, 0xdc, 0xab, 0xcd, 0xef},
                            .ip = {192, 168, 1, 2},
                            .sn = {255, 255, 255, 0},
                            .gw = {192, 168, 1, 1},
                            .dns = {0, 0, 0, 0},
                            .dhcp = NETINFO_STATIC };

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */


  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_SPI1_Init();
  MX_USART1_UART_Init();
  MX_USART2_UART_Init();
  MX_USART3_UART_Init();
  MX_USART4_UART_Init();
  MX_I2C1_Init();
  MX_USB_DEVICE_Init();
  MX_TIM17_Init();
  MX_TIM7_Init();
  /* USER CODE BEGIN 2 */

  L6360_Reset(0);

  HAL_TIM_Base_Start(&htim17);
  HAL_TIM_Base_Start_IT(&htim7);

  HAL_Delay(2000); //wait to init usb (temporary)
  HAL_GPIO_WritePin(USB_ENABLE_GPIO_Port, USB_ENABLE_Pin, SET);

  __HAL_UART_FLUSH_DRREGISTER(&huart1);
  __HAL_UART_FLUSH_DRREGISTER(&huart2);
  __HAL_UART_FLUSH_DRREGISTER(&huart3);
  __HAL_UART_FLUSH_DRREGISTER(&huart4);


<<<<<<< HEAD
  memset(USB_txBuffer, '\0', sizeof(USB_txBuffer));
  USB_txLength = sprintf((char*)USB_txBuffer, "\r\nStart Program v1.1\r\n\n");
  CDC_Transmit_FS(USB_txBuffer, USB_txLength);
=======
//  memset(USB_txBuffer, '\0', sizeof(USB_txBuffer));
//  USB_txLength = sprintf((char*)USB_txBuffer, "\r\nStart Program v2.3\r\n\n");
//  CDC_Transmit_FS(USB_txBuffer, USB_txLength);
>>>>>>> test1
  HAL_Delay(1000);



  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

	  if(USB_rxFlag == 1)
	  {
		  USB_rxFlag = 0;
		  if( USB_rxLength > 1)
		  {
<<<<<<< HEAD
			  CDC_Transmit_FS(USB_rxBuffer, USB_rxLength);
//			  IoLinkMType0(0, USB_rxBuffer);
=======

			  IoLinkHeader(&HEADER_RS, USB_rxBuffer, USB_rxLength);
//			  HAL_UART_Receive_IT(&huart1, &uartRxBuffer[0], 1);

>>>>>>> test1
		  }
		  else
		  {
			  switch(USB_rxBuffer[0])
			  {
			  	  case '0': //stop all
			  		  L6360_Reset(1); break;
			  	  case '1':
			  		  SIO_Init(0); break;
			  	  case '2':
			  		  IO_LINK_Init(0); break;
			  	  case '3':
			  		  SIO_Init(1); break;
			  	  case '4':
			  		  IO_LINK_Init(1); break;
			  	  case '5':
			  		  SIO_Init(2); break;
			  	  case '6':
			  		  IO_LINK_Init(2); break;
			  	  case '7':
			  		  SIO_Init(3); break;
			  	  case '8':
			  		  IO_LINK_Init(3); break;
			  	  default:
			  		  HAL_NVIC_SystemReset(); break;
			  }
		  }


	  }

//	  HAL_Delay(500);

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};
  RCC_CRSInitTypeDef RCC_CRSInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_HSI48;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSI48State = RCC_HSI48_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI48;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USB|RCC_PERIPHCLK_USART1
                              |RCC_PERIPHCLK_USART2|RCC_PERIPHCLK_I2C1;
  PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK1;
  PeriphClkInit.Usart2ClockSelection = RCC_USART2CLKSOURCE_PCLK1;
  PeriphClkInit.I2c1ClockSelection = RCC_I2C1CLKSOURCE_HSI;
  PeriphClkInit.UsbClockSelection = RCC_USBCLKSOURCE_HSI48;

  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
  /** Enable the SYSCFG APB clock
  */
  __HAL_RCC_CRS_CLK_ENABLE();
  /** Configures CRS
  */
  RCC_CRSInitStruct.Prescaler = RCC_CRS_SYNC_DIV1;
  RCC_CRSInitStruct.Source = RCC_CRS_SYNC_SOURCE_USB;
  RCC_CRSInitStruct.Polarity = RCC_CRS_SYNC_POLARITY_RISING;
  RCC_CRSInitStruct.ReloadValue = __HAL_RCC_CRS_RELOADVALUE_CALCULATE(48000000,1000);
  RCC_CRSInitStruct.ErrorLimitValue = 34;
  RCC_CRSInitStruct.HSI48CalibrationValue = 32;

  HAL_RCCEx_CRSConfig(&RCC_CRSInitStruct);
}

/* USER CODE BEGIN 4 */

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
		if(huart->Instance == USART1)
		{
			if(buf_rec0_l == 0)
			{
//				  timeout_rec0 = HAL_GetTick() + TIMEOUT_RECEIVE;
				timeout_rec0 = HAL_GetTick();
				buf_rec0[0] = 0x99;
//				buf_rec0[1] = 0x88;
//				buf_rec0[2] = 0x77;
			}

			buf_rec0[buf_rec0_l] = uartRxBuffer[0];
			buf_rec0_l++;

			//			if(HAL_GetTick() >= timeout_rec0)
//			if((HAL_GetTick() - timeout_rec0) > (uint32_t)TIMEOUT_RECEIVE)
//			{

//				memmove(buf_rec0+8, buf_rec0, buf_rec0_l);
//				buf_rec0[0] = (uint8_t)HEADER_RS.HeaderVersion;
//				buf_rec0[1] = (uint8_t)HEADER_RS.HeaderSize;
//				buf_rec0[2] = (uint8_t)HEADER_RS.IO_LINK_ProtocolVersion;
//				buf_rec0[3] = (uint8_t)HEADER_RS.TransferDirection;
//				buf_rec0[4] = (uint8_t)HEADER_RS.IO_LINK_FrameType;
//				buf_rec0[5] = (uint8_t)HEADER_RS.IO_LINK_FrameSize0;
//				buf_rec0[6] = (uint8_t)HEADER_RS.IO_LINK_FrameSize1;
//				buf_rec0[7] = (uint8_t)HEADER_RS.PortNumber;
				CDC_Transmit_FS(&buf_rec0[0], buf_rec0_l);
//				memset(buf_rec0, '\0', buf_rec0_l+8);
				buf_rec0_l = 0;
//				HAL_UART_Abort_IT(&huart1);
				__HAL_UART_FLUSH_DRREGISTER(&huart1);

//			}
//			else
//			{

				HAL_UART_Receive_IT(&huart1, &uartRxBuffer[0], 1);

//			}



		}
		if(huart->Instance == USART2)
		{
//			CDC_Transmit_FS(&uartRxBuffer[1], 1);
			HAL_UART_Receive_IT(&huart2, &uartRxBuffer[1], 1);
		}
		if(huart->Instance == USART3)
		{
//			CDC_Transmit_FS(&uartRxBuffer[2], 1);
			HAL_UART_Receive_IT(&huart3, &uartRxBuffer[2], 1);
		}
		if(huart->Instance == USART4)
		{
//			CDC_Transmit_FS(&uartRxBuffer[3], 1);
			HAL_UART_Receive_IT(&huart4, &uartRxBuffer[3], 1);
		}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{

	if(htim->Instance == TIM7)
	{
		if(cnt%100 == 0) // co 10 ms
		{
			if(periodically_uart[0] == 1)
			{
				uint8_t data_period_tx[2] = {0xF1, 0x94};
				L6360_PinEnableCQ(0);
				L6360_UartSendData(0, data_period_tx[0]);
				L6360_UartSendData(0, data_period_tx[1]);
				L6360_PinDisableCQ(0);
			}
			if(periodically_uart[1] == 1)
			{
				uint8_t data_period_tx[2] = {0xF1, 0x94};
				L6360_PinEnableCQ(1);
				L6360_UartSendData(1, data_period_tx[0]);
				L6360_UartSendData(1, data_period_tx[1]);
				L6360_PinDisableCQ(1);
			}
			if(periodically_uart[2] == 1)
			{
				uint8_t data_period_tx[2] = {0xF1, 0x94};
				L6360_PinEnableCQ(2);
				L6360_UartSendData(2, data_period_tx[0]);
				L6360_UartSendData(2, data_period_tx[1]);
				L6360_PinDisableCQ(2);
			}
			if(periodically_uart[3] == 1)
			{
				uint8_t data_period_tx[2] = {0xF1, 0x94};
				L6360_PinEnableCQ(3);
				L6360_UartSendData(3, data_period_tx[0]);
				L6360_UartSendData(3, data_period_tx[1]);
				L6360_PinDisableCQ(3);
			}
		}

		if(cnt%100 == 0) // co 100 ms
		{
			if(periodically_i2c == 1)
			{
				uint8_t data_i2c_rx[1];
				HAL_I2C_Master_Receive(&hi2c1, 0xC0, data_i2c_rx, 1, 10);
				HAL_I2C_Master_Receive(&hi2c1, 0xC2, data_i2c_rx, 1, 10);
				HAL_I2C_Master_Receive(&hi2c1, 0xC4, data_i2c_rx, 1, 10);
				HAL_I2C_Master_Receive(&hi2c1, 0xC6, data_i2c_rx, 1, 10);
			}
		}

		if(cnt%200 == 0)
		{
			if(periodically_sio > 0)
			{
				uint8_t send = L6360_SioRead(periodically_sio - 10) + '0';
				CDC_Transmit_FS(&send, 1);
			}
		}


		cnt++;
		if(cnt > 65000)
		{
			cnt = 1;
		}
	}
}

void DisplayNetConf(void)
{
	uint8_t tmpstr[6] = {0,};
	ctlnetwork(CN_GET_NETINFO, (void*) &gWIZNETINFO);
	ctlwizchip(CW_GET_ID,(void*)tmpstr);

	if(gWIZNETINFO.dhcp == NETINFO_DHCP)
	{
//		printf("\r\n===== %s NET CONF : DHCP =====\r\n",(char*)tmpstr);
		memset(USB_txBuffer, '\0', sizeof(USB_txBuffer));
		USB_txLength = sprintf((char*)USB_txBuffer, "\r\n===== %s NET CONF : DHCP =====\r\n",(char*)tmpstr);
		CDC_Transmit_FS(USB_txBuffer, USB_txLength);
	}
	else
	{
//		printf("\r\n===== %s NET CONF : Static =====\r\n",(char*)tmpstr);
		memset(USB_txBuffer, '\0', sizeof(USB_txBuffer));
		USB_txLength = sprintf((char*)USB_txBuffer, "\r\n===== %s NET CONF : Static =====\r\n",(char*)tmpstr);
		CDC_Transmit_FS(USB_txBuffer, USB_txLength);
	}
	memset(USB_txBuffer, '\0', sizeof(USB_txBuffer));
	USB_txLength = sprintf((char*)USB_txBuffer, " MAC : %02X:%02X:%02X:%02X:%02X:%02X\r\n", gWIZNETINFO.mac[0], gWIZNETINFO.mac[1], gWIZNETINFO.mac[2], gWIZNETINFO.mac[3], gWIZNETINFO.mac[4], gWIZNETINFO.mac[5]);
	CDC_Transmit_FS(USB_txBuffer, USB_txLength);
	memset(USB_txBuffer, '\0', sizeof(USB_txBuffer));
	USB_txLength = sprintf((char*)USB_txBuffer, " IP : %d.%d.%d.%d\r\n", gWIZNETINFO.ip[0], gWIZNETINFO.ip[1], gWIZNETINFO.ip[2], gWIZNETINFO.ip[3]);
	CDC_Transmit_FS(USB_txBuffer, USB_txLength);
	memset(USB_txBuffer, '\0', sizeof(USB_txBuffer));
	USB_txLength = sprintf((char*)USB_txBuffer, " GW : %d.%d.%d.%d\r\n", gWIZNETINFO.gw[0], gWIZNETINFO.gw[1], gWIZNETINFO.gw[2], gWIZNETINFO.gw[3]);
	CDC_Transmit_FS(USB_txBuffer, USB_txLength);
	memset(USB_txBuffer, '\0', sizeof(USB_txBuffer));
	USB_txLength = sprintf((char*)USB_txBuffer, " SN : %d.%d.%d.%d\r\n", gWIZNETINFO.sn[0], gWIZNETINFO.sn[1], gWIZNETINFO.sn[2], gWIZNETINFO.sn[3]);
	CDC_Transmit_FS(USB_txBuffer, USB_txLength);
//	printf(" MAC : %02X:%02X:%02X:%02X:%02X:%02X\r\n", gWIZNETINFO.mac[0], gWIZNETINFO.mac[1], gWIZNETINFO.mac[2], gWIZNETINFO.mac[3], gWIZNETINFO.mac[4], gWIZNETINFO.mac[5]);
//	printf(" IP : %d.%d.%d.%d\r\n", gWIZNETINFO.ip[0], gWIZNETINFO.ip[1], gWIZNETINFO.ip[2], gWIZNETINFO.ip[3]);
//	printf(" GW : %d.%d.%d.%d\r\n", gWIZNETINFO.gw[0], gWIZNETINFO.gw[1], gWIZNETINFO.gw[2], gWIZNETINFO.gw[3]);
//	printf(" SN : %d.%d.%d.%d\r\n", gWIZNETINFO.sn[0], gWIZNETINFO.sn[1], gWIZNETINFO.sn[2], gWIZNETINFO.sn[3]);
//	printf("=======================================\r\n");
}





/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
