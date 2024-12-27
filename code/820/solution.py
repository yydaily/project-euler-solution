# -*- coding: UTF-8 -*-


def S(a):
    return sum([pow(10, a, i * 10) // i % 10 for i in range(1, a + 1)])


print(S(7))
print(S(100))
print(S(10**7))
