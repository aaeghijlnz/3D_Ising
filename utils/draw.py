import matplotlib.pyplot as plt
import numpy as np
s1 = np.loadtxt('ele_dipole.txt')
plt.figure()
plt.plot(s1)
plt.savefig('1.png')
plt.show()
s2 = np.loadtxt('ele_susc.txt')
plt.figure()
plt.plot(s2)
plt.savefig('2.png')
plt.show()
