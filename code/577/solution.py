from random import random
from math import *


def cal(n):
    return (
        15 * n ** 4
        + 270 * n ** 3
        + 1665 * n ** 2
        + [4050, 4170, 3930][n % 3] * n
        + [3240, 3600, 2520][n % 3]
    ) // 3240


ans = 0
for i in range(12343):
    ans += cal(i)

print(ans)
