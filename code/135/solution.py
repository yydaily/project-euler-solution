from random import random
from math import *

num = [0] * 1000000

for a in range(1, 1000000):
    for d in range(a // 3 + 1, 1000000):
        v = (3 * d - a) * (d + a)
        if v >= 1000000:
            break
        num[v] += 1

ans = 0
for i in num:
    if i == 10:
        ans += 1
print(ans)
