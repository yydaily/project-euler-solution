from random import random
from math import *

num = [[0 for i in range(60)] for j in range(60)]
ans = 0
m = {}


def add(a):
    global ans
    if a in m:
        return
    m[a] = True
    copy = a
    for i in range(2, int(sqrt(a)) + 1):
        if a % i == 0:
            a //= i
            if a % i == 0:
                return
    ans += copy


if __name__ == "__main__":
    num[1][1] = 1
    for i in range(2, 52):
        for j in range(1, i + 1):
            if j == 1 or j == i:
                num[i][j] = 1
            else:
                num[i][j] = num[i - 1][j] + num[i - 1][j - 1]
            add(num[i][j])
    print(ans)
