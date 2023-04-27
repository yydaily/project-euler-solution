# -*- coding: UTF-8 -*-
def qpow(a, b, m):
    ret = 1
    while b > 0:
        if (b & 1) > 0:
            ret = ret * a % m
        a = a * a % m
        b >>= 1
    return ret


def g(p):
    a = qpow(2, qpow(2, p, p - 1), p)
    ans1 = (a & 1) * qpow(2, p - 1, p)
    ans2 = qpow(2, p - 1, p * p) - 1 + p * p
    ans2 //= p
    ans2 *= a

    return (ans1 + ans2) % p


def G(n):
    prime = [True] * (n + 1)
    p = []
    for i in range(2, n + 1):
        if prime[i]:
            p.append(i)
        for pri in p:
            if i * pri > n:
                break
            prime[i * pri] = False
            if i % pri == 0:
                break
    ans = 0
    for i in range(1, len(p)):
        ans += g(p[i])
    return ans


print(G(100))
print(G(10 ** 4))
print(G(10 ** 7))
