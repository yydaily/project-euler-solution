from random import random
from math import *

true = True
false = False

e6 = 1000000
num = [0 for i in range(e6 + 10)]
vis = [false for i in range(e6 + 10)]


def cal_next(a):
    ret = 1
    for i in range(2, a):
        if i * i > a:
            break
        if a % i == 0:
            ret += i
            if a // i != i:
                ret += a // i
    return ret


def cal_len(i, origin, show):
    if i <= 2 or i > e6:
        return -100
    if vis[i] and i == origin:
        return 0
    if vis[i]:
        return -100
    if show:
        print(i, " ")
    ret = 1
    vis[i] = true
    ret += cal_len(num[i], origin, show)
    vis[i] = false
    return ret


if __name__ == "__main__":
    for i in range(2, e6):
        num[i] = cal_next(i)
    print("gen success")
    max_len, index = 0, 0
    for i in range(2, e6):
        len = cal_len(i, i, false)
        if len > 0:
            cal_len(i, i, true)
            print(": ", len)
        if len > max_len:
            max_len = len
            index = i
    print(max_len, index)
