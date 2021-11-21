mod = int(1e9+7)
def add(a, b):
	return (a+b)%mod
def mul(a, b):
	return a*b%mod
upper = int(1e8)
prime = [False for i in range(upper)]

def cal(ind):
	buf = ind
	while buf <= upper:
		buf *= ind
	buf /= ind
	return buf

ans = 1
for i in range(2, upper):
	if prime[i] == False:
		ans = mul(ans, cal(i))
		for j in range(i*2, upper, i):
			prime[j] = True

print(mul(ans, 2))
