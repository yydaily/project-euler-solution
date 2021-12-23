mod = int(1e9 + 7)


def add(a, b):
    return (a + b) % mod


def mul(a, b):
    return a * b % mod


def qpow(a, b):
    ret = 1
    while b > 0:
        if (b & 1) != 0:
            ret = mul(ret, a)
        a = mul(a, a)
        b = int(b >> 1)
    return ret


def cal(a, b):
    if a < b:
        return 0
    x1 = qpow(2, a % b)
    x2 = qpow(qpow(2, b), int(a / b))
    x3 = add(1, mod - x2)
    x4 = qpow(add(1, mod - qpow(2, b)), mod - 2)
    return mul(x1, mul(x3, x4))


def exgcd(a, b):
    if b == 0:
        return 1, 0, True
    x, y, y_neg = exgcd(b, a % b)
    return y, add(x, mod - mul(y, cal(a, b))), not y_neg


def get_ans(a, b):
    x, y, y_neg = exgcd(a, b)
    x = mul(x, 2)
    y = mul(y, 2)
    if y_neg:
        y = add(mod, -y)
    else:
        x = add(mod, -x)
    return add(add(mod, -2), add(x, y))


def is_prime(a):
    for i in range(2, a):
        if a % i == 0:
            return False
    return True


if __name__ == "__main__":
    ans = 0
    prime = []
    for i in range(2, 1000):
        if is_prime(i):
            prime.append(i * i * i * i * i)
    for i in range(len(prime)):
        for j in range(i + 1, len(prime)):
            ans = add(ans, get_ans(prime[i], prime[j]))
    print(ans)
