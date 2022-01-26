from random import random
from math import *

cnt = [[0.0 for i in range(200)] for j in range(20)]
val = [[0.0 for i in range(200)] for j in range(20)]


def init():
    cnt[0][0] = 1
    for i in range(19):
        for j in range(200):
            for add in range(10):
                if j + add >= 200:
                    break
                cnt[i + 1][j + add] += cnt[i][j]
                val[i + 1][j + add] += val[i][j] * 10.0 + cnt[i][j] * add


upper = 1234567890123456789.0


def gao(a):
    ret = 0.0
    while a > 0:
        ret += a % 10
        a //= 10
    return ret


def cal(prefix=0):
    if prefix > upper:
        return 0
    prefix_sum = gao(prefix)
    max_diff = upper - prefix
    diff, index = 1, 0
    while diff * 10.0 <= max_diff:
        diff *= 10
        index += 1

    ret = cal(prefix + diff)
    for i in range(200):
        if cnt[index][i] > 0 and i + prefix_sum > 0:
            ret += 1.0 * (val[index][i] + prefix * cnt[index][i]) / (i + prefix_sum)
    # print(prefix, ret)
    return ret


if __name__ == "__main__":
    init()
    print("%.12e" % cal())
