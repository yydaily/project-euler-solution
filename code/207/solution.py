from random import random
from math import *

a, b = 0, 0
for k in range(3, 10 ** 9, 2):
    b += 1
    now = k + 1
    while (now & 1) == 0:
        now >>= 1
    if now == 1:
        a += 1
    if a * 12345 < b:
        print((k * k - 1) // 4)
        break
