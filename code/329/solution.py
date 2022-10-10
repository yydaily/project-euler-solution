from random import random
from math import *


def gcd(a, b):
    if a == 0:
        return b
    return gcd(b % a, a)


def format(a, b):
    g = gcd(a, b)
    return [a // g, b // g]


def mul(a, b):
    return format(a[0] * b[0], a[1] * b[1])


def add(a, b):
    return format(a[0] * b[1] + b[0] * a[1], a[1] * b[1])


is_prime = {}
now = [[0, 1] for i in range(501)]


def handle(p):
    global now
    nxt = [[0, 1] for i in range(501)]
    x = 1
    if p:
        x = 2
    nxt[2] = mul(now[1], [x, 3])
    nxt[499] = mul(now[500], [x, 3])

    for i in range(2, 500):
        buf = [1, 6]
        if is_prime[i - 1] == p:
            buf = [1, 3]
        nxt[i - 1] = add(nxt[i - 1], mul(now[i], buf))
        buf = [1, 6]
        if is_prime[i + 1] == p:
            buf = [1, 3]
        nxt[i + 1] = add(nxt[i + 1], mul(now[i], buf))
    for i in range(1, 501):
        now[i] = nxt[i]


if __name__ == "__main__":
    for i in range(1, 501):
        is_prime[i] = True
    for i in range(2, 501):
        if is_prime[i]:
            for j in range(i * 2, 501, i):
                is_prime[j] = False
    is_prime[1] = False
    for i in range(1, 501):
        now[i] = [1, 1500]
        if is_prime[i]:
            now[i] = [1, 750]
    query = "PPPPNNPPPNPPNPN"
    for i in range(1, len(query)):
        handle(query[i] == "P")
    ans = [0, 1]
    for i in range(1, 501):
        ans = add(ans, now[i])
        print(i, now[i])
    print(ans)
