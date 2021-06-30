from IOLinkTools import IOLink, IOLinkFrame, IO_PORT_NUMBER, IO_FRAME_TYPE

import time

def newframe_handler(io_link_frame):
    print("IO_LINK > ", end=' ')
    print(io_link_frame.PortNumber.name + ": " + io_link_frame.FrameType.name + " | " + io_link_frame.FrameData.hex(), end='\n')


iolink = IOLink('COM43',newframe_handler, 1)

iolink.sendData(IO_PORT_NUMBER.PORT_0, IO_FRAME_TYPE.WAKE_UP, (b'')) #WAKEUP
time.sleep(2)

## read device name
iolink.sendData(IO_PORT_NUMBER.PORT_0, IO_FRAME_TYPE.TYPE_1,(b'\x70\x93\x10\x83')) #  request read from 0x10 (Name of device)  
time.sleep(0.5)
iolink.sendData(IO_PORT_NUMBER.PORT_0, IO_FRAME_TYPE.TYPE_1,(b'\xF0')) #request of data read ISDU Read Start
time.sleep(0.5)
iolink.sendData(IO_PORT_NUMBER.PORT_0, IO_FRAME_TYPE.TYPE_1,(b'\xF0')) #request of data read ISDU Read Start
time.sleep(0.5)
iolink.sendData(IO_PORT_NUMBER.PORT_0, IO_FRAME_TYPE.TYPE_1,(b'\xE1')) #request of data read ISDU Read Count 1
time.sleep(0.5)
iolink.sendData(IO_PORT_NUMBER.PORT_0, IO_FRAME_TYPE.TYPE_1,(b'\xE2')) #request of data read ISDU Read Count 1
time.sleep(0.5)
iolink.sendData(IO_PORT_NUMBER.PORT_0, IO_FRAME_TYPE.TYPE_1,(b'\xF1')) #request of data read end ISDU Abort
time.sleep(0.5)


## read cyclic data
iolink.sendData(IO_PORT_NUMBER.PORT_0, IO_FRAME_TYPE.TYPE_1,(b'\x20\x99')) #request read cyclic data, device state
time.sleep(0.5)
for x in range(15):

    iolink.sendData(IO_PORT_NUMBER.PORT_0, IO_FRAME_TYPE.TYPE_2,(b'\xF1'))
    time.sleep(0.5)

iolink.deInitSerial()

print("end")
## end

# input("Press Enter to continue...")

# * czujnik gavazzi - numer urzadzenia *
# 0x01 0x00 0x00 0x01 0x00 0x00 0x00 0x00 0x70 0x93 
# 0x01 0x00 0x00 0x01 0x00 0x00 0x00 0x00 0x61 0x15
# 0x01 0x00 0x00 0x01 0x00 0x00 0x00 0x00 0x62 0x86
# 0x01 0x00 0x00 0x01 0x00 0x00 0x00 0x00 0xF0
# 0x01 0x00 0x00 0x01 0x00 0x00 0x00 0x00 0xE1
# 0x01 0x00 0x00 0x01 0x00 0x00 0x00 0x00 0xE2
# ...
# 0x01 0x00 0x00 0x01 0x00 0x00 0x00 0x00 0xEE
# 0x01 0x00 0x00 0x01 0x00 0x00 0x00 0x00 0xF1 
# # czujnik gavazzi - numer urzadzenia #

# * czujnik gavazzi - wywołanie danych cyklicznych (czujnik zblizeniowy) *
# 0x01 0x00 0x00 0x01 0x00 0x00 0x00 0x00 0x20 0x99 
# # czujnik gavazzi - wywołanie danych cyklicznych (czujnik zblizeniowy) #

# *** M TYPE 2 ***
# * rzadanie odczytu danych cyklicznych *
# 0x01 0x00 0x00 0x01 0x02 0x00 0x00 0x00 0xF1