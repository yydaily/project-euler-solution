value_upper = 300000
ans = [[0 for i in range(value_upper)] for j in range(52)]
back = [[0 for i in range(value_upper)] for j in range(52)]


def add(a):
    for i in range(51):
        for j in range(value_upper - a):
            if ans[i][j] > 0:
                back[i + 1][j + a] += ans[i][j]
                if back[i + 1][j + a] > 2:
                    back[i + 1][j + a] = 2
    for i in range(51):
        for j in range(value_upper):
            ans[i][j] = back[i][j]


if __name__ == "__main__":
    ans[0][0] = 1
    back[0][0] = 1
    for i in range(1, 101):
        add(i * i)
        print(i, "over")
    ret = 0
    for i in range(value_upper):
        if ans[50][i] == 1:
            ret += i
    print(ret)
