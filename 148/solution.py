def cal(a):
	if a <= 7:
		return int(a * (a+1) / 2)
	base = 1
	row = 1
	while a > row * 7:
		row *= 7
		base *= 28
	cnt = int(a / row)
	ret = int(cnt * (cnt + 1) / 2) * base
	return ret + (cnt + 1) * cal(a - cnt * row)

print(cal(1000 * 1000 * 1000))
