from random import random
from math import *

length = 30
ans = [[[0 for k in range(5)] for j in range(5)] for i in range(40)]

ans[0][0][0] = 1
for i in range(length):
    for j in range(3):
        for k in range(2):
            ans[i + 1][j + 1][k] += ans[i][j][k]
            ans[i + 1][0][k] += ans[i][j][k]
            ans[i + 1][0][k + 1] += ans[i][j][k]
rans = 0
for j in range(3):
    for k in range(2):
        rans += ans[length][j][k]
print(rans)
