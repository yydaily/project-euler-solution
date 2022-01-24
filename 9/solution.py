from random import random
from math import *

for i in range(3, 500):
	for j in range(i+1, 500):
		k = sqrt(i*i+j*j)
		if k == int(k) and i+j+k==1000:
			print(i*j*int(k))
