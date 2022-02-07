from random import random
from math import *

upper = int(1e7)
val = [0 for i in range(upper)]


def get(a):
    if a < upper and val[a] > 0:
        return val[a]
    if a == 1:
        return 1
    b = a >> 1
    if (a & 1) > 0:
        b = a * 3 + 1
    v = get(b) + 1
    if a < upper:
        val[a] = v
    return v


if __name__ == "__main__":
    ans, ind = 0, 0
    for i in range(1, 1000000):
        v = get(i)
        if v > ans:
            ans = v
            ind = i
    print(ind)
