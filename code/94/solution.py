from random import random
from math import *

ans1 = 0
k, t = 8, 15
while True:
    n = k * 2 + 1
    S = n * 3 - 1
    if S > 1e9:
        break
    if S > 0:
        ans1 += S
        print(n, n, n - 1)
    k, t = -2 * k - t - 2, -3 * k - 2 * t - 2

ans2 = 0
k, t = 2, 4
while True:
    n = k * 2 + 1
    S = n * 3 + 1
    if S > 1e9:
        break
    if S > 0:
        ans2 += S
        print(n, n, n + 1)
    k, t = -2 * k - t - 1, -3 * k - 2 * t - 1

print(ans1 + ans2)
