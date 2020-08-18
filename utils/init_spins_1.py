import numpy as np
file_handle = open("cfj.txt",mode="w")
for i in range(8000):
    file_handle.write('1\r')
file_handle.close()
