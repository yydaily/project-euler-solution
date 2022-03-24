from random import random
from math import *
import sys

sys.setrecursionlimit(2000)

mod = int(1e8)


def mul(a, b):
    return a * b % mod


def qpow(a, b):
    ret = 1
    while b > 0:
        if (b & 1) == 1:
            ret = mul(ret, a)
        a = mul(a, a)
        b >>= 1
    return ret


def cal(a, b):
    if b == 1:
        return a
    return qpow(a, cal(a, b - 1))


print(cal(3, 2))
print(cal(3, 3))
print(cal(3, 4))
print(cal(1777, 1855))
