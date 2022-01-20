def cal(a, b):
	if a > b:
		a, b = b, a
	a<<=1
	b<<=1

	ret = 0
	for i in range(0, a, 2):
		for j in range(0, b, 2):
			for l in range(i+1, a+1, 2):
				ret += (b-j)//2
	for i in range(a):
		for j in range(i&1, b, 2):
			for l in range(min(j, a-i), 0, -1):
				ret += min(a-i-l+1, b-j+1) - max(1, l-j)
	return ret

if __name__ == '__main__':
	ans = 0
	for i in range (1, 48):
		for j in range(1, 44):
			ans += cal(i, j)
	print(ans)
