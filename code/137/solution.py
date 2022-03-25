from random import random
from math import *

a, b = 1, 2
for i in range(15):
    print(i + 1, a * b)
    a, b = b, a + b
    a, b = b, a + b
