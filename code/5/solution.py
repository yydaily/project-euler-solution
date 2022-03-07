def gcd(a, b):
    if a == 0:
        return b
    return gcd(b % a, a)


def lcm(a, b):
    return a / gcd(a, b) * b


ans = 1
for i in range(2, 21):
    ans = lcm(ans, i)

print(ans)
