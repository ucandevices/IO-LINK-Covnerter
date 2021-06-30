import serial
import math
import time
import threading
import logging
from enum import Enum

logger = logging.getLogger()

class IO_PORT_NUMBER(Enum):
    PORT_0 = 0
    PORT_1 = 1
    PORT_2 = 2
    PORT_3 = 3

class IO_FRAME_TYPE(Enum): 
    TYPE_0 = 0
    TYPE_1 = 1
    TYPE_2 = 2 
    L6360_RESET = 10
    POWER_UP = 11
    WAKE_UP = 12 
    SIO = 13
class IOLinkFrame:
    """IO-LINK SPE Kindoff packet.

    Attributes
    ----------
    IO_LINK_FrameType: uint8_t
        cast from enum ? TYPE_0, TYPE_1_1, TYPE_1_2, and TYPE_2_1 1541 through TYPE_2_5 + extra WAKEUP
        enum IO_FRAME {TYPE_0 = 0, TYPE_1, TYPE_2 L6360_RESET = 10, POWER_UP, WAKE_UP, SIO};
    data: bytearray
        frame data as byte array
    """
    PortNumber = IO_PORT_NUMBER.PORT_0
    FrameType = IO_FRAME_TYPE.TYPE_0
    FrameData = bytearray()
    FrameLen = 0


class IOLink:


    IO_LINK_HEADER_SIZE_BYTES = 8

    def __def_frame_rx_handler(self, f):
        pass

    def __def_new_frame_rx_handler(self, f):
        pass

    def __init__(self, com, rx_handler, autochecksumCalculation):
        self.ser = serial.Serial(com, timeout=2)
        if (self.ser == None):
            raise NameError('SerialPortNotPresent')
        self.ser.reset_output_buffer()
        self.ser.reset_input_buffer()
        self.autochecksumCalculation = autochecksumCalculation
        self.__rx_byte_thread_handler = threading.Thread(target=self.__rxThread, args=())
        self.uart_buffer = bytearray()
        self._stop_event = threading.Event()
        self.frame_rx_handler = self.__def_frame_rx_handler
        self.newframe_handler = rx_handler
        self.lf = IOLinkFrame()

        self.__rx_byte_thread_handler.start()

    def __rxThread(self):
        no_data_counter = 0
        while True:
            if (self._stop_event.is_set()):
                break
            while (self.ser.in_waiting > 0):
                cc = self.ser.read(self.ser.in_waiting)
                self.uart_buffer.extend(cc)
                no_data_counter = 0
            no_data_counter = no_data_counter + 1
            time.sleep(0.01)
            # there is data in buffer and no new data was reviced for 3 ms
            if ((len(self.uart_buffer) >= 64)):
                self.__newFrameProcess()

    def __newFrameProcess(self):
        # Parsing form"
        # typedef struct {
        #     uint8_t HeaderVersion; // 0
        #     uint8_t HeaderSize; // size in bytes fixed 8
        #     uint8_t IO_LINK_ProtocolVersion; // 0
        #     uint8_t TransferDirection; // cast from enum ? in / out
        #     uint8_t IO_LINK_FrameType; // cast from enum ? TYPE_0, TYPE_1_1, TYPE_1_2, and TYPE_2_1 1541 through TYPE_2_5 + extra WAKEUP
        #     uint16_t IO_LINK_FrameSize; // IO LINK Frame Size in bytes
        #     uint8_t PortNumber; //for UCAN 0-3 IO LINK PORT
        # } IO_LINK_SPE_HEADER;
        #
        self.lf.FrameType = IO_FRAME_TYPE(self.uart_buffer[4])
        self.lf.FrameLen = self.uart_buffer[6]
        self.lf.PortNumber = IO_PORT_NUMBER(self.uart_buffer[7])
        self.lf.FrameData = self.uart_buffer[self.IO_LINK_HEADER_SIZE_BYTES:len(self.uart_buffer)]
        # self.lf.FrameData = self.uart_buffer[0:len(self.uart_buffer)]
        self.uart_buffer = bytearray()
        self.newframe_handler(self.lf)

    def sendData(self, portNo, FrameType,data):
        #construct IO_LINK_MASTER header
        header = bytearray(8)
        header[0] = self.autochecksumCalculation #HeaderVersion; // Currently calculate CRC on embedded "1" or CRC is send in request "0"
        header[1] = 0 # // size in bytes fixed 8
        header[2] = 0 # // 0
        header[3] = 1 # // cast from enum ? in / out
        header[4] = FrameType.value # //cast from enum ? TYPE_0, TYPE_1_1, TYPE_1_2, and TYPE_2_1 1541 through TYPE_2_5 + extra WAKEUP
        header[5] = 0 # // IO LINK Frame Size in bytes
        header[6] = 0 # // IO LINK Frame Size in bytes
        header[7] = portNo.value #//for UCAN 0-3 IO LINK PORT
    
        header.extend(data)
        self.ser.write(header)
        logger.info(header)

    def deInitSerial(self):
        if (self.__rx_byte_thread_handler.is_alive()):
            self._stop_event.set()
            self.__rx_byte_thread_handler.join()
     
    def __del__(self):
        self.deInitSerial()
        self.ser.flush()
        self.ser.close()
        del self.ser
