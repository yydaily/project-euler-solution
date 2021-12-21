mod = int(1e9+7)
def cal_add(a, b):
	return (a+b)%mod
def mul(a, b):
	return a*b%mod
def qpow(a, b):
	ret = 1
	while b > 0:
		if (b&1) != 0:
			ret = mul(ret, a)
		a = mul(a, a)
		b>>=1
	return ret
ans = [[] for j in range(20)]
def cal(a, b):
	return mul(mul(a, b), qpow(cal_add(a, b), mod-2))
def add(a, x, y):
	for i in ans[x]:
		for j in ans[y]:
			ans[a].append(cal_add(i, j))
			ans[a].append(cal(i, j))
def show():
	a = []
	for i in range(1, 19):
		for j in ans[i]:
			a.append(j)
	a = list(set(a))
	print(len(a))
if __name__ == '__main__':
	ans[1].append(1)
	for i in range(2, 19):
		for j in range(1, int(i/2+1)):
			add(i, j, i-j)
		ans[i] = list(set(ans[i]))
	show()
