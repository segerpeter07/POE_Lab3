import matplotlib.pyplot as plt
import plotly.plotly as py
import numpy as np
import re
import math

while True:
    ir_left = []
    ir_right = []
    drive_l = []
    drive_r = []

    file = open('data', 'r')
    for line in file:
        data = re.findall('\d+', line)
        ir_left.append(data[0])
        ir_right.append(data[1])
        drive_l.append(data[2])
        drive_r.append(data[3])
    
