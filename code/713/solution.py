# -*- coding: UTF-8 -*-
from random import random
from math import *


def L(n):
    m = isqrt(n - 1)
    return (
        m ** 2 * (1 + m) ** 2 // 4
        - m ** 2 * n
        + sum((n - 1) // i * (2 * n - i * (1 + (n - 1) // i)) for i in range(1, m + 1))
    )


print(L(1000))
print(L(10 ** 7))
