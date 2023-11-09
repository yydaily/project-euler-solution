# -*- coding: UTF-8 -*-
from random import random

mod = 989898989
fac = [0 for i in range(1000000)]
inv_fac = [0 for i in range(1000000)]

fac[0] = 1
for i in range(1, 1000000):
    fac[i] = fac[i - 1] * i % mod
inv_fac[1000000 - 1] = pow(fac[1000000 - 1], mod - 2, mod)
for i in range(1000000 - 2, -1, -1):
    inv_fac[i] = inv_fac[i + 1] * (i + 1) % mod


def C(n, k):
    return fac[n] * inv_fac[k] * inv_fac[n - k] % mod


def F(n):
    ans = 0
    for i in range(n + 1):
        for j in range(n - i + 1):
            x = abs(i * 2 - j * 2) * 2
            if i + j + x > n or (n - i - j - x) % 2 > 0:
                continue
            x += (n - i - j - x) // 2
            ans += C(n, i) * C(n - i, j) * C(n - i - j, x) % mod
    return ans % mod


print(F(2))
print(F(10))
print(F(9898))
