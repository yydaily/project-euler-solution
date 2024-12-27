from math import isqrt

mem = {}


def F(N):
    if N in mem:
        return mem[N]
    s = N**2 // 8
    z = isqrt(N)
    for g in range(3, z + 1, 2):
        s -= F(N // g)
    for x in range(1, N // (z + 1) + 1):
        s -= ((N // x + 1) // 2 - (N // (x + 1) + 1) // 2) * F(x)
    mem[N] = s
    return s


def H(N):
    return 1 + 2 * F(N)


print(H(10**9))
