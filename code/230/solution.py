from random import random
from math import *

a = "1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679"
b = "8214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196"
length = [0] * 1000


def D(index):
    length[0] = len(a)
    length[1] = len(b)
    ind = 1
    while length[ind] < index:
        length[ind + 1] = length[ind] + length[ind - 1]
        ind += 1
    while ind > 1:
        if length[ind - 2] >= index:
            ind -= 2
        else:
            index -= length[ind - 2]
            ind -= 1
    if ind == 1:
        return b[index]
    return a[index]


if __name__ == "__main__":
    base = 1
    ans = ""
    for i in range(18):
        ans = D((127 + 19 * i) * base - 1) + ans
        base *= 7
    print(ans)
