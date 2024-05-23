# -*- coding: UTF-8 -*-
from random import random
from math import *

num = [0] * 1000
dis = [[0 for i in range(1000)] for j in range(1000)]
ans = [[0 for i in range(1000)] for j in range(1000)]


def G(n):
    now = 1
    for i in range(1, n + 1):
        now = now * 3 % (n + 1)
        num[i] = now

    for i in range(1, n + 1):
        for j in range(1, n + 1):
            dis[num[i]][num[j]] = abs(i - j)

    for j in range(1, n + 1):
        for i in range(j, 0, -1):
            if i == j:
                ans[i][j] = 0
                continue
            ans[i][j] = 10 ** 9
            for k in range(i, j):
                ans[i][j] = min(ans[i][j], ans[i][k] + ans[k + 1][j] + dis[k][j])
    return ans[1][n]


if __name__ == "__main__":
    print(G(6))
    print(G(16))
    print(G(976))
