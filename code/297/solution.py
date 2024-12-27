from random import random
from math import *

num = []
m = {}


def cnt(a):
    if a <= 0:
        return 0
    if a in m:
        return m[a]
    for i in range(len(num) - 1, -1, -1):
        if a >= num[i]:
            m[a] = 1 + cnt(num[i] - 1) + cnt(a - num[i]) + a - num[i]
            return m[a]
    return 0


upper = 10**17
if __name__ == "__main__":
    a, b = 1, 1
    while b < upper:
        num.append(b)
        a, b = b, a + b
    print(cnt(upper - 1))
