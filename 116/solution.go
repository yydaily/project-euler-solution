package main

import "fmt"

var num = [51]int64{}

func cal(count int64, step ...int64) int64 {
	for i := 1; i <= 50; i++ {
		num[i] = 0
	}
	num[0] = 1
	for i := int64(1); i <= 50; i++ {
		for _, s := range step {
			if i-s >= 0 {
				num[i] += num[i-s]
			}
		}
	}
	return num[50]
}

func main() {
	ans := int64(0)
	for i := int64(2); i <= 4; i++ {
		ans += cal(2, 1, i) - 1
	}
	fmt.Printf("%d\n", ans)
}
