from random import random
from math import *


def cal(a):
    ret = 0
    while a > 0:
        ret += a % 10
        a //= 10
    return ret


def cal2(a):
    if a == 1:
        return 1
    return cal2(a - 1) * a


print(cal(cal2(100)))
