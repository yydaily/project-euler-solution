def f(a, b):
    if a <= b:
        return a
    le = b
    ri = b
    i = 1
    while True:
        le = ri + 1
        ri = ri + i
        if ri >= a:
            return b + f(a, le)
        i *= 2


print(f(6, 1))
print(f(10, 3))
print(f(10**17, 9**17))
