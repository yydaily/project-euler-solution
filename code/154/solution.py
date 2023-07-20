# -*- coding: UTF-8 -*-
from random import random
from math import *

len = int(2e5 + 10)
fac2 = [0 for i in range(len)]
fac5 = [0 for i in range(len)]


def cal(a, base):
    ret = 0
    while a % base == 0:
        a //= base
        ret += 1
    return ret


def init():
    for i in range(2, len):
        fac2[i] = fac2[i - 1] + cal(i, 2)
        fac5[i] = fac5[i - 1] + cal(i, 5)


def C(a, b, fac):
    return fac[a] - fac[b] - fac[a - b]


def solve(upper, need2, need5):
    ans = 0
    for i in range(0, upper + 1):
        cnt2 = C(upper, i, fac2)
        cnt5 = C(upper, i, fac5)
        for j in range(0, upper - i + 1):
            if (
                cnt2 + C(upper - i, j, fac2) >= need2
                and cnt5 + C(upper - i, j, fac5) >= need5
            ):
                ans += 1
    return ans


if __name__ == "__main__":
    print(solve(200000, 12, 12))
