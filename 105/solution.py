from random import random
from math import *


def check(num):
    m = {}
    val = []
    for i in range(0, 1 << len(num)):
        sum, cnt = 0, 0
        for j in range(0, len(num)):
            if (i & (1 << j)) > 0:
                sum += num[j]
                cnt += 1
        if sum in m:
            return False
        val.append(sum)
        m[sum] = cnt
    val.sort()
    for i in range(1, len(val)):
        if m[val[i]] < m[val[i - 1]]:
            return False
    return True


if __name__ == "__main__":
    ans = 0
    with open("./in") as f:
        lines = f.readlines()
        for line in lines:
            if len(line) <= 1:
                continue
            val = line[: len(line) - 1].split(",")
            ints = []
            sum = 0
            for v in val:
                ints.append(int(v))
                sum += int(v)
            if check(ints):
                ans += sum
    print(ans)
