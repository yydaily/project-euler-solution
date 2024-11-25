siz = 3 * 10**7
cache = [0] * siz


def a(n):
    if n < siz and cache[n] > 0:
        return cache[n]
    ret = 0
    if n % 2 == 1:
        ret = a(n // 2) - 3 * a(n // 2 + 1)
    else:
        ret = 2 * a(n // 2)
    if n < siz:
        cache[n] = ret
    return ret


def S(n):
    x = n // 2
    ret = 1
    while x % 2 == 0:
        x //= 2
        ret *= 2
    return 4 - ret * a(x)


cache[1] = 1
print(S(10))
print(S(10**12))
