/*
 * l6360.h
 *
 *  Created on: Mar 18, 2021
 *      Author: Grzegorz G
 */

#ifndef L6360_H_
#define L6360_H_

#include "stm32f0xx_hal.h"
#include "main.h"
#include "i2c.h"
#include "usart.h"
#include "tim.h"
#include "usbd_cdc_if.h"


/*
 * 	***
 * Timing below was setting for blocking UART RX, now are IT, maybe RX handle time now is faster and need be adjust
 * 	***
 *
 * WAKE UP TIMING PROCEDURE (6 tries)
 * TX LOW for 75...85us -> default TIME0 75
 * WAIT MAX 425us and then wait Tdmt COM3 117...160us -> default TIME1 530
 * Send TX at BAUD 230400
 * WAIT for response 703...963us -> default TIME2 650 (because of add also time of RX handle)
 * If response -> break else
 * Send TX at BAUD 38400
 * WAIT for response 5624...7708us -> default TIME3_1 4000 + Rx handle + TIME3_2 640
 * If response -> break else
 * Send TX at BAUD 4800
 * WAIT for response 20000...40000us -> default 20000
 *
 */
#define WAKE_TIME_0 (70)
#define WAKE_TIME_1 (500)
#define WAKE_TIME_2 (570)
#define WAKE_TIME_3_1 (5600)
#define WAKE_TIME_3_2 (0)
#define WAKE_TIME_4 (20000)


///** I2C address of first L6360 */
//#define L6360_I2C_ADD_0 (0U)
///** I2C address of second L6360 */
//#define L6360_I2C_ADD_1 (1U)
///** I2C address of third L6360 */
//#define L6360_I2C_ADD_2 (2U)
///** I2C address of fourth L6360 */
//#define L6360_I2C_ADD_3 (3U)
/** Used UART for port 0 */
#define L6360_UART_HANDLE_0 	huart1
/** Used UART for port 0 */
#define L6360_UART_HANDLE_1 	huart2
/** Used UART for port 0 */
#define L6360_UART_HANDLE_2 	huart3
/** Used UART for port 0 */
#define L6360_UART_HANDLE_3 	huart4
/** Used UART for port 0 */
#define L6360_UART_PORT_0 		USART1
/** Used UART for port 0 */
#define L6360_UART_PORT_1 		USART2
/** Used UART for port 0 */
#define L6360_UART_PORT_2 		USART3
/** Used UART for port 0 */
#define L6360_UART_PORT_3 		USART4
/** Used I2C */
#define L6360_I2C_HANDLE 		hi2c1
#define L6360_I2C_PORT 			I2C1

#define PARITY(x)      ((uint8_t)(((((uint8_t)(x)&0x80U)>>7U)^(((uint8_t)(x)&0x40U)>>6U)^(((uint8_t)(x)&0x20U)>>5U)^(((uint8_t)(x)&0x10U)>>4U)^(((uint8_t)(x)&0x08U)>>3U)^(((uint8_t)(x)&0x04U)>>2U)^(((uint8_t)(x)&0x02U)>>1U)^((uint8_t)(x)&0x01U))))
#define ODD_PARITY(x)  ((uint8_t)((((uint8_t)(x)&0x80U)>>7U)^(((uint8_t)(x)&0x20U)>>5U)^(((uint8_t)(x)&0x08U)>>3U)^(((uint8_t)(x)&0x02U)>>1U)))
#define EVEN_PARITY(x) ((uint8_t)((((uint8_t)(x)&0x40U)>>6U)^(((uint8_t)(x)&0x10U)>>4U)^(((uint8_t)(x)&0x04U)>>2U)^((uint8_t)(x)&0x01U)))


void delay_us (uint16_t us);

uint8_t L6360_PowerUp(uint8_t portId);
uint8_t L6360_WakeUp(uint8_t portId);

//uint8_t L6360_I2C_CurrentParity(uint8_t* buffer);
//uint8_t L6360_I2C_CurrentWrite(uint8_t i2cAdd, uint8_t data);
//uint16_t L6360_I2C_CurrentRead(uint8_t i2cAdd); /* reg and parity */
//
//uint8_t L6360_I2C_SequencialParity(uint8_t* buffer);
//uint8_t L6360_I2C_SequencialCurrentWrite(uint8_t i2cAdd, uint8_t regAdd, uint8_t data);
//uint8_t L6360_I2C_SequencialCurrentRead(uint8_t i2cAdd);


uint8_t L6360_Read(uint8_t portId);
uint8_t L6360_ReadState(uint8_t portId);
uint8_t L6360_ReadName(uint8_t portId);
uint8_t L6360_ReadStart(uint8_t portId);


void L6360_PinEnableLPlus(uint8_t portId); /* Enable the ENC/Q gpio pin*/
void L6360_PinDisableLPlus(uint8_t portId); /* Disable the ENL+ gpio pin*/

void L6360_PinEnableCQ(uint8_t portId); /* Enable the ENC/Q gpio pin*/
void L6360_PinDisableCQ(uint8_t portId); /* Disable the ENC/Q gpio pin*/

void L6360_PinEnableReset(uint8_t portId); /* Enable the Reset gpio pin*/
void L6360_PinDisableReset(uint8_t portId); /* Disable the Reset gpio pin*/

uint8_t L6360_SioInit(uint8_t portId);
uint8_t L6360_SioRead(uint8_t portId);

uint8_t L6360_I2cInit(uint8_t freq_mode);   /* Initialise the I2C used for L6360   0- 100kHz, 1- 400kHz*/

uint8_t L6360_UartPinsInit(uint8_t portId); /* Initialise the UART pins! used for L6360 */
uint8_t L6360_UartInit(uint8_t portId);   /* Initialise the UART used for L6360 */
uint8_t L6360_UartSendData(uint8_t portId, uint8_t data);   /* send data to L6360 via uart (InCq data) */
uint8_t L6360_UartSendDataIT(uint8_t portId, uint8_t data);
uint8_t L6360_UartReceiveData(uint8_t portId);
uint8_t L6360_UartReceiveDataIT(uint8_t portId);
uint8_t L6360_UartReceiveDataWakeup(uint8_t portId);
uint8_t L6360_UartStopReceiveIT(uint8_t portId);
uint8_t L6360_UartSetBaudrate(uint8_t portId, uint32_t baudrate); /* Set the UART baudrate used for L6360 */
uint8_t L6360_UartCheckReceive(uint8_t portId);

#endif /* L6360_H_ */
