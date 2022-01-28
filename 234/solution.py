from random import random
from math import *

upper = 999966663333
p = [False for i in range(1000010)]
cnt = 0
sum = 0


def handle(pi, pj):
    global cnt, sum
    l = pi * pi + 1
    r = min(upper, pj * pj - 1)
    if l > r:
        return
    r += 1
    for i in range(l // pi * pi, r, pi):
        if i < l or i % pj == 0:
            continue
        cnt += 1
        sum += i
    for i in range(l // pj * pj, r, pj):
        if i < l or i % pi == 0:
            continue
        cnt += 1
        sum += i


def Handle():
    last = -1
    for i in range(2, 1000000):
        if not p[i]:
            if last != -1:
                handle(last, i)
            last = i
        for j in range(i << 1, 1000000, i):
            p[j] = True


if __name__ == "__main__":
    Handle()
    print(cnt, sum)
