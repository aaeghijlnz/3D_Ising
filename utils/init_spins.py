import numpy as np
import random
array=(1,1)
#array=(1,1)
file_handle = open("cfj.txt",mode="w")
for i in range(8000):
    file_handle.write("%d\r" % array[random.randint(0,1)])
file_handle.close()
