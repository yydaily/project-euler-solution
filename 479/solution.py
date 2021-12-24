u = 1000000
mod = int(1e9 + 7)


def add(a, b):
    a = (a + b) % mod
    return (a + mod) % mod


def mul(a, b):
    a = a * b % mod
    return (a + mod) % mod


def qpow(a, b):
    a %= mod
    a = (a + mod) % mod
    ret = 1
    while b > 0:
        if (b & 1) != 0:
            ret = mul(ret, a)
        a = mul(a, a)
        b >>= 1
    return ret


def cal(a):
    ret = a
    ret = mul(ret, qpow(1 - a, mod - 2))
    ret = mul(ret, add(0, 1 - qpow(a, u)))
    return ret


if __name__ == "__main__":
    ans = 0
    for i in range(1, u + 1):
        ans = add(ans, cal(add(0, 1 - i * i)))
    print(ans)
