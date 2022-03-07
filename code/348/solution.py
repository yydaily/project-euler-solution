from math import sqrt

number = []


def gen(a):
    global number_cnt
    len = 0
    digit = []
    while a > 0:
        digit.append(a % 10)
        len += 1
        a //= 10

    v, v2 = 0, 0
    for i in range(len - 1, -1, -1):
        v = v * 10 + digit[i]
        if i > 0:
            v2 = v2 * 10 + digit[i]
    for i in range(0, len):
        v = v * 10 + digit[i]
        v2 = v2 * 10 + digit[i]
    number.append(v)
    number.append(v2)


def check(a):
    cnt = 0
    for i in range(2, a):
        i3 = i * i * i
        if i3 > a:
            break
        x = int(sqrt(a - i3))
        if x > 1 and x * x + i3 == a:
            cnt += 1
        if cnt > 4:
            return False
    return cnt == 4


if __name__ == "__main__":
    cnt = 0
    sum = 0
    for i in range(100000):
        gen(i)
    print("gen over!")
    number.sort()
    for i in number:
        if check(i):
            cnt += 1
            sum += i
            print("found ", i)
        if cnt == 5:
            break
    print(sum)
