mod = 1307674368000


def add(a, b):
    return (a + b) % mod


def mul(a, b):
    return a * b % mod


class matrix:
    num = []

    def __init__(self):
        self.num = [[0] * 3 for i in range(3)]


def Mul(a, b):
    c = matrix()
    for i in range(3):
        for j in range(3):
            for k in range(3):
                c.num[i][k] = add(c.num[i][k], mul(a.num[i][j], b.num[j][k]))
    return c


def qpow(a, b):
    ret = matrix()
    for i in range(3):
        ret.num[i][i] = 1
    while b > 0:
        if (b & 1) == 1:
            ret = Mul(ret, a)
        a = Mul(a, a)
        b >>= 1
    return ret


def cal(n, x):
    n -= 2
    base = matrix()
    base.num[0][0] = base.num[2][1] = 1
    base.num[0][1] = base.num[1][1] = x
    base.num[0][2] = base.num[1][2] = mul(x, x)
    r = matrix()
    r.num[0][0] = add(x, mul(x, x))
    r.num[1][0] = mul(x, x)
    r.num[2][0] = x
    return Mul(qpow(base, n), r).num[0][0]


if __name__ == "__main__":
    ans = 0
    n = 10**15
    for i in range(0, 101):
        ans = add(ans, cal(n, i))
    print(ans)
