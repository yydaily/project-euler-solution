from random import random
from math import *

people = 100
max_dis = people >> 1
a, b = [0.0] * people, [0] * people


def gao():
    global a, b
    for i in range(1, max_dis + 1):
        for x in range(1, 7):
            for y in range(1, 7):
                dis = i + int(x == 6) - int(x == 1) + int(y == 1) - int(y == 6)
                if dis == -1:
                    dis = 1
                if dis > max_dis:
                    dis = people - dis
                b[dis] += a[i] / 36.0


a[max_dis] = 1.0
ans = 0
for i in range(1, 100000):
    for j in range(len(b)):
        b[j] = 0
    gao()
    ans += i * b[0]
    a[1 : max_dis + 1] = b[1 : max_dis + 1]
print("%4.6f" % ans)
