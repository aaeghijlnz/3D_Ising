import matplotlib.pyplot as plt
import numpy as np
import matplotlib.pyplot as plt

s1 = np.loadtxt('ele_dipole.txt')
plt.figure()
plt.title('The Change of Average Electric Dipole with Temperature')
plt.xlabel("T")
plt.ylabel("electric dipole")
my_x_ticks = np.arange(0,7.1,0.5)
plt.xticks(my_x_ticks)
plt.plot(s1[:,0],s1[:,1],color='black',linewidth=2,linestyle='-')
plt.savefig('Average_Electric_Dipole.png')
#plt.show()

s2 = np.loadtxt('ele_susc.txt')
plt.figure()
plt.title('The Change of Polarizability with Temperature')
plt.xlabel("T")
plt.ylabel("Polarizability")
my_x_ticks = np.arange(0,7.1,0.5)
plt.xticks(my_x_ticks)
plt.plot(s2[:,0],s2[:,1],color='black',linewidth=2,linestyle='-')
plt.savefig('Polarizability.png')
#plt.show()
