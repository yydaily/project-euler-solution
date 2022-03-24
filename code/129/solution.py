from random import random
from math import *


def cal(a):
    now, ret = 0, 0
    while True:
        now = (now * 10 + 1) % a
        ret += 1
        if now == 0:
            return ret


for i in range(10 ** 6 + 1, 10 ** 7, 2):
    if i % 10 == 5:
        continue
    v = cal(i)
    print(i, v)
    if v >= 10 ** 6:
        break
