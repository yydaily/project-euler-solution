from random import random
from math import *


def f(x):
    return int(2 ** (30.403243784 - x * x)) * 1e-9


now = -1
for i in range(1, int(1e12)):
    now = f(now)
    if abs(now - f(f(now))) < 1e-10:
        print(i, now + f(now))
        break
