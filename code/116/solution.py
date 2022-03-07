from random import random
from math import *


def cal(*args):
    num = [0 for i in range(51)]
    num[0] = 1
    for i in range(1, 51):
        for s in args[0]:
            if i - s >= 0:
                num[i] += num[i - s]
    return num[50]


print(cal([1, 2]) + cal([1, 3]) + cal([1, 4]) - 3)
