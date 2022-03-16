from random import random
from math import *


def cal(a):
    if (a & 1) == 1:
        return a - 1
    return a - 2


ans = 0
for i in range(3, 1001):
    ans += cal(i) * i
print(ans)
