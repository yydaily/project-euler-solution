from random import random
from math import *


def get_all_primes(a):
    ret = {}
    for i in range(2, int(sqrt(a + 1)) + 1):
        while a % i == 0:
            ret[i] = 1 if i not in ret else ret[i] + 1
            a //= i
    if a != 1:
        ret[a] = 1
    return ret


def get_all_factor(a):
    p = get_all_primes(a)
    ret = [1]
    for k in p:
        s = len(ret)
        now = 1
        for cnt in range(p[k]):
            now *= k
            for x in range(s):
                ret.append(ret[x] * now)
    return ret


def gcd(a, b):
    return b if a == 0 else gcd(b % a, a)


def gen(a, b):
    while gcd(a + 1, b) != 1:
        a += 1
        b += gcd(a, b)

    x = b * 100
    for fac in get_all_factor(b - a - 1):
        if fac == 1:
            continue
        x = min(x, fac - (a + 1) % fac)
    return a + x + 1, b + x + gcd(a + x + 1, b + x)


if __name__ == "__main__":
    index, val, ans = 4, 13, 0
    upper = 10**15
    while True:
        print(index, val)
        ans = upper - index + val
        index, val = gen(index, val)
        if index > upper:
            break
    print(ans)
