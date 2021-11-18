sum_of_even = 0
a, b = 1, 2
while b < 4 * 1000 * 1000:
	if b % 2 == 0:
		sum_of_even += b
	a, b = b, a+b
print(sum_of_even)
