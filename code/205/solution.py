a = [0] * 50
b = [0] * 50
c = [0] * 50


def h(x, upper):
    global c
    c = [0] * 50
    for i in range(1, upper + 1):
        for j in range(0, 40):
            c[j + i] += x[j]


a[0], b[0] = 1, 1

for i in range(1, 10):
    h(a, 4)
    a = c
for i in range(1, 7):
    h(b, 6)
    b = c

s = 0
w = 0

for i in range(50):
    for j in range(50):
        s += a[i] * b[j]
        w += a[i] * b[j] * (i > j)
print(w / s)
