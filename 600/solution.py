def cal2(a):
    l = a % 2 + 1
    r = a + 1
    le = (r - l) / 2 + 1
    return (l + r) * le / 2


def cal(a):
    ret = 0
    for i in range(1, a):
        if i * 3 > a:
            break
        ret += cal2(a - i * 3)
    return ret


upper = 55106
ans = 0
for i in range(0, upper):
    if i * 3 + 6 > upper:
        break
    ans += cal(int((upper - i * 3) / 2))
print(ans)
