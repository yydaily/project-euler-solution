from random import random
from math import *

query = "UDDDUdddDDUDDddDdDddDDUDDdUUDd"


def meet(a, index):
    for i in range(index + 1):
        if query[i] == "D":
            if a % 3 != 0:
                return False
            a //= 3
        elif query[i] == "d":
            if a % 3 != 2:
                return False
            a = (a * 2 - 1) // 3
        else:
            if a % 3 != 1:
                return False
            a = (a * 4 + 2) // 3
    return True


base = 1
x1, x2 = 0, 0
for i in range(len(query)):
    while not meet(x1, i):
        x1 += base
    x2 = x1 + base
    while not meet(x2, i):
        x2 += base
    base = x2 - x1
while x2 < 1e15:
    x2 += base
print(x2)
