from random import random
from math import *


def cal(a):
    cnt = 0
    for i in range(1, int(sqrt(a)) + 1):
        if i * i > a:
            return cnt
        if a % i == 0:
            cnt += 2
            if a / i == i:
                cnt -= 1
    return cnt


if __name__ == "__main__":
    i, val = 1, 1
    while cal(val) <= 500:
        i += 1
        val += i
    print(val)
