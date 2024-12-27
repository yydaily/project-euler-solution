from random import random
from math import *

mod = 10**9 + 87
e7 = 10**7
p = [False] * (e7 + 10)
l = [0] * (e7 + 10)
cnt = [0] * (e7 + 10)
inv = [0] * (4 * e7 + 10)


def init():
    inv[1] = 1
    for i in range(2, 4 * e7 + 1):
        inv[i] = ((mod - mod // i) * inv[mod % i]) % mod
    for i in range(2, e7 + 1):
        if not p[i]:
            for j in range(i, e7 + 1, i):
                l[j] = i
                p[j] = True
    print("init success")


base = 1


def cal(a):
    global base
    while a != 1:
        x = 1 + 2 * cnt[l[a]]
        base = (base * inv[x] * (1 + 2 * cnt[l[a]] + 2)) % mod
        cnt[l[a]] += 1
        a //= l[a]
    return base


if __name__ == "__main__":
    init()
    ans = 0
    for i in range(2, e7 + 1):
        if i % 100000 == 0:
            print(i // 100000, "%")
        ans += cal(i)
    print(ans % mod)
