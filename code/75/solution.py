from random import random
from math import *


def gcd(a, b):
    if a == 0:
        return b
    return gcd(b % a, a)


upper = 1500000
cnt = {}

for m in range(int(sqrt(upper))):
    for n in range(1, m):
        a = m * m - n * n
        b = 2 * m * n
        c = m * m + n * n
        if a + b + c > upper:
            break
        if gcd(a, gcd(b, c)) != 1:
            continue
        for i in range(a + b + c, upper + 1, a + b + c):
            if i not in cnt:
                cnt[i] = 1
            else:
                cnt[i] = cnt[i] + 1
ans = 0
for k in cnt:
    if cnt[k] == 1:
        ans += 1
print(ans)
