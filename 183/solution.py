def gcd(a, b):
    if a == 0:
        return b
    return gcd(b % a, a)


def handle(a):
    ind = 1
    val = 1
    for i in range(int(a / 2.71828) - 2, int(a / 2.71828) + 2):
        if i < 0 or i >= a:
            continue
        if a ** (i - ind) * val >= i ** i:
            ind = i
            val = i ** i
    ind //= gcd(a, ind)
    while ind % 2 == 0:
        ind //= 2
    while ind % 5 == 0:
        ind //= 5
    if ind == 1:
        return -a
    return a


ans = 0
for i in range(5, 10001):
    a = handle(i)
    ans += a
print(ans)
