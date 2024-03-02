# -*- coding: UTF-8 -*-
from random import random
from math import *


def power(a, b, mod):
    res = 1
    while b:
        if b & 1:
            res = res * a % mod
        a = a * a % mod
        b >>= 1
    return res


mod = 815730721
mod2 = 752982204
mod3 = 231686832
mod4 = 71288256
mod5 = 21934848
mod6 = 6749184


def C(n, mod, mod2):
    a = power(2, power(3, n - 2, mod2), mod)
    b = power(3, (power(3, n - 3, mod2) - 1) // 2 * 3, mod)
    return a * b % mod


def C3(n):
    a = C(n, mod5, mod6)
    b = C(a, mod3, mod4)
    return C(b, mod, mod2)


print(C(10000, mod, mod2))
print(C3(10000))
