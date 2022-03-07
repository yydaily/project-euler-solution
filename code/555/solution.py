from random import random
from math import *

p = 1000000
m = p

ans = 0
for k in range(2, p + 1):
    for x in range(1, int(sqrt(k) + 1)):
        if k % x == 0:
            ans += x * (((m - k) << 1 | 1) + x * 3)
            if x != 1 and x * x != k:
                ans += (k // x) * (((m - k) << 1 | 1) + k // x * 3)
print(int(ans / 2))
