def rev(a):
    ret = 0
    while a > 0:
        ret = ret * 10 + a % 10
        a = a // 10
    return ret


def check(a):
    if a % 10 == 0:
        return 0
    a += rev(a)
    while a > 0:
        if a % 2 == 0:
            return 0
        a = a // 10
    return 1


upper = 1000 * 1000 * 100
ans = 0
for i in range(1, upper, 2):
    if i % 1000000 == 0:
        print(i)
    if check(i) == 1:
        ans += 2
print(ans)
