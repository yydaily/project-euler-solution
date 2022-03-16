from random import random
from math import *

n = 50


def cnt(x, y, dx, dy):
    ret = 0
    for i in range(1, n):
        x += dx
        y += dy
        if x < 0 or x > n or y < 0 or y > n:
            break
        ret += 1
    return ret


def gcd(a, b):
    if a == 0:
        return b
    return gcd(b % a, a)


def cal(x, y):
    ans = 0
    g = gcd(x, y)
    ans += cnt(x, y, -y // g, x // g)
    ans += cnt(x, y, y // g, -x // g)
    return ans


if __name__ == "__main__":
    ans = 3 * n * n
    for x in range(1, n + 1):
        for y in range(1, n + 1):
            ans += cal(x, y)
    print(ans)
