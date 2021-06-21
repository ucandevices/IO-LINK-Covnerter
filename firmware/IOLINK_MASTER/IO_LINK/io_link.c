/*
 * io_link.c
 *
 *  Created on: Mar 18, 2021
 *      Author: Grzegorz G
 */
#include "io_link.h"
#include "l6360.h"

extern uint8_t USB_txBuffer[64];
extern uint8_t USB_txLength;
extern uint8_t periodically_uart[4];
extern uint8_t periodically_i2c;
extern uint8_t periodically_sio;
extern uint8_t com_baud[4];
extern uint8_t uartRxBuffer[4];
//extern uint8_t TIMEOUT_RECEIVE;

void IO_LINK_Init(uint8_t dev)
{
	L6360_Reset(0);
	if(L6360_PowerUp(dev) == HAL_OK)
	{
//		memset(USB_txBuffer, '\0', sizeof(USB_txBuffer));
//		USB_txLength = sprintf((char*)USB_txBuffer, "\r\nPower up dev %d CORRECT\r\n", dev);
//		CDC_Transmit_FS(USB_txBuffer, USB_txLength);

		periodically_i2c = 1;
		HAL_Delay(500);

		com_baud[dev] = L6360_WakeUp(dev);
		if(com_baud[dev] > 5)
		{
//			memset(USB_txBuffer, '\0', sizeof(USB_txBuffer));
//			USB_txLength = sprintf((char*)USB_txBuffer, "\rWake up dev %d CORRECT - BAUD %d\r\n", dev, com_baud[dev]/10);
//			CDC_Transmit_FS(USB_txBuffer, USB_txLength);

//			L6360_UartStopReceiveIT(dev);
			HAL_Delay(10);
//			L6360_UartReceiveDataIT(dev);

			L6360_ReadStart(dev);

			HAL_Delay(100);

//			L6360_UartCheckReceive(dev);
//			__HAL_UART_FLUSH_DRREGISTER()
			L6360_UartReceiveDataIT(dev);
			L6360_UartReceiveDataIT(dev);

			L6360_UartReceiveDataIT(dev);

//			memset(USB_txBuffer, '\0', sizeof(USB_txBuffer));
//			USB_txLength = sprintf((char*)USB_txBuffer, "\r\nINIT DEV %d DONE\r\n\n", dev);
//			CDC_Transmit_FS(USB_txBuffer, USB_txLength);

//			if(L6360_ReadState(dev) == HAL_OK)
//			{
//				HAL_Delay(50);
//				periodically_uart[dev] = 1;
//			}
		}
		else
		{
			L6360_Reset(0);
//			memset(USB_txBuffer, '\0', sizeof(USB_txBuffer));
//			USB_txLength = sprintf((char*)USB_txBuffer, "\rWake up dev %d WRONG\r\n", dev);
//			CDC_Transmit_FS(USB_txBuffer, USB_txLength);
		}

	}
	else
	{
		L6360_Reset(0);
//		memset(USB_txBuffer, '\0', sizeof(USB_txBuffer));
//		USB_txLength = sprintf((char*)USB_txBuffer, "\r\nPower up dev %d WRONG\r\n", dev);
//		CDC_Transmit_FS(USB_txBuffer, USB_txLength);
	}
}


void SIO_Init(uint8_t dev)
{
	L6360_Reset(0);
	L6360_SioInit(dev);
	L6360_PinEnableLPlus(dev);
//	memset(USB_txBuffer, '\0', sizeof(USB_txBuffer));
//	USB_txLength = sprintf((char*)USB_txBuffer, "\r\nRead SIO dev %d every 0.2s\r\n", dev);
//	CDC_Transmit_FS(USB_txBuffer, USB_txLength);
//	periodically_sio = dev + 10;

//	L6360_PinDisableLPlus(dev);
}

void L6360_Reset(uint8_t com)
{
	  periodically_i2c = 0;
	  periodically_sio = 0;
	  for(int i=0; i<4; i++)
	  {
		  periodically_uart[i] = 0;
		  L6360_PinDisableCQ(i);
		  L6360_PinDisableLPlus(i);
		  L6360_PinDisableReset(i);
		  HAL_Delay(100);
		  L6360_PinEnableReset(i);
		  if(com == 1)
		  {
			  memset(USB_txBuffer, '\0', sizeof(USB_txBuffer));
			  USB_txLength = sprintf((char*)USB_txBuffer, "\r\nReset dev %d\r\n", i);
			  CDC_Transmit_FS(USB_txBuffer, USB_txLength);
		  }

	  }
}

