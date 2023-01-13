# -*- coding: UTF-8 -*-
from random import random
from math import *

n = [0] * 50
k = [0] * 50

n[0] = 1
k[0] = 2
n[1] = 3
k[1] = 5

ans = 0
for i in range(40):
    n[i + 2] = 3 * n[i] + 2 * k[i] + 3
    k[i + 2] = 4 * n[i] + 3 * k[i] + 5
    ans += n[i]
print(ans)
