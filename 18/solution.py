from random import random
from math import *

num = [[0 for i in range(100)] for j in range(100)]

nums = []
with open("./in", "r") as f:
    for line in f.readlines():
        line = line[: len(line) - 1]  # trim \n
        nums.append(line)

ans = 0
length = int(nums[0])
for i in range(length):
    number = nums[i + 1].split(" ")
    for j in range(0, i + 1):
        num[i][j] = int(number[j])
        if i > 0:
            num[i][j] += max(num[i - 1][j], num[i - 1][j - 1] if j > 0 else 0)
        ans = max(ans, num[i][j])
print(ans)
