mod = int(1e9)


def add(a, b):
    return (a + b) % mod


def mul(a, b):
    return a * b % mod


def Mul(a, b):
    ret = [[0 for j in range(11)] for i in range(11)]
    for i in range(11):
        for j in range(11):
            for k in range(11):
                ret[i][k] = add(ret[i][k], mul(a[i][j], b[j][k]))
    return ret


def qpow(a, b):
    ret = [[0 for j in range(11)] for i in range(11)]
    for i in range(11):
        ret[i][i] = 1
    while b > 0:
        if (b & 1) == 1:
            ret = Mul(ret, a)
        a = Mul(a, a)
        b >>= 1
    return ret


base = [
    [1, 0, 0, 2, 1, 0, 0, 1, 1, 7, mod - 2],
    [0, 0, 0, 1, 1, 0, 0, 0, 1, 1, mod - 1],
    [0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 1, 0, 0, 0, 1, 0, 6, mod - 1],
    [0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
]

power = int(1e18)
ret = qpow(base, power - 4)
print(ret[0][0] * 2 + ret[0][5] * 2 + ret[0][9] + ret[0][10]) % mod
