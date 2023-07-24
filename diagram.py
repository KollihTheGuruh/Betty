import matplotlib.pyplot as plt
import numpy as np

def f(t):
      return np.sin(t)

t = np.linspace(0, 2 * np.pi, 100)
y = np.zeros(len(t))

for i in range(1, len(t)):
        y[i] = y[i-1] + (f(t[i]) - 5 * np.sin(y[i-1])) * (t[i] - t[i-1]) / 3

        plt.plot(t, y)
        plt.xlabel('t')
        plt.ylabel('y')
        plt.title('Simulation Diagram')
        plt.show()

