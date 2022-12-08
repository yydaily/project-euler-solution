# -*- coding: UTF-8 -*-
from random import random
from math import *


def cal(i):
    if i % 6 == 0:
        return i // 2
    if i % 6 == 1:
        return i // 6 * 4 + 1
    if i % 6 == 2:
        return i // 6 * 3 + 1
    if i % 6 == 3 or i % 6 == 5:
        return i // 6
    if i % 6 == 4:
        return i - 1


def solve(N, M):
    vis = {}
    prefix_sum = 0
    for i in range(1, 6 * M + 1):
        now = cal(i)
        prefix_sum = (prefix_sum + now) % M
        if prefix_sum not in vis:
            vis[prefix_sum] = 1
        else:
            vis[prefix_sum] = vis[prefix_sum] + 1
    for k in vis:
        vis[k] = vis[k] * (N // (M * 6))
    prefix_sum *= N // (M * 6)
    for i in range(N // (M * 6) * M * 6, N + 1):
        now = cal(i)
        prefix_sum = (prefix_sum + now) % M
        if prefix_sum not in vis:
            vis[prefix_sum] = 1
        else:
            vis[prefix_sum] = vis[prefix_sum] + 1
    ans = 0
    for k in vis:
        ans += vis[k] * (vis[k] - 1) // 2
    return ans


print(solve(10, 10))
print(solve(10 ** 4, 10 ** 3))
print(solve(10 ** 12, 10 ** 6))
