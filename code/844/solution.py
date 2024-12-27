# -*- coding: UTF-8 -*-
from random import random
from math import *
from copy import deepcopy as dc
from decimal import Decimal

ans = 0


def M(N, data, value):
    global ans
    for k in data:
        delta = Decimal((value // k) ** 2 - 4 * (value - k * k))
        sqrt_delta = int(delta.sqrt())
        if sqrt_delta * sqrt_delta != delta:
            continue
        buf = value // k + sqrt_delta
        if buf % 2 != 0:
            continue
        buf //= 2
        if buf <= k or buf > N:
            continue

        new_data = dc(data)
        new_data[k] -= 1
        if new_data[k] == 0:
            del new_data[k]
        if buf not in new_data:
            new_data[buf] = 1
        else:
            new_data[buf] += 1
        ans += buf
        M(N, new_data, value - k * k + buf * buf)


def s1(a):
    return a * (a + 1) * (a * 2 + 1) // 6 - a


def S(K, N):
    global ans
    ans = 0

    if K > 10**9:
        ans += (K - 10**9) * (K + 10**9 + 1) // 2
        K = 10**9

    if K > 10**6:
        ans += s1(K) - s1(10**6)
        K = 10**6

    for k in range(3, K + 1):
        ans += 1
        M(N, {1: k}, k)
    return ans


print(S(3, 1000))
print(S(4, 100))
print(S(10, 10**8))
print(S(10**18, 10**18) % 1405695061)
