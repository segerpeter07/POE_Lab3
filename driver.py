from serial import Serial, SerialException
import time

cxn = Serial("/dev/ttyACM0", baudrate=9600)
time.sleep(2)

while True:
    cmd = input("Select your Speed (0-10): ")


    if cmd == 'exit':
        cxn.write(0)
        cxn.close()
        exit()
    else:
        cmd = int(cmd)
        cxn.write([cmd])
        print 'Python: ' + str(cmd)

        while cxn.inWaiting() < 1:
            pass
        print "Arduino: " + cxn.readline()

        # if out != '':
        #     print(out)
