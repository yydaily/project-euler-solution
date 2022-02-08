def a(i):
    return i * (i + 1)


def F(limit):
    k = int(limit ** 0.5)
    results = set()
    for i in range(1, k + 1):
        c = a(i)
        l = (limit // c) ** 0.5
        for j in range(i, int(l) + 1):
            n = c * a(j)
            if n > limit:
                break
            results.add(n)
    return len(results)


print(F(10 ** 14))
