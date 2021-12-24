maxm = 4000 * 10000 + 1
num = list(range(0, maxm))
e = [0] * maxm

for i in range(2, maxm):
    if num[i] == i:
        for j in range(i, maxm, i):
            num[j] = int(num[j] / i * (i - 1))
e[1] = 1
ans = 0
for i in range(2, maxm):
    e[i] = e[num[i]] + 1
    if e[i] == 25 and num[i] == i - 1:
        ans += i
print(ans)