uint8_t IoLinkCalcChecksum(uint8_t m_type, uint8_t *pData, uint8_t data_length)
{
	// mc ^ all data ^ seed and second is checksum
	uint8_t seed = 0x52;
	uint8_t checksum8 = 0x00;
	uint8_t checksum6 = 0x00;

	checksum8 = seed;

	for (int i=0; i<data_length; i++)
	{
		checksum8 = checksum8 ^ pData[i];

	}
	uint8_t d7 = 0, d6 = 0;
	uint8_t d5 = ((checksum8 >> 7) & 0x01 ) ^ ((checksum8 >> 5) & 0x01 ) ^ ((checksum8 >> 3) & 0x01 ) ^ ((checksum8 >> 1) & 0x01 );
	uint8_t d4 = ((checksum8 >> 6) & 0x01 ) ^ ((checksum8 >> 4) & 0x01 ) ^ ((checksum8 >> 2) & 0x01 ) ^ ((checksum8 >> 0) & 0x01 );
	uint8_t d3 = ((checksum8 >> 7) & 0x01 ) ^ ((checksum8 >> 6) & 0x01 );
	uint8_t d2 = ((checksum8 >> 5) & 0x01 ) ^ ((checksum8 >> 4) & 0x01 );
	uint8_t d1 = ((checksum8 >> 3) & 0x01 ) ^ ((checksum8 >> 2) & 0x01 );
	uint8_t d0 = ((checksum8 >> 1) & 0x01 ) ^ ((checksum8 >> 0) & 0x01 );

	switch(m_type)
	{
		case 0: break;
		case 1: d6 = 1; d4 ^= 1; d3 ^= 1; break;
		case 2: d7 = 1; d5 ^= 1; d3 ^= 1; break;
		case 3: break;
		default: break;
	}
	checksum6 |= (d7 << 7) | (d6 << 6) | (d5 << 5) | (d4 << 4) | (d3 << 3) | (d2 << 2) | (d1 << 1) | (d0 << 0);

	return checksum6;
}

void IoLinkMSender(uint8_t *pData, uint8_t data_length, uint8_t calc_ch)
{
    uint8_t port = pData[7];
//    uint16_t frame_size = (pData[6] & 0xFF) | (pData[5] << 8);
    uint8_t frame_type = pData[4];
//    uint8_t direction = pData[3];


    uint8_t arr_send[data_length-8];
    for(int i=0; i<(data_length-8); i++)
    {
        arr_send[i] = pData[i+8];
        // printf("%x", arr_send[i]);
    }

    if(calc_ch == 1)
    {
        uint8_t checksum = IoLinkCalcChecksum(frame_type, arr_send, (data_length-8));
//        printf("%x \n", checksum);
        data_length += 1;
        for(int i = (data_length-8); i >= 2; i--)
        {
            arr_send[i] = arr_send[i - 1];
        }
        arr_send[1] = checksum;
    }



	L6360_PinEnableCQ(port);
    for(int i=0; i<(data_length-8); i++)
    {
    	L6360_UartSendData(port, arr_send[i]);
    }
	L6360_PinDisableCQ(port);

//	L6360_UartReceiveDataIT(port);


}
//
//uint8_t IoLinkMType0(uint8_t portId, uint8_t mc_data, uint8_t wr_data)
//{
//
//	uint8_t checksum = 0;
//	if (wr_data == 0)
//	{
//		checksum = IoLinkCalcChecksum(0, mc_data, 0);
//		L6360_UartSendData(portId, mc_data);
//		L6360_UartSendData(portId, checksum);
//		L6360_UartReceiveData(portId);
//		CDC_Transmit_FS(&uartRxBuffer[portId], 1);
//	}
//	else
//	{
//		checksum = IoLinkCalcChecksum(0, mc_data, wr_data);
//		L6360_UartSendData(portId, mc_data);
//		L6360_UartSendData(portId, checksum);
//		L6360_UartSendData(portId, wr_data);
//	}
//
//	L6360_UartReceiveData(portId);
//	CDC_Transmit_FS(&uartRxBuffer[portId], 1);
//
//
//	return 1;
//}

uint8_t IoLinkHeader(struct IO_LINK_SPE_HEADER* str1, uint8_t *pData, uint8_t dataLength)
{

	str1->HeaderVersion 			= pData[0];
	str1->HeaderSize 				= pData[1];
	str1->IO_LINK_ProtocolVersion 	= pData[2];
	str1->TransferDirection 		= pData[3];
	str1->IO_LINK_FrameType 		= pData[4];
	str1->IO_LINK_FrameSize0 		= pData[5];
	str1->IO_LINK_FrameSize1 		= pData[6];
	str1->PortNumber 				= pData[7];

	uint8_t calc_checksum = pData[0];

	if (dataLength < 8)
	{
		return 0;
	}

	switch(pData[4])
	{
		case L6360_RESET:
			L6360_Reset(1);
			*pData = 0;
			break;
		case POWER_UP:
			L6360_PowerUp(pData[7]);
			*pData = 0;
			break;
		case WAKE_UP:
			IO_LINK_Init(pData[7]);
			*pData = 0;
			break;
		case SIO:
			SIO_Init(pData[7]);
			*pData = 0;
			break;
		case TYPE_0:
//			TIMEOUT_RECEIVE = 2;
			if(pData[3] == READ)
			{
				if(dataLength != 9)
				{
					return 10;
				}
				else
				{
					IoLinkMSender(pData, dataLength, calc_checksum);
				}
			}
			else if(pData[3] == WRITE)
			{
				if(dataLength != 10)
				{
					return 10;
				}
				else
				{
					IoLinkMSender(pData, dataLength, calc_checksum);
				}
			}
			else
			{
				return 10;
			}

			break;
		case TYPE_1:
//			TIMEOUT_RECEIVE = 4;
			IoLinkMSender(pData, dataLength, calc_checksum);
			break;

		case TYPE_2:
//			TIMEOUT_RECEIVE = 4;
			IoLinkMSender(pData, dataLength, calc_checksum);
			break;
		default:
			return 0;
			break;
	}

	return 1;

}

