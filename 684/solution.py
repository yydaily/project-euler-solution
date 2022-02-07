from random import random
from math import *

mod = int(1e9 + 7)


def add(*params):
    ret = 0
    for i in params:
        ret = (ret + i) % mod
        ret = (ret + mod) % mod
    return ret


def mul(*params):
    ret = 1
    for i in params:
        ret = (ret * i) % mod
        ret = (ret + mod) % mod
    return ret


def qpow(a, b):
    ret = 1
    while b > 0:
        if (b & 1) > 0:
            ret = mul(ret, a)
        a = mul(a, a)
        b >>= 1
    return ret


def cal(n):
    inv_81 = qpow(81, mod - 2)
    base = mul(9, n, qpow(10, n))
    base = add(base, -qpow(10, n), 1)
    return mul(base, inv_81)


def S(a):
    cnt = a // 9
    m = a - cnt * 9
    inv_9 = qpow(9, mod - 2)
    inv_2 = qpow(2, mod - 2)

    x = mul(add(qpow(10, cnt), -1), inv_9)
    ans = mul(45, x)
    return add(
        mul(45, x),
        mul(a, 9, x),
        -mul(81, cal(cnt)),
        mul(m, m + 1, inv_2, qpow(10, cnt)),
    )


if __name__ == "__main__":
    a, b = 1, 1
    ans = 0
    for i in range(2, 91):
        ans = add(ans, S(b))
        a, b = b, a + b
    print(ans)
