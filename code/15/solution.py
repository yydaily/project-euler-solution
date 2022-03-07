from random import random
from math import *

c = [[0 for i in range(41)] for j in range(21)]


def cal(a, b):
    if a > b:
        return 0
    if a == b or a == 0:
        return 1
    if c[a][b] > 0:
        return c[a][b]
    c[a][b] = cal(a - 1, b - 1) + cal(a, b - 1)
    return c[a][b]


print(cal(2, 4))
print(cal(20, 40))
