from random import random
from math import *

len = 15
gain, total = 0, 1
for i in range(1, len + 1):
    total *= i + 1
for i in range(1 << len):
    b, r, now = 0, 0, 1
    for j in range(len):
        if (i & (1 << j)) != 0:
            r += 1
            now *= j + 1
        else:
            b += 1
    if b > r:
        gain += now
print(total, gain)
print(total // gain)
