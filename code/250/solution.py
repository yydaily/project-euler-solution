from random import random
from math import *


def qpow(a, b):
    ret = 1
    while b > 0:
        if (b & 1) > 0:
            ret = (ret * a) % 250
        a = (a * a) % 250
        b >>= 1
    return ret


num = [0] * 300
mod = 10 ** 16

num[0] = 1
for i in range(1, 250251):
    now = qpow(i, i)
    cc = [0] * 300
    for i in range(250):
        cc[(i + now) % 250] = (cc[(i + now) % 250] + num[i]) % mod
    for i in range(250):
        num[i] = (num[i] + cc[i]) % mod
print(num[0] - 1)
