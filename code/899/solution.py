def L(a):
    ans = 0
    i = 1
    while i <= a:
        cnt = min(a, 2 * i - 1) - i + 1
        cnt2 = (a + 1) // 2 // i
        ans += cnt * cnt2 * 2
        i *= 2
    i = 1
    while i <= a:
        ans -= 1
        i = i * 2 + 1
    return ans


print(L(7))
print(L(49))
print(L(7**17))
