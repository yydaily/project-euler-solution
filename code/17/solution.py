from random import random
from math import *


num = [
    "",
    "One",
    "Two",
    "Three",
    "Four",
    "Five",
    "Six",
    "Seven",
    "Eight",
    "Nine",
    "Ten",
    "Eleven",
    "Twelve",
    "Thirteen",
    "Fourteen",
    "Fifteen",
    "Sixteen",
    "Seventeen",
    "Eighteen",
    "Nineteen",
    "Twenty",
]
num2 = [
    "",
    "",
    "Twenty",
    "Thirty",
    "Forty",
    "Fifty",
    "Sixty",
    "Seventy",
    "Eighty",
    "Ninety",
]


def cal(a):
    hundred = a // 100
    ten = a // 10 - hundred * 10
    single = a % 10

    ret = ""
    if hundred > 0:
        ret += num[hundred] + "Hundred"
        if ten + single > 0:
            ret += "And"
    if a % 100 <= 20:
        return ret + num[a % 100]
    return ret + num2[ten] + num[single]


if __name__ == "__main__":
    ans = 11
    for i in range(1, 1000):
        ans += len(cal(i))
    print(ans)
