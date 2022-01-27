from random import random
from math import *


def cal(n, m):
    num = [0 for i in range(1000)]
    num1 = [0 for i in range(1000)]
    num[0] = 1
    for i in range(1, n + 1):
        num[i] = num[i - 1] + num1[i - 1]
        if i >= m:
            for j in range(i - m, -1, -1):
                num1[i] += num[j]
    return num[n] + num1[n]


if __name__ == "__main__":
    for i in range(10, 1000):
        v = cal(i, 50)
        print(i, v)
        if v >= 1000000:
            break
