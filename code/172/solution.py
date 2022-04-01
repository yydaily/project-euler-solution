from random import random
from math import *

num = [0] * 20
ans = 0


def fac(a):
    if a <= 1:
        return 1
    return fac(a - 1) * a


def C(a, b):
    return fac(a) / fac(b) / fac(a - b)


def cal():
    global ans
    buf = C(17, num[0])
    cnt = 18 - num[0]
    for i in range(1, 10):
        buf *= C(cnt, num[i])
        cnt -= num[i]
    ans += buf


def dfs(a, need=18):
    if need == 0:
        cal()
        return
    if a == 10:
        return
    for i in range(0, min(3, need) + 1):
        num[a] = i
        dfs(a + 1, need - i)
        num[a] = 0


dfs(0)
print(int(ans))
