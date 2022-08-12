from random import random
from math import *


def check(a):
    b = sqrt(a)
    return b * b == a


def start(a):
    if a == 1:
        return 1
    ret = 2 * (a // 2) * (a // 2)
    if a % 2 == 1:
        ret += 2 * (a // 2)
    return ret


def nxt(a):
    b = int(sqrt(2 * a))
    while b * b - a <= a:
        b += 1
    return b * b - a


def cal(r, c):
    a0 = start(r)
    a1 = nxt(a0)
    b = int(sqrt(a1 + a0))
    c -= 1
    x = c // 2
    ret = a0 + x * (2 * b + 2 * x - 1)
    if c % 2 == 1:
        ret = nxt(ret)
    return ret


def ans(a, b):
    upper = 1
    for i in range(a):
        upper *= 2
    for i in range(b):
        upper *= 3

    rans = 0
    x = 1
    for i in range(a + 1):
        y = x
        for j in range(b + 1):
            rans += cal(y, upper // y)
            y *= 3
        x *= 2
    return rans


print(ans(27, 12) % (10 ** 8))
