from random import random
from math import *


def mul(list1, list2):
    m = {}
    for i in list1:
        for j in list2:
            if (i + j) in m:
                m[i + j] = m[i + j] + 1
            else:
                m[i + j] = 1
    ret = []
    for k in m:
        if (m[k] & 1) > 0:
            ret.append(k)
    return ret


def resolve(n):
    ret = [0]
    base = [0, 1, 3]
    while n > 0:
        if (n & 1) > 0:
            ret = mul(ret, base)
        base = mul(base, base)
        n //= 2
    return ret


mod = 10 ** 9 + 7


def qpow2(n):
    ret = 1
    base = 2
    while n > 0:
        if (n & 1) > 0:
            ret = ret * base % mod
        base = base * base % mod
        n //= 2
    return ret


def value(List):
    ret = 0
    for index in List:
        ret += qpow2(index)
    return ret % mod


n = (8 ** 12) * (12 ** 8)
index_list = resolve(n)
print(value(index_list))
