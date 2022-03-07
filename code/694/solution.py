from random import random
from math import *

upper = 0
min_prime = [0] * 1000001


def init():
    for i in range(2, 1000001):
        if min_prime[i] == 0:
            for j in range(i, 1000001, i):
                min_prime[j] = i


m = {}


def cal(v):
    if str(v) in m:
        return 0
    m[str(v)] = True
    base = 1
    for i in v:
        base *= i * i * i
    base = upper // base
    if base == 0:
        return 0
    ret = 0

    num = [1]
    while True:
        nxt = []
        for i in num:
            ret += base // i
            for j in v:
                if i * j <= base:
                    nxt.append(i * j)
        nxt.sort()
        num = []
        if len(nxt) == 0:
            break
        num.append(nxt[0])
        for i in nxt:
            if i == num[len(num) - 1]:
                continue
            num.append(i)
    return ret


def Cal(u):
    global m, upper
    m = {}
    upper = u
    ans = upper
    for i in range(2, int(sqrt(upper))):
        if i * i * i > upper:
            break
        v = []
        vis = {}
        base = i
        while base != 1:
            if min_prime[base] not in vis:
                vis[min_prime[base]] = True
                v.append(min_prime[base])
            base //= min_prime[base]
        ans += cal(v)
    return ans


if __name__ == "__main__":
    init()
    print(Cal(16))
    print(Cal(100))
    print(Cal(10000))
    print(Cal(10 ** 18))
