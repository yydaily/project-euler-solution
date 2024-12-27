# -*- coding: UTF-8 -*-
from random import random
from math import *

mod = 10**9 + 7

fac = [0] * (111 * 10**6 + 100)
fac_inv = [0] * (111 * 10**6 + 100)


def mypow(x, n):
    res = 1
    while n:
        if n & 1:
            res = res * x % mod
        x = x * x % mod
        n >>= 1
    return res


def init():
    fac[0] = 1
    for i in range(1, len(fac)):
        fac[i] = fac[i - 1] * i % mod
    fac_inv[len(fac) - 1] = mypow(fac[len(fac) - 1], mod - 2)
    for i in range(len(fac) - 2, -1, -1):
        fac_inv[i] = fac_inv[i + 1] * (i + 1) % mod


def C(n, m):
    if n < m:
        return 0
    return fac[n] * fac_inv[m] % mod * fac_inv[n - m] % mod


def cal(n, m):
    return C(n + m - 1, m - 1)


def W(a, b, c):
    ans = 0
    for i in range(1, a + 1):
        base1 = C(b - 1, i)
        base1 = (base1 * C(a - 1, i - 1)) % mod
        ans = (ans + cal(c - 2 * i * 2, a + b + 1) * base1) % mod

        base2 = C(b - 1, i - 1) * 2 % mod
        base2 = (base2 * C(a - 1, i - 1)) % mod
        ans = (ans + cal(c - (2 * i - 1) * 2, a + b + 1) * base2) % mod

        if i == 1:
            continue

        base3 = C(b - 1, i - 2) % mod
        base3 = (base3 * C(a - 1, i - 1)) % mod
        ans = (ans + cal(c - (2 * i - 2) * 2, a + b + 1) * base3) % mod

    return ans


if __name__ == "__main__":
    init()
    print(W(2, 2, 4))
    print(W(4, 4, 44))
    print(W(10**6, 10**7, 10**8))
