from random import random
from math import *

num = [0 for i in range(1000)]
num1 = [0 for i in range(1000)]


def cal(n, m):
    num[0] = 1
    for i in range(1, n + 1):
        num[i] = num[i - 1] + num1[i - 1]
        if i >= m:
            for j in range(i - m, -1, -1):
                num1[i] += num[j]
    return num[n] + num1[n]


print(cal(50, 3))
