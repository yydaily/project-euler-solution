# -*- coding: UTF-8 -*-
mod = 1008691207
e8 = int(1e8)


def cal(a):
    fac, ans1, ans2 = 1, 1, 0
    for i in range(1, a):
        ans2 += fac * (a - i) % mod
        fac = fac * i % mod
        ans1 += fac * 2 % mod
    return ((fac * a - ans1 + ans2) % mod + mod) % mod


print(cal(3))
print(cal(5))
print(cal(e8))
