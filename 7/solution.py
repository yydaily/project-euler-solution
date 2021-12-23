Len = int(1e6)
prime = [False for i in range(Len)]

cnt = 0
for i in range(2, Len):
	if not prime[i]:
		cnt+=1
		if cnt == 10001:
			print(i)
		for j in range(i<<1,Len,i):
			prime[j] = True
