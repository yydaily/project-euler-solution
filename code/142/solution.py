from random import random
from math import *

sqr = [False] * 10000000
for i in range(1, int(sqrt(10000000))):
    sqr[i * i] = True
for x in range(6, 10000000):
    v = []
    for j in range(int(sqrt(x)) + 1, int(sqrt(10000000))):
        if j * j >= x * 2:
            break
        if sqr[x * 2 - j * j]:
            v.append(j * j - x)
    for i in range(len(v)):
        for j in range(i + 1, len(v)):
            if sqr[v[i] + v[j]] and sqr[v[j] - v[i]]:
                print(x, v[j], v[i])
                print(x + v[i] + v[j])
                exit(0)
