from random import random
from math import *

upper = int(2e7 + 10)
p = [True for i in range(upper)]
minn = [0 for i in range(upper)]


def init():
    for i in range(2, upper):
        if p[i]:
            for j in range(i, upper, i):
                p[j] = False
                minn[j] = i
        minn[i] = minn[i / minn[i]] + minn[i]


if __name__ == "__main__":
    init()
    lower = 15000000
    upper = 20000000
    ans = 0
    for i in range(1, upper - lower + 1):
        ans += minn[lower + i] - minn[i]
    print(ans)
