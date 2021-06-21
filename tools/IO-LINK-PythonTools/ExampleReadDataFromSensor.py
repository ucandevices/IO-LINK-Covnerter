from IOLinkTools import IOLink, IOLinkFrame
import time

def newframe_handler(io_link_frame):
    print("new data rx", end=' ')
    print(io_link_frame.FrameData.hex(), end='\n')


iolink = IOLink('COM43',newframe_handler)

iolink.sendData((b'\x01\x00\x00\x01\x0C\x00\x00\x00')) #WAKEUP
time.sleep(2)

## read device name
iolink.sendData((b'\x01\x00\x00\x01\x01\x00\x00\x00\x70\x93\x10\x83\x00\x00\x00\x00\x00')) #  request read from 0x10 (Name of device)  
time.sleep(0.5)
iolink.sendData((b'\x01\x00\x00\x01\x01\x00\x00\x00\xF0')) #request of data read 
time.sleep(0.5)
iolink.sendData((b'\x01\x00\x00\x01\x01\x00\x00\x00\xF0')) #request of data read 
time.sleep(0.5)
iolink.sendData((b'\x01\x00\x00\x01\x01\x00\x00\x00\xE1')) #request of data read 
time.sleep(0.5)
iolink.sendData((b'\x01\x00\x00\x01\x01\x00\x00\x00\xE2')) #request of data read 
time.sleep(0.5)
iolink.sendData((b'\x01\x00\x00\x01\x01\x00\x00\x00\xF1')) #request of data read end
time.sleep(0.5)


## read cyclic data
iolink.sendData((b'\x01\x00\x00\x01\x01\x00\x00\x00\x20\x99\x00\x00\x00\x00\x00\x00\x00')) #request read cyclic data, device state
time.sleep(0.5)
while True:
    iolink.sendData((b'\x01\x00\x00\x01\x02\x00\x00\x00\xF1'))
    time.sleep(0.5)

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