package main

import "fmt"

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	return a + b - max(a, b)
}

func cal(a, b int) int {
	if a > b {
		a, b = b, a
	}
	a <<= 1
	b <<= 1
	ret := 0
	for i := 0; i < a; i += 2 {
		for j := 0; j < b; j += 2 {
			for l := i + 1; l <= a; l += 2 {
				ret += (b - j) / 2
			}
		}
	}
	for i := 0; i < a; i++ {
		for j := i & 1; j < b; j += 2 {
			for l := min(j, a-i); l >= 1; l-- {
				ret += min(a-i-l+1, b-j+1) - max(1, l-j)
			}
		}
	}
	return ret
}

func main() {
	ans := 0
	for i := 1; i <= 47; i++ {
		for j := 1; j <= 43; j++ {
			ans += cal(i, j)
		}
	}
	fmt.Printf("%d\n", ans)
}
