from random import random
from math import *

m = {}


def check(a):
    if a in m:
        return False
    m[a] = True
    checker = 0
    copy = a
    while copy > 0:
        checker = checker * 10 + copy % 10
        copy //= 10
    return checker == a


ans = 0
for i in range(1, 10001):
    now = i * i
    for add in range(1, 10001):
        now += (i + add) * (i + add)
        if now >= 100000000:
            break
        if check(now):
            ans += now
print(ans)
