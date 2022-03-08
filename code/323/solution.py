import decimal

e = []
e.append(decimal.Decimal(0))


def x(a):
    if a == 0:
        return decimal.Decimal(1)
    return a * x(a - 1)


def C(a, b):
    return x(a) / x(b) / x(a - b)


for i in range(1, 33):
    e.append(decimal.Decimal(1) / (decimal.Decimal(2) ** i - 1))
    for j in range(0, i):
        e[i] += (e[j] + 1) * C(i, j) / (decimal.Decimal(2) ** i - 1)
print("%.10f" % e[32])
