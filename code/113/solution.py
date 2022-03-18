from random import random
from math import *

m = {}


def dfs(length, now, nxt):
    if length not in m:
        m[length] = {}
    if now not in m[length]:
        m[length][now] = {}
    if nxt in m[length][now]:
        return m[length][now][nxt]
    if nxt == 10 or nxt == -1:
        return 1
    ret = 0
    for i in range(0, length + 1):
        ret += dfs(length - i, nxt, nxt * 2 - now)
    m[length][now][nxt] = ret
    return ret


l = 100

ans = -10 * l
for i in range(1, l + 1):
    ans += dfs(i, 1, 2)
    ans += dfs(i, 9, 8)
print(ans)
