mod = int(1e9) + 7
C = [[0 for i in range(100)] for j in range(100)]


def add(a, b):
    return (a + b) % mod


def mul(a, b):
    return (a % mod) * (b % mod) % mod


def init():
    for i in range(100):
        C[i][0] = 1
        C[i][i] = 1
        for j in range(1, i):
            C[i][j] = add(C[i - 1][j - 1], C[i - 1][j])


def cal2(x, a):
    ret = 0
    for i in range(x):
        ret = add(ret, mul(C[x - 1][a - 1], mul(2**i, 2**i)))
        for j in range(i):
            ret = add(ret, mul(mul(2, C[x - 2][a - 2]), mul(2**i, 2**j)))
    return ret


def cal(x, a):
    return mul(C[x - 1][a - 1], add(2**x, -1))


def sum(x, add_cnt, add_val):
    ans = mul(add_cnt, add_val)
    ans = mul(ans, ans)
    for i in range(1, x + 1):
        base = mul(add_cnt + i, add_cnt + i)
        prefix = mul(mul(add_val, add_val), C[x][i])
        suffix = cal2(x, i)
        mid = mul(2, mul(add_val, cal(x, i)))
        ans = add(ans, mul(base, add(prefix, add(suffix, mid))))
    return ans


if __name__ == "__main__":
    init()
    upper = int(10**16) + 1
    lower = 0
    cnt = 0
    ans = 0
    while upper != lower:
        diff = 0
        while upper - lower >= (2**diff):
            diff += 1
        diff -= 1
        ans = add(ans, sum(diff, cnt, lower))
        cnt = cnt + 1
        lower += 1 << diff
    print(ans)
