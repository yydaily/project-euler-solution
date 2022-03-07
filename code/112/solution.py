def check(a):
    while a > 100 and a % 10 == (a // 10) % 10:
        a //= 10
    if a <= 100:
        return 0
    if a % 10 > (a // 10) % 10:
        last = a % 10
        while a > 0:
            if a % 10 > last:
                return 1
            last = a % 10
            a //= 10
    else:
        last = a % 10
        while a > 0:
            if a % 10 < last:
                return 1
            last = a % 10
            a //= 10
    return 0


cnt = 0
for i in range(1, 10000000):
    cnt += check(i)
    if cnt * 100 == 99 * i:
        print(i)
        break
