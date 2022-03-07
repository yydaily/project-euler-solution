from math import sqrt, pi


def cal(n):
    return sqrt(pi * n) > 19999


for i in range(1, 200000000):
    if cal(i):
        print(i)
        break
