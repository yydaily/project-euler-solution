target = 309086668800
val = [154543334400, 68685926400, 38635833600, 24726933504, 17171481600, 12615782400, 9658958400, 7631769600, 6181733376, 4292870400, 3657830400, 3153945600, 2747437056, 2414739600, 1907942400, 1545433344, 1401753600, 1073217600, 847974400, 788486400, 686859264, 603684900, 504631296, 476985600, 406425600, 386358336, 350438400, 305270784, 268304400, 228614400, 211993600, 197121600, 171714816, 155750400, 150921225, 146313216, 126157824, 119246400, 96589584]
m = {}
left_maxm, right_maxm = 1 << 20, 1 << 19
ans = 0

for i in range(left_maxm):
    now = 0
    for j in range(20):
        if (i & (1 << j)) > 0:
            now += val[j]
            if now >= target:
                break
    if now == target:
        ans += 1
    elif now < target:
        if now not in m:
            m[now] = 1
        else:
            m[now] = m[now] + 1

for i in range(right_maxm):
    need = target
    for j in range(19):
        if (i & (1 << j)) > 0:
            need -= val[j + 20]
    if need in m:
        ans += m[need]

print(ans)