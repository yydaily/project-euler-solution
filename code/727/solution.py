# -*- coding: UTF-8 -*-
from math import *


def f(x, y):
    return x * x + y * y


class point:
    def __init__(self, x, y):
        self.x = x
        self.y = y


def cal1(a, b, c):
    d1 = f(b.x, b.y) - f(a.x, a.y)
    d2 = f(c.x, c.y) - f(b.x, b.y)
    fm = 2 * ((c.y - b.y) * (b.x - a.x) - (b.y - a.y) * (c.x - b.x))
    ans_x = ((c.y - b.y) * d1 - (b.y - a.y) * d2) / fm
    ans_y = ((b.x - a.x) * d2 - (c.x - b.x) * d1) / fm
    return point(ans_x, ans_y)


def cal2(ra, rb, rc):
    r = (ra * rb * rc) / (
        ra * rb + rb * rc + ra * rc + 2 * sqrt(ra * rb * rc * (ra + rb + rc))
    )

    cos_alpha = (f(ra + r, ra + rb) - f(rb + r, 0)) / 2 / (ra + r) / (ra + rb)
    return point(cos_alpha * (ra + r), (ra + r) * sin(acos(cos_alpha)))


def cal(ra, rb, rc):
    cos_alpha = (f(ra + rb, ra + rc) - f(rb + rc, 0)) / 2 / (ra + rb) / (ra + rc)
    cos_beta = (f(ra + rb, rb + rc) - f(ra + rc, 0)) / 2 / (ra + rb) / (rb + rc)
    O1 = cal1(
        point(ra, 0),
        point(cos_alpha * ra, sin(acos(cos_alpha)) * ra),
        point(ra + rb - cos_beta * rb, rb * sin(acos(cos_beta))),
    )
    O2 = cal2(ra, rb, rc)
    return sqrt(f(O1.x - O2.x, O1.y - O2.y))


def gcd2(a, b):
    if a == 0:
        return b
    return gcd2(b % a, a)


def gcd(a, b, c):
    return gcd2(a, gcd2(b, c))


if __name__ == "__main__":
    cnt = 0.0
    ans = 0
    for i in range(1, 101):
        for j in range(i + 1, 101):
            for k in range(j + 1, 101):
                if gcd(i, j, k) != 1:
                    continue
                cnt += 1
                ans += cal(i, j, k)
    ans /= cnt
    print("%.8f" % ans)
