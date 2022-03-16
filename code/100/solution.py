from random import random
from math import *

def gen(a, b):
	return -3*a -4*b + 3, -2*a -3*b + 2

a, b, va, vb = 0, 0, 0, 0
while vb < 1e12:
	a, b = gen(a, b)
	if a < 0:
		va = 1-a
		vb = 1-b*2
	else:
		va = a
		vb = b*2
	print(va, vb)
