import numpy as np
from netCDF4 import Dataset
import os
import matplotlib.pyplot as plt

#find all ncfiles in this dir
def ncfiles():
	L=[]
	for root,dirs,files in os.walk("."):
		for file in files:
			if os.path.splitext(file)[1]=='.nc':
				L.append(os.path.join(root,file))
	return L

print("There are all the ncfiles:")
#print(ncfiles())

data = np.empty(shape=[0,3])										#1_d 1*3

for file in ncfiles():
	dataset = Dataset(file) 
	Temp=tuple(dataset.variables.keys())     					#TEMP is The name of the variable
#	all_steps = len(dataset.dimensions['steps'])				#all_steps
	av_sum = 0
	av2_sum = 0
	arr = dataset.variables[Temp[0]][0]							#The 1d_values of the variable
	for av_steps in arr[-1000:]:									#The last 1000
		av_sum += av_steps
		av2_sum += av_steps * av_steps
	av_P = av_sum / float(1000)
	av_P2 = av2_sum / float(1000)
	av_X = (av_P2 - av_P * av_P) / float(Temp[0])
	data=np.append(data,[[float(Temp[0]),av_P,av_X]],axis=0)
data=data[np.lexsort(data[:,::-1].T)]							#in numerical order
print(data)

Tmax=data[-1,0]
Tmin=data[1,0]
plt.figure()
plt.title('The Change of Average Electric Dipole with Temperature')
plt.xlabel("T")
plt.ylabel("electric dipole")
my_x_ticks = np.arange(Tmin,Tmax)
plt.xticks(my_x_ticks)
plt.plot(data[:,0],abs(data[:,1]),color='black',linewidth=2,linestyle='-')
plt.savefig('Average_Electric_Dipole.png')
#plt.show()


plt.figure()
plt.title('The Change of Polarizability with Temperature')
plt.xlabel("T")
plt.ylabel("Polarizability")
my_x_ticks =np.arange(Tmin,Tmax)
plt.xticks(my_x_ticks)
plt.plot(data[:,0],data[:,2],color='black',linewidth=2,linestyle='-')
plt.savefig('Polarizability.png')
#plt.show()
