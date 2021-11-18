def cal(a, b=999):
	c = b / a
	return a * c * (c+1) / 2

print(cal(3) + cal(5) - cal(15))
