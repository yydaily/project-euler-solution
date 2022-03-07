dp = {}

num = [181, 141, 52, 214]

l = 30


def get_next(a):
    for i in range(4):
        if a == num[i]:
            return 1 << i
    return 0


def set(a, b, c, d):  # {{{
    if a not in dp:
        dp[a] = {}
    if b not in dp[a]:
        dp[a][b] = {}
    if c not in dp[a][b]:
        dp[a][b][c] = 0
    dp[a][b][c] += d


def get(a, b, c):
    if a not in dp:
        return 0
    if b not in dp[a]:
        return 0
    if c not in dp[a][b]:
        return 0
    return dp[a][b][c]  # }}}


for i in range(256):  # {{{
    set(4, i, 0, 1)
for i in range(4):
    set(4, num[i], 1 << i, 1)
    set(4, num[i], 0, -1)  # }}}

for i in range(5, l + 1):
    for j in range(256):
        for k in range(4):
            now = ((j & 63) << 2) | k
            nxt = get_next(now)
            for vis in range(16):
                if (vis & nxt) != 0:
                    continue
                set(i, now, vis | nxt, get(i - 1, j, vis))
# print(i, now, vis|nxt, get(i, now, vis|nxt), vis)

# 208 = 03100
# 5 208 0 1 0
ans = 0
for i in range(256):
    ans += get(l, i, 15)
print(ans)
