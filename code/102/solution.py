from random import random
from math import *


def area(x1, y1, x2, y2, x3, y3):
    a = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2))
    b = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3))
    c = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3))
    p = (a + b + c) / 2
    s = sqrt(p * (p - a) * (p - b) * (p - c))
    return s


def check(x1, y1, x2, y2, x3, y3):
    origin = area(x1, y1, x2, y2, x3, y3)
    s1 = area(0, 0, x1, y1, x2, y2)
    s2 = area(0, 0, x2, y2, x3, y3)
    s3 = area(0, 0, x1, y1, x3, y3)
    return fabs(origin - s1 - s2 - s3) <= 1e-6


def cal(query):
    val = query.split(",")
    if check(
        float(val[0]),
        float(val[1]),
        float(val[2]),
        float(val[3]),
        float(val[4]),
        float(val[5]),
    ):
        return 1
    return 0


if __name__ == "__main__":
    ans = 0
    with open("./in") as f:
        lines = f.readlines()
        for line in lines:
            if len(line) <= 1:
                continue
            ans += cal(line[: len(line) - 1])
    print(ans)
