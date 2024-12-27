# -*- coding: UTF-8 -*-
sqrt_5 = -1
mod = 0


def init(m):
    global mod, sqrt_5
    mod = m
    for i in range(1, m):
        if i * i % m == 5:
            sqrt_5 = i
            return


def qpow(a, b):
    a = (a % mod + mod) % mod
    ret = 1
    while b > 0:
        if (b & 1) > 0:
            ret = ret * a % mod
        a = a * a % mod
        b >>= 1
    return ret


def Q(a, m):
    init(m)
    pow4 = qpow(4, a)
    l = qpow(1 + sqrt_5, a - 1)
    r = qpow(1 - sqrt_5, a - 1)

    lret = l * qpow(pow4 - (1 + sqrt_5) * l % mod, mod - 2) % mod
    rret = r * qpow(pow4 - (1 - sqrt_5) * r % mod, mod - 2) % mod

    ans = (lret - rret) * 2 * qpow(sqrt_5, mod - 2)

    return (ans % mod + mod) % mod


print(Q(2, 109))
print(Q(3, 109))
print(Q(10**18, 10**9 + 9))
