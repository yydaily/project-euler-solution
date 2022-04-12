from random import random
from math import *

length = 4
a = [1, 1, 1, 1]


def cal(a):
    sum_cnt = sum(a[i] for i in range(length))
    ret = 0
    if sum_cnt == 1:
        if a[length - 1] == 1:
            return 0
        ret = 1
    for i in range(length):
        if a[i] == 0:
            continue
        x = [a[j] for j in range(length)]
        x[i] -= 1
        for j in range(i + 1, length):
            x[j] += 1
        ret += a[i] / sum_cnt * cal(x)
    return ret


print("%.6f" % cal(a))
