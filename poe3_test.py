from serial import Serial, SerialException
# Import the necessary packages and modules
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
import plotly.plotly as py
import math
import re

# NOTE: You won't be able to program your Arduino or run the Serial
# Monitor while the Python script is running.
cxn = Serial("/dev/ttyACM0", baudrate=9600)
ir_list = []

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
while True:
    result = str(cxn.readline());
    #result comes in the form distance value, angle top servo, angle bottom servo
    #print(result)
    results = re.findall('\d+', result)
    print(results)
    sign = int(results[1])

    if sign == 1:
        ir_data = results[0]
        ir_list.append(ir_data)
    else:
        ax.plot(ir_list)

        ax.set_xlabel('X Label')
        ax.set_ylabel('Y Label')

        plt.show()
