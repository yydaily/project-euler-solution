from random import random
from math import *

u = 10**7 + 10
ans = [0] * u
num = [4 * i * i + 1 for i in range(u)]

for i in range(1, 10**7 + 1):
    p = num[i]
    if p == 4 * i * i + 1:
        ans[i] = p
    if p <= 1:
        continue
    for j in range(i, 10**7 + 1, p):
        while num[j] % p == 0:
            ans[j] = max(ans[j], p)
            num[j] //= p
    for j in range(p - i, 10**7 + 1, p):
        if j <= 0:
            continue
        while num[j] % p == 0:
            ans[j] = max(ans[j], p)
            num[j] //= p

mod = 10**18
print(sum(ans[i] for i in range(1, 10**7 + 1)) % mod)
