# -*- coding: UTF-8 -*-
from random import random
from math import *

ans = 0
base = 2.0
for i in range(2, 31):
    ans += (base - 1) / i
    base *= 2
print("%.2f" % ans)
