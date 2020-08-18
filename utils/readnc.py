import numpy as np
from netCDF4 import Dataset

dataset = Dataset('average_mc_T_2.2.nc')
Temp=tuple(dataset.variables.keys())
print(Temp)
arr = dataset.variables[Temp[0]][0]
print(arr)
for av_steps in arr[-1:]:
	print("3")
a = len(dataset.dimensions['steps'])
print(a)




np.savetxt("dd_mat2.txt",arr)

