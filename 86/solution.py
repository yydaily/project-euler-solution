from random import random
from math import *

sqr = {}


def init(m):
    for i in range(1, m + 1):
        sqr[i * i] = i


def cal(a, b_and_c):
    lower = b_and_c / 2 + b_and_c % 2
    upper = min(b_and_c - 1, a)
    return max(0, upper - lower + 1)


def count(a):
    ret = 0
    for b_and_c in range(1, a << 1 | 1):
        if a * a + b_and_c * b_and_c in sqr:
            ret += cal(a, b_and_c)
    return ret


if __name__ == "__main__":
    init(10000)
    ans = 0
    for i in range(1, 10000):
        ans += count(i)
        if ans >= 1000000:
            print(i)
            break
