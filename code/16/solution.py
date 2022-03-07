from random import random
from math import *


def cal(a):
    ret = 0
    while a > 0:
        ret += a % 10
        a //= 10
    return ret


print(cal(2 ** 1000))
