from random import random
from math import *

a, b = 1, 1
for i in range(3, 10000):
    a, b = b, a + b
    if b >= 10**999:
        print(i)
        break
