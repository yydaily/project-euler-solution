def check(x):
    z = str(x * x)
    a = int(z[: len(z) // 2])
    b = int(z[len(z) // 2 :])
    if z[len(z) // 2] == "0":
        return False
    return a + b == x


ans = 0
for i in range(9, 10**8):
    if check(i):
        ans += i * i
print(ans)
