from random import random
from math import *

mod = 10 ** 10


def cal(a):
    ret = 0
    for i in range(1, a + 1):
        ret += (i ** i) % mod
    return ret % mod


print(cal(10))
print(cal(1000))
