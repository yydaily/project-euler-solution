from random import random
from math import *

ans = [0] * (10**6)


def cal(a):
    ret = (a - 1) % 9 + 1
    for i in range(2, int(sqrt(a)) + 1):
        if a % i == 0:
            ret = max(ret, ans[i] + ans[a // i])
    ans[a] = ret
    return ret


ans = sum(cal(i) for i in range(2, 10**6))
print(ans)
