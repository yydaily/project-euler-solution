# -*- coding: UTF-8 -*-
from random import random
from math import *


def check(a):
    u = int(sqrt(a))
    for i in range(2, u + 1):
        if a % i == 0:
            return False, 0

    summary = 0
    remind = 1
    l = 0
    while remind != 1 or l == 0:
        l += 1
        summary += (remind * 10) // a
        remind = (remind * 10) % a
    return l + 1 == a, summary


print(check(7))
print(check(17))

for i in range(724709891, 729909892, 100000):
    ok, value = check(i)
    if ok:
        print(value)
