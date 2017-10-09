from serial import Serial, SerialException
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
import plotly.plotly as py
import math
import re

cxn = Serial("/dev/ttyACM1", baudrate=9600)
ir_list = []

fig = plt.figure()
ax = fig.add_subplot(111)

while True:
    result = str(cxn.readline())
    results = re.findall('\d+', result)
    if(len(results) == 2):
        data = results[0]
        flag = results[1]
        print(flag)
        if(flag == '1'):
            ir_data = results[0]
            ir_list.append(ir_data)
        elif(flag == '2'):
            x = list(range(0,len(ir_list)))
            ax.plot(x ,ir_list)

            ax.set_xlabel('X Label')
            ax.set_ylabel('Y Label')

            plt.show()
