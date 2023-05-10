# -*- coding: UTF-8 -*-
x = [0, 1, 2, 3, 11, 12, 13, 21, 22, 23, 31, 32, 33, 111]


def C(a, b):
    ret = 1
    for i in range(1, b + 1):
        ret = ret * (a - b + i) // i
    return ret


def cal2(a, b, c):
    return C(a + b + c, a) * C(b + c, min(b, c))


v = []


def cal(length):
    global v
    ret = 0
    v = []
    for i in x:
        for j in x:
            for k in x:
                if i + j + k != length:
                    continue
                ret += cal2(i, j, k)
                v.append([i, j, k])
    return ret


def solve(index, length, mod):
    ret = 0
    cnt = [0, 0, 0]
    for i in range(length):
        for j in range(1, 4):
            cnt[j - 1] += 1
            solution = 0
            for a in v:
                if a[0] < cnt[0] or a[1] < cnt[1] or a[2] < cnt[2]:
                    continue
                solution += cal2(a[0] - cnt[0], a[1] - cnt[1], a[2] - cnt[2])
            cnt[j - 1] -= 1

            if solution < index:
                index -= solution
            else:
                cnt[j - 1] += 1
                ret = (ret * 10 + j) % mod
                break
    return ret


def F(index, mod):
    if index <= 12:
        return x[index]
    index -= 12
    for length in range(3, 1000):
        now = cal(length)
        if index > now:
            index -= now
            continue
        return solve(index, length, mod)


if __name__ == "__main__":
    print(F(4, 10 ** 20))
    print(F(10, 10 ** 20))
    print(F(40, 10 ** 20))
    print(F(1000, 10 ** 20))
    print(F(6000, 10 ** 20))
    print(F(111111111111222333, 123123123))
