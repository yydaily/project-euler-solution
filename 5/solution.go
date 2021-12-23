package main

import "fmt"

func gcd(a, b int) int {
	if a == 0 {
		return b
	}
	return gcd(b%a, a)
}

func lcm(a, b int) int {
	return a / gcd(a, b) * b
}

func main() {
	ans := 1
	for i := 2; i <= 20; i++ {
		ans = lcm(ans, i)
	}
	fmt.Printf("%d\n", ans)
}
