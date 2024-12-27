# -*- coding: UTF-8 -*-
from decimal import Decimal, getcontext

getcontext().prec = 50


def C(a, b):
    ret = Decimal(1)
    for i in range(1, b + 1):
        ret = ret * Decimal(a - i + 1) / Decimal(i)
    return ret


def p(瑕疵, 总数):
    ret = Decimal(0)
    a = Decimal(1)
    for i in range(2, 瑕疵 + 1):
        a *= Decimal(i)
    b = Decimal(1)
    c = C(总数, 瑕疵)
    d = 1
    for y in range(瑕疵 // 2 + 1):
        ret += a * b * c * d

        x = 瑕疵 - 2 * y
        a /= Decimal(y * 2 + 2)
        a /= Decimal(y * 2 + 1)
        b *= Decimal((y + 1) * (2 * y + 1))

        d = (
            d
            * Decimal(总数 - x + 1)
            * Decimal(总数 - x + 2)
            / Decimal(y + 1)
            / Decimal(总数 - x - y + 1)
        )
        c = (
            c
            * Decimal(瑕疵 - 2 * y)
            * Decimal(瑕疵 - 2 * y - 1)
            / Decimal(总数 - 瑕疵 + 2 * y + 1)
            / Decimal(总数 - 瑕疵 + 2 * y + 2)
        )

    return ret


if __name__ == "__main__":
    瑕疵 = 20000
    总数 = 1000000

    a = p(瑕疵, 总数)
    b = Decimal(总数**瑕疵)

    getcontext().prec = 10
    print(Decimal(1) - a / b)
