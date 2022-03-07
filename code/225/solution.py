from random import random
from math import *


def check(a):
    t = [1, 1, 1]
    while True:
        tar = (t[0] + t[1] + t[2]) % a
        if tar == 0:
            return False
        t[0], t[1], t[2] = t[1], t[2], tar
        if t[0] == t[1] and t[1] == t[2] and t[2] == 1:
            return True
    return True


if __name__ == "__main__":
    cnt = 0
    for i in range(27, 100000000, 2):
        if check(i):
            cnt += 1
        if cnt == 124:
            print(i)
            break
