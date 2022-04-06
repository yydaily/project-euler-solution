from random import random
from math import *


def cal(a, b, c, depth):
    k = a + b + c + 2 * sqrt(a * b + b * c + a * c)
    if depth == 1:
        return 1 / k / k
    return (
        1 / k / k
        + cal(a, b, k, depth - 1)
        + cal(a, c, k, depth - 1)
        + cal(b, c, k, depth - 1)
    )


init = 1 / (2 * sqrt(3) - 3)
ans = 3 + 3 * cal(-1 / init, 1, 1, 10) + cal(1, 1, 1, 10)
print("%.8f" % (1 - ans / init / init))
