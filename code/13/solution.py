ans = [0 for i in range(101)]

with open("./in", "r") as f:
    strs = f.readlines()

for s in strs:
    s = s[: len(s) - 1]
    for i in range(len(s)):
        ans[i] += int(s[len(s) - i - 1])

for i in range(100):
    ans[i + 1] += ans[i] // 10
    ans[i] %= 10

ind = 0
for i in range(99, -1, -1):
    if ans[i] != 0:
        ind = i
        break

for i in range(ind, ind - 10, -1):
    print(ans[i], end="")
