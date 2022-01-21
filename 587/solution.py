from math import sqrt, ceil
R = 100000

def cal(i):
	return R - sqrt(i*(2*R-i))

def check(n):
	sum, buf = 0, 0
	for i in range(R):
		upper1 = cal(i)
		upper2 = i/n
		sum+=upper1
		buf+=min(upper1, upper2)
	return buf/sum*1000

if __name__ == '__main__':
	l, r = 15, 1e10
	while l + 0.1 < r :
		mid = (l+r)/2
		if check(mid) > 1:
			l = mid
		else:
			r = mid
	print(ceil(l))
