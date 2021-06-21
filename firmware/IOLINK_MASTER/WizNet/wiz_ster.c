/*
 * wiz_ster.c
 *
 *  Created on: May 14, 2021
 *      Author: ggucwa
 */


#include "wiz_ster.h"
#include "string.h"
#include "stdio.h"
#include "main.h"



void W5500_CsSelect(void) {
	HAL_GPIO_WritePin(CS_ETH_GPIO_Port, CS_ETH_Pin, GPIO_PIN_RESET); //CS LOW
}

void W5500_CsDeselect(void) {
	HAL_GPIO_WritePin(CS_ETH_GPIO_Port, CS_ETH_Pin, GPIO_PIN_SET); //CS HIGH
}

#ifdef W5500_BURST
void W5500_ReadBurst(uint8_t *pBuf, uint16_t len) {
	HAL_SPI_Receive_Auto(&hspi1, pBuf, len);
	return;
}

void W5500_WriteBurst(uint8_t *pBuf, uint16_t len) {
	HAL_SPI_Transmit_Auto(&hspi1, pBuf, len);
	return;
}
#endif

void W5500_Write(uint8_t b) {
	HAL_SPI_Transmit_Auto(&hspi1, &b, 1);
}

uint8_t W5500_Read(void) {
	uint8_t rbuf;
	HAL_SPI_Receive_Auto(&hspi1, &rbuf, 1);
	return rbuf;
}

int8_t OpenNetSocket(uint8_t sock_id)
{
	uint8_t sd, sck_state;

	sd = socket(sock_id, Sn_MR_UDP, NET_LOCAL_PORT, 0);//SF_IO_NONBLOCK);

	if(sd != sock_id) {
//		error(8, 0);
	}

	do {
		getsockopt(sd , SO_STATUS, &sck_state);
	} while (sck_state != SOCK_UDP);

	return sd;
}

