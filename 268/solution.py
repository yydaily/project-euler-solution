u = 10 ** 16
a = [
    2,
    3,
    5,
    7,
    11,
    13,
    17,
    19,
    23,
    29,
    31,
    37,
    41,
    43,
    47,
    53,
    59,
    61,
    67,
    71,
    73,
    79,
    83,
    89,
    97,
]
cnt_ = {}


def C(a, b):
    ret = 1
    for i in range(b + 1, a + 1):
        ret = int(ret * i / (i - b))
    return ret


def init():
    for i in range(20):
        cnt_[i] = 0
    cnt_[4] = 1
    for i in range(5, 15):
        cnt_[i] = 0
        for j in range(4, i):
            cnt_[i] += cnt_[j] * C(i, j)
        cnt_[i] = 1 - cnt_[i]


def cal(buf):
    x = 1
    cnt = 0
    for i in range(26):
        if (buf & (1 << i)) > 0:
            x *= a[i]
            cnt += 1
            if x > u:
                return 0
    return cnt_[cnt] * int(u / x)


if __name__ == "__main__":
    init()
    upper = 1 << 25
    ans = 0
    for i in range(1, upper):
        ans += cal(i)
    print(ans)
