mod = int(1e6)
length = int(1e5)
pp = [0] * length
asist = [0] * (length * 2)

for i in range(length):
    asist[i << 1] = int(i * (i * 3 - 1) / 2)
    asist[i << 1 | 1] = int(i * (i * 3 + 1) / 2)

pp[0], pp[1], pp[2] = 1, 1, 2
for i in range(3, length):
    k, flags, j = 0, 0, 2
    while asist[j] <= i:
        flags = k & 2
        if flags == 0:
            pp[i] = (pp[i] + pp[i - asist[j]] + mod) % mod
        else:
            pp[i] = (pp[i] - pp[i - asist[j]] + mod) % mod
        k = (k + 1) & 7
        j += 1
for i in range(1, length):
    print(i, pp[i])
    if pp[i] == 0:
        break
