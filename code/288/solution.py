from random import random
from math import *

n = 61
upper = 10 ** 7
mod = 61 ** 10
s = [0] * (upper + 1)
pown = [0] * (upper + 1)


def init():
    s[0] = 290797
    pown[0] = 1
    for i in range(upper):
        s[i + 1] = s[i] * s[i] % 50515093
        s[i] %= n
        pown[i + 1] = pown[i] * n % mod
    s[upper] %= n


def NF():
    ans = 0
    for i in range(upper, 0, -1):
        ans = ans + s[i] * pown[i - 1]
        s[i - 1] += s[i]
    return ans % mod


if __name__ == "__main__":
    init()
    print(NF())
