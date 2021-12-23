a = 600851475143
b = 2
while b <= a:
    while a % b == 0:
        print(b)
        a /= b
    b += 1
