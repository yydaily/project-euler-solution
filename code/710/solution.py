from random import random
from math import *

mod = int(1e6)
cnt = [0 for i in range(8)]
cnt2 = [0 for i in range(8)]

cnt[0], cnt2[2] = 1, 1

summary_cnt = [1, 0]
summary_cnt2 = [0, 0]

for i in range(1, 100000000):
    ind, sum_ind = i & 7, i & 1
    cnt[ind] = 1
    if i >= 4:
        cnt2[ind] = (cnt[ind ^ 4] - cnt2[ind ^ 4]) % mod
    cnt[ind] = (cnt[ind] + summary_cnt[sum_ind]) % mod
    cnt2[ind] = (cnt2[ind] + summary_cnt2[sum_ind]) % mod
    if i in [42, 6, 20]:
        print(i, cnt2[ind])
    if i > 42 and cnt2[ind] == 0:
        print(i)
        break
    summary_cnt[sum_ind] = (summary_cnt[sum_ind] + cnt[ind]) % mod
    summary_cnt2[sum_ind] = (summary_cnt2[sum_ind] + cnt2[ind]) % mod
