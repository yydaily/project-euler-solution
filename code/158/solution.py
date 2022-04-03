from random import random
from math import *


def cnt(a):
    ret = (1 << a) - a - 1
    for i in range(1, a + 1):
        ret = ret * (26 - i + 1) // i
    return ret


print(max(cnt(i) for i in range(1, 27)))
