from random import random
from math import *


def cal(a):
    ret = 1
    for i in range(a):
        ret *= (2 * (i + 1) / (a + 1)) ** (i + 1)
    return ret


ret = 0
for i in range(2, 16):
    ret += int(cal(i))
print(ret)
