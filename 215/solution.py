ll = []
l = []
mat = []
ans = []


def generate(num2, num3):
    global ll
    global l
    if num2 + num3 == 1:
        a = 0
        for i in ll:
            a |= 1 << i
        l.append(a)
        return
    base = 0
    if len(ll) != 0:
        base = ll[len(ll) - 1]
    if num2 > 0:
        ll.append(base + 2)
        generate(num2 - 1, num3)
        ll = ll[: len(ll) - 1]
    if num3 > 0:
        ll.append(base + 3)
        generate(num2, num3 - 1)
        ll = ll[: len(ll) - 1]


def gen(buf):
    ret = [0] * len(buf)
    for i in range(len(buf)):
        for j in mat[i]:
            ret[i] += buf[j]
    return ret


if __name__ == "__main__":
    h = 10
    w = 32
    for i in range(w % 2, w, 2):
        j = (w - i * 3) / 2
        if j < 0:
            break
        generate(j, i)
    for i in range(len(l)):
        mat.append([])
    for i in range(len(l)):
        for j in range(i + 1, len(l)):
            if (l[i] & l[j]) == 0:
                mat[i].append(j)
                mat[j].append(i)
    ans = [1] * len(l)
    for i in range(1, h):
        ans = gen(ans)
    answer = 0
    for i in ans:
        answer += i
    print(answer)
