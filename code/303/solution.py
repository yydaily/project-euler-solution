from random import random
from math import *


def cal(a):
    if a == 9999:
        return 0
    x = []
    ano = []
    x.append([0, 0])
    i = 1
    while True:
        for j in x:
            if j[0] > 0 or j[1] > 0:
                now = [j[0] * 10 + (j[1] * 10) // a, (j[1] * 10) % a]
                if now[1] == 0:
                    return now[0]
                ano.append(now)

            now = [j[0] * 10 + (j[1] * 10 + 1) // a, (j[1] * 10 + 1) % a]
            if now[1] == 0:
                return now[0]
            ano.append(now)

            now = [j[0] * 10 + (j[1] * 10 + 2) // a, (j[1] * 10 + 2) % a]
            if now[1] == 0:
                return now[0]
            ano.append(now)
        x = ano
        ano = []
        i *= 10


print(sum(cal(i) for i in range(1, 10001)) + 1111333355557778)
