from random import random
from math import *

root = 524287
mod = 10**6
e4 = 10**4
pre = [0] * mod
cnt = [0] * mod
val = [0] * (e4)


def find(a):
    if pre[a] == a:
        return a
    pre[a] = find(pre[a])
    return pre[a]


def merge(a, b):
    if a == b:
        return True
    aa, bb = find(a), find(b)
    if aa == bb:
        return False
    pre[bb] = aa
    cnt[aa] += cnt[bb]
    return False


def get(index):
    if index <= 55:
        val[index] = (100003 - 200003 * index + 300007 * index * index * index) % mod
    else:
        val[index % e4] = (
            val[(index + e4 - 24) % e4] + val[(index - 55 + e4) % e4]
        ) % mod
    return val[index % e4]


if __name__ == "__main__":
    for i in range(mod):
        pre[i] = i
        cnt[i] = 1

    ans = 0
    for i in range(1, mod * mod):
        a = get(i * 2 - 1)
        b = get(i * 2)
        if merge(a, b):
            ans -= 1
        if cnt[find(root)] >= mod / 100 * 99:
            print(i + ans)
            break
