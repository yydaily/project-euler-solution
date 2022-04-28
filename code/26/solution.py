def cal(a):
    base, ans = 1, 0
    m = {}
    while base > 0:
        base = base * 10 % a
        if base in m:
            return ans - m[base] + 1
        ans += 1
        m[base] = ans
        if base == 1:
            return ans
    return 0


ans = 1
for i in range(3, 1000):
    if cal(i) > cal(ans):
        ans = i
print(ans)
