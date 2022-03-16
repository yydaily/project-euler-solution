from random import random
from copy import deepcopy
from math import *


def gen(v):
    x = deepcopy(v)
    if len(v) <= 2:
        x.append(v[len(v) - 1] * 2 - v[0])
        return x
    diff = []
    for i in range(1, len(v)):
        diff.append(v[i] - v[i - 1])
    diff = gen(diff)
    x.append(v[len(v) - 1] + diff[len(diff) - 1])
    return x


def cal(a):
    ans = 1
    base = 1
    for i in range(1, 11):
        base *= -a
        ans += base
    return ans


if __name__ == "__main__":
    ans, v = 0, []
    for i in range(1, 10000):
        now = cal(i)
        v.append(now)
        diff = gen(v)
        if diff[len(diff) - 1] == cal(i + 1):
            break
        print(diff[len(diff) - 1], cal(i + 1))
        ans += diff[len(diff) - 1]
    print(ans)
