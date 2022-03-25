from random import random
from math import *

v = []
k, l = 0, 1
for i in range(14):
    k, l = -9 * k - 4 * l - 4, -20 * k - 9 * l - 8
    if l > 0:
        v.append(l)

k, l = 0, -1
for i in range(14):
    k, l = -9 * k - 4 * l + 4, -20 * k - 9 * l + 8
    if l > 0:
        v.append(l)

v.sort()
print(sum(v[i] for i in range(12)))
