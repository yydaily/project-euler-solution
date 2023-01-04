# -*- coding: UTF-8 -*-
from random import random
from math import *

sg = [0] * 200000
cnt = [0] * 100


def init_sg(upper):
    global cnt, sg
    for i in range(len(sg)):
        sg[i] = 0
    cnt = [0 for i in range(100)]
    cnt[0] = 1
    for i in range(1, upper + 1):
        m = {}
        for j in range(1, int(sqrt(i) + 5)):
            if j * j > i:
                break
            m[sg[i - j * j]] = True
        for j in range(0, 100):
            if j in m:
                continue
            sg[i] = j
            cnt[j] += 1
            break


def S(upper):
    init_sg(upper)
    ans1, ans2, ans3, ans4 = 0, 0, 0, cnt[0]
    for i in range(0, upper + 1):
        if sg[i] == 0:
            ans2 += upper - i
            ans3 += i
    buf = 0
    for i in range(100):
        for j in range(100):
            for k in range(100):
                if (i ^ j ^ k) == 0:
                    buf += cnt[i] * cnt[j] * cnt[k]
    ans1 = (buf - ans2 * 3 - ans3 * 3 - ans4) // 6
    return ans1 + ans2 + ans3 + ans4


if __name__ == "__main__":
    print(S(29))
    print(S(100000))
