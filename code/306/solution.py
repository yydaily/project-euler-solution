# -*- coding: UTF-8 -*-
from random import random
from math import *


def solve(upper):
    ret = upper // 34 * 5
    ret += sum(list(1 for i in [1, 15, 35] if upper > i))
    ret += sum(list(1 for i in [5, 9, 21, 25, 29] if upper % 34 >= i))
    return upper - ret


print(solve(5))
print(solve(50))
print(solve(1000_000))
