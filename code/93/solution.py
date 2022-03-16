from random import random
from math import *


def gen(v):
    if len(v) == 1:
        return [v[0]]
    ret = []
    for i in v:
        buf = []
        for j in v:
            if j == i:
                continue
            buf.append(j)
        now = gen(buf)
        for j in now:
            ret.append(i + j)
            ret.append(i * j)

            ret.append(i - j)
            ret.append(j - i)
            if j > 0:
                ret.append(i / j)
            if i > 0:
                ret.append(j / i)
    return ret


def cal(x):
    m = {}
    for i in x:
        if int(i) == i and int(i) not in m:
            m[int(i)] = True
    for i in range(1, 10000):
        if i not in m:
            return i - 1


if __name__ == "__main__":
    ans = 0
    for i in range(1, 20):
        for j in range(i + 1, 20):
            for k in range(j + 1, 20):
                for l in range(k + 1, 20):
                    now = cal(gen([i, j, k, l]))
                    if now > ans:
                        ans = now
                        print(str(i) + str(j) + str(k) + str(l))
