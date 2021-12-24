def fac(a):
    if a <= 1:
        return 1
    return a * fac(a - 1)


def C(a, b):
    return fac(a) / fac(b) / fac(a - b)


def get_cnt(a):
    ret = 1
    for i in range(7):
        ret *= C(10, a[i])
    return ret


cases = 0
color = 0
num = [0] * 10
upper = 11 ** 7
for i in range(1, upper):
    buf = i
    total = 0
    c = 0
    for j in range(7):
        num[j] = buf % 11
        buf /= 11
        if num[j] != 0:
            c += 1
        total += num[j]
    if total == 20:
        cnt = get_cnt(num)
        color += c * cnt
        cases += cnt
print(color * 1.0 / cases)
