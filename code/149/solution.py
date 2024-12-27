from random import random
from math import *

mod = 10**6
nouse = [0] * 4000006
num = [[0 for i in range(2010)] for j in range(2010)]
ans = [[[0 for i in range(2010)] for j in range(2010)] for k in range(4)]

for i in range(1, 4000001):
    if i <= 55:
        nouse[i] = (100003 - 200003 * i + 300007 * i * i * i) % mod - 500000
        num[(i - 1) // 2000 + 1][(i - 1) % 2000 + 1] = nouse[i]
    else:
        nouse[i] = (nouse[i - 24] + nouse[i - 55] + 1000000) % mod - 500000
        num[(i - 1) // 2000 + 1][(i - 1) % 2000 + 1] = nouse[i]

rans = 0
for i in range(1, 2001):
    for j in range(1, 2001):
        ans[0][i][j] = max(ans[0][i - 1][j], 0) + num[i][j]
        ans[1][i][j] = max(ans[1][i][j - 1], 0) + num[i][j]
        ans[2][i][j] = max(ans[2][i - 1][j - 1], 0) + num[i][j]
        rans = max(max(rans, ans[0][i][j]), max(ans[1][i][j], ans[2][i][j]))
    for j in range(2000, 0, -1):
        ans[3][i][j] = max(ans[3][i - 1][j + 1], 0) + num[i][j]
        rans = max(rans, ans[3][i][j])
print(rans)
