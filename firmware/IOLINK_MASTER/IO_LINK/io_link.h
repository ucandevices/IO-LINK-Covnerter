/*
 * io_link.h
 *
 *  Created on: Mar 18, 2021
 *      Author: Grzegorz G
 */

#ifndef IO_LINK_H_
#define IO_LINK_H_

#include "stm32f0xx_hal.h"

struct IO_LINK_SPE_HEADER{
    uint8_t HeaderVersion; // 0
    uint8_t HeaderSize; // size in bytes fixed 8
    uint8_t IO_LINK_ProtocolVersion; // 0
    uint8_t TransferDirection; // cast from enum ? in / out
    uint8_t IO_LINK_FrameType; // cast from enum ? TYPE_0, TYPE_1_1, TYPE_1_2, and TYPE_2_1 1541 through TYPE_2_5 + extra WAKEUP
    uint8_t IO_LINK_FrameSize0; // IO LINK Frame Size in bytes
    uint8_t IO_LINK_FrameSize1; // IO LINK Frame Size in bytes
    uint8_t PortNumber; //for UCAN 0-3 IO LINK PORT
};


enum IO_FRAME {TYPE_0 = 0, TYPE_1, TYPE_2, L6360_RESET = 10, POWER_UP, WAKE_UP, SIO};
enum IO_DIR {WRITE = 0, READ = 1};
enum IO_PORT {PORT0 = 0, PORT1, PORT2, PORT3};

void IO_LINK_Init(uint8_t dev);
void SIO_Init(uint8_t dev);
void L6360_Reset(uint8_t com);

uint8_t IoLinkCalcChecksum(uint8_t m_type, uint8_t *pData, uint8_t data_length);

//uint8_t IoLinkMType0(uint8_t portId, uint8_t mc_data, uint8_t wr_data);

uint8_t IoLinkHeader(struct IO_LINK_SPE_HEADER* str1, uint8_t *pData, uint8_t dataLength);
void IoLinkMSender(uint8_t *pData, uint8_t data_length, uint8_t calc_ch);
//uint8_t IoLinkSender(uint8_t *pData, uint8_t dataLength);

#endif /* IO_LINK_H_ */

/*
 * M-sequence control (MC)
 *  R C C A A A A A
 * R/W | Com channel | Address
 * R/W (1) - 1 - Read / 0 - Write
 * Communication channel (2) - 0 - Process / 1 - Page / 2 - Diagnosis / 3 - ISDU
 * Address (5)
 * ******
 *
 * Checksum (CKT)
 * M M C C C C C C
 * M seq type | Checksum
 * M-sequence type - 0 - Type0 / 1 - Type1 / 2 - Type2 / 3 - reserved
 * ******
 *
 * Status (CKS)
 * E P C C C C C C
 * Event flag | PD status | Checksum
 * Event flag (1) - 0 - No event / 1 - Event
 * PD status (1) - 0 - PD valid / 1 - PD invalid
 * Checksum (6)
 * ******
 *
 * Calc of checksum
 * Seed value 0x52 xor MC -> Checksum 8
 * 	D56 = D78 xor D58 xor D38 xor D18
 * 	D46 = D68 xor D48 xor D28 xor D08
 * 	D36 = D78 xor D68
 * 	D26 = D58 xor D48
 * 	D16 = D38 xor D28
 * 	D06 = D18 xor D08
 *
 * ******
 *
 * M-seq TYPE0
 * Read MC CKT
 * Reply OD CKS
 *
 * Write MC CKT OD
 * Reply CKS
 *
 *
 *
 */
