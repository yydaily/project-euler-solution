import sys

sys.setrecursionlimit(5000)
from random import random
from math import *

upper = 75 * 10 ** 6
ans = 0
vis = {}


def dfs(a, b, c):
    global ans
    if a > b:
        a, b = b, a
    if a > c:
        a, c = c, a
    if b > c:
        b, c = c, b
    if a + b + c > upper:
        return
    s = str(a) + " " + str(b) + " " + str(c)
    if s in vis:
        return
    vis[s] = True
    ans += 1
    dfs(2 * c + b - 2 * a, 2 * c + 2 * b - a, 3 * c + 2 * b - 2 * a)
    dfs(2 * c + b + 2 * a, 2 * c + 2 * b + a, 3 * c + 2 * b + 2 * a)
    dfs(2 * c - 2 * b + a, 2 * c - b + 2 * a, 3 * c - 2 * b + 2 * a)


dfs(2, 2, 3)
print(ans)
