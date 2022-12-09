# -*- coding: UTF-8 -*-
from random import random
from math import *
from decimal import Decimal, getcontext

getcontext().prec = 100

l = Decimal(50)
r = Decimal(100)


def cal(a):
    # dp[i][j] 表示前 i 个球投中 j 个的概率
    dp = [[Decimal(0) for i in range(51)] for j in range(51)]
    dp[0][0] = Decimal(1)
    for i in range(1, 51):
        for j in range(0, 50):
            dp[i][j] += dp[i - 1][j] * Decimal(i) / a
            if j > 0:
                dp[i][j] += dp[i - 1][j - 1] * (Decimal(1) - Decimal(i) / a)
    return dp[50][20]


while r - l >= 1e-15:
    mid = (l + r) / Decimal(2)
    if cal(mid) > 0.02:
        l = mid
    else:
        r = mid
print(l.quantize(Decimal("0.0000000001")))
