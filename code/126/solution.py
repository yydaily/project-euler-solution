from random import random
from math import *


def gen(a, b, c, layer):
    return 2 * a * b + 2 * b * c + 2 * a * c + 4 * (layer - 1) * (a + b + c + layer - 2)


upper = 20000
cnt = [0] * upper

i = 1
while gen(i, i + 1, i + 2, 1) < upper:
    j = i
    while gen(i, j, j + 1, 1) < upper:
        k = j
        while gen(i, j, k, 1) < upper:
            layer = 1
            while gen(i, j, k, layer) < upper:
                cnt[gen(i, j, k, layer)] += 1
                layer += 1
            k += 1
        j += 1
    i += 1

for i in range(1, upper):
    if cnt[i] == 1000:
        print(i)
        break
