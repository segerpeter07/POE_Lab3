import matplotlib.pyplot as plt
import re

while True:

    time = []
    ir_left = []
    ir_right = []
    drive_l = []
    drive_r = []

    cur_time = 0

    file = open('data', 'r')
    for line in file:
        data = re.findall('\d+', line)
        time.append(cur_time)
        ir_left.append(data[0])
        ir_right.append(data[1])
        drive_l.append(data[2])
        drive_r.append(data[3])
        cur_time += 1

    plt.subplot(2, 1, 1)
    plt.title("IR Sensor Data and Drive Data")
    plt.plot(time,ir_left)

    plt.subplot(2, 1, 2)
    plt.plot(time,drive_l)

    plt.subplot(2, 1, 1)
    plt.plot(time,ir_right)

    plt.subplot(2, 1, 2)
    plt.plot(time, drive_r)

    plt.show()
