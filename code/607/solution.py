# -*- coding: UTF-8 -*-
from math import *


def cost_time(x0, y0, x1, y1, speed):
    x0 -= x1
    y0 -= y1
    return sqrt(x0 * x0 + y0 * y0) / speed


def cal(x0, y0, x1, y1, speed, target_speed):
    sin_theta_1 = (x1 - x0) / sqrt((y1 - y0) * (y1 - y0) + (x1 - x0) * (x1 - x0))
    sin_theta_2 = sin_theta_1 / speed * target_speed
    return tan(asin(sin_theta_2)) * 10 + x1, y1 + 10


def cal2(x, y):
    ans = cost_time(0, 0, x, y, 10)
    startx, starty = 0, 0
    for i in range(9, 4, -1):
        x2, y2 = cal(startx, starty, x, y, i + 1, i)
        ans += cost_time(x, y, x2, y2, i)
        startx = x
        starty = y
        x = x2
        y = y2
    return ans + cost_time(x, y, 50 * sqrt(2), 50 * sqrt(2), 10)


if __name__ == "__main__":
    endy = (50 * sqrt(2) - 50) / 2
    endx_l, endx_r = 0, 50 * sqrt(2)
    diff = 1
    while diff >= 1e-12:
        lmid = (endx_l * 2 + endx_r) / 3
        rmid = (endx_r * 2 + endx_l) / 3

        lvalue = cal2(lmid, endy)
        rvalue = cal2(rmid, endy)

        diff = abs(rvalue - lvalue)
        if lvalue < rvalue:
            endx_r = rmid
        else:
            endx_l = lmid
    print("%.10f" % cal2(endx_l, endy))
