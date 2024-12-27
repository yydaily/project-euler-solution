from random import random
from math import *

upper = int(10**6)
ans = 0
for i in range(upper // 4 + 1, 2, -1):
    for j in range(i - 2, 0, -2):
        now = i * i - j * j
        if now <= upper:
            ans += 1
        else:
            break
print(ans)
