from IOLinkTools import IOLink, IOLinkFrame
import time

def newframe_handler(io_link_frame):
    print("new data rx")
    print(io_link_frame.FrameType)
    print(io_link_frame.FrameData)



iolink = IOLink('/dev/ttyS2',newframe_handler)
iolink.sendData((b'\x01\x00\x00\x01\x0A\x00\x00\x00'))

time.sleep(2)

input("Press Enter to continue...")