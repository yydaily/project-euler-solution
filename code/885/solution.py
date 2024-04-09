# -*- coding: UTF-8 -*-
from random import random
from math import *

jiecheng = [0] * 20
cnt = [0] * 10
mod = 1123455689
ans = 0


def init():
    jiecheng[0] = 1
    for i in range(1, 20):
        jiecheng[i] = jiecheng[i - 1] * i


def C(a, b):
    if a < b:
        return 0
    return jiecheng[a] // jiecheng[b] // jiecheng[a - b]


def cal():
    s = sum(cnt)
    ret = 1
    for i in range(10):
        ret = ret * C(s - (i == 0), cnt[i])
        s -= cnt[i]
    return ret % mod


def dfs(index, need, now):
    if index == 10:
        global ans
        ans = (ans + now * cal()) % mod
        return

    buf = now
    for i in range(need + 1):
        cnt[index] = i
        dfs(index + 1, need - i, buf)
        cnt[index] = 0
        buf = buf * 10 + index


def S(a):
    global ans
    ans = 0
    dfs(0, a, 0)
    return ans


if __name__ == "__main__":
    init()
    print(S(1))
    print(S(5))
    print(S(18))
