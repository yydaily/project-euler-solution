from random import random
from math import *

cache = {}


def solve(a):
    if a <= 0:
        return 1
    if a in cache:
        return cache[a]
    ret = 0
    if (a & 1) == 1:
        ret = solve(a >> 1)
    else:
        ret = solve(a >> 1) + solve((a >> 1) - 1)
    cache[a] = ret
    return ret


print(solve(10 ** 25))
