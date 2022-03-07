package main

import "fmt"

var num, num1 = [1000]int64{}, [1000]int64{}

func cal(n, m int64) int64 {
	for i := 0; i < 1000; i++ {
		num[i], num1[i] = 0, 0
	}
	num[0] = 1
	for i := int64(1); i <= n; i++ {
		num[i] = num[i-1] + num1[i-1]
		if i >= m {
			for j := i - m; j >= 0; j-- {
				num1[i] += num[j]
			}
		}
	}
	return num[n] + num1[n]
}

func main() {
	for i := int64(10); ; i++ {
		value := cal(i, 50)
		fmt.Printf("%d %d\n", i, value)
		if value >= 1000000 {
			break
		}
	}
}
