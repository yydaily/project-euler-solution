from random import random
from math import *

cnt = [0] * 1000001

for i in range(3, 1000000):
    for j in range(i - 2, 0, -2):
        v = (i + j) * (i - j)
        if v > 1000000:
            break
        cnt[v] += 1

ans = 0
for i in range(1, 1000001):
    if 0 < cnt[i] <= 10:
        ans += 1
print(ans)
