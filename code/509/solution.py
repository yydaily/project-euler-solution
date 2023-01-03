# -*- coding: UTF-8 -*-
from random import random
from math import *

cnt = [0] * 50
mod = 1234567890


def S(a):
    cnt[0] = a // 2 + a % 2
    cnt[1] = a - cnt[0]
    i = 2
    while cnt[i - 1] > 0:
        cnt[i] = cnt[i - 1] // 2
        cnt[i - 1] -= cnt[i]
        i += 1
    ans = 0
    for a in range(50):
        for b in range(50):
            for c in range(50):
                if (a ^ b ^ c) != 0 and cnt[a] > 0 and cnt[b] > 0 and cnt[c] > 0:
                    ans += cnt[a] * cnt[b] * cnt[c]
    return ans % mod


print(S(10))
print(S(100))
print(S(123456787654321))
