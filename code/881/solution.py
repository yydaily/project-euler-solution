# -*- coding: UTF-8 -*-
from random import random
from math import *

prime = [
    2,
    3,
    5,
    7,
    11,
    13,
    17,
    19,
    23,
    29,
    31,
    37,
    41,
    43,
    47,
    53,
    59,
    61,
    67,
    71,
    73,
    79,
    83,
    89,
    97,
    101,
    103,
    107,
    109,
    113,
]
ans = 6


def gen(a):
    ret = {}
    for i in range(a + 1):
        ret[i] = 1
    return ret


def merge(a, b):
    ret = {}
    for i in a:
        for j in b:
            if i + j in ret:
                ret[i + j] += a[i] * b[j]
            else:
                ret[i + j] = a[i] * b[j]
    return ret


def cal(v):
    x = {0: 1}
    for vv in v:
        x = merge(x, gen(vv))
    ret = 0
    for i in x:
        ret = max(ret, x[i])
    return ret


def dfs(prime_index, max_cnt, now, v):
    global ans
    if prime_index >= 15:
        return
    if cal(v) >= 10000:
        ans = min(ans, now)
        return
    p = prime[prime_index]
    for i in range(1, max_cnt + 1):
        if now > ans / p:
            return
        now *= p
        v.append(i)
        dfs(prime_index + 1, max_cnt, now, v)
        v.pop()


for i in range(15):
    ans *= prime[i]
dfs(0, 62, 1, [])
print(ans)
