def cal(a):
    ret = 0
    while a > 0:
        ret = ret * 10 + a % 10
        a = int(a / 10)
    return ret


ans = 0
for i in range(100, 1000):
    for j in range(100, 1000):
        if cal(i * j) == i * j:
            ans = max(ans, i * j)
print(ans)
