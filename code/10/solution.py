from random import random
from math import *

upper = 2000000
p = [False] * upper

sum = 0
for i in range(2, upper):
    if p[i]:
        continue
    sum += i
    for j in range(i << 1, upper, i):
        p[j] = True

print(sum)
