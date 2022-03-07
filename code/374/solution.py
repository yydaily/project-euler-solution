from random import random
from math import *

mod = 982451653
query = int(1e14)
upper = int(15 * (10 ** 6))
fac = [0] * (upper + 10)
inv = [0] * (upper + 10)


def init():
    fac[1], inv[1] = 1, 1
    for i in range(2, upper + 1):
        fac[i] = (fac[i - 1] * i) % mod
        inv[i] = ((mod - mod // i) * inv[mod % i]) % mod
    print("init success")


def cal1():
    ret, length, base, sum = 0, 2, 15, 8
    i = 5
    while sum <= query:
        ret = (ret + length * base) % mod
        length += 1
        sum += i
        base = (base * inv[i] * (i - 1) * (i + 1)) % mod
        i += 1
    print("cal part 1 success: ", ret)
    return ret


def cal2():
    base, maxm, ret, length = 26, 7, 0, 2
    while maxm <= query:
        ret = (ret + base * length) % mod
        base = (base * (length + 3) + fac[length + 2]) % mod
        maxm += length + 3
        length += 1

    base = (fac[length + 1] * length) % mod
    nouse = (length + 1) * (length + 2) / 2 - 1
    while nouse <= query:
        ret = (ret + base) % mod
        base = (base * (length + 2) * inv[length + 1]) % mod
        length -= 1
        nouse += 1
    print("cal part 2 success: ", ret)
    return ret


if __name__ == "__main__":
    init()
    ans = (10 + cal1() + cal2()) % mod
    print(ans)
