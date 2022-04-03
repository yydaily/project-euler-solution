from random import random
from math import *

upper = int(1e12)
e5 = int(1e5)


def qpow(a, b):
    ret = 1
    while b > 0:
        if (b & 1) > 0:
            ret = ret * a % e5
        a = a * a % e5
        b >>= 1
    return ret


def count(a, base):
    ret = 0
    while a > 0:
        a = int(a // base)
        ret += a
    return ret


cnt = [0] * e5

if __name__ == "__main__":
    ans = 1
    a = 1
    while a <= upper:
        b = 1
        while a * b <= upper:
            x = upper // (a * b)
            for y in range(1, e5, 2):
                if y % 5 == 0:
                    continue
                cnt[y] += x // e5
                if x % e5 >= y:
                    cnt[y] += 1
            b *= 5
        a <<= 1
    for y in range(1, e5):
        ans = ans * qpow(y, cnt[y]) % e5
    ans = ans * qpow(2, count(upper, 2) - count(upper, 5)) % e5
    print(ans)
