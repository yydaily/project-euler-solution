from random import random
from math import *


def cal(a, b):
    x = (a + b) ** 2
    y = (100 - a - b) ** 2
    return sqrt(x - y)


num = [i for i in range(50, 29, -2)] + [i for i in range(31, 50, 2)]

ans = num[0] + num[len(num) - 1]

for i in range(1, len(num)):
    ans += cal(num[i - 1], num[i])

print(int(ans * 1000))
