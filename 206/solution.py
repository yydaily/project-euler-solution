from math import sqrt

lower = int(sqrt(10203040506070809))
while lower % 10 != 7:
    lower += 1

upper = int(sqrt(19300000000000000))
# 138924439
# 138901917
for i in range(lower, upper, 10):
    buf = i * i
    find = True
    for j in range(9, 0, -1):
        if buf % 10 != j:
            find = False
            break
        buf //= 100
    if find:
        print(i * 10)
