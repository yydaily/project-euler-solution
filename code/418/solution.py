from random import random
from math import *
from copy import deepcopy

INF = 10**100


def add(a, b):
    if b not in a:
        a[b] = 0
    a[b] = a[b] + 1


def gen(m, a):
    for i in range(2, a + 1):
        while a % i == 0:
            add(m, i)
            a //= i


def solve(m, l, r, now=1, ind=0):
    if now > r:
        return []

    keys = list(m.keys())
    if len(keys) == ind:
        if l <= now and now <= r:
            return [now]
        return []

    ret = []
    for i in range(m[keys[ind]] + 1):
        buf = solve(m, l, r, now * (int(keys[ind]) ** i), ind + 1)
        ret = ret + buf
    return ret


m = {}
u = 1
for i in range(2, 44):
    gen(m, i)
    u *= i
E = u ** (1 / 3)
l = E * 0.999
r = E * 1.001
print(int(l), int(r))

nums = solve(m, l, r)
nums.sort()
print(len(nums))

ok_a, ok_b, ok_c = 1, 1, INF
for i in range(len(nums)):
    print(i)
    for j in range(i, len(nums)):
        if u % (nums[i] * nums[j]) != 0:
            continue
        c = u // nums[i] // nums[j]
        if c < nums[j]:
            break
        if ok_c * nums[i] >= ok_a * c:
            ok_a = nums[i]
            ok_b = nums[j]
            ok_c = c
print(ok_a, ok_b, ok_c)
print(ok_a + ok_b + ok_c)
