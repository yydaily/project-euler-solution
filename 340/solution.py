a = 21 ** 7
b = 7 ** 21
c = 12 ** 7

buf = 4 * a - 4 * c + b

base = int((buf * 2 - a + 1) * a / 2)
cnt = int((b + 1) / a)
ans = (base * 2 + 3 * a * (a - c) * (cnt - 1)) * cnt / 2
print(ans)

buf = buf + cnt * 3 * (a - c)
ind = b % a
ans += int((buf * 2 - ind) * (ind + 1) / 2)

print(ans % 1000000000)
