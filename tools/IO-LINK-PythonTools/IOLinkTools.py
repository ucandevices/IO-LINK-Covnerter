import serial
import math
import time
import threading
import logging

logger = logging.getLogger()

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
    FrameType = 0
    FrameData = bytearray()
    

class IOLink:
    IO_LINK_HEADER_SIZE_BYTES = 8
    def __def_frame_rx_handler(self,f):
        pass

    def __def_new_frame_rx_handler(self,f):
        pass
    def __init__(self, com, rx_handler):
        self.ser = serial.Serial(com,timeout=0.02)
        if (self.ser == None):
            raise NameError('SerialPortNotPresent') 
        self.ser.reset_output_buffer()
        self.ser.reset_input_buffer()
        
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
            while(self.ser.in_waiting > 0):                
                cc = self.ser.read(self.ser.in_waiting)
                self.uart_buffer.extend(cc)  
                no_data_counter = 0
            no_data_counter = no_data_counter + 1                                                
            time.sleep(0.001)
            #there is data in buffer and no new data was reviced for 3 ms
            if ((len(self.uart_buffer) >= self.IO_LINK_HEADER_SIZE_BYTES) & (no_data_counter > 3)):
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
        self.lf.FrameType = self.uart_buffer[4]
        self.lf.FrameData = self.uart_buffer[self.IO_LINK_HEADER_SIZE_BYTES:len(self.uart_buffer)]
        self.uart_buffer = bytearray()
        self.newframe_handler(self.lf)

    def sendData(self, data):
        self.ser.write(data)
        logger.info(data)

    def deInitSerial(self):
        self.ser.flush() 
        self.ser.close()
        del self.ser

    def __del__(self):
        """Stop reception"""
        if (self.__rx_byte_thread_handler.is_alive()):
            self._stop_event.set()
            self.__rx_byte_thread_handler.join()
        self.deInitSerial()