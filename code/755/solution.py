num = [0] * 100
sum = [0] * 100

num[1] = 1
sum[1] = 1
num[2] = 2
sum[2] = 3
for i in range(3, 63):
    num[i] = num[i - 1] + num[i - 2]
    sum[i] = sum[i - 1] + num[i]


def gao(a, upper):
    if upper >= sum[a]:
        return 1 << a
    ret = gao(a - 1, upper)
    if upper >= num[a]:
        ret += gao(a - 1, upper - num[a])
    return ret


print(gao(62, int(10 ** 13)))
