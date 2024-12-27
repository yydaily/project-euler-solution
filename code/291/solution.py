from random import random
from math import *

upper = 5 * 10**7
v = [2 * n * n + 2 * n + 1 for n in range(upper + 1)]

ans = 0
for i in range(1, len(v)):
    p = v[i]
    if p == 2 * i * i + 2 * i + 1:
        ans += 1
    if p <= 1:
        continue
    for j in range(i, len(v), p):
        while v[j] % p == 0:
            v[j] //= p
    for j in range(p - 1 - i, len(v), p):
        while v[j] % p == 0:
            v[j] //= p
print(ans)
