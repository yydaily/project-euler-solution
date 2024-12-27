from random import random
from math import *


def qpow(a, b, mod):
    ret = 1
    while b > 0:
        if b % 2 == 1:
            ret = ret * a % mod
        a = a * a % mod
        b >>= 1
    return ret


cache = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "a", "b", "c", "d", "e", "f"]


def show(a, base=14):
    ret = ""
    while a > 0:
        ret = cache[a % base] + ret
        a //= base
    return ret


def ans(a):
    ret = 0
    cnt = 1
    for i in range(len(a)):
        ret += cnt * int(a[i], 16)
        if a[i] != "0":
            cnt += 1
    return ret


l = 10000
base = 14  # if base is 10, set this field to 10
a = 2
b = base // a
al = a**l
bl = b**l

t0 = qpow(bl, al // a * (a - 1) - 1, al)
t1 = qpow(al, bl // b * (b - 1) - 1, bl)
data = t1 * al
data2 = t0 * bl

if l <= 10:
    print(show(data, base))
    print(show(data2, base))

print(show(1 + ans(show(data)) + ans(show(data2)), base))
