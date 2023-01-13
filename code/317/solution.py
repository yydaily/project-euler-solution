# -*- coding: UTF-8 -*-
from random import random
from math import *


def solve(hight, v, g):
    upper = v * v / g / 2 + hight
    return pi * upper * upper / g * v * v


print("%.4f" % solve(100, 20, 9.81))
