from random import random
from math import *
from decimal import *

getcontext().prec = 1000


def cal(a):
    l = Decimal(1)
    r = Decimal(a)
    while r - l >= 1e-200:
        mid = (l + r) / 2
        if mid * mid < a:
            l = mid
        else:
            r = mid
    ret = 0
    for i in range(100):
        ret += int(l)
        l -= int(l)
        l *= 10
    return ret


ans = 0
for i in range(1, 100):
    x = int(sqrt(i))
    if x * x == i:
        continue
    x = cal(Decimal(i))
    print(i, x)
    ans += x

print(ans)
