from random import random
from math import *
from decimal import *

getcontext().prec = 300


def get_min_area(a, b):
    start = [(Decimal(1), Decimal(0), 0, 0)]

    min_area = Decimal(10)

    while len(start) > 0:
        now = start.pop()
        if now[2] > a or now[3] > b:
            continue

        # cal delta
        delta = now[0] + now[1]
        delta = delta * delta
        delta -= 4 * now[0] * now[1] - 4
        delta = delta.sqrt()

        # cal dis
        dis = (delta - now[0] - now[1]) / Decimal(2)

        # update area
        if now[2] == a and now[3] == b:
            min_area = min(min_area, dis * dis)
            continue

        # spread
        start.append((now[0], now[1] + dis, now[2], now[3] + 1))
        start.append((now[0] + dis, now[1], now[2] + 1, now[3]))
    return min_area


def get_index(area):
    start = [(Decimal(1), Decimal(0))]
    ans = 0
    while len(start) > 0:
        now = start.pop()
        # cal delta
        delta = now[0] + now[1]
        delta = delta * delta
        delta -= 4 * now[0] * now[1] - 4
        delta = delta.sqrt()

        # cal dis
        dis = (delta - now[0] - now[1]) / Decimal(2)

        if dis * dis < area:
            continue

        ans += 1
        start.append((now[0], now[1] + dis))
        start.append((now[0] + dis, now[1]))
    return ans


area = get_min_area(3, 3)
ans = get_index(area)
print(ans)
