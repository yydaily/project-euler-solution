from random import random
from math import *

mod = int(1e9 + 7)
n = int(1e16)
inv2 = int((mod + 1) // 2)


def cal(l):
    x = int(n - l * (l + 1) // 2 + 1)
    if x <= 0:
        return 0
    ans1 = (int(x // l) * int(x // l + 1) * l * inv2) % mod
    ans2 = (x % l * int(x // l + 1)) % mod
    return (ans1 + ans2) % mod


if __name__ == "__main__":
    ans = 0
    for i in range(1, mod):
        now = cal(i)
        if now == 0:
            break
        ans += now
    print(ans % mod)
