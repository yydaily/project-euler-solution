from random import random
from math import *

need_len = 10
need_sum = need_len * (need_len - 1) / 2

cnt = [0] * need_len
C = [[0 for i in range(15)] for j in range(15)]


def init():
    for i in range(15):
        for j in range(i + 1):
            if i == j or j == 0:
                C[i][j] = 1
            else:
                C[i][j] = C[i - 1][j] + C[i - 1][j - 1]


def add():
    buf = 1
    len, len2 = need_len, need_len
    for i in range(need_len):
        buf *= C[len][2 - cnt[i]]
        len -= 2 - cnt[i]

        if i == 0:
            buf *= C[len2 - 1][cnt[i]]
        else:
            buf *= C[len2][cnt[i]]
        len2 -= cnt[i]
    return buf


def dfs(index, cnt_sum, sum):
    ret = 0
    if cnt_sum > need_len:
        return 0
    if index == need_len:
        if (2 * need_sum - 2 * sum) % 11 != 0 or cnt_sum != need_len:
            return 0
        return add()
    for i in range(3):
        cnt[index] = i
        ret += dfs(index + 1, cnt_sum + i, sum + i * index)
        cnt[index] = 0
    return ret


init()
print(dfs(0, 0, 0))
