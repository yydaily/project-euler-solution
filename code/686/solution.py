from random import random
from math import *

a = 1.0
ind, cnt = 0, 0

while cnt < 678910:
    a *= 2
    ind += 1
    if a > 10:
        a /= 10.0
    if 1.23 <= a and a < 1.24:
        cnt += 1

print(ind)
