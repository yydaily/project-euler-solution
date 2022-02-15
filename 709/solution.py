from random import random
from math import *

mod = 1020202009


def gen(n):
    A = {-1: 0, 0: 1}
    k = 0
    e = 1
    for i in range(n + 1):
        Am = 0
        A[k + e] = 0
        e = -e
        for j in range(i + 1):
            Am = (Am + A[k]) % mod
            A[k] = Am
            k += e
        if i % 10 == 0:
            print(i, Am)


gen(24680)
