from random import random
from math import *

need_check = []
p = [False for i in range(int(1e8))]


def check(a):
    upper = int(sqrt(a) + 1)
    for i in range(2, upper):
        if a % i == 0 and p[i + a // i]:
            return False
    return True


if __name__ == "__main__":
    p[0], p[1] = True, True
    for i in range(2, int(1e8)):
        if not p[i]:
            need_check.append(i - 1)
            for j in range(i << 1, int(1e8), i):
                p[j] = True
    sum = 0
    for i in need_check:
        if check(i):
            sum += i
    print(sum)
