import matplotlib.pyplot as plt
import plotly.plotly as py
import plotly.graph_objs as go
import numpy as np
import re
import math
import os

while True:
    # py.sign_in('segerpeter07', os.environ.get('PLOTLY_API_KEY'))

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
    # trace0 = go.Scatter(
    #     x = time,
    #     y = ir_left,
    #     mode = 'lines',
    #     name = 'IR-Left'
    # )
    # trace1 = go.Scatter(
    #     x = time,
    #     y = ir_right,
    #     mode = 'lines',
    #     name = 'IR-Right'
    # )
    # trace2 = go.Scatter(
    #     x = time,
    #     y = drive_l,
    #     mode = 'lines',
    #     name = 'Motor-Left'
    # )
    # trace3 = go.Scatter(
    #     x = time,
    #     y = drive_r,
    #     mode = 'lines',
    #     name = 'Motor-Right'
    # )
    #
    # plots = [trace0, trace1, trace2, trace3]
    #
    # py.image.save_as(plots, filename='line-mode.png')
    # py.iplot(data, filename='line-mode')
