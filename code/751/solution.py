from decimal import *
from math import floor

getcontext().prec = 100


def gao(a):
    ret = "2."
    b1 = Decimal(a)
    for i in range(1, 30):
        b2 = Decimal(floor(b1)) * (b1 - Decimal(floor(b1)) + 1)
        ret = ret + str(int(floor(b2)))
        b1 = b2
    return Decimal(ret)


l = Decimal(2.1)
r = Decimal(3)
for n in range(1, 100):
    mid = (l + r) / 2
    if gao(mid) > mid:
        l = mid
    else:
        r = mid
print(str(l)[:26])
