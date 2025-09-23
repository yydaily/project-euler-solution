m = {}


def filter(s, index):
    ret = s[:index] + s[index + 1 :]
    while len(ret) > 0 and ret[0] == "0":
        ret = ret[1:]
    if len(ret) == 0:
        return "0"
    return ret


def check(n):
    now = bin(n)[2:]
    if now in m and m[now] != 0:
        return m[now]
    for i in range(len(now)):
        nxt = filter(now, i)
        if nxt in m and m[nxt] == -1:
            m[now] = 1
            return 1
    m[now] = -1
    return -1


pow9 = [1]
for i in range(1, 30):
    pow9.append(pow9[-1] * 9)


def W(n):
    m["0"] = -1
    x = -1
    while n > 0:
        x += 1
        n //= 10

    ans = 0
    for i in range(1, 1 << x):
        if check(i) == 1:
            ans += pow9[bin(i).count("1")]
    return ans


print(W(100))
print(W(10**4))
print(W(10**18))
