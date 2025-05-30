import matplotlib
matplotlib.use('TkAgg')
import os

import numpy as np
import matplotlib.pyplot as plt

def read_data_from_file(filename):
    x = []
    y = []
    with open(filename, 'r') as file:
        for line in file:
            data = line.strip().split()
            x.append(int(data[0]))
            y.append(int(data[2]))
    return np.array(x), np.array(y)

filename = 'log.txt'  
x, y = read_data_from_file(filename)

plt.scatter(x, y, marker='o', color='b', s=10)
plt.title('График результатов вычислений')  
plt.xlabel('Размер матрицы n*n') 
plt.ylabel('Время выполнения (нс)') 
plt.grid(True)  
plt.tight_layout()
plt.savefig(os.path.join('plot.png'), dpi=300)
plt.show()

