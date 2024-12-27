# -*- coding: UTF-8 -*-
from random import random
from math import *

mod = 10**9 + 7

fac = [0] * (2 * 10**7 + 1)
fac_inv = [0] * (2 * 10**7 + 1)


def pow(x, y):
    ret = 1
    while y:
        if y & 1:
            ret = ret * x % mod
        x = x * x % mod
        y >>= 1
    return ret


def C(n, r):
    return fac[n] * fac_inv[r] % mod * fac_inv[n - r] % mod


def gcd(a, b):
    while b:
        a, b = b, a % b
    return a


def init():
    fac[0] = 1
    for i in range(1, 2 * 10**7 + 1):
        fac[i] = fac[i - 1] * i % mod
    fac_inv[2 * 10**7] = pow(fac[2 * 10**7], mod - 2)
    for i in range(2 * 10**7 - 1, -1, -1):
        fac_inv[i] = fac_inv[i + 1] * (i + 1) % mod


def gen(upper):
    ret = []
    n = 1
    while n * n * n * n < upper:
        m = n + 1
        while 4 * m * m * n * n <= upper:
            a = m * m - n * n
            b = 2 * m * n
            m += 1
            if gcd(a, b) != 1:
                continue

            u = min(upper // a // a, upper // b // b)
            base = 1
            while base * base <= u:
                ret.append([a * a * base * base, b * b * base * base])
                ret.append([b * b * base * base, a * a * base * base])
                base += 1

        n += 1
    ret.sort()
    return ret


def to(a, b):
    return C(a + b, a)


def P(n):
    poi = gen(n)
    ways = [0] * len(poi)
    ans = to(n, n)
    for i in range(len(poi)):
        ways[i] = to(poi[i][0], poi[i][1])
        for j in range(i):
            if poi[i][1] < poi[j][1]:
                continue
            ways[i] = (
                ways[i]
                - ways[j] * to(poi[i][0] - poi[j][0], poi[i][1] - poi[j][1]) % mod
                + mod
            ) % mod
        ans = (ans - ways[i] * to(n - poi[i][0], n - poi[i][1]) % mod + mod) % mod
    return ans


if __name__ == "__main__":
    init()
    print(P(5))
    print(P(16))
    print(P(1000))
    print(P(10**7))
