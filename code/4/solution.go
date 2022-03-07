package main

import "fmt"

func cal(a int) int {
	ret := 0
	for a > 0 {
		ret = ret*10 + a%10
		a /= 10
	}
	return ret
}

func main() {
	ans := 0
	for i := 100; i <= 999; i++ {
		for j := 100; j <= 999; j++ {
			if cal(i*j) == i*j {
				if i*j > ans {
					ans = i * j
				}
			}
		}
	}
	fmt.Printf("%d\n", ans)
}
