from serial import Serial, SerialException
import time

cxn = Serial("/dev/ttyACM0", baudrate=9600)

while True:
    cmd = input("Select your Speed (0-10): ")

    if cmd == 'exit':
        cxn.close()
        exit()
    else:
        cxn.write(cmd)
    #
    #     out = ''
    #
    #     while cxn.inWaiting() > 0:
    #         out += cxn.read(1)
    #
    #     if out != '':
    #         print(out)
