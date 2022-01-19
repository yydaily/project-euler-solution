mod = int(1e9+9)
upper = 765432
total_cnt = 234567
cnt = [[0]*10 for i in range(10)]
cc = [0]*10
cc_back = [0]*10

def add(a):
	x = 0
	while a > 0:
		cnt[x][a%10]+=1
		x+=1
		a = a//10

def cal(ind):
	for i in range(10):
		cc[i] = cnt[ind][i]
		cc_back[i] = 0
	for r in range(1, total_cnt):
		for i in range(1, 10):
			for j in range(1, 10):
				cc_back[(i*j)%10] = (cc_back[(i*j)%10] + cc[i] * cnt[ind][j])%mod
		for i in range(1, 10):
			cc[i] = cc_back[i]
			cc_back[i] = 0
	ret = 0
	for i in range(1, 10):
		ret = (ret + i * cc[i]) % mod
	return ret

if __name__ == '__main__':
	for i in range(upper+1):
		add(i)
	ans = 0
	base = 1
	for i in range(10):
		ans = (ans+cal(i)*base)%mod
		base*=10
	print(ans)
