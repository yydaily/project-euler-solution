def check(a):
    return a < 100


a, b = [], []
for i in range(1, 21):
    a.append(100 + i)
    a.append(200 + i * 2)
    a.append(300 + i * 3)
    b.append(200 + i * 2)

a.append(100 + 25)
a.append(200 + 50)
b.append(200 + 50)

ans = 0

for k in b:
    if check(k % 100):
        ans += 1
print(ans)

for i in a:
    for k in b:
        if check(i % 100 + k % 100):
            ans += 1
print(ans)

for i in a:
    for j in a:
        for k in b:
            if check(i % 100 + j % 100 + k % 100) and j >= i:
                ans += 1
print(ans)
