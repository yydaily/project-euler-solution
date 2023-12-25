# -*- coding: UTF-8 -*-
from random import random
from math import *

ans = 0
for p in range(1, 2011):
    for q in range(p + 1, 2011 - p + 1):
        buf = p + q - 2 * sqrt(p * q)
        if 0 < buf < 1:
            ans += ceil(-2011 / log10(buf))
print(ans)
