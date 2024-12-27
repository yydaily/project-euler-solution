from random import random
from math import *

mod = 10**9 + 7


def qpow(a, b):
    ret = 1
    while b > 0:
        if b % 2 == 1:
            ret = ret * a % mod
        a = a * a % mod
        b >>= 1
    return ret


upper = 10**7 + 10**6
fac, inv = [0] * upper, [0] * upper


def init():
    fac[0] = 1
    for i in range(1, upper):
        fac[i] = fac[i - 1] * i % mod
    inv[upper - 1] = qpow(fac[upper - 1], mod - 2)
    for i in range(upper - 2, -1, -1):
        inv[i] = inv[i + 1] * (i + 1) % mod


def C(a, b):
    return (fac[a] * inv[b]) % mod * inv[a - b] % mod


def G(a):
    x = sqrt(a)
    ans = 0
    i = 0
    while i * i < a:
        ans = (ans + C(int(i + a - i * x), i)) % mod
        i += 1
    return ans


if __name__ == "__main__":
    init()
    print(G(90))
    ans = 0
    for i in range(10000001, 10010000):
        is_prime = True
        j = 2
        while j * j <= i:
            if i % j == 0:
                is_prime = False
                break
            j += 1
        if is_prime:
            ans += G(i)
    print(ans % mod)
