#!/usr/local/bin/python3
from functools import cache


@cache
def calc(n):
    # return \sum_{i=1}^n D(i)
    if n == 0:
        return 0
    r = int(n ** (1 / 3))
    if (r + 1) ** 3 <= n:
        r += 1
    r = r ** 3
    return calc(r - 1) + calc(n - r) + n - r + 1


def S(N):
    u = int(N ** (1 / 3))
    for i in range(u):
        calc(i ** 3)
    return calc(N - 1)


print(S(100))
print(S(10 ** 17))
