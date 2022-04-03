from random import random
from math import *

cnt = [[[0 for i in range(1050)] for j in range(11)] for k in range(50)]

for i in range(1, 10):
    cnt[1][i][1 << i] = 1

for i in range(1, 40):
    for j in range(0, 10):
        for k in range(0, 1024):
            if j > 0:
                cnt[i + 1][j - 1][k | 1 << (j - 1)] += cnt[i][j][k]
            if j < 9:
                cnt[i + 1][j + 1][k | 1 << (j + 1)] += cnt[i][j][k]

print(sum(cnt[i][j][1023] for i in range(10, 41) for j in range(10)))
