# -*- coding: UTF-8 -*-
from random import random
from math import *

e9 = int(1e9)

a = [0] * 10


def qpow(a, b):
    ret = 1
    while b > 0:
        if (b & 1) > 0:
            ret = (ret * a) % e9
        a = (a * a) % e9
        b //= 2
    return ret


def G(n):
    a[0] = 0
    while n > 0:
        a[0] += 1
        a[a[0]] = n & 1
        n //= 2
    ans = 0
    while True:
        if a[1] > 0:
            ans = (ans + a[1]) % e9
            a[1] = 0
            continue
        if a[2] > 0:
            a[2] -= 1
            ans = (2 * ans + 3) % e9
            continue
        if a[3] > 0:
            a[3] -= 1
            ans = (ans + (qpow(2, ans + 3) - 1) * (ans + 3)) % e9
            continue
        if a[4] > 0:
            a[4] -= 1
            a[1], a[2], a[3] = ans + 2, ans + 2, ans + 2
            ans += 1
            continue
        break
    return ans


ans = 0
for i in range(1, 16):
    ans += G(i)
print(ans % e9)
