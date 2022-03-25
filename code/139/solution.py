from random import random
from math import *


def gcd(a, b):
    if a == 0:
        return b
    return gcd(b % a, a)


ans = 0
for m in range(2, 10000):
    for n in range(((m & 1) ^ 1), m, 2):
        if gcd(m, n) != 1:
            continue
        C = 2 * m * (m + n)
        if C > 10 ** 8:
            break
        a = m * m - n * n
        b = 2 * m * n
        c = m * m + n * n
        s = int(sqrt(c * c - 2 * a * b))
        if c % s != 0:
            continue
        ans += (10 ** 8) // C
print(ans)
