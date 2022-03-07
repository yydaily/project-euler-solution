def cal(a, b):
    if a >= b:
        return b
    base = cal(a, b - 1)
    cnt = max(0, int(base / (a - 2)) - 4)
    ans = cnt * a
    base -= cnt * (a - 2)
    if base <= a - 1:
        return ans + base + 1
    ans += a
    base -= a - 1
    while base >= a - 2:
        ans += a
        base -= a - 2
    if base > 0:
        ans += base + 2
    return ans


ans = 0
for i in range(3, 41):
    ans += cal(i, 31)
print(ans)
