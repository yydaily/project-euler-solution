from random import random
from math import *

num = [[-4, 5], [-4, -5], [0, -1], [0, 1], [-3, 2], [-3, -2]]

v = []
for i in num:
    n, t = i[0], i[1]
    while abs(n) < 3197021343560:
        n, t = -9 * n - 4 * t - 14, -20 * n - 9 * t - 28
        if n > 0:
            v.append(n)
v.sort()
print(sum(v[:30]))
