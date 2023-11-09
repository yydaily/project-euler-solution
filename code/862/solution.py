# -*- coding: UTF-8 -*-
from random import random
from math import *

fac = [0 for i in range(14)]
cnt = [0 for i in range(10)]
total_length = 0


def init():
    fac[0] = 1
    for i in range(1, 14):
        fac[i] = fac[i - 1] * i


def calculate():
    global cnt, total_length, fac
    now = total_length
    ans = fac[now - 1] // fac[cnt[0]] // fac[now - cnt[0] - 1]
    for i in range(1, 10):
        now -= cnt[i - 1]
        ans *= fac[now] // fac[cnt[i]] // fac[now - cnt[i]]
    return ans * (ans - 1) // 2


def dfs(remain, start):
    if remain == 0:
        return calculate()

    if start == 9:
        cnt[9] = remain
        ret = calculate()
        cnt[9] = 0
        return ret

    ret = 0
    for i in range(remain + 1):
        cnt[start] = i
        ret += dfs(remain - i, start + 1)
        cnt[start] = 0

    return ret


def S(k):
    global total_length
    total_length = k
    ans = 0
    for i in range(k):
        cnt[0] = i
        ans += dfs(k - i, 1)
    return ans


if __name__ == "__main__":
    init()
    print(S(3))
    print(S(12))
