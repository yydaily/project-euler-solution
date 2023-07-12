# -*- coding: UTF-8 -*-
cache = zeros((61, 41, 61, 41))
cache = [
    [[[0 for i in range(41)] for j in range(61)] for k in range(41)] for l in range(61)
]


def cal(b, w, b_cnt, w_cnt):
    global cache
    if b * w_cnt > b_cnt * w:
        return 0
    if b == 0 and w == 0:
        return 1

    if cache[b][w][b_cnt][w_cnt] > 0:
        return cache[b][w][b_cnt][w_cnt]

    ret = 0
    for i in range(b + 1):
        for j in range(w + 1):
            if i == 0 and j == 0:
                continue
            if i * w_cnt > b_cnt * j:
                continue
            if i * w_cnt == b_cnt * j and i > b_cnt:
                continue
            if i * w_cnt == b_cnt * j and i == b_cnt and j > w_cnt:
                continue
            ret += cal(b - i, w - j, i, j)
    cache[b][w][b_cnt][w_cnt] = int(ret)
    return int(ret)


print(cal(3, 1, 60, 0))
print(cal(60, 40, 60, 0))
