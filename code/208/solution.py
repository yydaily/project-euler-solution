from random import random
from math import *

true = True
false = False


class p:
    def __init__(self, cnt, dir, x, y):
        self.cnt = cnt
        self.dir = dir
        self.x = x
        self.y = y

    def __hash__(self):
        return int(self.x * 10000 + self.y * 100)

    def __eq__(self, other):
        if abs(self.x - other.x) > 1e-6:
            return false
        if abs(self.y - other.y) > 1e-6:
            return false
        return true


origin = p([0, 0, 0, 0, 0], 0, 0, 0)
pre = {origin: 1}


def spread2(a):
    b = p(a.cnt, (a.dir + 72) % 360, a.x, a.y)
    b.cnt[a.dir // 72] += 1
    angle = (a.dir + 36) * 1.0 / 180 * acos(-1)
    b.x = a.x + cos(angle)
    b.y = a.y + sin(angle)

    c = p(a.cnt, (a.dir + 360 - 72) % 360, a.x, a.y)
    c.cnt[(a.dir // 72 + 4) % 5] += 1
    angle = (a.dir + 360 - 72) % 360 * 1.0 / 180 * acos(-1)
    c.x = a.x + cos(angle)
    c.y = a.y + sin(angle)
    return [b, c]


def spread():
    now = {}
    for i in pre:
        nxt = spread2(i)
        if nxt[0] not in now:
            now[nxt[0]] = 0
        if nxt[1] not in now:
            now[nxt[1]] = 0
        now[nxt[0]] += pre[i]
        now[nxt[1]] += pre[i]
    return now


for i in range(70):
    print(i)
    pre = spread()

print(pre[origin])
