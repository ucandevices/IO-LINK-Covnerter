/*
 * wiz_ster.h
 *
 *  Created on: May 14, 2021
 *      Author: ggucwa
 */

#ifndef WIZ_STER_H_
#define WIZ_STER_H_

#include "main.h"
#include "spi.h"
#include "socket.h"

//https://devel.mephi.ru/dyokunev/stm32-nucleo-f401re-w5500-usr-es1/src/master/Src/main.c

#define	NET_LOCAL_PORT	30319
#define	NET_REMOTE_PORT	30319

#define W5500_BURST
#define HAL_SPI_Receive_Auto(a, b, c) 	HAL_SPI_Receive(a, b, c, 0xffffffff)
#define HAL_SPI_Transmit_Auto(a, b, c) 	HAL_SPI_Transmit(a, b, c, 0xffffffff)


void W5500_CsSelect(void);
void W5500_CsDeselect(void);
void W5500_ReadBurst(uint8_t *pBuf, uint16_t len);
void W5500_WriteBurst(uint8_t *pBuf, uint16_t len);
void W5500_Write(uint8_t b);
uint8_t W5500_Read(void);
int8_t OpenNetSocket(uint8_t sock_id);



#endif /* WIZ_STER_H_ */
