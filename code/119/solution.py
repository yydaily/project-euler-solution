from random import random
from math import *
from numpy import unique


def check(base):
    copy = base
    x = 0
    while base > 0:
        x += base % 10
        base //= 10
    if x == 1:
        return False
    while copy % x == 0:
        copy //= x
    return copy == 1


if __name__ == "__main__":
    a = []
    for i in range(2, 90):
        base = i
        while base <= 10:
            base *= i
        while base <= 1e18:
            if check(base):
                a.append(base)
            base *= i
    a = unique(a)
    print(a[29])
