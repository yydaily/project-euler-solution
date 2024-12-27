# -*- coding: UTF-8 -*-
from random import random
from math import *


def Q(length):
    ret = 0
    base = 904962
    length //= 2
    while length > 0:
        length //= 2
        ret += length * base
    return ret


print(Q(8))
print(Q(10**12))
